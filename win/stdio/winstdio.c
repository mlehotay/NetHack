/* NetHack 3.7  winstdio.c $FLEY-Date: 1671641739 2022/12/21 16:55:39 $ $FLEY-Branch: towel $ $FLEY-Revision: 1.1 $ */
/* Copyright (c) Michael Lehotay, 2022. */
/* NetHack may be freely redistributed. See license for details. */

#include <stdio.h>
#include "winstdio.h"

/* Vanilla stdio procs from safeproc.c */
extern void stdio_wait_synch(void);
extern void stdio_raw_print(const char* str);
extern void stdio_nonl_raw_print(const char* str);
extern void stdio_raw_print_bold(const char* str);
extern int stdio_nhgetch(void);

/* genl_ routines from extern.h */
extern void genl_outrip(winid, int, time_t);
extern void genl_player_selection(void);
extern int genl_player_setup(void);
extern boolean genl_can_suspend_no(void);
extern boolean genl_can_suspend_yes(void);
extern char genl_message_menu(char, int, const char *);
extern void genl_preference_update(const char *);
extern char *genl_getmsghistory(boolean);
extern void genl_putmsghistory(const char *, boolean);
extern void genl_status_init(void);
extern void genl_status_finish(void);
extern void genl_status_enablefield(int, const char *, const char *, boolean);
extern void genl_status_update(int, genericptr_t, int, int, int, unsigned long *);
extern void genl_putmixed(winid, int, const char *);
extern void genl_display_file(const char *, boolean);

struct window_procs stdio_procs = {
    WPID(stdio), 0L, 0L, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    stdio_init_nhwindows, stdio_player_selection, stdio_askname,
    stdio_get_nh_event, stdio_exit_nhwindows, stdio_suspend_nhwindows,
    stdio_resume_nhwindows, stdio_create_nhwindow, stdio_clear_nhwindow,
    stdio_display_nhwindow, stdio_destroy_nhwindow, stdio_curs, stdio_putstr,
    genl_putmixed, genl_display_file, stdio_start_menu, stdio_add_menu,
    stdio_end_menu, stdio_select_menu, genl_message_menu, stdio_mark_synch,
    stdio_wait_synch,
 #ifdef CLIPPING
     stdio_cliparound,
 #endif
 #ifdef POSITIONBAR
     dummy_update_position_bar,
 #endif
     stdio_print_glyph, stdio_raw_print, stdio_raw_print_bold, stdio_nhgetch,
     stdio_nh_poskey, stdio_nhbell, stdio_doprev_message, stdio_yn_function,
     stdio_getlin, stdio_get_ext_cmd, stdio_number_pad, stdio_delay_output,
 #ifdef CHANGE_COLOR
     dummy_change_color,
 #ifdef MAC /* old OS 9, not OSX */
    stdio_change_background, stdio_safe_font_name,
 #endif
     dummy_get_color_string,
 #endif
     stdio_start_screen, stdio_end_screen, genl_outrip,
     genl_preference_update, genl_getmsghistory, genl_putmsghistory,
     genl_status_init, genl_status_finish, genl_status_enablefield,
     genl_status_update, genl_can_suspend_yes, stdio_update_inventory,
     stdio_ctrl_nhwindow,
 };

void
win_stdio_init(int dir)
{
    if (dir == WININIT) {
        /* initialize window port */
    } else if (dir == WININIT_UNDO) {
        /* undo side effects of initialization (if any) */
    }
}

void
stdio_init_nhwindows(int *argcp UNUSED, char **argv UNUSED)
{
    int i;
    for (i = 1; i <= 4; ++i)
        stdio_raw_print(copyright_banner_line(i));
}

void
stdio_player_selection(void)
{
    return;
}

void
stdio_askname(void)
{
    return;
}

void
stdio_get_nh_event(void)
{
    return;
}

void
stdio_suspend_nhwindows(const char *str UNUSED)
{
    return;
}

void
stdio_resume_nhwindows(void)
{
    return;
}

void
stdio_exit_nhwindows(const char *str UNUSED)
{
    return;
}

winid
stdio_create_nhwindow(int type UNUSED)
{
    return WIN_ERR;
}

void
stdio_clear_nhwindow(winid window UNUSED)
{
    return;
}

void
stdio_display_nhwindow(winid window UNUSED, boolean blocking UNUSED)
{
    return;
}

void
stdio_dismiss_nhwindow(winid window UNUSED)
{
    return;
}

void
stdio_destroy_nhwindow(winid window UNUSED)
{
    return;
}

void
stdio_curs(winid window UNUSED, int x UNUSED, int y UNUSED)
{
    return;
}

void
stdio_putstr(winid window UNUSED, int attr UNUSED, const char *str)
{
    stdio_raw_print(str);
}

