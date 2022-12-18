/* NetHack 3.7  winstdio.c $FLEY-Date: 1671395425 2022/12/18 20:30:25 $ $FLEY-Branch: towel $ $FLEY-Revision: 1.0 $ */
/* Copyright (c) Michael Lehotay, 2022. */
/* NetHack may be freely redistributed. See license for details. */

#include "winstdio.h"

struct window_procs stdio_procs = {
     "stdio",   /* name of window port */
     wp_stdio,  /* wp_id */
     0L,        /* wincap */
     0L,        /* wincap2 */
     {0},       /* has_color[] */
     stdio_init_nhwindows,
     stdio_player_selection,
     stdio_askname,
     stdio_get_nh_event,
     stdio_exit_nhwindows,
     stdio_suspend_nhwindows,
     stdio_resume_nhwindows,
     stdio_create_nhwindow,
     stdio_clear_nhwindow,
     stdio_display_nhwindow,
     stdio_destroy_nhwindow,
     stdio_curs,
     stdio_putstr,
     genl_putmixed,
     stdio_display_file,
     stdio_start_menu,
     stdio_add_menu,
     stdio_end_menu,
     stdio_select_menu,
     genl_message_menu,
     stdio_mark_synch,
     stdio_wait_synch,
 #ifdef CLIPPING
     stdio_cliparound,
 #endif
 #ifdef POSITIONBAR
     dummy_update_position_bar,
 #endif
     stdio_print_glyph,
     stdio_raw_print,
     stdio_raw_print_bold,
     stdio_nhgetch,
     stdio_nh_poskey,
     stdio_nhbell,
     stdio_doprev_message,
     stdio_yn_function,
     stdio_getlin,
     stdio_get_ext_cmd,
     stdio_number_pad,
     stdio_delay_output,
 #ifdef CHANGE_COLOR
     dummy_change_color,
 #ifdef MAC /* old OS 9, not OSX */
     (void (*)(int)) 0,
     (short (*)(winid, char *)) 0,
 #endif
     dummy_get_color_string,
 #endif
     stdio_start_screen,
     stdio_end_screen,
     genl_outrip,
     stdio_preference_update,
     stdio_getmsghistory,
     stdio_putmsghistory,
     stdio_status_init,
     stdio_status_finish,
     genl_status_enablefield,
     stdio_status_update,
     genl_can_suspend_yes,
     stdio_update_inventory,
     stdio_ctrl_nhwindow,
 };

void stdio_init_nhwindows(int *, char **)
{
    /* code for initializing the stdio port */
}
