#if !defined(AFX_ADDOBJECT_H__7C763D1A_CF83_4EF5_BB65_16C94F93D814__INCLUDED_)
#define AFX_ADDOBJECT_H__7C763D1A_CF83_4EF5_BB65_16C94F93D814__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddObject.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddObject dialog

class CAddObject : public CDialog
{
// Construction
public:
	CAddObject(CWnd* pParent = NULL);   // standard constructor
    void GetSet(CDaoDatabase* pDB);
// Dialog Data
	//{{AFX_DATA(CAddObject)
	enum { IDD = IDD_ADDOBJECT };
	CComboBox	m_Com;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddObject)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddObject)
	afx_msg void OnAdd();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDaoDatabase* m_pDBASE;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDOBJECT_H__7C763D1A_CF83_4EF5_BB65_16C94F93D814__INCLUDED_)
