// Del.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "Del.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDel dialog


CDel::CDel(CWnd* pParent /*=NULL*/)
	: CDialog(CDel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDel)
	m_xue = 0;
	m_Pass = 0;
	//}}AFX_DATA_INIT
}


void CDel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDel)
	DDX_Control(pDX, IDOK, m_Ok);
	DDX_Control(pDX, IDCANCEL, m_Can);
	DDX_Text(pDX, IDC_EDIT1, m_xue);
	DDX_Text(pDX, IDC_EDIT2, m_Pass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDel, CDialog)
	//{{AFX_MSG_MAP(CDel)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDel message handlers
