/****************************************************************/
/* xview.c
/*	euslisp to xview interface functions
/*
/****************************************************************/

#include "../c/eus.h"
#include "euslocal.h"
#include <sys/time.h>
#include <pixrect/pixrect_hs.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/canvas.h>
#include <xview/tty.h>
#include <xview/ttysw.h>
#include <xview/textsw.h>
/*
#include <xview/menu.h>
*/
#include <xview/scrollbar.h>
#include <xview/seln.h>
#include <xview/icon.h>
#include <xview/icon_load.h>
#include <xview/expandname.h>
#include <xview/pixwin.h>
#include <xview/notify.h>
#include <xview/cms.h>  

extern textsw_append_file_name();
extern textsw_delete();
extern textsw_edit();
extern textsw_erase();
extern textsw_find_bytes();
extern textsw_match_bytes();
extern textsw_index_for_file_line();
extern textsw_insert();
extern textsw_first();
extern textsw_next();
extern textsw_replace_bytes();
extern textsw_save();
extern textsw_screen_line_count();
extern textsw_scroll_lines();
extern textsw_store_file();
extern ttysw_input();
extern ttysw_output();

/*
  extern notify_default_wait3();
extern notify_dispatch();
extern notify_do_dispatch();
extern notify_interpose_destroy_func();
extern notify_interpose_event_func();
extern notify_itimer_value();
extern notify_next_destroy_func();
extern notify_next_event_func();
extern notify_set_destroy_func();
extern notify_set_exception_func();
extern notify_set_input_func();
extern notify_set_itimer_func();
extern notify_set_signal_func();
extern notify_set_output_func();
extern notify_set_wait3_func();
extern notify_start();
extern notify_stop();
extern notify_no_dispatch();
extern notify_perror();
extern notify_veto_destroy();
*/
extern pointer *makebnum();

char *ckstrchr(p)
     pointer p;
{
  if (!isstring(p)) error(E_NOSTRING);
  return(strchr(p));
}

pointer call_sunview(func,n,argv)
     long (*func)();
     long n,argv;
{
  register long cargv[100];
  n = largv2cargv(n,argv,cargv,1,100);
  cargv[n] = 0;
  if (n<12) {
    return(makebnum((long)(*func)(cargv[0],cargv[1],cargv[2],
				  cargv[3],cargv[4],cargv[5],
				  cargv[6],cargv[7],cargv[8],
				  cargv[9],cargv[10],cargv[11])));
  }
  else if (n<25) {
    return(makebnum((*func)(cargv[0],cargv[1],cargv[2],
			    cargv[3], cargv[4],cargv[5],
			    cargv[6],cargv[7],cargv[8],
			    cargv[9],cargv[10],cargv[11],
			    cargv[12],cargv[13],cargv[14],
			    cargv[15],cargv[16],cargv[17],
			    cargv[18],cargv[19],cargv[20],
			    cargv[21],cargv[22],cargv[23],
			    cargv[24])));
  }
  else if (n<=48){
    return(makebnum((*func)(cargv[0],cargv[1],cargv[2],
			    cargv[3],cargv[4],cargv[5],
			    cargv[6],cargv[7],cargv[8],
			    cargv[9],cargv[10],cargv[11],
			    cargv[12],cargv[13],cargv[14],
			    cargv[15],cargv[16],cargv[17],
			    cargv[18],cargv[19],cargv[20],
			    cargv[21],cargv[22],cargv[23],
			    cargv[24],cargv[25],cargv[25],
			    cargv[26],cargv[27],cargv[28],
			    cargv[29],cargv[30],cargv[31],
			    cargv[32],cargv[33],cargv[34],
			    cargv[35],cargv[36],cargv[37],
			    cargv[38],cargv[39],cargv[40],
			    cargv[41],cargv[42],cargv[43],
			    cargv[44],cargv[45],cargv[46],
			    cargv[47])));
  }
  else {
    return(makebnum((*func)(cargv[0],cargv[1],cargv[2],
			    cargv[3],cargv[4],cargv[5],
			    cargv[6],cargv[7],cargv[8],
			    cargv[9],cargv[10],cargv[11],
			    cargv[12],cargv[13],cargv[14],
			    cargv[15],cargv[16],cargv[17],
			    cargv[18],cargv[19],cargv[20],
			    cargv[21],cargv[22],cargv[23],
			    cargv[24],cargv[25],cargv[25],
			    cargv[26],cargv[27],cargv[28],
			    cargv[29],cargv[30],cargv[31],
			    cargv[32],cargv[33],cargv[34],
			    cargv[35],cargv[36],cargv[37],
			    cargv[38],cargv[39],cargv[40],
			    cargv[41],cargv[42],cargv[43],
			    cargv[44],cargv[45],cargv[46],
			    cargv[47],cargv[48],cargv[49],
			    cargv[50],cargv[51],cargv[52],
			    cargv[53],cargv[54],cargv[55],
			    cargv[56],cargv[57],cargv[58],
			    cargv[59],cargv[60],cargv[61],
			    cargv[62],cargv[63],cargv[64],
			    cargv[65],cargv[66],cargv[67],
			    cargv[68],cargv[69],cargv[70],
			    cargv[71],cargv[72],cargv[73],
			    cargv[74],cargv[75],cargv[76],
			    cargv[77],cargv[78],cargv[79],
			    cargv[80],cargv[81],cargv[82],
			    cargv[83],cargv[84],cargv[85],
			    cargv[86],cargv[87],cargv[88],
			    cargv[89],cargv[90],cargv[91],
			    cargv[92],cargv[93],cargv[94],
			    cargv[95],cargv[96],cargv[97],
			    cargv[98],cargv[99])));
    
  }
}
pointer WINDOW_CREATE(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(xv_create,n,argv));
}

pointer call_xv_create(type,n,argv)
     caddr_t type;
     int n;
     register pointer argv[];
{
  register long cargv[100];
  n = largv2cargv(n,argv,cargv,1,100);
  cargv[n] = 0;
  if (n<25) {
    return(makebnum((int)
		    xv_create(cargv[0],type,cargv[1],cargv[2],
				      cargv[3], cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24])));
  }
  else if (n<48){
    return(makebnum((int)
		    xv_create(cargv[0],type,cargv[1],cargv[2],
				      cargv[3],cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24],cargv[25],cargv[25],
				      cargv[26],cargv[27],cargv[28],
				      cargv[29],cargv[30],cargv[31],
				      cargv[32],cargv[33],cargv[34],
				      cargv[35],cargv[36],cargv[37],
				      cargv[38],cargv[39],cargv[40],
				      cargv[41],cargv[42],cargv[43],
				      cargv[44],cargv[45],cargv[46])));

  }
  else {
    return(makebnum((int)
		    xv_create(cargv[0],type,cargv[1],cargv[2],
				      cargv[3],cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24],cargv[25],cargv[25],
				      cargv[26],cargv[27],cargv[28],
				      cargv[29],cargv[30],cargv[31],
				      cargv[32],cargv[33],cargv[34],
				      cargv[35],cargv[36],cargv[37],
				      cargv[38],cargv[39],cargv[40],
				      cargv[41],cargv[42],cargv[43],
				      cargv[44],cargv[45],cargv[46],
				      cargv[47],cargv[48],cargv[49],
				      cargv[50],cargv[51],cargv[52],
				      cargv[53],cargv[54],cargv[55],
				      cargv[56],cargv[57],cargv[58],
				      cargv[59],cargv[60],cargv[61],
				      cargv[62],cargv[63],cargv[64],
				      cargv[65],cargv[66],cargv[67],
				      cargv[68],cargv[69],cargv[70],
				      cargv[71],cargv[72],cargv[73],
				      cargv[74],cargv[75],cargv[76],
				      cargv[77],cargv[78],cargv[79],
				      cargv[80],cargv[81],cargv[82],
				      cargv[83],cargv[84],cargv[85],
				      cargv[86],cargv[87],cargv[88],
				      cargv[89],cargv[90],cargv[91],
				      cargv[92],cargv[93],cargv[94],
				      cargv[95],cargv[96],cargv[97],
				      cargv[98],cargv[99])));
  }
}

long saved_time=0;

pointer WINDOW_CREATE_FRAME(n,argv)
     int n;
     register pointer argv[];
{
  struct timezone tz;
  struct timeval tv;
  
  gettimeofday(&tv,&tz);
  saved_time = tv . tv_sec;
  return(call_xv_create(FRAME,n,argv));
}

pointer WINDOW_CREATE_PANEL(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(PANEL,n,argv));
}

pointer WINDOW_CREATE_CANVAS(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(CANVAS,n,argv));
}

pointer WINDOW_CREATE_TTY(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(TTY,n,argv));
}
pointer WINDOW_CREATE_TEXTSW(n,argv)
     int n;
     register pointer argv[];
{
  register long cargv[50];
  n= largv2cargv(n,argv,cargv,1,48);
  cargv[n] = 0;
  return(makebnum(xv_create(cargv[0],TEXTSW,cargv[1],cargv[2],
				cargv[3],cargv[4],cargv[5],
				cargv[6],cargv[7],cargv[8],
				cargv[9],cargv[10],cargv[11],
				cargv[12],cargv[13],cargv[14],
				cargv[15],cargv[16],cargv[17],
				cargv[18],cargv[19],cargv[20],
				cargv[21],cargv[22],cargv[23],
				cargv[24],cargv[25],cargv[25],
				cargv[26],cargv[27],cargv[28],
				cargv[29],cargv[30],cargv[31],
				cargv[32],cargv[33],cargv[34],
				cargv[35],cargv[36],cargv[37],
				cargv[38],cargv[39],cargv[40],
				cargv[41],cargv[42],cargv[43],
				cargv[44],cargv[45],cargv[46])));
}

