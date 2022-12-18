/* NetHack 3.7  winstdio.h $FLEY-Date: 1671395425 2022/12/18 20:30:25 $ $FLEY-Branch: towel $ $FLEY-Revision: 1.0 $ */
/* Copyright (c) Michael Lehotay, 2022. */
/* NetHack may be freely redistributed. See license for details. */

#ifndef WINSTDIO_H
#define WINSTDIO_H

#include "hack.h"

extern struct window_procs stdio_procs;

extern void stdio_init_nhwindows(int *, char **);
extern void stdio_askname(void);
extern void stdio_player_selection(void);
extern void stdio_get_nh_event(void);
extern void stdio_exit_nhwindows(const char *);
extern void stdio_suspend_nhwindows(const char *);
extern void stdio_resume_nhwindows(void);
extern winid stdio_create_nhwindow(int);
extern void stdio_clear_nhwindow(winid);
extern void stdio_display_nhwindow(winid, boolean);
extern void stdio_destroy_nhwindow(winid);
extern void stdio_curs(winid, int, int);
extern void stdio_putstr(winid, int, const char *);
extern void stdio_putmixed(winid, int, const char *);
extern void stdio_display_file(const char *, boolean);
extern void stdio_start_menu(winid, unsigned long);
extern void stdio_add_menu(winid, const glyph_info *, const ANY_P *,
                     char, char, int, int,
                     const char *, unsigned int);
extern void stdio_end_menu(winid, const char *);
extern int stdio_select_menu(winid, int, MENU_ITEM_P **);
extern char stdio_message_menu(char, int, const char *);
extern void stdio_mark_synch(void);
extern void stdio_wait_synch(void);
#ifdef CLIPPING
extern void stdio_cliparound(int, int);
#endif
#ifdef POSITIONBAR
extern void stdio_update_positionbar(char *);
#endif
extern void stdio_print_glyph(winid, coordxy, coordxy,
                        const glyph_info *, const glyph_info *);
extern void stdio_raw_print(const char *);
extern void stdio_raw_print_bold(const char *);
extern int stdio_nhgetch(void);
extern int stdio_nh_poskey(coordxy *, coordxy *, int *);
extern void stdio_nhbell(void);
extern int stdio_doprev_message(void);
extern char stdio_yn_function(const char *, const char *, char);
extern void stdio_getlin(const char *, char *);
extern int stdio_get_ext_cmd(void);
extern void stdio_number_pad(int);
extern void stdio_delay_output(void);
#ifdef CHANGE_COLOR
extern void stdio_change_color(int, long, int);
#ifdef MAC
extern void stdio_change_background(int);
extern short stdio_set_font_name(winid, char *);
#endif
extern char *stdio_get_color_string(void);
#endif

extern void stdio_start_screen(void);
extern void stdio_end_screen(void);
extern void stdio_outrip(winid, int, time_t);
extern void stdio_preference_update(const char *);
extern char *stdio_getmsghistory(boolean);
extern void stdio_putmsghistory(const char *, boolean);
extern void stdio_status_init(void);
extern void stdio_status_finish(void);
extern void stdio_status_enablefield(int, const char *, const char *,
                               boolean);
extern void stdio_status_update(int, genericptr_t, int, int, int,
                          unsigned long *);
extern boolean stdio_can_suspend(void);
extern void stdio_update_inventory(int);
extern win_request_info *stdio_ctrl_nhwindow(winid, int, win_request_info *);

#endif /* WINSTDIO_H */
