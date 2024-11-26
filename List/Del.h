#if !defined(AFX_DEL_H__A2C6AAE1_842C_4DB1_8E59_75C743C76739__INCLUDED_)
#define AFX_DEL_H__A2C6AAE1_842C_4DB1_8E59_75C743C76739__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Del.h : header file
//
#include "LinkButton.h"
/////////////////////////////////////////////////////////////////////////////
// CDel dialog

class CDel : public CDialog
{
// Construction
public:
	CDel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDel)
	enum { IDD = IDD_DEL };
	CLinkButton	m_Ok;
	CLinkButton	m_Can;
	long	m_xue;
	long	m_Pass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDel)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEL_H__A2C6AAE1_842C_4DB1_8E59_75C743C76739__INCLUDED_)