pointer WINDOW_SET(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(xv_set,n,argv));
}
pointer WINDOW_GET(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(xv_get,n,argv));
}

pointer WINDOW_FIT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  window_fit(cknumtoint(argv[0]));
  return(T);
}

pointer WINDOW_MAIN_LOOP(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  (void) window_main_loop(cknumtoint(argv[0]));
  return(T);
}

pointer WINDOW_DESTROY(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  xv_destroy_check(cknumtoint(argv[0]));
  return(T);
}

pointer WINDOW_DONE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)window_done(cknumtoint(argv[0]))));
}

pointer WINDOW_BELL(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  (void) window_bell(cknumtoint(argv[0]));
  return(T);
}
pointer WINDOW_READ_EVENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)window_read_event(cknumtoint(argv[0]))));
}
pointer WINDOW_REFUSE_KBD_FOCUS(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  (void) window_refuse_kbd_focus(cknumtoint(argv[0]));
  return(T);
}
pointer WINDOW_FIT_HEIGHT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  window_fit_height(cknumtoint(argv[0]));
  return(T);
}
pointer WINDOW_FIT_WIDTH(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  window_fit_width(cknumtoint(argv[0]));
  return(T);
}
pointer WINDOW_RELEASE_EVENT_LOCK(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  (void) window_release_event_lock(cknumtoint(argv[0]));
  return(T);
}


pointer GET_CANVAS_PIXWIN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)canvas_pixwin(cknumtoint(argv[0]))));
}

pointer my_CANVAS_PAINT_WINDOW(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)canvas_paint_window(cknumtoint(argv[0]))));
}
pointer CANVAS_EVENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)canvas_event(cknumtoint(argv[0]),
				   cknumtoint(argv[1]))));
}
pointer CANVAS_WINDOW_EVENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)canvas_window_event(cknumtoint(argv[0]),
					  cknumtoint(argv[1]))));
}

pointer my_MENU_CREATE(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(menu_create,n,argv));
}
pointer MENU_CREATE_ITEM(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(menu_create_item,n,argv));
}
pointer MENU_SET(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(menu_set,n,argv));
}
pointer my_MENU_DESTROY(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  (void) menu_destroy(cknumtoint(argv[0]));
  return(T);
}

pointer MENU_DESTROY_WITH_PROC(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  (void) menu_destroy_with_proc(cknumtoint(argv[0]),
				cknumtoint(argv[1]));
  return(T);
}
pointer MENU_FIND(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(menu_find,n,argv));
}

pointer MENU_GET(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(menu_get,n,argv));
}

pointer MENU_SHOW(n,argv)
     int n;
     register pointer argv[];
{
/* XView CONVERSION - No longer blocks until menu taken down. Need to specify a MENU_DONE_PROC or even better, a MENU_ACTON_PROC for each menu item. See Sect 2.5 in API Guide */
  return(call_sunview(menu_show,n,argv));
}

pointer MENU_RETURN_ITEM(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)menu_return_item(cknumtoint(argv[0]),
					cknumtoint(argv[1]))));
}

pointer MENU_RETURN_VALUE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)menu_return_value(cknumtoint(argv[0]),
					 cknumtoint(argv[1]))));
}


pointer PANEL_SET(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(xv_set,n,argv));
}

pointer PANEL_FREE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)panel_free(cknumtoint(argv[0]))));
}
pointer PANEL_ACCEPT_KEY(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_accept_key(cknumtoint(argv[0]),
					 cknumtoint(argv[1]))));
}
pointer PANEL_ACCEPT_MENU(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_accept_menu(cknumtoint(argv[0]),
					 cknumtoint(argv[1]))));
}
pointer PANEL_ACCEPT_PREVIEW(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_accept_preview(cknumtoint(argv[0]),
					 cknumtoint(argv[1]))));
}
pointer PANEL_BEGIN_PREVIEW(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_begin_preview(cknumtoint(argv[0]),
					   cknumtoint(argv[1]))));
}
pointer PANEL_CANCEL_PREVIEW(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_cancel_preview(cknumtoint(argv[0]),
					    cknumtoint(argv[1]))));
}
pointer PANEL_ADVANCE_CARET(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)panel_advance_caret(cknumtoint(argv[0]))));
}
pointer PANEL_BACKUP_CARET(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)panel_backup_caret(cknumtoint(argv[0]))));
}

pointer PANEL_BUTTON_IMAGE(n,argv)
     int n;
     register pointer argv[];
{
/* XView CONVERSION - Still supported, but for OPEN LOOK buttons, should use PANEL_LABEL_STRING for PANEL_BUTTON items. Sect 3.2  */
  return(call_sunview(panel_button_image,n,argv));
}

pointer PANEL_CREATE_ITEM(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(xv_create,n,argv));
}
pointer PANEL_DEFAULT_HANDLE_EVENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  panel_default_handle_event(cknumtoint(argv[0]),
			     cknumtoint(argv[1]));
  return(T);
}
pointer PANEL_EVENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_event(cknumtoint(argv[0]),
				   cknumtoint(argv[1]))));
}
pointer PANEL_DESTROY_ITEM(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)xv_destroy(cknumtoint(argv[0]))));
}

pointer my_PANEL_GET(n,argv)
     int n; register pointer argv[];
{
/* XView CONVERSION - You may wish to change this to xv_get format. Look at panel.h and/or See Sect 2.5 */
  return(call_sunview(xv_get,n,argv));
}
pointer PANEL_GET_VALUE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
/* XView CONVERSION - You may wish to change this to xv_get format. Look at panel.h and/or See Sect 2.5 */
  return(makebnum((int)xv_get(cknumtoint(argv[0]), PANEL_VALUE)));
}
pointer PANEL_UPDATE_SCROLLING_SIZE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum((int)panel_update_scrolling_size(cknumtoint(argv[0]))));
}
pointer PANEL_UPDATE_PREVIEW(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_update_preview(cknumtoint(argv[0]),
					    cknumtoint(argv[1]))));
}
pointer PANEL_WINDOW_EVENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_window_event(cknumtoint(argv[0]),
					  cknumtoint(argv[1]))));
}
pointer PANEL_TEXT_NOTIFY(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_text_notify(cknumtoint(argv[0]),
					 cknumtoint(argv[1]))));
}
pointer PANEL_SET_VALUE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
/* XView CONVERSION - You may wish to change this to xv_set format. Look at panel.h and/or See Sect 2.5 */
  return(makebnum((int)panel_set_value(cknumtoint(argv[0]),
				       cknumtoint(argv[1]))));
}
pointer my_PANEL_PAINT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum((int)panel_paint(cknumtoint(argv[0]),
				   cknumtoint(argv[1]))));
}

pointer SCROLLBAR_CREATE(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(scrollbar_create,n,argv));
}

