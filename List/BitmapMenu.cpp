#include "List.h"
#include <afxwin.h>
#include <afxcmn.h>
#include <afxtempl.h>
#include <BitmapMenu.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BMenuData::BMenuData()
{
	menuIconNormal = -1;
	menuIconSelected = -1;
	menuIconDisabled = -1;
	nID = 0;
}

CBitmapMenu::CBitmapMenu(CImageList* pList)
{
	SetImageList(pList);

	m_clrText =  GetSysColor(COLOR_MENUTEXT);
	m_clrBack = GetSysColor(COLOR_MENU);

	m_brBackground.CreateSolidBrush(m_clrBack);
	m_penBack.CreatePen(PS_SOLID,0,m_clrBack);

	m_bLBtnDown = FALSE;
	m_hilightStyle = Normal;
	m_clrHilight = GetSysColor(COLOR_HIGHLIGHT);
	m_brSelect.CreateSolidBrush(m_clrHilight);
	m_clrHilightText = GetSysColor(COLOR_HIGHLIGHTTEXT);
	ZeroMemory((LPVOID)&m_lf,sizeof(LOGFONT));
	
	NONCLIENTMETRICS nm;

	nm.cbSize = sizeof(NONCLIENTMETRICS);

	//Get the system metrics for the Captionfromhere

	VERIFY(SystemParametersInfo(SPI_GETNONCLIENTMETRICS,0,&nm,0)); 
	m_lf =	nm.lfMenuFont;
	m_iMenuHeight = nm.iMenuHeight;
	m_fontMenu.CreateFontIndirect(&m_lf);
}

CBitmapMenu::~CBitmapMenu()
{
	DestroyMenu();
}

BOOL CBitmapMenu::DestroyMenu()
{
	// Destroy Sub menus:
	int m;
	
	for( m = m_SubMenus.GetUpperBound(); m >= 0; m-- )
		delete(m_SubMenus[m]);
	m_SubMenus.RemoveAll();
	
	// Destroy brushes:
	if( (HBRUSH)m_brBackground != NULL )
		m_brBackground.DeleteObject();
	if( (HFONT)m_fontMenu != NULL )
		m_fontMenu.DeleteObject();
	if( (HBRUSH)m_brSelect != NULL )
		m_brSelect.DeleteObject ();

	// Destroy menu data
	int numItems;
	
	numItems = m_MenuList.GetUpperBound();
	for( m = 0; m <= numItems; m++ )
		delete(m_MenuList[m]);
	m_MenuList.RemoveAll();

	// Call base-class implementation last:
	return(CMenu::DestroyMenu());
}

