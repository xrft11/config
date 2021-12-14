/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = { 1  };		/* border pixel of windows */
static const unsigned int gappx     = { 15 };		/* gaps between windows */
static const unsigned int snap      = { 15 };		/* snap pixel */
static const int showbar            = { 1  };		/* 0 means no bar */
static const int topbar             = { 1  };		/* 0 means bottom bar */
static const char *fonts[]          = { "Hack:pixelsize=15:antialias=true:autohint=true" };
static const char col_gray1[]       = { "#21242b" };		/* bar background */
static const char col_gray2[]       = { "#5c6370" };		/* unfocused window border */
static const char col_gray3[]       = { "#abb2bf" };		/* unfocused tag text */
static const char col_gray4[]       = { "#dfe5f2" };		/* focused tag text */
static const char col_gray5[]       = { "#5c6370" };		/* focused tag background */
static const char col_gray6[]       = { "#abb2bf" };		/* focused window border */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_gray5, col_gray6 },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const char *tagsel[][2] = {
	{ "#ff6e7a", "#21242b" },
	{ "#c0fa96", "#21242b" },
	{ "#ffd587", "#21242b" },
	{ "#6ebeff", "#21242b" },
	{ "#e387ff", "#21242b" },
};

static const Rule rules[] = {
        /* xprop(1):
         *      WM_CLASS(STRING) = instance, class
         *      WM_NAME(STRING) = title
         */
         /*class      instance    title       tags mask     isfloating   monitor*/
        { "",         NULL,       NULL,       0,            1,           -1 },
        { "",         NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termicmd[]  = { "st", NULL };
static const char *lutricmd[]  = { "lutris", NULL };
static const char *filemcmd[]  = { "pcmanfm", NULL };
static const char *dmenucmd[]  = { "dmenu_run", NULL };
static const char *browscmd[]  = { "librewolf", NULL };
static const char *virtmcmd[]  = { "virt-manager", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termicmd } },
	{ MODKEY,                       XK_s,      spawn,          {.v = termicmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = filemcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = browscmd } },
	{ MODKEY,                       XK_v,      spawn,          {.v = virtmcmd } },
	{ MODKEY,                       XK_l,      spawn,          {.v = lutricmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_F11,    togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