pointer PANEL_CREATE_MESSAGE(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(PANEL_MESSAGE,n,argv));
}
pointer PANEL_CREATE_BUTTON(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(PANEL_BUTTON,n,argv));
}
pointer PANEL_CREATE_CHOICE(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(PANEL_CHOICE,n,argv));
}
pointer PANEL_CREATE_CYCLE(n,argv)
     int n;
     register pointer argv[];
{
  register long cargv[100];
  n = largv2cargv(n,argv,cargv,1,100);
  cargv[n] = 0;
  if (n<25) {
    return(makebnum((int)
		    xv_create(cargv[0],PANEL_CYCLE,
				      cargv[1],cargv[2],
				      cargv[3], cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24])));
  }
  else if (n<48){
    return(makebnum((int)
		    xv_create(cargv[0],PANEL_CYCLE,
				      cargv[1],cargv[2],
				      cargv[3],cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24],cargv[25],cargv[25],
				      cargv[26],cargv[27],cargv[28],
				      cargv[29],cargv[30],cargv[31],
				      cargv[32],cargv[33],cargv[34],
				      cargv[35],cargv[36],cargv[37],
				      cargv[38],cargv[39],cargv[40],
				      cargv[41],cargv[42],cargv[43],
				      cargv[44],cargv[45],cargv[46])));

  }
  else {
    return(makebnum((int)
		    xv_create(cargv[0],PANEL_CYCLE,
				      cargv[1],cargv[2],
				      cargv[3],cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24],cargv[25],cargv[25],
				      cargv[26],cargv[27],cargv[28],
				      cargv[29],cargv[30],cargv[31],
				      cargv[32],cargv[33],cargv[34],
				      cargv[35],cargv[36],cargv[37],
				      cargv[38],cargv[39],cargv[40],
				      cargv[41],cargv[42],cargv[43],
				      cargv[44],cargv[45],cargv[46],
				      cargv[47],cargv[48],cargv[49],
				      cargv[50],cargv[51],cargv[52],
				      cargv[53],cargv[54],cargv[55],
				      cargv[56],cargv[57],cargv[58],
				      cargv[59],cargv[60],cargv[61],
				      cargv[62],cargv[63],cargv[64],
				      cargv[65],cargv[66],cargv[67],
				      cargv[68],cargv[69],cargv[70],
				      cargv[71],cargv[72],cargv[73],
				      cargv[74],cargv[75],cargv[76],
				      cargv[77],cargv[78],cargv[79],
				      cargv[80],cargv[81],cargv[82],
				      cargv[83],cargv[84],cargv[85],
				      cargv[86],cargv[87],cargv[88],
				      cargv[89],cargv[90],cargv[91],
				      cargv[92],cargv[93],cargv[94],
				      cargv[95],cargv[96],cargv[97],
				      cargv[98],cargv[99])));
  }
}
pointer PANEL_CREATE_TOGGLE(n,argv)
     int n;
     register pointer argv[];
{
  register long cargv[100];
  n = largv2cargv(n,argv,cargv,1,100);
  cargv[n] = 0;
  if (n<25) {
    return(makebnum((int)
		    xv_create(cargv[0],PANEL_TOGGLE,
				      cargv[1],cargv[2],
				      cargv[3], cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24])));
  }
  else if (n<48){
    return(makebnum((int)
		    xv_create(cargv[0],PANEL_TOGGLE,
				      cargv[1],cargv[2],
				      cargv[3],cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24],cargv[25],cargv[25],
				      cargv[26],cargv[27],cargv[28],
				      cargv[29],cargv[30],cargv[31],
				      cargv[32],cargv[33],cargv[34],
				      cargv[35],cargv[36],cargv[37],
				      cargv[38],cargv[39],cargv[40],
				      cargv[41],cargv[42],cargv[43],
				      cargv[44],cargv[45],cargv[46])));

  }
  else {
    return(makebnum((int)
		    xv_create(cargv[0],PANEL_TOGGLE,
				      cargv[1],cargv[2],
				      cargv[3],cargv[4],cargv[5],
				      cargv[6],cargv[7],cargv[8],
				      cargv[9],cargv[10],cargv[11],
				      cargv[12],cargv[13],cargv[14],
				      cargv[15],cargv[16],cargv[17],
				      cargv[18],cargv[19],cargv[20],
				      cargv[21],cargv[22],cargv[23],
				      cargv[24],cargv[25],cargv[25],
				      cargv[26],cargv[27],cargv[28],
				      cargv[29],cargv[30],cargv[31],
				      cargv[32],cargv[33],cargv[34],
				      cargv[35],cargv[36],cargv[37],
				      cargv[38],cargv[39],cargv[40],
				      cargv[41],cargv[42],cargv[43],
				      cargv[44],cargv[45],cargv[46],
				      cargv[47],cargv[48],cargv[49],
				      cargv[50],cargv[51],cargv[52],
				      cargv[53],cargv[54],cargv[55],
				      cargv[56],cargv[57],cargv[58],
				      cargv[59],cargv[60],cargv[61],
				      cargv[62],cargv[63],cargv[64],
				      cargv[65],cargv[66],cargv[67],
				      cargv[68],cargv[69],cargv[70],
				      cargv[71],cargv[72],cargv[73],
				      cargv[74],cargv[75],cargv[76],
				      cargv[77],cargv[78],cargv[79],
				      cargv[80],cargv[81],cargv[82],
				      cargv[83],cargv[84],cargv[85],
				      cargv[86],cargv[87],cargv[88],
				      cargv[89],cargv[90],cargv[91],
				      cargv[92],cargv[93],cargv[94],
				      cargv[95],cargv[96],cargv[97],
				      cargv[98],cargv[99])));
  }
}
pointer PANEL_CREATE_TEXT(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(PANEL_TEXT,n,argv));
}
pointer PANEL_CREATE_SLIDER(n,argv)
     int n;
     register pointer argv[];
{
  return(call_xv_create(PANEL_SLIDER,n,argv));
}

pointer ICON_CREATE(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(icon_create,n,argv));
}
pointer ICON_SET(n,argv)
     int n;
     register pointer argv[];
{
  return(call_sunview(icon_set,n,argv));
}
pointer ICON_GET(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(icon_get,n,argv));
}
pointer ICON_DESTROY(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(icon_destroy(cknumtoint(argv[0]))));
}

pointer PW_BATCH(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  pw_batch(cknumtoint(argv[0]), cknumtoint(argv[1]));
  return(T);
}

my_pw_batch_off(pw)
     Pixwin *pw;
{
  pw_batch_off(pw);
}
my_pw_batch_on(pw)
     Pixwin *pw;
{
  pw_batch_on(pw);
}
my_pw_get(pw,x,y)
     Pixwin *pw; int x,y;
{
  return(pw_get(pw,x,y));
}
my_pw_get_region_rect(pw,r)
     Pixwin *pw; Rect *r;
{
  pw_get_region_rect(pw,r);
}

/* XView CONVERSION - Need to set WIN_DYNAMIC_VISUAL. See Sect 4.3 */
my_pw_putcolormap(pw,index,count,red,green,blue)
     Pixwin *pw; int index,count,red,green,blue;
{
  return(pw_putcolormap(pw,index,count,red,green,blue));
}
my_pw_writebackground(pw,dx,dy,dw,dh,op)
     Pixwin *pw;
     int dx,dy,dw,dh,op;
{ return(pw_writebackground(pw,dx,dy,dw,dh,op)); }

pointer PW_BATCH_OFF(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(my_pw_batch_off,n,argv));
}
pointer PW_BATCH_ON(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(my_pw_batch_on,n,argv));
}
pointer PW_BATCHROP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,6,6);
  pw_char(cargv[0], cargv[1], cargv[2], cargv[3],
	  cargv[4],cargv[5]);
  return(T);
}
pointer PW_CHAR(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,6,6);
  pw_char(cargv[0], cargv[1], cargv[2], cargv[3],
	  cargv[4],cargv[5]);
  return(T);
}
pointer PW_COPY(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  pw_copy((Pixwin *)cargv[0], cargv[1], cargv[2], cargv[3],
	  cargv[4],cargv[5],(Pixwin *)cargv[6],cargv[7],cargv[8]);
  return(T);
}
pointer PW_GET(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(my_pw_get,n,argv));
}
pointer MY_PW_LINE(n,argv)
     int n; register pointer argv[];
{
  ckarg(8);
  pw_line(cknumtoint(argv[0]), cknumtoint(argv[1]), cknumtoint(argv[2]),
	  cknumtoint(argv[3]), cknumtoint(argv[4]),
	  cknumtoint(argv[5]), cknumtoint(argv[6]), cknumtoint(argv[7]));
  return(T);
}

pointer PW_LOCK(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  pw_lock((Pixwin *)cknumtoint(argv[0]),
	  (Rect *)cknumtoint(argv[1]));
  return(T);
}
pointer PW_PFSYSCLOSE(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  return(makebnum(pw_pfsysclose()));
}

pointer PW_POLYGON_2(n,argv)
     int n; register pointer argv[];
{
  int plist[2*1000],size,npts[10],nsize;
  ckarg(10);
  nsize=trans_argv_iargv(1,&argv[4],npts);
  size=trans_argv_iargv(1,&argv[5],plist);
  pw_polygon_2(cknumtoint(argv[0]),cknumtoint(argv[1]), cknumtoint(argv[2]),
	       cknumtoint(argv[3]),npts,plist,
	       cknumtoint(argv[6]),cknumtoint(argv[7]),
	       cknumtoint(argv[8]),cknumtoint(argv[9]));
  return(T);
}
pointer MY_PW_POLYLINE(n,argv)
     int n; register pointer argv[];
{
  int plist[2*1000],size;
  ckarg(9);
  size=trans_argv_iargv(1,&argv[4],plist);
  pw_polyline(cknumtoint(argv[0]),
	      cknumtoint(argv[1]), cknumtoint(argv[2]),
	      cknumtoint(argv[3]),plist,
	      cknumtoint(argv[5]),cknumtoint(argv[6]),
	      cknumtoint(argv[7]),cknumtoint(argv[8]));
  return(T);
}

pointer MY_PW_POLYPOINT(n,argv)
     int n; register pointer argv[];
{
  int plist[2*1000],size;
  ckarg(6);
  size=trans_argv_iargv(1,&argv[4],plist);
  pw_polypoint(cknumtoint(argv[0]),
	       cknumtoint(argv[1]), cknumtoint(argv[2]),
	       cknumtoint(argv[3]),plist,
	       cknumtoint(argv[5]));
  return(T);
}
pointer PW_PUT(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,4,4);
  pw_put((Pixwin *)cargv[0],cargv[1],cargv[2],cargv[3]);
  return(T);
}
pointer PW_READ(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  pw_read((Pixrect *)cargv[0],cargv[1],cargv[2],cargv[3],
	  cargv[4],cargv[5],(Pixwin *)cargv[6],cargv[7],cargv[8]);
  return(T);
}

