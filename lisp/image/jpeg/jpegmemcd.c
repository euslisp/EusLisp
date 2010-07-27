/* jpegmemcd.c
*   (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory
*   JPEG compression/decompression for in-core image/jpeg_data.
*
*   int JPEG_compress(RGBimage, width, height, JPEGimage,size, quality); 
*   int JPEG_decompress(JPEGimage, jpeg_size,
*		       RGBimage, result_size, *width, *height)
*/


#include <stdio.h>
#include "jpeglib.h"
#include <setjmp.h>


int JPEG_compress(JSAMPLE *image_buffer, long width, long height,
                  unsigned char *jpeg_image_buffer, long size, int quality)
{
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  JSAMPROW row_pointer[1];      /* pointer to JSAMPLE row[s] */
  int row_stride;               /* physical row width in image buffer */
  long data_count=size;

  cinfo.err = jpeg_std_error(&jerr);

  jpeg_create_compress(&cinfo);

  jpeg_memio_dest(&cinfo, jpeg_image_buffer, &data_count);

/*  fprintf(stderr, 
	"jpeg compress: w=%d h=%d src=%x dest=%x size=%d quality=%d\n", width, height,
	image_buffer, jpeg_image_buffer, size, quality); */

  cinfo.image_width = width;    /* image width and height, in pixels */
  cinfo.image_height = height;
  cinfo.input_components = 3;           /* # of color components per pixel */
  cinfo.in_color_space = JCS_RGB;       /* colorspace of input image */

  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);

  jpeg_start_compress(&cinfo, TRUE);

  row_stride = width * 3;       /* JSAMPLEs per row in image_buffer */

  while (cinfo.next_scanline < cinfo.image_height) {
    row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
    (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
  }

  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);
  return(data_count);
}


/****************************************************************/
struct my_error_mgr {
  struct jpeg_error_mgr pub;	/* "public" fields */

  jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct my_error_mgr * my_error_ptr;


static void my_error_exit (j_common_ptr cinfo)
{
  my_error_ptr myerr = (my_error_ptr) cinfo->err;

  (*cinfo->err->output_message) (cinfo);

  longjmp(myerr->setjmp_buffer, 1);
}

extern int JPEG_header (JOCTET *jpeg_image, long jpeg_size,
			long *width, long *height , long *components)
{ struct jpeg_decompress_struct cinfo;
  struct my_error_mgr jerr;
  long total_size;

  cinfo.err = jpeg_std_error(&jerr.pub);
  jerr.pub.error_exit = my_error_exit;

  if (setjmp(jerr.setjmp_buffer)) {
    jpeg_destroy_decompress(&cinfo);
    return 0;  }

  jpeg_create_decompress(&cinfo);

  jpeg_memio_src(&cinfo, jpeg_image, jpeg_size);

  (void) jpeg_read_header(&cinfo, TRUE);

  jpeg_calc_output_dimensions(&cinfo);

  *width= cinfo.output_width;
  *height= cinfo.output_height;
  *components= cinfo.output_components;
  total_size = cinfo.output_width * cinfo.output_height * 
		cinfo.output_components;

  jpeg_destroy_decompress(&cinfo);
  return(total_size);
}


extern int JPEG_decompress (JOCTET *jpeg_image, long jpeg_size,
			 JOCTET *result_image,
			 long   *width, long *height)
{
  JOCTET *rimage;
  struct jpeg_decompress_struct cinfo;
  struct my_error_mgr jerr;
  JSAMPLE *jsampbuf;
  int row_stride;		/* physical row width in output buffer */
  long total_size;

  cinfo.err = jpeg_std_error(&jerr.pub);
  jerr.pub.error_exit = my_error_exit;

  if (setjmp(jerr.setjmp_buffer)) {
    jpeg_destroy_decompress(&cinfo);
    return 0;  }

  jpeg_create_decompress(&cinfo);

  jpeg_memio_src(&cinfo, jpeg_image, jpeg_size);

  (void) jpeg_read_header(&cinfo, TRUE);

  jpeg_calc_output_dimensions(&cinfo);

  *width= cinfo.output_width;
  *height= cinfo.output_height;

  row_stride = cinfo.output_width * cinfo.output_components;
  total_size = row_stride * cinfo.output_height;

  /*  printf("read_JPEG: width=%d height=%d\n", *width, *height); */
  /*if (total_size > result_size) {
    fprintf(stderr, "jpeg_decompress: result too big. %d > %d\n",
		total_size, result_size);
    jpeg_destroy_decompress(&cinfo);
    return(FALSE);} */

  /* start decompression */
  (void) jpeg_start_decompress(&cinfo);

  while (cinfo.output_scanline < cinfo.output_height) {
    jsampbuf= &result_image[cinfo.output_scanline * row_stride]; 
    (void) jpeg_read_scanlines(&cinfo, &jsampbuf, 1);
  }

  (void) jpeg_finish_decompress(&cinfo); 

  jpeg_destroy_decompress(&cinfo);
  return(total_size);
}


