// EditDialog.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "EditDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDialog dialog


CEditDialog::CEditDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDialog)
	m_f1 = 0.0f;
	m_f2 = 0.0f;
	m_f3 = 0.0f;
	m_f4 = 0.0f;
	m_f5 = 0.0f;
	m_f6 = 0.0f;
	m_f7 = 0.0f;
	m_f8 = 0.0f;
	m_f9 = 0.0f;
	m_f10 = 0.0f;
	m_xue = 0;
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CEditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDialog)
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, ID_EDIT, m_Edit);
	DDX_Text(pDX, IDC_EDIT3, m_f1);
	DDV_MinMaxFloat(pDX, m_f1, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT4, m_f2);
	DDV_MinMaxFloat(pDX, m_f2, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT5, m_f3);
	DDV_MinMaxFloat(pDX, m_f3, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT6, m_f4);
	DDV_MinMaxFloat(pDX, m_f4, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT7, m_f5);
	DDV_MinMaxFloat(pDX, m_f5, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT8, m_f6);
	DDV_MinMaxFloat(pDX, m_f6, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT9, m_f7);
	DDV_MinMaxFloat(pDX, m_f7, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT10, m_f8);
	DDV_MinMaxFloat(pDX, m_f8, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT11, m_f9);
	DDV_MinMaxFloat(pDX, m_f9, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT12, m_f10);
	DDV_MinMaxFloat(pDX, m_f10, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT1, m_xue);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDialog, CDialog)
	//{{AFX_MSG_MAP(CEditDialog)
	ON_BN_CLICKED(ID_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDialog message handlers
void CEditDialog::Set()
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

BOOL CEditDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->Set();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CEditDialog::GetSet(CDaoRecordset* pSet,CDaoDatabase* pDB,long n,CString str)
{
	m_pSet=pSet;
	m_pDB=pDB;
	m_nField=n;
	m_GetString=str;
}

void CEditDialog::OnEdit() 
{
 this->UpdateData(TRUE);
  
  float sum=0;
  float avege=0;
  CString SqlCmd;
  
 switch(m_nField)
  {
 case 5:
  sum=m_f1;
  avege=sum;
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);;
  break;
 case 6:
  sum=m_f1+m_f2;
  avege=sum/(float)(m_nField-4);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
 case 7:
  sum=m_f1+m_f2+m_f3;
  avege=sum/(float)(m_nField-4);
  //SqlCmd.Format("UPDATE  %s  (SET %s=%f AND SET %s=%f AND SET %s=%f AND SET 总成绩=%f AND SET 平均成绩=%f  )WHERE 学号=%d",m_GetString ,str1,m_f1,str2,m_f2,str3,m_f3,sum,avege,m_xue);
 // AfxMessageBox(SqlCmd);
 // m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 8:
  sum=m_f1+m_f2+m_f3+m_f4;
  avege=sum/(float)(m_nField-4);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 9:
 sum=m_f1+m_f2+m_f3+m_f4+m_f5;
  avege=sum/(float)(m_nField-4);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str5,m_f5,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 10:
 sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f6;
  avege=sum/(float)(m_nField-4);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str5,m_f5,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str6,m_f6,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 11:
 sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str5,m_f5,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str6,m_f6,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str7,m_f7,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 12:
  sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7+m_f8;
  SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str5,m_f5,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str6,m_f6,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str7,m_f7,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str8,m_f8,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 13:
  sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7+m_f8+m_f9;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str5,m_f5,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str6,m_f6,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str7,m_f7,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str8,m_f8,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str9,m_f9,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
case 14:
  sum=m_f1+m_f2+m_f3+m_f4+m_f5+m_f7+m_f8+m_f9+m_f10;
  avege=sum/(float)(m_nField-4);
  SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str1,m_f1,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str2,m_f2,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str3,m_f3,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str4,m_f4,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str5,m_f5,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str6,m_f6,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str7,m_f7,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str8,m_f8,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str9,m_f9,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET %s=%f   WHERE 学号=%d",m_GetString ,str10,m_f10,m_xue);
 m_pDB->Execute(SqlCmd);
 SqlCmd.Format("UPDATE  %s  SET 总成绩=%f   WHERE 学号=%d",m_GetString ,sum,m_xue);
 m_pDB->Execute(SqlCmd);
SqlCmd.Format("UPDATE  %s  SET 平均成绩=%f   WHERE 学号=%d",m_GetString ,avege,m_xue);
 m_pDB->Execute(SqlCmd);
  break;
default:
	break;
  }
 AfxMessageBox("修改成功");
 CDialog::OnOK();
 
}
