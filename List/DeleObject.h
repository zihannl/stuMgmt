#if !defined(AFX_DELEOBJECT_H__E7024D37_7312_4FD3_BA7F_363053E6178C__INCLUDED_)
#define AFX_DELEOBJECT_H__E7024D37_7312_4FD3_BA7F_363053E6178C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleObject.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleObject dialog

class CDeleObject : public CDialog
{
// Construction
public:
	CDeleObject(CWnd* pParent = NULL);   // standard constructor
    void GetSet(CDaoDatabase * pDB);  
    void Bind(long a,long b,CString str);
// Dialog Data
	//{{AFX_DATA(CDeleObject)
	enum { IDD = IDD_DELEOBJECT };
	CComboBox	m_Com;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleObject)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleObject)
	afx_msg void OnDele();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDaoDatabase * m_pDBASE;
	CDaoRecordset* m_pSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELEOBJECT_H__E7024D37_7312_4FD3_BA7F_363053E6178C__INCLUDED_)