/*
=================================================================================
void CBitmapMenu::DrawItem(LPDRAWITEMSTRUCT)
---------------------------------------
Called by the framework when a particular item needs to be drawn.  We overide
this to draw the menu item in a custom-fashion, including icons and the 3D
rectangle bar.
=================================================================================
*/
void CBitmapMenu::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	ASSERT(lpDIS != NULL);

	CDC* pDC;
	
	pDC = CDC::FromHandle(lpDIS->hDC);
	
	CRect rect;
	HICON hIcon;

	COLORREF clrText;

	clrText = m_clrText;
	
	// draw the colored rectangle portion		
	rect.CopyRect(&lpDIS->rcItem);
	
	// draw the up/down/focused/disabled state
	UINT action;
	UINT state;
	
	action = lpDIS->itemAction;
	state = lpDIS->itemState;

	CString strText;
	LOGFONT lf;
	
	lf = m_lf;
	
	CFont dispFont;
	CFont *pFont;

	if( lpDIS->itemData != NULL )
	{
		int nIconNormal = (((BMenuData*)(lpDIS->itemData))->menuIconNormal);
		int nIconSelected = (((BMenuData*)(lpDIS->itemData))->menuIconSelected);
		int nIconDisabled = (((BMenuData*)(lpDIS->itemData))->menuIconDisabled);

		strText = (((BMenuData*)(lpDIS->itemData))->menuText);

		if(nIconNormal == -1)
			hIcon = NULL;
		else
		{
			hIcon = NULL;

			// Obtain the IDs for the appropriate Icons:
			if( state & ODS_SELECTED && !(state & ODS_GRAYED) )
			{
				// Selected (but not disabled)
				if( nIconSelected != -1 )
					hIcon = m_pList->ExtractIcon(nIconSelected);
			}
			else
			{
				if( state & ODS_GRAYED )
					// Disabled (selected or not)
					if( nIconDisabled != -1 )
						hIcon = m_pList->ExtractIcon(nIconDisabled);
			}
			// If we didn't manage to select a specific icon, we'll use the
			// default (normal) one...
			if( hIcon == NULL )
				hIcon = m_pList->ExtractIcon(nIconNormal);
		}
	}
	else
	{
		strText.Empty();
		hIcon = NULL;
	}

	if( (state & ODS_SELECTED) )
	{
		// draw the down edges
		CPen *pOldPen = pDC->SelectObject(&m_penBack);

		// You need only Text highlight and thats what you get
		if( m_hilightStyle != Normal )
			pDC->FillRect(rect,&m_brBackground);
		else
			pDC->FillRect(rect,&m_brSelect);

		pDC->SelectObject(pOldPen);

		// This version provides a black-border:
		//pDC->Draw3dRect(rect,GetSysColor (COLOR_3DHILIGHT),RGB(0,0,0));
		//lf.lfWeight = FW_BOLD;
		if( (HFONT)dispFont != NULL )
			dispFont.DeleteObject();

		dispFont.CreateFontIndirect(&lf);
		clrText = m_clrHilightText;
	}
	else
	{
		CPen *pOldPen = pDC->SelectObject(&m_penBack);
		pDC->FillRect (rect,&m_brBackground);
		pDC->SelectObject (pOldPen);
		
		// draw the up edges
		pDC->Draw3dRect (rect,m_clrBack,m_clrBack);
		if( (HFONT)dispFont != NULL )
			dispFont.DeleteObject();

		dispFont.CreateFontIndirect(&lf);
	}

	// draw the text if there is any
	//We have to paint the text only if the image is nonexistant

	if (hIcon != NULL)
		DrawIconEx(pDC->GetSafeHdc(), rect.left,
					rect.top + (rect.Height() - m_nIconY) / 2, hIcon,
					m_nIconX, m_nIconY, 0, NULL, DI_NORMAL);

	rect.left = rect.left + m_nIconX + 2;

	if( !strText.IsEmpty() )
	{
		int iOldMode = pDC->GetBkMode();
		
		pDC->SetBkMode(TRANSPARENT);

		// Draw the text in the correct colour:
		UINT nFormat = DT_LEFT|DT_SINGLELINE|DT_EXPANDTABS|DT_VCENTER;

		if( !(lpDIS->itemState & ODS_GRAYED) )
		{
			pDC->SetTextColor(clrText);
			pDC->DrawText (strText,rect,nFormat);
		}
		else
		{
			// Draw the slightly lighter greyed text at an offset:
			RECT offset = *rect;

			offset.left += 1;
			offset.right += 1;
			offset.top += 1;
			offset.bottom += 1;

			pDC->SetTextColor(GetSysColor(COLOR_BTNHILIGHT));
			pDC->DrawText(strText,&offset, nFormat);

			// And the standard Grey text:
			pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT));
			pDC->DrawText(strText,rect, nFormat);
		}

		pFont = pDC->SelectObject(&dispFont);
		pDC->SetBkMode(iOldMode);
		pDC->SelectObject(pFont); //set it to the old font
	}
	dispFont.DeleteObject();
}

/*
	=================================================================================
	void CBitmapMenu::MeasureItem(LPMEASUREITEMSTRUCT)
	---------------------------------------------
	Called by the framework when it wants to know what the width and height of our
	item will be.  To accomplish this we provide the width of the icon plus the
	width of the menu text, and then the height of the icon.
	=================================================================================
*/
void CBitmapMenu::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{
	// Obtain the width of the text:
	CWnd *pWnd = AfxGetMainWnd();						// Get main window
	CDC *pDC = pWnd->GetDC();							// Get device context
	CFont* pFont = pDC->SelectObject(&m_fontMenu);		// Select menu font in...
	LPCTSTR lpstrText = (((BMenuData*)(lpMIS->itemData))->menuText);	// Get pointer to text

	SIZE t;

	GetTextExtentPoint32(pDC->GetSafeHdc(), lpstrText, strlen(lpstrText), &t); // Width of caption

	pDC->SelectObject(pFont);		// Select old font in
	pWnd->ReleaseDC(pDC);			// Release the DC

	lpMIS->itemWidth = t.cx;
	lpMIS->itemHeight = max(GetSystemMetrics(SM_CYMENU), t.cy);

	lpMIS->itemWidth += m_nIconX;
	lpMIS->itemHeight = max(m_nIconY, lpMIS->itemHeight);
}

