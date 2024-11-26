// DeleObject.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "DeleObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleObject dialog


CDeleObject::CDeleObject(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleObject::IDD, pParent)
{  m_pSet=NULL;
  	m_pDBASE=NULL;
	//{{AFX_DATA_INIT(CDeleObject)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDeleObject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleObject)
	DDX_Control(pDX, IDC_COMBO1, m_Com);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleObject, CDialog)
	//{{AFX_MSG_MAP(CDeleObject)
	ON_BN_CLICKED(ID_DELE, OnDele)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleObject message handlers

void CDeleObject::OnDele() 
{
	// TODO: Add your control notification handler code here
  CString m_string;
  if(m_Com.GetCurSel()==CB_ERR)
   {
	AfxMessageBox("一定要选择科目");
	return;
   }
   else{
   m_Com.GetLBText(m_Com.GetCurSel(),m_string);
   CString SqlCmd;
   m_pSet=new CDaoRecordset(m_pDBASE);
   CDaoTableDefInfo tabInfo;
   int nTableDefCount = m_pDBASE->GetTableDefCount();
	for (int i = 0; i < nTableDefCount; i++)
	{   if(m_pSet->IsOpen())
	     m_pSet->Close();
		m_pDBASE->GetTableDefInfo(i,tabInfo);
		if (tabInfo.m_lAttributes & dbSystemObject)
		continue;
	    SqlCmd.Format("Alter Table %s Drop %s;",tabInfo.m_strName,m_string);
	    m_pDBASE->Execute(SqlCmd);
	    CString strSQL="SELECT * FROM " + tabInfo.m_strName;
	
	    m_pSet->Open(dbOpenDynaset, strSQL);
	    m_pSet->MoveFirst();
		m_pSet->MoveLast();
        long count =m_pSet->GetRecordCount();
        long nField=m_pSet->GetFieldCount();
		this->Bind(count,nField,tabInfo.m_strName);
	}
	
  m_pSet->Close();
    SqlCmd.Format("%s科目删除成功",m_string);
    AfxMessageBox(SqlCmd);

}

}
void CDeleObject::GetSet(CDaoDatabase *pDB)
{ 
	m_pDBASE=pDB;
}

void CDeleObject::OnCancel() 
{
 // m_pDBASE->Close();
  //if(m_pSet->IsOpen())
  //  m_pSet->Close();
	CDialog::OnCancel();
}
void CDeleObject::Bind(long a,long b,CString str)
{  float sum;
   float ave;
   COleVariant varValue;
	for(long i=0;i<a;i++)
	{	 sum=0;
         ave=0;
	    m_pSet->SetAbsolutePosition(i);//Set the file to desired index
		for(long j=2;j<b-2;j++)    
		{
		m_pSet->GetFieldValue(j, varValue);
		const VARIANT* variant = LPCVARIANT(varValue);
		if(variant->vt & VT_BYREF)
	 	return;
       switch(variant->vt)
	   {  case VT_R4:   
				     sum+=variant->fltVal;  
					 break;
           default:
					break;
			}
    
	}
ave=sum/(float)(b-4);
	 CString str;
	 str.Format("%f",sum);

	m_pSet->Edit();
	m_pSet->SetFieldValue(b-2,(LPCTSTR)str);
	m_pSet->Update();
	str.Format("%f",ave);
	m_pSet->Edit();
	m_pSet->SetFieldValue(b-1,(LPCTSTR)str);
	m_pSet->Update();
	}
}