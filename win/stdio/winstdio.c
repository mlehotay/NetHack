/* NetHack 3.7  winstdio.c $FLEY-Date: 1671491379 2022/12/19 23:09:39 $ $FLEY-Branch: towel $ $FLEY-Revision: 1.0 $ */
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
     stdio_outrip, /* genl_outrip */
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

void stdio_ini_routine(int) {}

void stdio_init_nhwindows(int *, char **)
{
    /* code for initializing the stdio port */
    printf("%s\n", COPYRIGHT_BANNER_A); /* from patchlevel.h */
    printf("%s\n", COPYRIGHT_BANNER_B); /* from patchlevel.h */
    printf("%s\n", nomakedefs.copyright_banner_c); /* internal global variable */
    printf("%s\n", COPYRIGHT_BANNER_D); /* from patchlevel.h */
}

void stdio_askname(void) { }
void stdio_player_selection(void) { }
void stdio_get_nh_event(void) { }
void stdio_exit_nhwindows(const char *) { }
void stdio_suspend_nhwindows(const char *) { }
void stdio_resume_nhwindows(void) { }
winid stdio_create_nhwindow(int) { return WIN_ERR; }
void stdio_clear_nhwindow(winid) { }
void stdio_display_nhwindow(winid, boolean) { }
void stdio_destroy_nhwindow(winid) { }
void stdio_curs(winid, int, int) { }
void stdio_putstr(winid, int, const char *) { }
void stdio_putmixed(winid, int, const char *) { }
void stdio_display_file(const char *, boolean) { }
void stdio_start_menu(winid, unsigned long) { }
void stdio_add_menu(winid, const glyph_info *, const ANY_P *,
                     char, char, int, int,
                     const char *, unsigned int) { }
void stdio_end_menu(winid, const char *) { }
int stdio_select_menu(winid, int, MENU_ITEM_P **) { return 0; }
char stdio_message_menu(char, int, const char *) { return '\0'; }
void stdio_mark_synch(void) { }
void stdio_wait_synch(void) { }
#ifdef CLIPPING
void stdio_cliparound(int, int) { }
#endif
#ifdef POSITIONBAR
void stdio_update_positionbar(char *) { }
#endif
void stdio_print_glyph(winid, coordxy, coordxy,
                        const glyph_info *, const glyph_info *) { }
void stdio_raw_print(const char *) { }
void stdio_raw_print_bold(const char *) { }
int stdio_nhgetch(void) { return 0;  }
int stdio_nh_poskey(coordxy *, coordxy *, int *) { return 0; }
void stdio_nhbell(void) { }
int stdio_doprev_message(void) { return 0; }
char stdio_yn_function(const char *, const char *, char) { return '\0'; }
void stdio_getlin(const char *, char *) { }
int stdio_get_ext_cmd(void) { return 0; }
void stdio_number_pad(int) { }
void stdio_delay_output(void) { }
#ifdef CHANGE_COLOR
void stdio_change_color(int, long, int) { }
#ifdef MAC
void stdio_change_background(int) { }
short stdio_set_font_name(winid, char *) { return 0; }
#endif
char *stdio_get_color_string(void) { return NULL; }
#endif

void stdio_start_screen(void) { }
void stdio_end_screen(void) { }
void stdio_outrip(winid, int, time_t) { }
void stdio_preference_update(const char *) { }
char *stdio_getmsghistory(boolean) { return NULL; }
void stdio_putmsghistory(const char *, boolean) { }
void stdio_status_init(void) { }
void stdio_status_finish(void) { }
void stdio_status_enablefield(int, const char *, const char *,
                               boolean) { }
void stdio_status_update(int, genericptr_t, int, int, int,
                          unsigned long *) { }
boolean stdio_can_suspend(void) { return FALSE; }
void stdio_update_inventory(int) { }
win_request_info *stdio_ctrl_nhwindow(winid, int, win_request_info *)  { return NULL; }