pointer MY_PW_REPLROP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  pw_replrop(cargv[0], cargv[1], cargv[2], cargv[3],
	     cargv[4],cargv[5],cargv[6],cargv[7],
	     cargv[8]);
  return(T);
}
pointer MY_PW_ROP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  pw_rop(cargv[0], cargv[1], cargv[2], cargv[3],
	 cargv[4],cargv[5],cargv[6],cargv[7],
	 cargv[8]);
  return(T);
}
pointer my_PW_SHOW(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  pw_show(cknumtoint(argv[0]));
  return(T);
}
pointer MY_PW_STENCIL(n,argv)
     int n; register pointer argv[];
{
  register long cargv[20];
  largv2cargv(n,argv,cargv,12,12);
  pw_polyline(cargv[0], cargv[1], cargv[2], cargv[3],
	      cargv[4],cargv[5],cargv[6],cargv[7],
	      cargv[8],cargv[9],cargv[10],cargv[11]);
  return(T);
}
pointer MY_PW_TEXT(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,6,6);
  pw_text(cargv[0], cargv[1], cargv[2], cargv[3],
	  cargv[4],cargv[5]);
  return(T);
}
pointer PW_TTEXT(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,6,6);
  pw_ttext(cargv[0], cargv[1], cargv[2], cargv[3],
	   cargv[4],cargv[5]);
  return(T);
}
pointer PW_UNLOCK(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  pw_unlock((Pixwin *)cknumtoint(argv[0]));
  return(T);
}
pointer MY_PW_VECTOR(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,7,7);
  pw_vector(cargv[0],cargv[1],cargv[2],cargv[3],
	    cargv[4],cargv[5],cargv[6]);
  return(T);
}
pointer PW_WRITE(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  pw_write(cargv[0],cargv[1],cargv[2],cargv[3],
	   cargv[4],cargv[5],cargv[6],cargv[7],
	   cargv[8]);
  return(T);
}
pointer PW_WRITEBACKGROUND(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,6,6);
  pw_writebackground(cargv[0], cargv[1], cargv[2], cargv[3],
		     cargv[4],cargv[5]);
  return(T);
}
pointer PW_BLACKONWHITE(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,3,3);
  pw_blackonwhite(cargv[0], cargv[1], cargv[2]);
  return(T);
}
pointer PW_CYCLECOLORMAP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,4,4);
  pw_cyclecolormap(cargv[0], cargv[1], cargv[2],cargv[3]);
  return(T);
}
pointer PW_GETATTRIBUTES(n,argv)
     int n; register pointer argv[];
{
  int planes;
  ckarg(1);
  pw_getattributes(cknumtoint(argv[0]),&planes);
  return(makeint(planes));
}
pointer PW_PUTATTRIBUTES(n,argv)
     int n; register pointer argv[];
{
  static int planes;
  ckarg(2);
  planes= cknumtoint(argv[1]);
  pw_putattributes(cknumtoint(argv[0]),&planes);
  return(T);
}

pointer PW_GETCMSNAME(n,argv)
     int n; register pointer argv[];
{
  int s=CMS_NAMESIZE,i;
  char buf[CMS_NAMESIZE];
  ckarg(1);
  for (i=0; i<CMS_NAMESIZE; i++) buf[i]=0;
  pw_getcmsname(cknumtoint(argv[0]), buf);
  return(makestring(buf,strlen(buf)));
}

pointer PW_GETCOLORMAP(n,argv)
     int n; register pointer argv[];
{
  struct xv_cmsdata *cms;
  pointer v;
  unsigned char red[256],green[256],blue[256];
  Pixwin *pw;
  ckarg(1);
  pw = (Pixwin *)cknumtoint(argv[0]);
  cms = xv_get(pw,WIN_CMS_DATA);
  pw_getcolormap(pw,0,cms -> size,red,green,blue);
  vpush(makestring(red,cms -> size));
  vpush(makestring(green,cms -> size));
  vpush(makestring(blue,cms -> size));
  v = cons(makeint(cms -> size),NIL);
  v = cons(vpop(),v);
  v = cons(vpop(),v);
  return(cons(vpop(),v));
}

pointer PW_PUTCOLORMAP(n,argv)
     int n; register pointer argv[];
{
/* XView CONVERSION - Need to set WIN_DYNAMIC_VISUAL. See Sect 4.3 */
  return(call_sunview(my_pw_putcolormap,n,argv));
}
pointer PW_REVERSEVIDEO(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,3,3);
  pw_reversevideo(cargv[0], cargv[1],cargv[3]);
  return(T);
}
pointer PW_SETCMSNAME(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,2,2);
  pw_setcmsname(cargv[0], cargv[1]);
  return(T);
}
pointer PW_WHITEONBLACK(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,3,3);
  pw_whiteonblack(cargv[0], cargv[1],cargv[2]);
  return(T);
}

pointer TEXTSW_ADD_MARK(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(textsw_add_mark,n,argv));
}
pointer TEXTSW_APPEND_FILE_NAME(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(textsw_append_file_name,n,argv));
}
pointer TEXTSW_DELETE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(textsw_delete,n,argv));
}
pointer TEXTSW_EDIT(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  return(call_sunview(textsw_edit,n,argv));
}
pointer TEXTSW_ERASE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(textsw_erase,n,argv));
}
pointer TEXTSW_FILE_LINES_VISIBLE(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,3,3);
  textsw_file_lines_visible(cargv[0], cargv[1], cargv[2]);
  return(T);
}
pointer TEXTSW_FIND_BYTES(n,argv)
     int n; register pointer argv[];
{
  ckarg(6);
  return(call_sunview(textsw_find_bytes,n,argv));
}
pointer TEXTSW_MATCH_BYTES(n,argv)
     int n; register pointer argv[];
{
  ckarg(8);
  return(call_sunview(textsw_match_bytes,n,argv));
}
pointer TEXTSW_FIND_MARK(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(textsw_find_mark,n,argv));
}
pointer my_TEXTSW_FIRST(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(call_sunview(textsw_first,n,argv));
}
pointer TEXTSW_INDEX_FOR_FILE_LINE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(textsw_index_for_file_line,n,argv));
}
pointer TEXTSW_INSERT(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(textsw_insert,n,argv));
}
pointer TEXTSW_NEXT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(call_sunview(textsw_next,n,argv));
}
pointer TEXTSW_NORMALIZE_VIEW(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,2,2);
  textsw_normalize_view(cargv[0], cargv[1]);
  return(T);
}
pointer TEXTSW_POSSIBLY_NORMALIZE(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,2,2);
  textsw_possibly_normalize(cargv[0], cargv[1]);
  return(T);
}
pointer TEXTSW_REMOVE_MARK(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,3,3);
  textsw_remove_mark(cargv[0], cargv[1], cargv[2]);
  return(T);
}
pointer TEXTSW_REPLACE_BYTES(n,argv)
     int n; register pointer argv[];
{
  ckarg(5);
  return(call_sunview(textsw_replace_bytes,n,argv));
}
pointer TEXTSW_RESET(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,3,3);
  textsw_reset(cargv[0], cargv[1], cargv[2]);
  return(T);
}
pointer TEXTSW_SAVE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(textsw_save,n,argv));
}
pointer TEXTSW_SCREEN_LINE_COUNT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(call_sunview(textsw_screen_line_count,n,argv));
}
/* XView CONVERSION - Possibly Defunct. See Sect 2.3 SCROLL_ 3.2 */
pointer TEXTSW_SCROLL_LINES(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(textsw_scroll_lines,n,argv));
}
pointer TEXTSW_STORE_FILE(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(textsw_store_file,n,argv));
}
pointer TEXTSW_SET_SELECTION(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,4,4);
  textsw_set_selection(cargv[0], cargv[1], cargv[2]);
  return(T);
}

pointer TTYSW_INPUT(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(ttysw_input,n,argv));
}
pointer TTYSW_OUTPUT(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(ttysw_output,n,argv));
}

pointer XV_COL(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(xv_col(cknumtoint(argv[0]),cknumtoint(argv[1]))));
}

pointer XV_ROW(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(xv_row(cknumtoint(argv[0]),cknumtoint(argv[1]))));
}

pointer NOTIFY_DEFAULT_WAIT3(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  return(call_sunview(notify_default_wait3,n,argv));
}
pointer L_NOTIFY_DISPATCH(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  return(makebnum(notify_dispatch()));
}
pointer NOTIFY_DO_DISPATCH(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  return(makebnum(notify_do_dispatch()));
}
pointer NOTIFY_INTERPOSE_DESTROY_FUNC(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(notify_interpose_destroy_func
				    ,n,argv));
}
pointer NOTIFY_INTERPOSE_EVENT_FUNC(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(notify_interpose_event_func
				    ,n,argv));
}
pointer NOTIFY_ITIMER_VALUE(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(notify_itimer_value,n,argv));
}
pointer NOTIFY_NEXT_DESTROY_FUNC(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(notify_next_destroy_func,n,argv));
}
pointer NOTIFY_NEXT_EVENT_FUNC(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(notify_next_event_func,n,argv));
}
pointer NOTIFY_SET_DESTROY_FUNC(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(notify_set_destroy_func,n,argv));
}
pointer NOTIFY_SET_EXCEPTION_FUNC(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(notify_set_exception_func
				    ,n,argv));
}
pointer NOTIFY_SET_INPUT_FUNC(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  return(call_sunview(notify_set_input_func,n,argv));
}
pointer NOTIFY_SET_ITIMER_FUNC(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(notify_set_itimer_func,n,argv));
}
pointer NOTIFY_SET_SIGNAL_FUNC(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(notify_set_signal_func,n,argv));
}
pointer NOTIFY_SET_OUTPUT_FUNC(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(notify_set_output_func,n,argv));
}
pointer NOTIFY_SET_WAIT3_FUNC(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(notify_set_wait3_func,n,argv));
}
pointer NOTIFY_START(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  return(makebnum(notify_start()));
}
pointer NOTIFY_STOP(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  return(makebnum(notify_stop()));
}
pointer NOTIFY_NO_DISPATCH(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  return(makebnum(notify_no_dispatch()));
}
pointer NOTIFY_PERROR(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  notify_perror(cknumtoint(argv[0]));
  return(T);
}
pointer NOTIFY_VETO_DESTROY(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(notify_veto_destroy(cknumtoint(argv[0]))));
}

/* pixrect */
extern xv_pf_close();
extern xv_pf_text();
extern xv_pf_ttext();
extern xv_pf_textbatch();
extern xv_pf_textwidth();
extern xv_pf_open();
extern xv_pf_open_private();

extern pr_traprop();
extern pr_dump_header();
extern pr_dump_image();
extern pr_dump();
extern pr_polygon_2();
extern pr_reversevideo();

/*  Next 4 lines for old version 3.3 of SUNVIEW */
/*
extern pr_dump_init();
extern pr_load_image();
extern pr_load();
extern pr_load_std_image();
*/

