/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom        */
static int centered = 1;                    /* -c option; centers dmenu on screen               */
static int min_width = 800;                 /* minimum width when centered                      */
static const char *fonts[] = { "Hack:pixelsize=18:antialias=true:autohint=true" };
static const char col_bg[] = { "#21242b" };
static const char col_fg[] = { "#abb2bf" };
static const char sel_fg[] = { "#dfe5f2" };
static const char sel_bg[] = { "#5c6370" };
static const char *prompt  = { NULL };      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
        /*     fg         bg       */
        [SchemeNorm] = { col_fg, col_bg },
        [SchemeSel]  = { sel_fg, sel_bg },
        [SchemeBor]  = { col_fg, col_fg },
        [SchemeOut]  = { col_fg, sel_bg },
};
/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 18;
static unsigned int columns    = 1;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = "";

/* Size of the window border */
static unsigned int border_width = 1;
