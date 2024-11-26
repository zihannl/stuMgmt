// ListDlg.h : header file
//

#if !defined(AFX_LISTDLG_H__AAE370E1_A32D_4DB8_AE94_4CCD96B1D1E9__INCLUDED_)
#define AFX_LISTDLG_H__AAE370E1_A32D_4DB8_AE94_4CCD96B1D1E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LinkButton.h"
/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog

class CListDlg : public CDialog
{
// Construction
public:
	CListDlg(CWnd* pParent = NULL);	// standard constructor
    void Enable(BOOL b);
void LoadSortList ( CString& strSortBy );
public:

   CString m_GetString;
// Dialog Data
	//{{AFX_DATA(CListDlg)
	enum { IDD = IDD_LIST_DIALOG };
	CLinkButton	m_Serch;
	CLinkButton	m_Strat;
	CLinkButton	m_CreatButton;
	CLinkButton	m_Edit;
	CLinkButton	m_Dele;
	CLinkButton	m_All;
	CLinkButton	m_Add;
	CComboBox	m_CreatBox;
	CListCtrl	m_List1;
	CComboBox	m_Com;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	public:
void OnGetdispinfoList(long row, long column);
// Implementation
private:
CMenu m_Menu;
protected:
	HICON m_hIcon;
    CBitmap m_Bitmap;
	CDaoDatabase* m_pDB;
	CDaoRecordset* m_pRecordSet;
    CImageList* m_pImageList;
    BOOL m_bTF,m_bCR;
    long nField;
BOOL m_bIsAsc;
	// Generated message map functions
	//{{AFX_MSG(CListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClosebutton();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnStrat();
	afx_msg void OnCreatbutton();
	afx_msg void OnAddbutton();
	afx_msg void OnDeleobject();
	afx_msg void OnAdd();
	afx_msg void OnAddbut();
	afx_msg void OnDelebut();
	afx_msg void OnAddobjcet();
	afx_msg void OnUpdateAddobjcet(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDeleobject(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddbut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelebut(CCmdUI* pCmdUI);
	afx_msg void OnDele();
	afx_msg void OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAll();
	afx_msg void OnSerch();
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTDLG_H__AAE370E1_A32D_4DB8_AE94_4CCD96B1D1E9__INCLUDED_)
