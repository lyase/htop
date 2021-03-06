/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_CategoriesPanel
#define HEADER_CategoriesPanel
/*
htop - CategoriesPanel.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Panel.h"
#include "Settings.h"
#include "ScreenManager.h"

typedef struct CategoriesPanel_ {
   Panel super;

   Settings* settings;
   ScreenManager* scr;
} CategoriesPanel;


void CategoriesPanel_makeMetersPage(CategoriesPanel* htop_this);

extern PanelClass CategoriesPanel_class;

CategoriesPanel* CategoriesPanel_new(Settings* settings, ScreenManager* scr);

#endif
