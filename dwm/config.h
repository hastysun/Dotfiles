/*
		 _
  __| |_      ___ __ ___
 / _` \ \ /\ / / '_ ` _ \
| (_| |\ V  V /| | | | | |
 \__,_| \_/\_/ |_| |_| |_|

*/

// Gavin Weiss
// June 2018




// Include
#include </usr/include/X11/XF86keysym.h>
#include "themes.h"



// Appearance
static const unsigned int borderpx  = 10;
static const unsigned int snap      = 16;
static const int showbar            = 1;
static const int topbar             = 1;
static const int resizehints 				= 0;    



//Fonts
static const char *fonts[]	= {
																"IBM Plex Mono:size=10",
																"Source Code Pro:size=10",
																"Font Awesome",
															};

static const char dmenufont[] = "IBM Plex Mono:size=10";




// Workspace Tags

// 9 Workspaces
// static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };


// 5 workspaces
// static const char *tags[] = { "I", "II", "III", "IV", "V" };
// static const char *tags[] = { "1", "2", "3", "4", "5" };
static const char *tags[] = { "H", "A", "S", "T", "Y", };




// Window Rules
static const Rule rules[] = {
	/* class				instance   title           tags mask   floating   monitor */
	{ "mpv",				NULL,			 NULL,			      1 << 2,			 0,					-1 },
};




// Layouts
static const float mfact     = 0.50; 
static const int nmaster     = 1;    

static const Layout layouts[] = {
	{ "",      tile },    
	{ "F",     NULL },    
	{ "[M]",   monocle },
};




// Modkey Definitions
#define Alt Mod1Mask
#define Super Mod4Mask

#define TAGKEYS(KEY,TAG) \
\
	{ Super,										   KEY,    view,           {.ui = 1 << TAG} }, \
	{ Super|ControlMask,           KEY,    toggleview,     {.ui = 1 << TAG} }, \
	{ Super|ShiftMask,             KEY,    tag,            {.ui = 1 << TAG} }, \
	{ Super|ControlMask|ShiftMask, KEY,    toggletag,      {.ui = 1 << TAG} }, \
\
	{ Alt,                         KEY,    view,           {.ui = 1 << TAG} }, \
	{ Alt|ControlMask,             KEY,    toggleview,     {.ui = 1 << TAG} }, \
	{ Alt|ShiftMask,               KEY,    tag,            {.ui = 1 << TAG} }, \
	{ Alt|ControlMask|ShiftMask,   KEY,    toggletag,      {.ui = 1 << TAG} }, 




// Helper Functions
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


// Commands
static char dmenumon[2]        = "0"; 
static const char *dmenucmd[]  = { "dmenu_run", NULL };
static const char *terminal[]  = { "st", NULL, NULL };
static const char *ranger[]    = { "st", "ranger", NULL };
static const char *volmute[]   = { "sh", "-c", "pactl set-sink-mute @DEFAULT_SINK@ toggle",	NULL };
static const char *volup[] 	   = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +5%",  NULL };
static const char *voldown[]   = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -5%",  NULL };
static const char *slock[] 	   = { "slock", NULL, NULL };
static const char *scrot[] 		 = { "nougat", "-f", NULL };



static const Theme theme[] = {

  { "arizona",  arizona },
  { "mint",     mint },

	};



// Keybindings
static Key keys[] = {

/* modifier            key										function          argument */

	{ Super|ShiftMask,	 28,	 /* t */					spawn,						{.v = mint },
  { Super,						 28,	 /* t */					spawn,						{.v = &theme[1]} },
	{ Super,      			 27,	 /* r */					spawn,		    		{.v = ranger } },
	{ Super,		      	 40,	 /* d */					spawn, 			    	{.v = dmenucmd } },
	{ Alt,         	  	 36,	 /* Return */			spawn,     		    {.v = terminal } },
	{ Alt,               56,	 /* b */					togglebar,      	{0} },
	{ Alt,               44,	 /* j */					focusstack, 	    {.i = +1 } },
	{ Alt,               45,	 /* k */					focusstack, 	    {.i = -1 } },
	{ 0,								166,	 /* pg right */   incnmaster,				{.i = +1 } },
	{ 0,							  167,   /* pg left */    incnmaster,				{.i = -1 } },
	{ Alt,               31,	 /* i */					incnmaster, 	    {.i = +1 } },
	{ Alt,               40,	 /* d */					incnmaster, 	    {.i = -1 } },
	{ Alt,               43,	 /* h */					setmfact,   	    {.f = -0.05} },
	{ Alt,               46,	 /* l */					setmfact,   	    {.f = +0.05} },
	{ Alt|ShiftMask,     36,	 /* Return */			zoom,           	{0} },
	{ Alt,               23,	 /* Tab */				view,           	{0} },
	{ Alt,	          	 24,	 /* q */					killclient,     	{0} },
	{ Alt,               28,	 /* t */					setlayout,      	{.v = &layouts[0]} },
	{ Alt,               41,	 /* f */ 					setlayout,      	{.v = &layouts[1]} },
	{ Alt,               58,	 /* m */					setlayout,      	{.v = &layouts[2]} },
	{ Alt|ShiftMask,     65,	 /* Space */			togglefloating, 	{0} },
	{ Alt,               19,	 /* 0 */ 					view,           	{.ui = ~0 } },
	{ Alt|ShiftMask,     19,	 /* 0 */					tag,            	{.ui = ~0 } },
	{ Alt,               59,	 /* , */					focusmon,       	{.i = -1 } },
	{ Alt,               60,	 /* . */					focusmon,       	{.i = +1 } },
	{ Alt|ShiftMask,     59,	 /* , */					tagmon,         	{.i = -1 } },
	{ Alt|ShiftMask,     60,	 /* . */					tagmon,         	{.i = +1 } },
	{ Alt|ShiftMask,     24,	 /* q */					quit,           	{0} },

	{ 0,								 107,	 /* PrtSc */		  spawn,						{.v = scrot } },
	{ 0,				         156,  /* Vantage */		spawn,					  {.v = slock } },
	{ 0,				         123,	 /* Volume - */		spawn,					  {.v = volup } }, 
	{ 0,				         122,  /* Volume + */		spawn,					  {.v = voldown } },
	{ 0,				         198,  /* Mute */				spawn,					  {.v = volmute } },


	TAGKEYS(             10,										0)
	TAGKEYS(             11,										1)
	TAGKEYS(             12,										2)
	TAGKEYS(             13,										3)
	TAGKEYS(             14,										4)
	TAGKEYS(             15,										5)
	TAGKEYS(             16,										6)
	TAGKEYS(             17,										7)
	TAGKEYS(             18,										8)	


};


// Button Definitions
/* This defines the behavior of something when it is clicked */
static Button buttons[] = {

	/* click            event mask     button        function        argument */

	{ ClkLtSymbol,      0,             Button1,      setlayout,      {0} },
	{ ClkLtSymbol,      0,             Button3,      setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,      0,             Button2,      zoom,           {0} },
	{ ClkStatusText,    0,             Button2,      spawn,          {.v = terminal } },
	{ ClkClientWin,     Alt,           Button1,      movemouse,      {0} },
	{ ClkClientWin,     Alt,           Button2,      togglefloating, {0} },
	{ ClkClientWin,     Alt,           Button3,      resizemouse,    {0} },
	{ ClkTagBar,        0,             Button1,      view,           {0} },
	{ ClkTagBar,        0,             Button3,      toggleview,     {0} },
	{ ClkTagBar,        Alt,           Button1,      tag,            {0} },
	{ ClkTagBar,        Alt,           Button3,      toggletag,      {0} },
};
