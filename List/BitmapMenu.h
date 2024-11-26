#include "StdAfx.h"
#ifndef __BITMAP_MENU_H__
#define __BITMAP_MENU_H__

class BMenuData
{
	public:
		BMenuData();
		char menuText[32];
		int menuIconNormal;
		int menuIconSelected;
		int menuIconDisabled;
		UINT nID;
};

typedef enum {Normal,TextOnly} HIGHLIGHTSTYLE;

class CBitmapMenu : public CMenu	// Derived from CMenu
{
	public:
		CBitmapMenu(CImageList* pList = NULL); 
		virtual ~CBitmapMenu();

	protected:
		CTypedPtrArray<CPtrArray, BMenuData*>	m_MenuList;	// Stores list of menu items 
		// When loading an owner-drawn menu using a Resource, CBitmapMenu must keep track of
		// the popup menu's that it creates. Warning, this list *MUST* be destroyed
		// last item first :)

		CTypedPtrArray<CPtrArray, CBitmapMenu*>	m_SubMenus;	// Stores list of sub-menus 

	public:
		virtual void DrawItem(LPDRAWITEMSTRUCT);		// Draw an item
		virtual void MeasureItem(LPMEASUREITEMSTRUCT);	// Measure an item

		void SetTextColor (COLORREF );	// Set the text color
		void SetBackColor (COLORREF);	// Set background color
		void SetHighlightColor (COLORREF);	// Set highlight Color
		void SetHighlightStyle (HIGHLIGHTSTYLE );	// Set Highlight style
		void SetHighlightTextColor (COLORREF);	// Set Highlight text color
		void SetImageList(CImageList* pList);


		BOOL AppendMenu(UINT nFlags, UINT nID = 0,
						LPCTSTR lpstrText = NULL, 
						int nIconNormal = -1,
						int nIconSelected = -1,
						int nIconDisabled = -1);	// Owner-Drawn Append 

		BOOL ModifyODMenu(LPCTSTR lpstrText,
							UINT nID = 0,
							int nIconNormal = -1,
							int nIconSelected = -1,
							int nIconDisabled = -1);	// Owner-Drawn Modify 

		virtual BOOL LoadMenu(LPCTSTR lpszResourceName);	// Load a menu
		virtual BOOL LoadMenu(int nResource);	// ... 

		virtual BOOL DestroyMenu();

	protected:
		COLORREF m_clrBack;
		COLORREF m_clrText;
		COLORREF m_clrHilight;
		COLORREF m_clrHilightText;

		LOGFONT m_lf;
		CFont m_fontMenu;

		UINT m_iMenuHeight;
		BOOL m_bLBtnDown;

		CImageList*	m_pList;

		UINT	m_nIconX;
		UINT	m_nIconY;

		CBrush m_brBackground,m_brSelect;
		CPen m_penBack;
		HIGHLIGHTSTYLE m_hilightStyle; 
};

#endif //__BITMAP_MENU_H__
