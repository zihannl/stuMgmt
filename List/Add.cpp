// Add.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "Add.h"
#include "ListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdd dialog


CAdd::CAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CAdd::IDD, pParent)
{  m_pSet=NULL;
   m_nField=0;
   m_pDB=NULL;
   m_GetString="";
	//{{AFX_DATA_INIT(CAdd)
	m_f1 = 0.0f;
	m_f2 = 0.0f;
	m_f3 = 0.0f;
	m_f4 = 0.0f;
	m_f5 = 0.0f;
	m_f6 = 0.0f;
	m_xue = 0;
	m_strName = _T("");
	m_f7 = 0.0f;
	m_f8 = 0.0f;
	m_f9 = 0.0f;
	m_f10 = 0.0f;
	//}}AFX_DATA_INIT
}


void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdd)
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, ID_ADD, m_Add);
	DDX_Text(pDX, IDC_EDIT1, m_f1);
	DDX_Text(pDX, IDC_EDIT2, m_f2);
	DDV_MinMaxFloat(pDX, m_f2, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT3, m_f3);
	DDV_MinMaxFloat(pDX, m_f3, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT4, m_f4);
	DDV_MinMaxFloat(pDX, m_f4, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT5, m_f5);
	DDV_MinMaxFloat(pDX, m_f5, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT6, m_f6);
	DDV_MinMaxFloat(pDX, m_f6, 0.f, 100.f);
	DDX_Text(pDX, IDC_XUE, m_xue);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT7, m_f7);
	DDV_MinMaxFloat(pDX, m_f7, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT8, m_f8);
	DDV_MinMaxFloat(pDX, m_f8, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT9, m_f9);
	DDV_MinMaxFloat(pDX, m_f9, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT10, m_f10);
	DDV_MinMaxFloat(pDX, m_f10, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdd, CDialog)
	//{{AFX_MSG_MAP(CAdd)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdd message handlers



BOOL CAdd::OnInitDialog() 
{
	
	this->Set();



	CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CAdd::GetSet(CDaoRecordset* pSet,CDaoDatabase* pDB,long n,CString str)
{
	m_pSet=pSet;
	m_pDB=pDB;
	m_nField=n;
	m_GetString=str;
}

void CAdd::Set()
{  for(int i = 2; i <m_nField-2; i++) // set up columns
	{    
		CDaoFieldInfo m_fieldinfo;
		m_pSet->GetFieldInfo(i, m_fieldinfo);//get field name
		CString temp = m_fieldinfo.m_strName;
	    if(i==2&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC1,temp);
		  str1=temp;
		}
		if(i==3&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC2,temp);
		str2=temp;
		}
	    if(i==4&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC3,temp);
		str3=temp;
		}
        if(i==5&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC4,temp);
		str4=temp;
		}
        if(i==6&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC5,temp);
		str5=temp;
		}
       if(i==7&&i<m_nField-2)
	   {SetDlgItemText(IDC_STATIC6,temp);
	   str6=temp;
	   }
         if(i==8&&i<m_nField-2)
		 {SetDlgItemText(IDC_STATIC7,temp);
		 str7=temp;
		 }
        if(i==9&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC8,temp);
		str8=temp;
		}
        if(i==10&&i<m_nField-2)
		{SetDlgItemText(IDC_STATIC9,temp);
		str9=temp;
		}
       if(i==11&&i<m_nField-2)
	   {SetDlgItemText(IDC_STATIC10,temp);
	   str10=temp;
	   }


		temp.ReleaseBuffer();
	
		}

}

void CAdd::OnAdd() 
{    
    
  this->UpdateData(TRUE);
  if(m_strName=="")
  { AfxMessageBox("必须填写姓名");
  return ;
  }
  float sum=0;
  float avege=0;
  CString SqlCmd;
  SqlCmd.Format("DELETE FROM %s WHERE 姓名=''",m_GetString);
  m_pDB->Execute(SqlCmd);
 switch(m_nField)
  {
 case 5:
  sum=m_f1;
  avege=sum;
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f)",
  m_GetString,str1,m_xue,m_strName,m_f1,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
 case 6:
  sum=m_f1+m_f2;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f)",
  m_GetString,str1,str2,m_xue,m_strName,m_f1,m_f2,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
 case 7:
  sum=m_f1+m_f2+m_f3;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,m_xue,m_strName,m_f1,m_f2,m_f3,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 8:
  sum=m_f1+m_f2+m_f3+m_f4;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 9:
 sum=m_f1+m_f2+m_f3+m_f4+m_f5;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,str5,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,m_f5,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 10:
 sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f6;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,str5,str6,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,m_f5,m_f6,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 11:
 sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,str5,str6,str7,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,m_f5,m_f6,m_f7,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 12:
  sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7+m_f8;
  avege=sum/(float)(m_nField-4);	
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,str5,str6,str7,str8,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,m_f5,m_f6,m_f7,m_f8,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 13:
  sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7+m_f8+m_f9;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,%s,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,str5,str6,str7,str8,str9,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,m_f5,m_f6,m_f7,m_f8,m_f9,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
case 14:
  sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7+m_f8+m_f9+m_f10;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("INSERT INTO %s(学号,姓名,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,总成绩,平均成绩)  VALUES(%d,'%s',%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f)",
  m_GetString,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,m_xue,m_strName,m_f1,m_f2,m_f3,m_f4,m_f5,m_f6,m_f7,m_f8,m_f9,m_f10,sum,avege);
  m_pDB->Execute(SqlCmd);
  break;
default:
	break;
  }
 AfxMessageBox("加入成功");
 m_xue=0;
 m_strName="";
 m_f1=m_f2=m_f3=m_f4=m_f5=m_f6=m_f7=m_f8=m_f9=m_f10=0;
 this->UpdateData(FALSE);
}
