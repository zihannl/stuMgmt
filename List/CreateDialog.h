#if !defined(AFX_CREATEDIALOG_H__C7F544A5_770F_4796_A5E6_1D3520139060__INCLUDED_)
#define AFX_CREATEDIALOG_H__C7F544A5_770F_4796_A5E6_1D3520139060__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CreateDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCreateDialog dialog

class CCreateDialog : public CDialog
{
// Construction
public:
	CCreateDialog(CWnd* pParent = NULL);   // standard constructor
    void GetSet(CDaoDatabase * pDB,CDaoRecordset* pSet,long n);
	void Set();
// Dialog Data
	//{{AFX_DATA(CCreateDialog)
	enum { IDD = IDD_CREATDIALOG };
	CComboBox	m_Com;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCreateDialog)
	afx_msg void OnCreate();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDaoDatabase * m_pDBASE;
    CDaoRecordset* m_pSet;
	long m_nField;
	CString str1,str2,str3,str4,str5,str6,str7,str8,str9,str10;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDIALOG_H__C7F544A5_770F_4796_A5E6_1D3520139060__INCLUDED_)
