
typedef struct pixel_image {
  unsigned char *imgary;	/*pointer to the image array*/
  long     depth; 		/*1,8,16, or 32*/
  long	   pixel_bytes;		/*number of bytes per a pixel*/	
  long     twidth, theight;	/*total_width, total_height*/
  long     tsize;		/*total_width x total_height*/
  long     start_x, start_y;
  long     width, height;	/*window_width, window_height*/
  long     wsize;		/*width x height */
  } pixel_image;

struct correlation_info {
  long corval;
  long x,y;
  };

