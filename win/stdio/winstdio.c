/* NetHack 3.7  winstdio.c $FLEY-Date: 1671806328 2022/12/23 14:38:48 $ $FLEY-Branch: towel $ $FLEY-Revision: 1.2 $ */
/* Copyright (c) Michael Lehotay, 2022 */
/* NetHack may be freely redistributed. See license for details. */

#include <stdio.h>
#include "winstdio.h"

/****************************************************************************/
/* STDIO window port interface for windows.c                                */
/****************************************************************************/

struct window_procs stdio_procs = {
    WPID(stdio), 0L, 0L, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    stdio_init_nhwindows, genl_player_selection, stdio_askname,
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
     stdio_update_positionbar,
 #endif
     stdio_print_glyph, stdio_raw_print, stdio_raw_print_bold, stdio_nhgetch,
     stdio_nh_poskey, stdio_nhbell, stdio_doprev_message, stdio_yn_function,
     stdio_getlin, stdio_get_ext_cmd, stdio_number_pad, stdio_delay_output,
 #ifdef CHANGE_COLOR
     safe_change_color,
 #ifdef MAC /* old OS 9, not OSX */
    safe_change_background, safe_set_font_name,
 #endif
     safe_get_color_string,
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

/****************************************************************************/
/* STDIO player interface routines                                          */
/****************************************************************************/

/* New or respecified common, high level routines */
extern char display_inventory(const char *lets, boolean want_reply); /* invent.c */
extern void raw_printf(const char *str, ...); /* pline.c */
extern void pline(const char *str, ...); /* pline.c */

/* global variables defined in decl.c */
extern char toplines[BUFSZ];    /* used by Norep() */
extern winid WIN_MESSAGE, WIN_MAP, WIN_INVEN; /* the three standard windows */

#if defined(UNIX) || defined(VMS)
#ifdef TTY_GRAPHICS
/* these are macros, not variables */
/* extern char *AE, *AS; */        /* for DECGraphics, checked in options.c */
/* extern int LI, CO; */              /* set in sys/unix/ioctl.c */
#endif /* TTY_GRAPHICS */
#endif /* UNIX || VMS */

extern struct wc_Opt wc_options[];  /* wincap options defined in options.c */

/** Low-level routines ******************************************************/

extern void stdio_raw_print(const char *str); /* safeproc.c */
extern void stdio_raw_print_bold(const char *str); /* safeproc.c */
extern void stdio_nonl_raw_print(const char* str); /* safeproc.c */
extern void genl_putmixed(winid window, int attr, const char *str); /* windows.c */
extern int stdio_nhgetch(void);  /* safeproc.c */

void
stdio_curs(winid window UNUSED, int x UNUSED, int y UNUSED)
{
    /* todo */
    return;
}

void
stdio_putstr(winid window UNUSED, int attr UNUSED, const char *str)
{
    stdio_raw_print(str);
}

void
stdio_get_nh_event(void)
{
    /* noop */
    return;
}

int
stdio_nh_poskey(coordxy *x UNUSED, coordxy *y UNUSED, int *mod UNUSED)
{
    return stdio_nhgetch();
}

/** High-level routines *****************************************************/

extern void genl_player_selection(void); /* role.c */
extern void genl_display_file(const char * fname, boolean complain); /* windows.c */

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
stdio_update_inventory(int arg UNUSED)
{
    return;
}

int
stdio_doprev_message(void)
{
    return 0;
}

#ifdef POSITIONBAR
void
stdio_update_positionbar(char *posbar UNUSED)
{
    return;
}
#endif /* POSITIONBAR */

/** Window Utility Routines *************************************************/

void
stdio_init_nhwindows(int *argcp UNUSED, char **argv UNUSED)
{
    int i;
    for (i = 1; i <= 4; ++i)
        stdio_raw_print(copyright_banner_line(i));
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

win_request_info *
stdio_ctrl_nhwindow(
    winid window UNUSED,
    int request UNUSED,
    win_request_info *wri UNUSED)
{
    return (win_request_info *) 0;
}

/** Menu Routines ***********************************************************/

extern char genl_message_menu(char let, int how, const char *mesg); /* windows.c */

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

/** Status Display Routines *************************************************/

extern void genl_status_init(void); /* windows.c */
extern void genl_status_enablefield(int fieldidx, const char *nm,
        const char *fmt, boolean enable); /* windows.c */
extern void genl_status_update(int idx, genericptr_t ptr, int chg,
        int percent, int color, unsigned long *colormasks); /* windows.c */
extern void genl_status_finish(void); /* windows.c */

/** Misc. Routiness *********************************************************/

extern void stdio_wait_synch(void); /* safeproc.c */
extern boolean genl_can_suspend_no(void); /* windows.c */
extern boolean genl_can_suspend_yes(void); /* windows.c */
extern void genl_outrip(winid tmpwin, int how, time_t when); /* rip.c */
extern void genl_preference_update(const char* pref); /* windows.c */
extern char *genl_getmsghistory(boolean init); /* windows.c */
extern void genl_putmsghistory(const char *msg, boolean is_restoring); /* windows.c */

#ifdef CHANGE_COLOR
extern void safe_change_color(int color, long rgb, int reverse); /* safeproc.c */
#ifdef MAC
extern void safe_change_background(int white_or_black); /* safeproc.c */
extern short safe_set_font_name(winid window, char *fontname) /* safeproc.c */
#endif /* MAC */
extern char *safe_get_color_string(void); /* safeproc.c */
#endif /* CHANGE_COLOR */

void
stdio_nhbell(void)
{
    return;
}

void
stdio_mark_synch(void)
{
}

void
stdio_delay_output(void)
{
    return;
}

void
stdio_askname(void)
{
    return;
}

#ifdef CLIPPING
void
stdio_cliparound(int x UNUSED, int y UNUSED)
{
}
#endif /* CLIPPING */

void
stdio_number_pad(int mode)
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
stdio_start_screen(void)
{
    return;
}

void
stdio_end_screen(void)
{
    return;
}
