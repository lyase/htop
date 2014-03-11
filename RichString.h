/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_RichString
#define HEADER_RichString
/*
htop - RichString.h
(C) 2004,2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#define RICHSTRING_MAXLEN 300

#include "config.h"
#include <ctype.h>

#include <assert.h>
#ifdef HAVE_NCURSESW_CURSES_H
#include <ncursesw/curses.h>
#elif HAVE_NCURSES_NCURSES_H
#include <ncurses/ncurses.h>
#elif HAVE_NCURSES_CURSES_H
#include <ncurses/curses.h>
#elif HAVE_NCURSES_H
#include <ncurses.h>
#elif HAVE_CURSES_H
#include <curses.h>
#endif

#define RichString_size(htop_this) ((htop_this)->chlen)
#define RichString_sizeVal(htop_this) ((htop_this).chlen)

#define RichString_begin(htop_this) RichString (htop_this); (htop_this).chlen = 0; (htop_this).chptr = (htop_this).chstr;
#define RichString_beginAllocated(htop_this) (htop_this).chlen = 0; (htop_this).chptr = (htop_this).chstr;
#define RichString_end(htop_this) RichString_prune(&(htop_this));

#ifdef HAVE_LIBNCURSESW
#define RichString_printVal(htop_this, y, x) mvadd_wchstr(y, x, (htop_this).chptr)
#define RichString_printoffnVal(htop_this, y, x, off, n) mvadd_wchnstr(y, x, (htop_this).chptr + off, n)
#define RichString_getCharVal(htop_this, i) ((htop_this).chptr[i].chars[0] & 255)
#define RichString_setChar(htop_this, at, ch) do{ (htop_this)->chptr[(at)].chars[0] = ch; } while(0)
#define CharType cchar_t
#else
#define RichString_printVal(htop_this, y, x) mvaddchstr(y, x, (htop_this).chptr)
#define RichString_printoffnVal(htop_this, y, x, off, n) mvaddchnstr(y, x, (htop_this).chptr + off, n)
#define RichString_getCharVal(htop_this, i) ((htop_this).chptr[i])
#define RichString_setChar(htop_this, at, ch) do{ (htop_this)->chptr[(at)] = ch; } while(0)
#define CharType chtype
#endif

typedef struct RichString_ {
   int chlen;
   CharType chstr[RICHSTRING_MAXLEN+1];
   CharType* chptr;
} RichString;


#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#define charBytes(n) (sizeof(CharType) * (n))

#ifdef HAVE_LIBNCURSESW

extern void RichString_setAttrn(RichString* htop_this, int attrs, int start, int finish);

int RichString_findChar(RichString* htop_this, char c, int start);

#else

void RichString_setAttrn(RichString* htop_this, int attrs, int start, int finish)
{
extern      chtype* ch;
extern      for (int i;
extern           *ch;
          ch++;
     }
}

int RichString_findChar(RichString* htop_this, char c, int start);

#endif

void RichString_prune(RichString* htop_this);

void RichString_setAttr(RichString* htop_this, int attrs);

void RichString_append(RichString* htop_this, int attrs, const char* data);

void RichString_appendn(RichString* htop_this, int attrs, const char* data, int len);

void RichString_write(RichString* htop_this, int attrs, const char* data);

#endif