extern pr_load_colormap();
extern pr_load_header();
extern pr_replrop();
extern pr_blackonwhite();
extern pr_whiteonblack();

pointer MPR_LINEBYTES(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makeint(mpr_linebytes(cknumtoint(argv[0]),
			       cknumtoint(argv[1]))));
}
pointer MEM_CREATE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(mem_create,n,argv));
}
pointer MEM_POINT(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  return(call_sunview(mem_point,n,argv));
}
pointer PF_TEXTBATCH(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  /* XView CONVERSION - Use xv_pf_text instead. Remember to extern it.  */
  /* XView CONVERSION - Use xv_pf_textbatch instead.  Remember to extern it. */
  return(call_sunview(xv_pf_textbatch,n,argv));
}
pointer PF_TEXTWIDTH(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  /* XView CONVERSION - Use xv_pf_text instead. Remember to extern it.  */
  /* XView CONVERSION - Use xv_pf_textwidth instead.  Remember to extern it. */
  return(call_sunview(xv_pf_textwidth,n,argv));
}
pointer PF_OPEN(n,argv)
     int n;
     register pointer argv[];
{
  ckarg(1);
  return(makebnum(xv_pf_open(ckstrchr(argv[0]))));
}
pointer PF_OPEN_PRIVATE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  /* XView CONVERSION - Use xv_pf_open_private instead.  Remember to extern it. */
  return(call_sunview(xv_pf_open_private,n,argv));
}
pointer PF_DEFAULT(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  /* XView CONVERSION - If function pf_default use xv_pf_default. If struct value ignore. Remember to extern it. */
  return(makebnum(xv_pf_default()));
}

pointer MY_PF_CLOSE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(call_sunview(xv_pf_close,n,argv));
}
pointer MY_PF_TEXT(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  return(call_sunview(xv_pf_text,n,argv));
}
pointer MY_PF_TTEXT(n,argv)
     int n; register pointer argv[];
{
  ckarg(4);
  return(call_sunview(xv_pf_ttext,n,argv));
}

pointer PR_OPEN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(call_sunview(pr_open,n,argv));
}
pointer PR_VECTOR(n,argv)
     int n; register pointer argv[];
{
  register int cargv[12];
  largv2cargv(n,argv,cargv,7,7);
  pr_vector(((struct pixrect *)cargv[0]),
	    cargv[1],cargv[2],cargv[3],cargv[4],
	    cargv[5],cargv[6]);
  return(T);
}
pointer PR_POLYGON_2(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,10,10);
  pr_polygon_2(cargv[0],cargv[1],cargv[2],cargv[3],
	       cargv[4],cargv[5],cargv[6],cargv[7],
	       cargv[8],cargv[9]);
  return(T);
}
pointer PR_REVERSEVIDEO(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_reversevideo,n,argv));
}
pointer PR_DUMP_INIT(n,argv)
     int n; register pointer argv[];
{
  ckarg(5);
  return(call_sunview(pr_dump_init,n,argv));
}
pointer PR_LOAD_COLORMAP(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_load_colormap,n,argv));
}
pointer PR_LOAD_HEADER(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(pr_load_header,n,argv));
}
pointer PR_LOAD_IMAGE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_load_image,n,argv));
}
pointer PR_LOAD(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(pr_load,n,argv));
}
pointer PR_LOAD_STD_IMAGE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_load_std_image,n,argv));
}
pointer PR_REPLROP(n,argv)
     int n; register pointer argv[];
{
  ckarg(9);
  return(call_sunview(pr_replrop,n,argv));
}
pointer PR_BLACKONWHITE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_blackonwhite,n,argv));
}
pointer PR_WHITEONBLACK(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_whiteonblack,n,argv));
}
pointer PR_TRAPROP(n,argv)
     int n; register pointer argv[];
{
  ckarg(8);
  return(call_sunview(pr_traprop,n,argv));
}
pointer PR_DUMP_HEADER(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_dump_header,n,argv));
}
pointer PR_DUMP_IMAGE(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(call_sunview(pr_dump_image,n,argv));
}
pointer PR_DUMP(n,argv)
     int n; register pointer argv[];
{
  ckarg(5);
  return(call_sunview(pr_dump,n,argv));
}
pointer PR_PUT(n,argv)
     int n; register pointer argv[];
{
  register long cargv[4];
  largv2cargv(n,argv,cargv,4,4);
  pr_put((Pixrect *)cargv[0],cargv[1],cargv[2],cargv[3]);
  return(T);
}
pointer PR_PUTATTRIBUTES(n,argv)
     int n; register pointer argv[];
{
  register long cargv[2];
  largv2cargv(n,argv,cargv,2,2);
  pr_putattributes(cargv[0],cargv[1]);
  return(T);
}

pointer PR_REGION(n,argv)
     int n; register pointer argv[];
{
  ckarg(5);
  pr_region(cknumtoint(argv[0]),
	    cknumtoint(argv[1]),
	    cknumtoint(argv[2]),
	    cknumtoint(argv[3]),
	    cknumtoint(argv[4]));
  return(T);
}
pointer PR_STENCIL(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,12,12);
  pr_stencil(cargv[0],cargv[1],cargv[2],cargv[3],
	     cargv[4],cargv[5],cargv[6],cargv[7],
	     cargv[8],cargv[9],cargv[10],cargv[11]);
  return(T);
}
pointer PR_GET(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(makebnum(pr_get(cknumtoint(argv[0]),
			 cknumtoint(argv[1]),cknumtoint(argv[2]))));
}
pointer PR_ROP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  pr_rop(cargv[0],cargv[1],cargv[2],
	 cargv[3],cargv[4],cargv[5],
	 cargv[6],cargv[7],cargv[8]);
  return(T);
}
pointer XV_ROP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[12];
  largv2cargv(n,argv,cargv,9,9);
  xv_rop(cargv[0],cargv[1],cargv[2],
	 cargv[3],cargv[4],cargv[5],
	 cargv[6],cargv[7],cargv[8]);
  return(T);
}

pointer PR_DESTROY(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  pr_destroy(cknumtoint(argv[0]));
  return(T);
}
pointer PR_PUTCOLORMAP(n,argv)
     int n; register pointer argv[];
{
  register long cargv[6];
  largv2cargv(n,argv,cargv,6,6);
  pr_putcolormap(cargv[0],cargv[1],cargv[2],cargv[3],cargv[4],
		  cargv[5]);
  return(T);
}

/* seln */

pointer SELN_ASK(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(seln_ask,n,argv));
}
pointer SELN_QUERY(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(seln_query,n,argv));
}
pointer READER(n,argv)
     int n; register pointer argv[];
{
  return(call_sunview(reader,n,argv));
}
pointer SELN_ACQUIRE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(seln_acquire,n,argv));
}
pointer SELN_DESTROY(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  seln_destroy(cknumtoint(argv[0]));
  return(T);
}
pointer SELN_DONE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(seln_done(cknumtoint(argv[0]),cknumtoint(argv[1]))));
}

pointer SELN_FIGURE_RESPONSE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(seln_figure_response(cknumtoint(argv[0]),
				       cknumtoint(argv[1]))));
}
pointer SELN_HOLD_FILE(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(seln_hold_file(cknumtoint(argv[0]),
				 cknumtoint(argv[1]))));
}
pointer SELN_HOLDER_SAME_CLIENT(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(seln_holder_same_client(cknumtoint(argv[0]),
					  cknumtoint(argv[1]))));
}
pointer SELN_HOLDER_SAME_PROCESS(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(seln_holder_same_process(cknumtoint(argv[0]))));
}
pointer SELN_INFORM(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(makebnum(seln_inform(cknumtoint(argv[0]),
			      cknumtoint(argv[1]),
			      cknumtoint(argv[2]))));
}
pointer SELN_INIT_REQUEST(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(call_sunview(seln_init_request,n,argv));
}
pointer SELN_INQUIRE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(seln_inquire(cknumtoint(argv[0]))));
}
pointer my_SELN_REQUEST(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(seln_request(cknumtoint(argv[0]),cknumtoint(argv[1]))));
}
pointer SELN_SAME_HOLDER(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(seln_same_holder(cknumtoint(argv[0]),
				   cknumtoint(argv[1]))));
}
pointer SELN_SECONDARY_EXISTS(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(seln_secondary_exists(cknumtoint(argv[0]))));
}
pointer SELN_SECONDARY_MADE(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(seln_secondary_made(cknumtoint(argv[0]))));
}
pointer SELN_USE_TIMEOUT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  seln_use_timeout(cknumtoint(argv[0]));
  return(T);
}
pointer SELN_YIELD_ALL(n,argv)
     int n; register pointer argv[];
{
  ckarg(0);
  (void) seln_yield_all();
  return(T);
}

pointer GET_SELECTION(n,argv)
     int n;
     register pointer argv[];
{
  Seln_holder holder;
  Seln_request *buffer;
  int len;
  ckarg(0);
  holder = seln_inquire(SELN_PRIMARY);
  buffer = seln_ask(&holder, SELN_REQ_CONTENTS_ASCII, 0, 0);
  len = strlen(buffer->data + sizeof(Seln_attribute));
  return(makestring(buffer->data + sizeof(Seln_attribute),
		    len));
}

pointer ADR_TO_STRING(n,argv)
     int n;
     register pointer argv[];
{
  char *ptr;
  ckarg(1);
  ptr = (char *) cknumtoint(argv[0]);
  if ((int)ptr<10000) error("ADR_TO_STRING: invalid string pointer");
  return(makestring(ptr,strlen(ptr)));
}

