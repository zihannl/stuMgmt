#if !defined(AFX_DISDIALOG_H__42A9FA8D_4CFA_4CBB_88E3_68B7086C7F10__INCLUDED_)
#define AFX_DISDIALOG_H__42A9FA8D_4CFA_4CBB_88E3_68B7086C7F10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDisDialog dialog

class CDisDialog : public CDialog
{
// Construction
public:
	CDisDialog(CWnd* pParent = NULL);   // standard constructor
    void GetSet(CDaoDatabase* pDB);
// Dialog Data
	//{{AFX_DATA(CDisDialog)
	enum { IDD = IDD_DISDIALOG };
	CComboBox	m_Com;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDisDialog)
	afx_msg void OnDele();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDaoDatabase* m_pDBASE;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISDIALOG_H__42A9FA8D_4CFA_4CBB_88E3_68B7086C7F10__INCLUDED_)
