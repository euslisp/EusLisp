  defun("ADR_TO_STRING",mod,ADR_TO_STRING);
  defun("EXPAND_NAME",mod,EXPAND_NAME);
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

extern canvas_event;
extern canvas_paint_window;
extern canvas_pixwin;
extern canvas_window_event;
extern scrollbar_create;
extern event_id;
extern event_is_button;
extern event_is_down;
extern event_is_up;
extern event_time;
extern event_x;
extern event_y;
extern icon_create;
extern icon_load_mpr;
extern mem_create;
extern mem_point;
extern menu_create;
extern menu_create_item;
extern menu_find;
extern menu_get;
extern menu_item_set;
extern menu_set;
extern menu_show;
extern notify_do_dispatch;
extern notify_no_dispatch;
extern notify_set_itimer_func;
extern panel_button_image;
extern panel_create_button;
extern panel_create_choice;
extern panel_create_cycle;
extern panel_create_message;
extern panel_create_slider;
extern panel_create_text;
extern panel_create_toggle;
extern panel_default_handle_event;
extern panel_event;
extern panel_get;
extern panel_get;
extern panel_set;
extern panel_update_scrolling_size;
extern panel_window_event;
extern pf_open;
extern pr_rop;
extern pr_text;
extern pr_vector;
extern pw_batch_off;
extern pw_copy;
extern pw_getcmsname;
extern pw_getcolormap;
extern pw_polygon_2;
extern pw_polyline;
extern pw_putcolormap;
extern pw_rop;
extern pw_setcmsname;
extern pw_text;
extern pw_ttext;
extern pw_vector;
extern pw_write;
extern pw_writebackground;
extern textstring;
extern textsw_delete;
extern textsw_erase;
extern textsw_insert;
extern textsw_replace_bytes;
extern textsw_save;
extern textsw_screen_line_count;
extern textsw_scroll_lines;
extern textsw_store_file;
extern ttysw_input;
extern ttysw_output;

extern window_create_canvas;
extern window_create_frame;
extern window_create_panel;
extern window_create_textsw;
extern window_create_tty;
extern window_destroy;

extern window_fit_height;
extern window_fit_width;
extern window_get;
extern window_set;
extern xv_col;
extern xv_row;
