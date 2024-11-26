// AddObject.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "AddObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddObject dialog


CAddObject::CAddObject(CWnd* pParent /*=NULL*/)
	: CDialog(CAddObject::IDD, pParent)
{   m_pDBASE=NULL;
	//{{AFX_DATA_INIT(CAddObject)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAddObject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddObject)
	DDX_Control(pDX, IDC_COMBO1, m_Com);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddObject, CDialog)
	//{{AFX_MSG_MAP(CAddObject)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddObject message handlers

void CAddObject::OnAdd() 
{
	// TODO: Add your control notification handler code here
   CString m_string;
   if(m_Com.GetCurSel()==CB_ERR)
   {
	AfxMessageBox("һ��Ҫѡ���Ŀ");
	return;
   }
   else{
   m_Com.GetLBText(m_Com.GetCurSel(),m_string);
   CString SqlCmd;
   CDaoTableDefInfo tabInfo;
   int nTableDefCount = m_pDBASE->GetTableDefCount();
	for (int i = 0; i < nTableDefCount; i++)
	{
		m_pDBASE->GetTableDefInfo(i,tabInfo);
		if (tabInfo.m_lAttributes & dbSystemObject)
			continue;
	    SqlCmd.Format("Alter Table %s Drop �ܳɼ�;",tabInfo.m_strName);
	    m_pDBASE->Execute(SqlCmd);
       SqlCmd.Format("Alter Table %s Drop ƽ���ɼ�;",tabInfo.m_strName);
	    m_pDBASE->Execute(SqlCmd);

        SqlCmd.Format("Alter Table %s Add %s REAL;",tabInfo.m_strName,m_string ); 
		m_pDBASE->Execute(SqlCmd);
       

       SqlCmd.Format("Alter Table %s Add �ܳɼ� REAL;",tabInfo.m_strName,m_string ); 
		m_pDBASE->Execute(SqlCmd);
       SqlCmd.Format("Alter Table %s Add ƽ���ɼ� REAL;",tabInfo.m_strName,m_string ); 
		m_pDBASE->Execute(SqlCmd);
	}
  
   SqlCmd.Format("%s��Ŀ����ɹ�",m_string);
   AfxMessageBox(SqlCmd);
   }
}

void CAddObject::GetSet(CDaoDatabase* pDB)
{
	m_pDBASE=pDB;
}

void CAddObject::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
