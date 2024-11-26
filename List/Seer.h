#if !defined(AFX_SEER_H__619FD118_A8D9_46AD_9050_564EDA5F20EF__INCLUDED_)
#define AFX_SEER_H__619FD118_A8D9_46AD_9050_564EDA5F20EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Seer.h : header file
//
#include "LinkButton.h"
/////////////////////////////////////////////////////////////////////////////
// CSeer dialog

class CSeer : public CDialog
{
// Construction
public:
	CSeer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSeer)
	enum { IDD = IDD_SER };
	CLinkButton	m_Can;
	CLinkButton	m_Ok;
	CComboBox	m_Com2;
	CComboBox	m_Com1;
	float	m_fEdit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSeer)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
CString m_str1,m_str2;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEER_H__619FD118_A8D9_46AD_9050_564EDA5F20EF__INCLUDED_)
