/* NetHack 3.7  winstdio.h $FLEY-Date: 1671979175 2022/12/25 14:39:35 $ $FLEY-Branch: towel $ $FLEY-Revision: 1.3 $ */
/* Copyright (c) Michael Lehotay, 2022. */
/* NetHack may be freely redistributed. See license for details. */

#ifndef WINSTDIO_H
#define WINSTDIO_H

#include "hack.h"

extern struct window_procs stdio_procs;
extern void win_stdio_init(int dir);

extern void stdio_init_nhwindows(int *argcp, char **argv);
extern void stdio_player_selection(void);
extern void stdio_askname(void);
extern void stdio_get_nh_event(void);
extern void stdio_suspend_nhwindows(const char *str);
extern void stdio_resume_nhwindows(void);
extern void stdio_exit_nhwindows(const char *str);
extern winid stdio_create_nhwindow(int type);
extern void stdio_clear_nhwindow(winid window);
extern void stdio_display_nhwindow(winid window, boolean blocking);
extern void stdio_dismiss_nhwindow(winid window);
extern void stdio_destroy_nhwindow(winid window);
extern void stdio_curs(winid window, int x, int y);
extern void stdio_putstr(winid window, int attr, const char *str);
extern void stdio_putmixed(winid window, int attr, const char *str);
extern void stdio_display_file(const char * fname, boolean complain);
extern void stdio_start_menu(winid window, unsigned long mbehavior);
extern void stdio_add_menu(winid window, const glyph_info *glyphinfo,
        const anything *identifier, char ch, char gch, int attr, int clr,
        const char *str, unsigned int itemflags);
extern void stdio_end_menu(winid window, const char *prompt);
extern int stdio_select_menu(winid window, int how, menu_item **menu_list);
extern char stdio_message_menu(char let, int how, const char *mesg);
extern void stdio_mark_synch(void);
extern void stdio_wait_synch(void);
#ifdef CLIPPING
extern void stdio_cliparound(int x, int y);
#endif /* CLIPPING */
extern void stdio_print_glyph(winid window, coordxy x, coordxy y,
        const glyph_info *glyphinfo, const glyph_info *bkglyphinfo);
extern void stdio_raw_print(const char *str);
extern void stdio_raw_print_bold(const char *str);
extern int stdio_nhgetch(void);
extern int stdio_nh_poskey(coordxy *x, coordxy *y, int *mod);
#ifdef POSITIONBAR
extern void stdio_update_positionbar(char *posbar);
#endif /* POSITIONBAR */
extern void stdio_status_init(void);
extern boolean stdio_can_suspend(void);
extern void stdio_nhbell(void);
extern int stdio_doprev_message(void);
extern char stdio_yn_function(const char *query, const char *resp, char def);
extern void stdio_getlin(const char* prompt, char *outbuf);
extern int stdio_get_ext_cmd(void);
extern void stdio_number_pad(int mode);
extern void stdio_delay_output(void);
#ifdef CHANGE_COLOR
extern void stdio_change_color(int color, long rgb, int reverse);
#ifdef MAC
extern void stdio_change_background(int white_or_black);
extern short stdio_set_font_name(winid window, char *fontname)
#endif /* MAC */
extern char *stdio_get_color_string(void);
#endif /* CHANGE_COLOR */
extern void stdio_start_screen(void);
extern void stdio_end_screen(void);
extern void stdio_outrip(winid tmpwin, int how, time_t when);
extern void stdio_preference_update(const char* pref);
extern char *stdio_getmsghistory(boolean init);
extern void stdio_putmsghistory(const char *msg, boolean is_restoring);
extern void stdio_status_finish(void);
extern void stdio_status_enablefield(int fieldidx, const char *nm,
        const char *fmt, boolean enable);
extern void stdio_status_update(int idx, genericptr_t ptr, int chg,
        int percent, int color, unsigned long *colormasks);
extern void stdio_update_inventory(int arg);
extern win_request_info *stdio_ctrl_nhwindow(winid window, int request,
    win_request_info *wri);

#endif /* WINSTDIO_H */

/* winstdio.h */
