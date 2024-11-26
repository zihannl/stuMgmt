// Seer.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "Seer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeer dialog


CSeer::CSeer(CWnd* pParent /*=NULL*/)
	: CDialog(CSeer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeer)
	m_fEdit = 0.0f;
	//}}AFX_DATA_INIT
}


void CSeer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeer)
	DDX_Control(pDX, IDCANCEL, m_Can);
	DDX_Control(pDX, IDOK, m_Ok);
	DDX_Control(pDX, IDC_COMBO2, m_Com2);
	DDX_Control(pDX, IDC_COMBO1, m_Com1);
	DDX_Text(pDX, IDC_EDIT1, m_fEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSeer, CDialog)
	//{{AFX_MSG_MAP(CSeer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeer message handlers

void CSeer::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
    m_Com1.GetLBText(m_Com1.GetCurSel(),m_str1);
    m_Com2.GetLBText(m_Com2.GetCurSel(),m_str2);
  	CDialog::OnOK();
}

BOOL CSeer::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Com1.SetCurSel(0);
	m_Com2.SetCurSel(1);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