/*
pointer PW_GET_X_OFFSET(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makeint(pw_get_x_offset(cknumtoint(argv[0]))));
}
pointer PW_GET_Y_OFFSET(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makeint(pw_get_y_offset(cknumtoint(argv[0]))));
}
*/

pointer EXPAND_NAME(n,argv)
     int n; register pointer argv[];
{
  static struct namelist *name_list;
  register pointer temp;
  register int i;
  ckarg(1);
  name_list = xv_expand_name(ckstrchr(argv[0]));
  temp = makevector(C_VECTOR,name_list->count);
  vpush(temp);
  for (i=0; i< name_list->count; i++) {
    temp->c.vec.v[i] =
      makestring(name_list->names[i],
		 strlen(name_list->names[i]));
  }
  free_namelist(name_list);
  return(vpop());
}


pointer ICON_LOAD(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(makebnum(icon_load(cknumtoint(argv[0]),
			    cknumtoint(argv[1]),
			    cknumtoint(argv[2]))));
}
pointer ICON_INIT_FROM_PR(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(icon_init_from_pr(cknumtoint(argv[0]),
				    cknumtoint(argv[1]))));
}
pointer ICON_LOAD_MPR(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(icon_load_mpr(cknumtoint(argv[0]),
				cknumtoint(argv[1]))));
}
pointer ICON_OPEN_HEADER(n,argv)
     int n; register pointer argv[];
{
  ckarg(3);
  return(makebnum(icon_open_header(cknumtoint(argv[0]),
				   cknumtoint(argv[1]),
				   cknumtoint(argv[2]))));
}

/* event */

pointer EVENT_ID(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(event_id(cknumtoint(argv[0]))));
}
pointer EVENT_IS_UP(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_up(cknumtoint(argv[0]))));
}
pointer EVENT_IS_DOWN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_down(cknumtoint(argv[0]))));
}
pointer EVENT_X(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(event_x(cknumtoint(argv[0]))));
}
pointer EVENT_Y(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(event_y(cknumtoint(argv[0]))));
}
pointer EVENT_SHIFTMASK(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(event_shiftmask(cknumtoint(argv[0]))));
}

pointer EVENT_TIME(n,argv)
     int n; register pointer argv[];
{
  long e;
  ckarg(1);
  e = cknumtoint(argv[0]);
  return(makeflt(
		 (float)((event_time(e) . tv_sec) - (long)saved_time)
		 + ((float)(event_time(e) . tv_usec) / 1000000.0)));
}
pointer EVENT_SET_TIME(n,argv)
     int n; register pointer argv[];
{
  struct timeval ti;
  float v;
  ckarg(2);
  v = cknumtoint(argv[1]);
  ti . tv_sec = (int) v;
  v -= ti . tv_sec;
  ti . tv_usec = (int)(1000000 * v);
  event_set_time(cknumtoint(argv[0]),ti);
  return(T);
}
pointer EVENT_SHIFT_IS_DOWN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_shift_is_down(cknumtoint(argv[0]))));
}
pointer EVENT_CTRL_IS_DOWN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_ctrl_is_down(cknumtoint(argv[0]))));
}
pointer EVENT_META_IS_DOWN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_meta_is_down(cknumtoint(argv[0]))));
}
pointer EVENT_IS_BUTTON(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_button(cknumtoint(argv[0]))));
}
pointer EVENT_IS_ASCII(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_ascii(cknumtoint(argv[0]))));
}
pointer EVENT_IS_META(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_meta(cknumtoint(argv[0]))));
}
pointer EVENT_IS_KEY_LEFT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
 return(makebool(event_is_key_left(cknumtoint(argv[0]))));
}
pointer EVENT_IS_KEY_RIGHT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_key_right(cknumtoint(argv[0]))));
}
pointer EVENT_IS_KEY_TOP(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebool(event_is_key_top(cknumtoint(argv[0]))));
}

pointer EVENT_SET_ID(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  event_set_id(cknumtoint(argv[0]),cknumtoint(argv[1]));
  return(T);
}
pointer EVENT_SET_SHIFTMASK(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(event_set_shiftmask(cknumtoint(argv[0]),
				      cknumtoint(argv[1]))));
}
pointer EVENT_SET_X(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(event_set_x(cknumtoint(argv[0]),
			      cknumtoint(argv[1]))));
}
pointer EVENT_SET_Y(n,argv)
     int n; register pointer argv[];
{
  ckarg(2);
  return(makebnum(event_set_y(cknumtoint(argv[0]),
			      cknumtoint(argv[1]))));
}
pointer EVENT_SET_UP(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(event_set_up(cknumtoint(argv[0]))));
}
pointer EVENT_SET_DOWN(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(event_set_down(cknumtoint(argv[0]))));
}

pointer L_KEY_LEFT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(KEY_LEFT((int)cknumtoint(argv[0]))));
}
pointer L_KEY_RIGHT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(KEY_RIGHT((int)cknumtoint(argv[0]))));
}
pointer L_KEY_TOP(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(KEY_TOP((int)cknumtoint(argv[0]))));
}
pointer L_BUT(n,argv)
     int n; register pointer argv[];
{
  ckarg(1);
  return(makebnum(BUT((int)cknumtoint(argv[0]))));
}


pointer PEEK_BYTE(n,argv)
     int n; register pointer argv[];
{
  char *cp;
  int offset;
  char c;
  ckarg(2);
  cp = cknumtoint(argv[0]);	/* addr pointer */
  offset = cknumtoint(argv[1]);
  c = *(char *)(cp + offset);
  return(makeint(c));
}

pointer PEEK_SHORT(n,argv)
     int n;
     register pointer argv[];
{
  char *cp;
  int offset;
  short v;
  ckarg(2);
  cp = cknumtoint(argv[0]);	/* addr pointer */
  offset = cknumtoint(argv[1]);
  v = *(short *)(cp + offset);
  return(makeint(v));
}
pointer PEEK_LONG(n,argv)
     int n;
     register pointer argv[];
{
  char *cp;
  int offset;
  long v;
  ckarg(2);
  cp = cknumtoint(argv[0]);	/* addr pointer */
  offset = cknumtoint(argv[1]);
  v = *(long *)(cp + offset);
  return(makeint(v));
}
pointer PEEK_DOUBLE(n,argv)
     int n;
     register pointer argv[];
{
  char *cp;
  int offset;
  double v;
  ckarg(2);
  cp = cknumtoint(argv[0]);	/* addr pointer */
  offset = cknumtoint(argv[1]);
  v = *(double *)(cp + offset);
  return(makeflt(v));
}

