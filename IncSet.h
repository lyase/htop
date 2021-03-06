/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_IncSet
#define HEADER_IncSet
/*
htop - IncSet.h
(C) 2005-2012 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/


#include "FunctionBar.h"
#include "Panel.h"
#include <stdbool.h>

#define INCMODE_MAX 40

typedef enum {
   INC_SEARCH = 0,
   INC_FILTER = 1
} IncType;

#define IncSet_filter(inc_) (inc_->filtering ? inc_->modes[INC_FILTER].buffer : NULL)

typedef struct IncMode_ {
   char buffer[INCMODE_MAX];
   int index;
   FunctionBar* bar;
   bool isFilter;
} IncMode;

typedef struct IncSet_ {
   IncMode modes[2];
   IncMode* active;
   FunctionBar* bar;
   FunctionBar* defaultBar;
   bool filtering;
} IncSet;

typedef const char* (*IncMode_GetPanelValue)(Panel*, int);


IncSet* IncSet_new(FunctionBar* bar);

void IncSet_delete(IncSet* htop_this);

bool IncSet_handleKey(IncSet* htop_this, int ch, Panel* panel, IncMode_GetPanelValue getPanelValue, Vector* lines);

const char* IncSet_getListItemValue(Panel* panel, int i);

void IncSet_activate(IncSet* htop_this, IncType type);

void IncSet_drawBar(IncSet* htop_this);

#endif