void
stdio_putmixed(winid window UNUSED, int attr UNUSED, const char *str UNUSED)
{
    genl_putmixed(window, attr, str);
}

void
stdio_display_file(const char * fname UNUSED, boolean complain UNUSED)
{
    return;
}

void
stdio_start_menu(winid window UNUSED, unsigned long mbehavior UNUSED)
{
    return;
}

/*
 * Add a menu item to the beginning of the menu list.  This list is reversed
 * later.
 */
void
stdio_add_menu(
    winid window UNUSED,      /* window to use, must be of type NHW_MENU */
    const glyph_info *glyphinfo UNUSED, /* glyph plus glyph info */
    const anything *identifier UNUSED, /* what to return if selected */
    char ch UNUSED,           /* keyboard accelerator (0 = pick our own) */
    char gch UNUSED,          /* group accelerator (0 = no group) */
    int attr UNUSED,          /* attribute for string (like stdio_putstr()) */
    int clr UNUSED,           /* colour for string */
    const char *str UNUSED,   /* menu string */
    unsigned int itemflags UNUSED) /* itemflags such as marked as selected */
{
    return;
}

/*
 * End a menu in this window, window must a type NHW_MENU.
 */
void
stdio_end_menu(
    winid window UNUSED,       /* menu to use */
    const char *prompt UNUSED) /* prompt to for menu */
{
    return;
}

int
stdio_select_menu(
    winid window UNUSED,
    int how UNUSED,
    menu_item **menu_list UNUSED)
{
    return 0;
}

/* special hack for treating top line --More-- as a one item menu */
char
stdio_message_menu(
    char let UNUSED,
    int how UNUSED,
    const char *mesg UNUSED)
{
    return '\033';
}

void
stdio_mark_synch(void)
{
}


#ifdef CLIPPING
void
stdio_cliparound(int x UNUSED, int y UNUSED)
{
}
#endif /* CLIPPING */

/*
 *  stdio_print_glyph
 *
 *  Print the glyph to the output device.  Don't flush the output device.
 */
void
stdio_print_glyph(
    winid window UNUSED,
    coordxy x UNUSED,
    coordxy y UNUSED,
    const glyph_info *glyphinfo UNUSED,
    const glyph_info *bkglyphinfo UNUSED)
{
    return;
}

/*
 * return a key, or 0, in which case a mouse button was pressed
 * mouse events should be returned as character postitions in the map window.
 * Since normal tty's don't have mice, just return a key.
 */
int
stdio_nh_poskey(coordxy *x UNUSED, coordxy *y UNUSED, int *mod UNUSED)
{
    return stdio_nhgetch();
}

#ifdef POSITIONBAR
void
stdio_update_positionbar(char *posbar UNUSED)
{
    return;
}
#endif /* POSITIONBAR */

/*
 *  stdio_status_init()
 *      -- initialize the port-specific data structures.
 */
void
stdio_status_init(void)
{
    return;
}

boolean
stdio_can_suspend(void)
{
    return FALSE;
}

void
stdio_nhbell(void)
{
    return;
}

int
stdio_doprev_message(void)
{
    return 0;
}

char
stdio_yn_function(const char *query UNUSED,
                 const char *resp UNUSED, char def UNUSED)
{
    return '\033';
}

void
stdio_getlin(const char* prompt UNUSED, char *outbuf)
{
    Strcpy(outbuf, "\033");
}

int
stdio_get_ext_cmd(void)
{
    return '\033';
}

void
stdio_number_pad(int mode)
{
    return;
}

void
stdio_delay_output(void)
{
    return;
}

void
stdio_start_screen(void)
{
    return;
}

void
stdio_end_screen(void)
{
    return;
}

void
stdio_outrip(winid tmpwin UNUSED, int how UNUSED, time_t when UNUSED)
{
    return;
}

void
stdio_preference_update(const char* pref UNUSED)
{
    return;
}

char *
stdio_getmsghistory(boolean init UNUSED)
{
    return (char *) 0;
}

void
stdio_putmsghistory(
    const char *msg UNUSED,
    boolean is_restoring UNUSED)
{
}

void
stdio_status_finish(void)
{
}

void
stdio_status_enablefield(
    int fieldidx UNUSED,
    const char *nm UNUSED,
    const char *fmt UNUSED,
    boolean enable UNUSED)
{
}

/* call once for each field, then call with BL_FLUSH to output the result */
void
stdio_status_update(
    int idx UNUSED,
    genericptr_t ptr UNUSED,
    int chg UNUSED,
    int percent UNUSED,
    int color UNUSED,
    unsigned long *colormasks UNUSED)
{
}

void
stdio_update_inventory(int arg UNUSED)
{
    return;
}

win_request_info *
stdio_ctrl_nhwindow(
    winid window UNUSED,
    int request UNUSED,
    win_request_info *wri UNUSED)
{
    return (win_request_info *) 0;
}