init_xview(mod)
     pointer mod;
{
  defun("XV_COL",mod,XV_COL);
  defun("XV_ROW",mod,XV_ROW);

  defun("WINDOW_CREATE",mod,WINDOW_CREATE);
  defun("WINDOW_CREATE_FRAME",mod,WINDOW_CREATE_FRAME);
  defun("WINDOW_CREATE_PANEL",mod,WINDOW_CREATE_PANEL);
  defun("WINDOW_CREATE_CANVAS",mod,WINDOW_CREATE_CANVAS);
  defun("WINDOW_CREATE_TTY",mod,WINDOW_CREATE_TTY);
  defun("WINDOW_CREATE_TEXTSW",mod,WINDOW_CREATE_TEXTSW);
  defun("WINDOW_SET",mod,WINDOW_SET);
  defun("WINDOW_GET",mod,WINDOW_GET);
  defun("WINDOW_FIT",mod,WINDOW_FIT);
  defun("WINDOW_MAIN_LOOP",mod,WINDOW_MAIN_LOOP);
  defun("WINDOW_DONE",mod,WINDOW_DONE);
  defun("WINDOW_DESTROY",mod,WINDOW_DESTROY);
  defun("WINDOW_BELL",mod,WINDOW_BELL);
  defun("WINDOW_READ_EVENT",mod,WINDOW_READ_EVENT);
  defun("WINDOW_REFUSE_KBD_FOCUS",mod,WINDOW_REFUSE_KBD_FOCUS);
  defun("WINDOW_FIT_HEIGHT",mod,WINDOW_FIT_HEIGHT);
  defun("WINDOW_FIT_WIDTH",mod,WINDOW_FIT_WIDTH);
  defun("WINDOW_RELEASE_EVENT_LOCK",mod,WINDOW_RELEASE_EVENT_LOCK);

  defun("CANVAS_PIXWIN",mod,GET_CANVAS_PIXWIN);
  defun("CANVAS_PAINT_WINDOW",mod,my_CANVAS_PAINT_WINDOW);

  defun("CANVAS_EVENT",mod,CANVAS_EVENT);
  defun("CANVAS_WINDOW_EVENT",mod,CANVAS_WINDOW_EVENT);

  defun("MENU_SET",mod,MENU_SET);
  defun("MENU_CREATE",mod,my_MENU_CREATE);
  defun("MENU_CREATE_ITEM",mod,MENU_CREATE_ITEM);
  defun("MENU_DESTROY",mod,my_MENU_DESTROY);
  defun("MENU_DESTROY_WITH_PROC",mod,MENU_DESTROY_WITH_PROC);
  defun("MENU_FIND",mod,MENU_FIND);
  defun("MENU_GET",mod,MENU_GET);
  defun("MENU_SHOW",mod,MENU_SHOW);
  defun("MENU_RETURN_ITEM",mod,MENU_RETURN_ITEM);
  defun("MENU_RETURN_VALUE",mod,MENU_RETURN_VALUE);

  defun("PANEL_SET",mod,PANEL_SET);
  defun("PANEL_FREE",mod,PANEL_FREE);
  defun("PANEL_ACCEPT_KEY",mod,PANEL_ACCEPT_KEY);
  defun("PANEL_ACCEPT_MENU",mod,PANEL_ACCEPT_MENU);
  defun("PANEL_ACCEPT_PREVIEW",mod,PANEL_ACCEPT_PREVIEW);
  defun("PANEL_BEGIN_PREVIEW",mod,PANEL_BEGIN_PREVIEW);
  defun("PANEL_CANCEL_PREVIEW",mod,PANEL_CANCEL_PREVIEW);
  defun("PANEL_ADVANCE_CARET",mod,PANEL_ADVANCE_CARET);
  defun("PANEL_BACKUP_CARET",mod,PANEL_BACKUP_CARET);
  defun("PANEL_BUTTON_IMAGE",mod,PANEL_BUTTON_IMAGE);
  defun("PANEL_CREATE_ITEM",mod,PANEL_CREATE_ITEM);
  defun("PANEL_CREATE_MESSAGE",mod,PANEL_CREATE_MESSAGE);
  defun("PANEL_CREATE_BUTTON",mod,PANEL_CREATE_BUTTON);
  defun("PANEL_CREATE_CHOICE",mod,PANEL_CREATE_CHOICE);
  defun("PANEL_CREATE_CYCLE",mod,PANEL_CREATE_CYCLE);
  defun("PANEL_CREATE_TOGGLE",mod,PANEL_CREATE_TOGGLE);
  defun("PANEL_CREATE_TEXT",mod,PANEL_CREATE_TEXT);
  defun("PANEL_CREATE_SLIDER",mod,PANEL_CREATE_SLIDER);
  defun("PANEL_DEFAULT_HANDLE_EVENT",mod,PANEL_DEFAULT_HANDLE_EVENT);
  defun("PANEL_EVENT",mod,PANEL_EVENT);
  defun("PANEL_DESTROY_ITEM",mod,PANEL_DESTROY_ITEM);
  defun("PANEL_GET",mod,my_PANEL_GET);
  defun("PANEL_GET_VALUE",mod,PANEL_GET_VALUE);
  defun("PANEL_UPDATE_SCROLLING_SIZE",mod,PANEL_UPDATE_SCROLLING_SIZE);
  defun("PANEL_UPDATE_PREVIEW",mod,PANEL_UPDATE_PREVIEW);
  defun("PANEL_WINDOW_EVENT",mod,PANEL_WINDOW_EVENT);
  defun("PANEL_TEXT_NOTIFY",mod,PANEL_TEXT_NOTIFY);
  defun("PANEL_SET_VALUE",mod,PANEL_SET_VALUE);
  defun("PANEL_PAINT",mod,my_PANEL_PAINT);


  defun("ICON_CREATE",mod,ICON_CREATE);
  defun("ICON_SET",mod,ICON_SET);
  defun("ICON_GET",mod,ICON_GET);
  defun("ICON_DESTROY",mod,ICON_DESTROY);
  defun("ICON_LOAD",mod,ICON_LOAD);
  defun("ICON_INIT_FROM_PR",mod,ICON_INIT_FROM_PR);
  defun("ICON_LOAD_MPR",mod,ICON_LOAD_MPR);
  defun("ICON_OPEN_HEADER",mod,ICON_OPEN_HEADER);

  defun("PW_BATCH",mod,PW_BATCH);
  defun("PW_BATCH_OFF",mod,PW_BATCH_OFF);
  defun("PW_BATCH_ON",mod,PW_BATCH_ON);
  defun("PW_BATCHROP",mod,PW_BATCHROP);
  defun("PW_CHAR",mod,PW_CHAR);
  defun("PW_COPY",mod,PW_COPY);
  defun("PW_GET",mod,PW_GET);
  defun("PW_LINE",mod,MY_PW_LINE);
  defun("PW_LOCK",mod,PW_LOCK);
  defun("PW_PFSYSCLOSE",mod,PW_PFSYSCLOSE);
  defun("PW_POLYGON_2",mod,PW_POLYGON_2);
  defun("PW_POLYLINE",mod,MY_PW_POLYLINE);
  defun("PW_POLYPOINT",mod,MY_PW_POLYPOINT);
  defun("PW_PUT",mod,PW_PUT);
  defun("PW_READ",mod,PW_READ);
  defun("PW_REPLROP",mod,MY_PW_REPLROP);
  defun("PW_ROP",mod,MY_PW_ROP);
  defun("PW_SHOW",mod,my_PW_SHOW);
  defun("PW_STENCIL",mod,MY_PW_STENCIL);
  defun("PW_TEXT",mod,MY_PW_TEXT);
  defun("PW_TTEXT",mod,PW_TTEXT);
  defun("PW_UNLOCK",mod,PW_UNLOCK);
  defun("PW_VECTOR",mod,MY_PW_VECTOR);
  defun("PW_WRITE",mod,PW_WRITE);
  defun("PW_WRITEBACKGROUND",mod,PW_WRITEBACKGROUND);
  defun("PW_BLACKONWHITE",mod,PW_BLACKONWHITE);
  defun("PW_CYCLECOLORMAP",mod,PW_CYCLECOLORMAP);
  defun("PW_GETATTRIBUTES",mod,PW_GETATTRIBUTES);
  defun("PW_GETCMSNAME",mod,PW_GETCMSNAME);
  defun("PW_GETCOLORMAP",mod,PW_GETCOLORMAP);
  defun("PW_PUTCOLORMAP",mod,PW_PUTCOLORMAP);
  defun("PW_REVERSEVIDEO",mod,PW_REVERSEVIDEO);
  defun("PW_SETCMSNAME",mod,PW_SETCMSNAME);
  defun("PW_WHITEONBLACK",mod,PW_WHITEONBLACK);

  defun("TEXTSW_ADD_MARK",mod,TEXTSW_ADD_MARK);
  defun("TEXTSW_APPEND_FILE_NAME",mod,TEXTSW_APPEND_FILE_NAME);
  defun("TEXTSW_DELETE",mod,TEXTSW_DELETE);
  defun("TEXTSW_EDIT",mod,TEXTSW_EDIT);
  defun("TEXTSW_ERASE",mod,TEXTSW_ERASE);
  defun("TEXTSW_FILE_LINES_VISIBLE",mod,TEXTSW_FILE_LINES_VISIBLE);
  defun("TEXTSW_FIND_BYTES",mod,TEXTSW_FIND_BYTES);
  defun("TEXTSW_MATCH_BYTES",mod,TEXTSW_MATCH_BYTES);
  defun("TEXTSW_FIND_MARK",mod,TEXTSW_FIND_MARK);
  defun("TEXTSW_FIRST",mod,my_TEXTSW_FIRST);
  defun("TEXTSW_INDEX_FOR_FILE_LINE",mod,TEXTSW_INDEX_FOR_FILE_LINE);
  defun("TEXTSW_INSERT",mod,TEXTSW_INSERT);
  defun("TEXTSW_NEXT",mod,TEXTSW_NEXT);
  defun("TEXTSW_NORMALIZE_VIEW",mod,TEXTSW_NORMALIZE_VIEW);
  defun("TEXTSW_POSSIBLY_NORMALIZE",mod,TEXTSW_POSSIBLY_NORMALIZE);
  defun("TEXTSW_REMOVE_MARK",mod,TEXTSW_REMOVE_MARK);
  defun("TEXTSW_REPLACE_BYTES",mod,TEXTSW_REPLACE_BYTES);
  defun("TEXTSW_RESET",mod,TEXTSW_RESET);
  defun("TEXTSW_SAVE",mod,TEXTSW_SAVE);
  defun("TEXTSW_SCREEN_LINE_COUNT",mod,TEXTSW_SCREEN_LINE_COUNT);
  defun("TEXTSW_SCROLL_LINES",mod,TEXTSW_SCROLL_LINES);
  defun("TEXTSW_STORE_FILE",mod,TEXTSW_STORE_FILE);
  defun("TEXTSW_SET_SELECTION",mod,TEXTSW_SET_SELECTION);

  defun("TTYSW_INPUT",mod,TTYSW_INPUT);
  defun("TTYSW_OUTPUT",mod,TTYSW_OUTPUT);

  defun("NOTIFY_DEFAULT_WAIT3",mod,NOTIFY_DEFAULT_WAIT3);
  defun("NOTIFY_DISPATCH",mod,L_NOTIFY_DISPATCH);
  defun("NOTIFY_DO_DISPATCH",mod,NOTIFY_DO_DISPATCH);
  defun("NOTIFY_INTERPOSE_DESTROY_FUNC",mod,
	NOTIFY_INTERPOSE_DESTROY_FUNC);
  defun("NOTIFY_INTERPOSE_EVENT_FUNC",mod,
	NOTIFY_INTERPOSE_EVENT_FUNC);
  defun("NOTIFY_ITIMER_VALUE",mod,NOTIFY_ITIMER_VALUE);
  defun("NOTIFY_NEXT_DESTROY_FUNC",mod,NOTIFY_NEXT_DESTROY_FUNC);
  defun("NOTIFY_NEXT_EVENT_FUNC",mod,NOTIFY_NEXT_EVENT_FUNC);
  defun("NOTIFY_SET_DESTROY_FUNC",mod,NOTIFY_SET_DESTROY_FUNC);
  defun("NOTIFY_SET_EXCEPTION_FUNC",mod,NOTIFY_SET_EXCEPTION_FUNC);
  defun("NOTIFY_SET_INPUT_FUNC",mod,NOTIFY_SET_INPUT_FUNC);
  defun("NOTIFY_SET_ITIMER_FUNC",mod,NOTIFY_SET_ITIMER_FUNC);
  defun("NOTIFY_SET_SIGNAL_FUNC",mod,NOTIFY_SET_SIGNAL_FUNC);
  defun("NOTIFY_SET_OUTPUT_FUNC",mod,NOTIFY_SET_OUTPUT_FUNC);
  defun("NOTIFY_SET_WAIT3_FUNC",mod,NOTIFY_SET_WAIT3_FUNC);
  defun("NOTIFY_START",mod,NOTIFY_START);
  defun("NOTIFY_STOP",mod,NOTIFY_STOP);
  defun("NOTIFY_NO_DISPATCH",mod,NOTIFY_NO_DISPATCH);
  defun("NOTIFY_PERROR",mod,NOTIFY_PERROR);
  defun("NOTIFY_VETO_DESTROY",mod,NOTIFY_VETO_DESTROY);

  defun("MPR_LINEBYTES",mod,MPR_LINEBYTES);
  defun("MEM_CREATE",mod,MEM_CREATE);
  defun("MEM_POINT",mod,MEM_POINT);

  defun("PF_TEXTBATCH",mod,PF_TEXTBATCH);
  defun("PF_TEXTWIDTH",mod,PF_TEXTWIDTH);
  defun("PF_CLOSE",mod,MY_PF_CLOSE);
  defun("PF_TEXT",mod,MY_PF_TEXT);
  defun("PF_TTEXT",mod,MY_PF_TTEXT);

  defun("PF_DEFAULT",mod,PF_DEFAULT);
  defun("PF_OPEN",mod,PF_OPEN);
  defun("PF_OPEN_PRIVATE",mod,PF_OPEN_PRIVATE);

  defun("PR_OPEN",mod,PR_OPEN);
  defun("PR_VECTOR",mod,PR_VECTOR);
  defun("PR_POLYGON_2",mod,PR_POLYGON_2);
  defun("PR_REVERSEVIDEO",mod,PR_REVERSEVIDEO);
  defun("PR_DUMP_INIT",mod,PR_DUMP_INIT);
  defun("PR_LOAD_COLORMAP",mod,PR_LOAD_COLORMAP);
  defun("PR_LOAD_HEADER",mod,PR_LOAD_HEADER);
  defun("PR_LOAD_IMAGE",mod,PR_LOAD_IMAGE);
  defun("PR_LOAD",mod,PR_LOAD);
  defun("PR_LOAD_STD_IMAGE",mod,PR_LOAD_STD_IMAGE);
  defun("PR_REPLROP",mod,PR_REPLROP);
  defun("PR_BLACKONWHITE",mod,PR_BLACKONWHITE);
  defun("PR_WHITEONBLACK",mod,PR_WHITEONBLACK);
  defun("PR_TRAPROP",mod,PR_TRAPROP);
  defun("PR_DUMP_HEADER",mod,PR_DUMP_HEADER);
  defun("PR_DUMP_IMAGE",mod,PR_DUMP_IMAGE);
  defun("PR_DUMP",mod,PR_DUMP);
  defun("PR_PUT",mod,PR_PUT);
  defun("PR_PUTATTRIBUTES",mod,PR_PUTATTRIBUTES);

  defun("PR_REGION",mod,PR_REGION);
  defun("PR_STENCIL",mod,PR_STENCIL);
  defun("PR_GET",mod,PR_GET);
  defun("PR_ROP",mod,PR_ROP);
  defun("PR_DESTROY",mod,PR_DESTROY);
  defun("PR_PUTCOLORMAP",mod,PR_PUTCOLORMAP);

  defun("XV_ROP",mod,XV_ROP);

  /*
    defun("PRS_REGION",mod,PRS_REGION);
  defun("PRS_STENCIL",mod,PRS_STENCIL);
  defun("PRS_ROP",mod,PRS_ROP);
  defun("PRS_GET",mod,PRS_GET);
  defun("PRS_VECTOR",mod,PRS_VECTOR);
  defun("PRS_GETCOLORMAP",mod,PRS_GETCOLORMAP);
  defun("PRS_GETATTRIBUTES",mod,PRS_GETATTRIBUTES);
  defun("PRS_DESTROY",mod,PRS_DESTROY);
  defun("PRS_REPLROP",mod,PRS_REPLROP);
  defun("PRS_PUTCOLORMAP",mod,PRS_PUTCOLORMAP);
  defun("PRS_PUT",mod,PRS_PUT);
  defun("PRS_PUTATTRIBUTES",mod,PRS_PUTATTRIBUTES);
*/
  defun("SELN_ASK",mod,SELN_ASK);
  defun("SELN_INIT_REQUEST",mod,SELN_INIT_REQUEST);
  defun("SELN_QUERY",mod,SELN_QUERY);
  defun("SELN_FIGURE_RESPONSE",mod,SELN_FIGURE_RESPONSE);
  defun("SELN_ACQUIRE",mod,SELN_ACQUIRE);
  defun("SELN_DESTROY",mod,SELN_DESTROY);
  defun("SELN_DONE",mod,SELN_DONE);
  defun("SELN_HOLD_FILE",mod,SELN_HOLD_FILE);
  defun("SELN_HOLDER_SAME_CLIENT",mod,SELN_HOLDER_SAME_CLIENT);
  defun("SELN_HOLDER_SAME_PROCESS",mod,SELN_HOLDER_SAME_PROCESS);
  defun("SELN_INFORM",mod,SELN_INFORM);
  defun("SELN_INQUIRE",mod,SELN_INQUIRE);
  defun("SELN_REQUEST",mod,my_SELN_REQUEST);
  defun("SELN_SAME_HOLDER",mod,SELN_SAME_HOLDER);
  defun("SELN_SECONDARY_EXISTS",mod,SELN_SECONDARY_EXISTS);
  defun("SELN_SECONDARY_MADE",mod,SELN_SECONDARY_MADE);
  defun("SELN_USE_TIMEOUT",mod,SELN_USE_TIMEOUT);
  defun("SELN_YIELD_ALL",mod,SELN_YIELD_ALL);
  defun("READER",mod,READER);

/*
  defun("PW_SET_X_OFFSET",mod,PW_SET_X_OFFSET);
  defun("PW_SET_Y_OFFSET",mod,PW_SET_Y_OFFSET);
  defun("PW_SET_XY_OFFSET",mod,PW_SET_XY_OFFSET);
  defun("PW_GET_X_OFFSET",mod,PW_GET_X_OFFSET);
  defun("PW_GET_Y_OFFSET",mod,PW_GET_Y_OFFSET);
  defun("PW_DAMAGED",mod,PW_DAMAGED);
  defun("PW_REPAIRRETAINED",mod,PW_REPAIRRETAINED);
  defun("PW_DONEDAMAGED",mod,PW_DONEDAMAGED);
  defun("PW_EXPOSED",mod,PW_EXPOSED);
*/
  defun("EVENT_ID",mod,EVENT_ID);
  defun("EVENT_IS_UP",mod,EVENT_IS_UP);
  defun("EVENT_IS_DOWN",mod,EVENT_IS_DOWN);
  defun("EVENT_X",mod,EVENT_X);
  defun("EVENT_Y",mod,EVENT_Y);
  defun("EVENT_SHIFTMASK",mod,EVENT_SHIFTMASK);
  defun("EVENT_TIME",mod,EVENT_TIME);
  defun("EVENT_SET_TIME",mod,EVENT_SET_TIME);
  defun("EVENT_SHIFT_IS_DOWN",mod,EVENT_SHIFT_IS_DOWN);
  defun("EVENT_CTRL_IS_DOWN",mod,EVENT_CTRL_IS_DOWN);
  defun("EVENT_META_IS_DOWN",mod,EVENT_META_IS_DOWN);
  defun("EVENT_IS_BUTTON",mod,EVENT_IS_BUTTON);
  defun("EVENT_IS_ASCII",mod,EVENT_IS_ASCII);
  defun("EVENT_IS_META",mod,EVENT_IS_META);
  defun("EVENT_IS_KEY_LEFT",mod,EVENT_IS_KEY_LEFT);
  defun("EVENT_IS_KEY_RIGHT",mod,EVENT_IS_KEY_RIGHT);
  defun("EVENT_IS_KEY_TOP",mod,EVENT_IS_KEY_TOP);
  defun("EVENT_SET_ID",mod,EVENT_SET_ID);
  defun("EVENT_SET_SHIFTMASK",mod,EVENT_SET_SHIFTMASK);
  defun("EVENT_SET_X",mod,EVENT_SET_X);
  defun("EVENT_SET_Y",mod,EVENT_SET_Y);
  defun("EVENT_SET_UP",mod,EVENT_SET_UP);
  defun("EVENT_SET_DOWN",mod,EVENT_SET_DOWN);

  defun("KEY_LEFT",mod,L_KEY_LEFT);
  defun("KEY_RIGHT",mod,L_KEY_RIGHT);
  defun("KEY_TOP",mod,L_KEY_TOP);
  defun("BUT",mod,L_BUT);

  defun("GET_SELECTION",mod,GET_SELECTION);
  defun("ADR_TO_STRING",mod,ADR_TO_STRING);
  defun("EXPAND_NAME",mod,EXPAND_NAME);
  defun("PEEK_BYTE",mod,PEEK_BYTE);
  defun("PEEK_SHORT",mod,PEEK_SHORT);
  defun("PEEK_LONG",mod,PEEK_LONG);
  defun("PEEK_DOUBLE",mod,PEEK_DOUBLE);

  defun("SCROLLBAR_CREATE",mod,SCROLLBAR_CREATE);

}
