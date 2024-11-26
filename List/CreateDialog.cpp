// CreateDialog.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "CreateDialog.h"
#include "ListDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreateDialog dialog


CCreateDialog::CCreateDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateDialog::IDD, pParent)
{  m_pDBASE=NULL;
m_pSet=NULL;
	//{{AFX_DATA_INIT(CCreateDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCreateDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDialog)
	DDX_Control(pDX, IDC_COMBO1, m_Com);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCreateDialog, CDialog)
	//{{AFX_MSG_MAP(CCreateDialog)
	ON_BN_CLICKED(ID_CREATE, OnCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateDialog message handlers

void CCreateDialog::OnCreate() 
{ 
  CString m_string;
   int k=m_Com.GetCurSel();
   if(k==CB_ERR )
   {
	AfxMessageBox("一定要选择班级");
	return;
   }
else
{       m_Com.GetLBText(k,m_string); 
        CString SqlCmd;
      switch(m_nField)
	  {  
	  case 5:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1); 
        m_pDBASE->Execute(SqlCmd);
		break;
	  case 6:
      SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2); 
        m_pDBASE->Execute(SqlCmd);
		break;
      case 7:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3); 
        m_pDBASE->Execute(SqlCmd);
		break;
     case 8:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4); 
        m_pDBASE->Execute(SqlCmd);
		break;
   case 9:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4,str5); 
        m_pDBASE->Execute(SqlCmd);
		break;
case 10:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4,str5,str6); 
        m_pDBASE->Execute(SqlCmd);
		break;
case 11:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4,str5,str6,str7); 
        m_pDBASE->Execute(SqlCmd);
case 12:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4,str5,str6,str7,str8); 
		AfxMessageBox(SqlCmd);
        m_pDBASE->Execute(SqlCmd);
		break;	
case 13:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4,str5,str6,str7,str8,str9); 
		AfxMessageBox(SqlCmd);
        m_pDBASE->Execute(SqlCmd);
case 14:
        SqlCmd.Format("CREATE TABLE %s(学号 INTEGER ,姓名 VARCHAR(10) ,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,%s REAL,总成绩 REAL,平均成绩 REAL );",m_string,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10); 
		AfxMessageBox(SqlCmd);
        m_pDBASE->Execute(SqlCmd);
		break;			break;	

	default:
		break;
	  }
   SqlCmd.Format("INSERT INTO %s(姓名) VALUES('')",m_string);
    m_pDBASE->Execute(SqlCmd);
   SqlCmd.Format("%s创建成功",m_string);
   AfxMessageBox(SqlCmd);
   }
 CWnd *pWnd=CWnd::FindWindow(NULL,"学生成绩管理");
((CListDlg*) pWnd)->m_Com.AddString(m_string);
}
void CCreateDialog::GetSet(CDaoDatabase *pDB,CDaoRecordset* pSet,long n)
{
   m_pDBASE=pDB;
   m_pSet=pSet;
   m_nField=n;
  
}

void CCreateDialog::OnCancel() 
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}

void CCreateDialog::Set()
{  long gk=m_nField-4;
   long i;
   CDaoFieldInfo m_fieldinfo;
		switch(gk)
		{
		case 1:
    	for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		str1=temp;
		}
		break;
		case 2:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		}
		break;
	  case 3:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		}
		break;
      case 4:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		}
		break;
case 5:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		if(i==6)
			str5=temp;
		}
		break;
case 6:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		if(i==6)
			str5=temp;
		if(i==7)
			str6=temp;
		}
		break;
case 7:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		if(i==6)
			str5=temp;
		if(i==7)
			str6=temp;
		if(i==8)
			str7=temp;
		}
		break;
case 8:
	    
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		if(i==6)
		str5=temp;
		if(i==7)
			str6=temp;
		if(i==8)
			str7=temp;
		if(i==9)
			str8=temp;
		}
		break;

case 9:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		if(i==6)
			str5=temp;
		if(i==7)
			str6=temp;
		if(i==8)
			str7=temp;
		if(i==9)
			str8=temp;
		if(i==10)
			str9=temp;
		}
		break;
case 10:
		for( i = 2; i <m_nField-2; i++) // set up columns
		{  
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
		if(i==2)
		str1=temp;
		if(i==3)
		str2=temp;
		if(i==4)
		str3=temp;
		if(i==5)
		str4=temp;
		if(i==6)
			str5=temp;
		if(i==7)
			str6=temp;
		if(i==8)
			str7=temp;
		if(i==9)
			str8=temp;
		if(i==10)
			str9=temp;
		if(i==11)
			str10=temp;
		}
	break;
	default:
		break;		
		}
		}

BOOL CCreateDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->Set();
	m_pSet->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
