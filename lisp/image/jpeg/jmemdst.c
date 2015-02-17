/*
 * jmemdst.c
 *
 * Copyright (C) 1994-1996, Toshihiro Matsui, Electrotechnical Laboratory
 */

#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>

/* Expanded data destination object for stdio output */

typedef struct {
  struct jpeg_destination_mgr pub; /* public fields */
  JOCTET * buffer;		/* start of buffer */
  long   * data_count_ptr;
} my_destination_mgr;

typedef my_destination_mgr * my_dest_ptr;

/*
 * Initialize destination --- called by jpeg_start_compress
 * before any data is actually written.
 */


METHODDEF(void)
init_destination (j_compress_ptr cinfo)
{
  my_dest_ptr dest = (my_dest_ptr) cinfo->dest;

  dest->pub.next_output_byte = dest->buffer;
  dest->pub.free_in_buffer = *dest->data_count_ptr;
}

/*
 * Empty the output buffer --- called whenever buffer fills up.
 *
 * In typical applications, this should write the entire output buffer
 * (ignoring the current state of next_output_byte & free_in_buffer),
 * reset the pointer & count to the start of the buffer, and return TRUE
 * indicating that the buffer has been dumped.
 *
 * In applications that need to be able to suspend compression due to output
 * overrun, a FALSE return indicates that the buffer cannot be emptied now.
 * In this situation, the compressor will return to its caller (possibly with
 * an indication that it has not accepted all the supplied scanlines).  The
 * application should resume compression after it has made more room in the
 * output buffer.  Note that there are substantial restrictions on the use of
 * suspension --- see the documentation.
 *
 * When suspending, the compressor will back up to a convenient restart point
 * (typically the start of the current MCU). next_output_byte & free_in_buffer
 * indicate where the restart point will be if the current call returns FALSE.
 * Data beyond this point will be regenerated after resumption, so do not
 * write it out when emptying the buffer externally.
 */

METHODDEF(boolean)
empty_output_buffer (j_compress_ptr cinfo)
{
  my_dest_ptr dest = (my_dest_ptr) cinfo->dest;

  
  fprintf(stderr, " : jpeg compression buffer overflow >%ld\n",
	  *dest->data_count_ptr);

  dest->pub.next_output_byte = dest->buffer;
  dest->pub.free_in_buffer = *dest->data_count_ptr;

  return TRUE;
}

/*
 * Terminate destination --- called by jpeg_finish_compress
 * after all data has been written.  Usually needs to flush buffer.
 *
 * NB: *not* called by jpeg_abort or jpeg_destroy; surrounding
 * application must deal with any cleanup that should happen even
 * for error exit.
 */

METHODDEF(void)
term_destination (j_compress_ptr cinfo)
{
  my_dest_ptr dest = (my_dest_ptr) cinfo->dest;
  size_t datacount = *dest->data_count_ptr - dest->pub.free_in_buffer;

  *dest->data_count_ptr = datacount;
  }


GLOBAL(void)
jpeg_memio_dest (j_compress_ptr cinfo, JOCTET *jpegimgbuf, long *size)
{
  my_dest_ptr dest;

  /* RGB image (provided by the main) is compressed into jpegimgbuf
   * and the size of the resulted JPEG data appears in the size.
   * The size should hold the maximum size of the jpegimgbuf at the beginning.
   */

  if (cinfo->dest == NULL) {	/* first time for this JPEG object? */
    cinfo->dest = (struct jpeg_destination_mgr *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
				  sizeof(my_destination_mgr));
  }

  dest = (my_dest_ptr) cinfo->dest;
  dest->pub.init_destination = init_destination;
  dest->pub.empty_output_buffer = empty_output_buffer;
  dest->pub.term_destination = term_destination;
  dest->buffer = jpegimgbuf;
  dest->data_count_ptr = size;
}