void CBitmapMenu::SetTextColor(COLORREF clrText)
{
	m_clrText = clrText;
}

void CBitmapMenu::SetBackColor(COLORREF clrBack)
{
	m_clrBack = clrBack;

	if( (HBRUSH)m_brBackground != NULL )
		m_brBackground.DeleteObject();
	m_brBackground.CreateSolidBrush (clrBack);
}

void CBitmapMenu::SetHighlightColor(COLORREF clrHilight)
{
	m_clrHilight = clrHilight;

	if( (HBRUSH)m_brSelect != NULL )
		m_brSelect.DeleteObject();
	m_brSelect.CreateSolidBrush(clrHilight);
}

void CBitmapMenu::SetHighlightTextColor(COLORREF clrHilightText)
{
	m_clrHilightText = clrHilightText;
}

void CBitmapMenu::SetHighlightStyle(HIGHLIGHTSTYLE hilightStyle)
{
	m_hilightStyle = hilightStyle;
}

void CBitmapMenu::SetImageList(CImageList* pList)
{
	m_pList = pList;

	if( m_pList != NULL )
	{
		IMAGEINFO info;;

		m_pList->GetImageInfo(0, &info);
		m_nIconX = info.rcImage.right - info.rcImage.left;
		m_nIconY = info.rcImage.bottom - info.rcImage.top;
	}
	else
	{
		m_nIconX = 0;
		m_nIconY = 0;
	}
}

/*
	=================================================================================
	BOOL CBitmapMenu::AppendODMenu(LPCTSTR, UINT, UINT, UINT, UINT)
	BOOL CBitmapMenu::ModifyODMenu(LPCTSTR, UINT, UINT, UINT, UINT)
	----------------------------------------------------------
	These 2 functions effectively replace the CMenu::AppendMenu() and CMenu::ModifyMenu()
	classes, with support for 3 icon states.  When using Owner-drawn menu items,
	use these functions instead of the usual ones.
	=================================================================================
*/
BOOL CBitmapMenu::AppendMenu(UINT nFlags,
							  UINT nID,
							  LPCTSTR lpstrText,
							  int nIconNormal,
							  int nIconSelected,
							  int nIconDisabled)
{
	if( (nFlags & MF_OWNERDRAW) != 0 || nIconNormal != -1 )
	{
		nFlags |= MF_OWNERDRAW;

		BMenuData *mdata = new BMenuData;
		m_MenuList.Add(mdata);

		lstrcpy(mdata->menuText, lpstrText);
		mdata->menuIconNormal = nIconNormal;
		mdata->menuIconSelected = nIconSelected;
		mdata->menuIconDisabled = nIconDisabled;
		return CMenu::AppendMenu(nFlags, nID, (LPCTSTR)mdata);
	}

	return CMenu::AppendMenu(nFlags, nID, lpstrText);
}

BOOL CBitmapMenu::ModifyODMenu(LPCTSTR lpstrText,
							  UINT nID,
							  int nIconNormal,
							  int nIconSelected,
							  int nIconDisabled)
{
	// Delete the existing BMenuData structure associated with this item (if any)
	int numMenuItems = m_MenuList.GetUpperBound();
	BMenuData *mdata;

	for( int m = 0; m <= numMenuItems; m++ )
	{
		if( (mdata = m_MenuList[m]) != NULL )
		{
			if( mdata->nID == nID )
			{
				delete(mdata);
				m_MenuList.RemoveAt(m);
				break;
			}
		}
	}
	
	// Create a new BMenuData structure:
	mdata = new BMenuData;
	m_MenuList.Add(mdata);

	lstrcpy(mdata->menuText, lpstrText);
	mdata->menuIconNormal = nIconNormal;
	mdata->menuIconSelected = nIconSelected;
	mdata->menuIconDisabled = nIconDisabled;

	return CMenu::ModifyMenu(nID, MF_BYCOMMAND | MF_OWNERDRAW, nID, (LPCTSTR)mdata);
}

BOOL CBitmapMenu::LoadMenu(LPCTSTR lpszResourceName)
{
	return CBitmapMenu::LoadMenu(MAKEINTRESOURCE(lpszResourceName));
}

