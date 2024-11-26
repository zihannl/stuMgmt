// DisDialog.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "DisDialog.h"
#include "ListDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisDialog dialog


CDisDialog::CDisDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDisDialog::IDD, pParent)
{   m_pDBASE=NULL;
	//{{AFX_DATA_INIT(CDisDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDisDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisDialog)
	DDX_Control(pDX, IDC_COMBO1, m_Com);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDisDialog, CDialog)
	//{{AFX_MSG_MAP(CDisDialog)
	ON_BN_CLICKED(ID_DELE, OnDele)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisDialog message handlers

void CDisDialog::OnDele() 
{
	// TODO: Add your control notification handler code here
   CString m_string;
   int k=m_Com.GetCurSel();
   if(k==CB_ERR )
   {
	AfxMessageBox("一定要选择班级");
	return;
   }
   else{
   m_Com.GetLBText(k,m_string);
   CString SqlCmd;
   SqlCmd.Format("DROP TABLE %s;",m_string); 
   m_pDBASE->Execute(SqlCmd);
   SqlCmd.Format("%s删除成功",m_string);
   AfxMessageBox(SqlCmd);
   }
 CWnd *pWnd=CWnd::FindWindow(NULL,"学生成绩管理");
 int nIndex;
 while ((nIndex= ((CListDlg*) pWnd)->m_Com.FindString(nIndex, m_string)) != CB_ERR)
	{ 
     ((CListDlg*) pWnd)->m_Com.DeleteString(nIndex);
	}

}

void CDisDialog::GetSet(CDaoDatabase* pDB)
{
	m_pDBASE=pDB;
}

void CDisDialog::OnCancel() 
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}
