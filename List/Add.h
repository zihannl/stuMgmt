#if !defined(AFX_ADD_H__E817383C_F77B_46BD_947A_A9C92CFC6288__INCLUDED_)
#define AFX_ADD_H__E817383C_F77B_46BD_947A_A9C92CFC6288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Add.h : header file
//
#include "LinkButton.h"
/////////////////////////////////////////////////////////////////////////////
// CAdd dialog

class CAdd : public CDialog
{
// Construction
public:
	CAdd(CWnd* pParent = NULL);   // standard constructor
    void GetSet(CDaoRecordset *pSet,CDaoDatabase* pDB,long n,CString str);
	void Set();
    
// Dialog Data
	//{{AFX_DATA(CAdd)
	enum { IDD = IDD_ADD };
	CLinkButton	m_Cancel;
	CLinkButton	m_Add;
	float	m_f1;
	float	m_f2;
	float	m_f3;
	float	m_f4;
	float	m_f5;
	float	m_f6;
	long	m_xue;
	CString	m_strName;
	float	m_f7;
	float	m_f8;
	float	m_f9;
	float	m_f10;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdd)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
CDaoRecordset *m_pSet;
CDaoDatabase *m_pDB;
long m_nField;
CString m_GetString;
CString str1,str2,str3,str4,str5,str6,str7,str8,str9,str10;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__E817383C_F77B_46BD_947A_A9C92CFC6288__INCLUDED_)