BOOL CBitmapMenu::LoadMenu(int nResource)
{
	// Find the Menu Resource:
	DWORD dwSize;
	WORD wrd = MAKEWORD(nResource, 0);

	HRSRC hRsrc = FindResource(NULL, (LPCTSTR)wrd, RT_MENU);

	// Find the resource
	if( hRsrc == NULL )
	{
		TRACE0("CBitmapMenu::LoadMenu() - Failed to find Menu Resource\n");
		ASSERT(FALSE);
	}

	// Get size of resource:
	dwSize = SizeofResource(NULL, hRsrc);

	// Load the Menu Resource:
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
	if( hGlobal == NULL )
	{
		TRACE0("CBitmapMenu::LoadMenu() - Failed to load Menu Resource\n");
		ASSERT(FALSE);
	}
	// Attempt to create us as a menu...
	if( !CMenu::CreateMenu() )
	{
		TRACE0("CBitmapMenu::LoadMenu() - Failed to create Menu\n");
		ASSERT(FALSE);
	}
	// Get Item template Header, and calculate offset of MENUITEMTEMPLATES
	MENUITEMTEMPLATEHEADER* pTpHdr = (MENUITEMTEMPLATEHEADER*)LockResource(hGlobal);
	BYTE*					pTp   = (BYTE*)pTpHdr + 
									(sizeof(MENUITEMTEMPLATEHEADER) + pTpHdr->offset);

	// Variables needed during processing of Menu Item Templates:
	BMenuData*	pData = NULL;							// New OD Menu Item Data
	WORD		dwFlags = 0;							// Flags of the Menu Item
	WORD		dwID	= 0;							// ID of the Menu Item
	BOOL		bLastPopup = 0; 						// Last popup?
	UINT		uFlags; 								// Actual Flags.
	char		caption[80];							// Allows up to 80 chars for caption
	int 		nLen   = 0; 							// Length of caption
	CTypedPtrArray<CPtrArray, CBitmapMenu*> m_Stack;		// Popup menu stack

	m_Stack.Add(this);									// Add it to this...
	
	do
	{
		// Obtain Flags and (if necessary), the ID...
		memcpy(&dwFlags, pTp, sizeof(WORD));
		pTp+=sizeof(WORD);
		
		// Obtain Flags
		if( !(dwFlags & MF_POPUP) )
		{
			memcpy(&dwID, pTp, sizeof(WORD));
			// Obtain ID
			pTp += sizeof(WORD);
		}
		else
			dwID = 0;

		uFlags = (UINT)dwFlags; 		// Remove MF_END from the flags that will
		if( uFlags & MF_END )			// be passed to the Append(OD)Menu functions.
			uFlags -= MF_END;
		// Obtain Caption (and length)
		nLen = 0;

		char *ch = (char*)pTp;
		while( *ch != 0 )
		{
			caption[nLen] = ch[0];
			nLen++; 					// Increment length
			ch+=2;						// Accounts for UNICODE '0's...
		}

		caption[nLen] = 0;				// Zero-terminate the string...
		pTp += (nLen+1) * 2;				// Increase Pointer...
		
		// Handle popup menus first....
		if( dwFlags & MF_POPUP )
		{
			if( dwFlags & MF_END )
				bLastPopup = TRUE;

			CBitmapMenu* pSubMenu = new CBitmapMenu;
			
			pSubMenu->CreatePopupMenu();
			
			// Append it to the top of the stack:
			m_Stack[m_Stack.GetUpperBound()]->AppendMenu(uFlags, (UINT)pSubMenu->m_hMenu, caption);
			m_Stack.Add(pSubMenu);					// Add to PopupStack
			m_SubMenus.Add(pSubMenu);				// For deletion...
		}
		else
		{
			m_Stack[m_Stack.GetUpperBound()]->AppendMenu(uFlags, dwID, caption, -1, -1, -1);
			if( dwFlags & MF_END )
				m_Stack.RemoveAt(m_Stack.GetUpperBound());	// Remove top of stack
			if(bLastPopup)
			{
				bLastPopup = FALSE;
				m_Stack.RemoveAt(m_Stack.GetUpperBound());	// And again...
			}
		}
	}
	while( m_Stack.GetUpperBound() != -1 );
	return TRUE;
}
