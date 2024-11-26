// ListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "List.h"
#include "ListDlg.h"
#include "CreateDialog.h"
#include "DisDialog.h"
#include  "AddObject.h"
#include "DeleObject.h"
#include "Add.h"
#include "Del.h"
#include "Seer.h"
#include "EditDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog

CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListDlg::IDD, pParent)
{   m_pDB=NULL;
    nField=0;
    m_pRecordSet=NULL;
   m_bIsAsc=FALSE;
	//{{AFX_DATA_INIT(CListDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON3);

}

void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListDlg)
	DDX_Control(pDX, IDC_SERCH, m_Serch);
	DDX_Control(pDX, IDC_STRAT, m_Strat);
	DDX_Control(pDX, IDC_EDIT, m_Edit);
	DDX_Control(pDX, IDC_DELE, m_Dele);
	DDX_Control(pDX, IDC_ALL, m_All);
	DDX_Control(pDX, IDC_ADD, m_Add);
	DDX_Control(pDX, IDC_LIST1, m_List1);
	DDX_Control(pDX, IDC_COMBO1, m_Com);
	//}}AFX_DATA_MAP

}

BEGIN_MESSAGE_MAP(CListDlg, CDialog)
	//{{AFX_MSG_MAP(CListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_STRAT, OnStrat)
	ON_COMMAND(ID_DELEOBJECT, OnDeleobject)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_COMMAND(ID_ADDBUT, OnAddbut)
	ON_COMMAND(ID_DELEBUT, OnDelebut)
	ON_COMMAND(ID_ADDOBJCET, OnAddobjcet)
	ON_UPDATE_COMMAND_UI(ID_ADDOBJCET, OnUpdateAddobjcet)
	ON_UPDATE_COMMAND_UI(ID_DELEOBJECT, OnUpdateDeleobject)
	ON_UPDATE_COMMAND_UI(ID_ADDBUT, OnUpdateAddbut)
	ON_UPDATE_COMMAND_UI(ID_DELEBUT, OnUpdateDelebut)
	ON_BN_CLICKED(IDC_DELE, OnDele)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, OnColumnclickList1)
	ON_BN_CLICKED(IDC_ALL, OnAll)
	ON_BN_CLICKED(IDC_SERCH, OnSerch)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListDlg message handlers

BOOL CListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
   
	// Add "About..." menu item to system menu.
    SetWindowText("学生成绩管理");
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
   

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	GetDlgItem(IDC_STRAT)->EnableWindow(FALSE);
    this->Enable(FALSE);

	m_pDB=new CDaoDatabase;
	CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
	int nPos;
	nPos=sPath.ReverseFind ('\\');
	sPath=sPath.Left (nPos);
	nPos=sPath.ReverseFind('\\');
    sPath=sPath.Left (nPos);
	CString lpszFile = sPath + "\\db6.mdb";
	try{
		m_pDB->Open(lpszFile);
	}
	catch(CDaoException* e)
	{
		AfxMessageBox(e->m_pErrorInfo->m_strDescription,MB_ICONEXCLAMATION);
		delete m_pDB;
		e->Delete();
		return FALSE;
	}
    
    CDaoTableDefInfo tabInfo;
	int nTableDefCount = m_pDB->GetTableDefCount();
	for (int i = 0; i < nTableDefCount; i++)
	{
		m_pDB->GetTableDefInfo(i,tabInfo);
		if (tabInfo.m_lAttributes & dbSystemObject)
			continue;
		m_Com.AddString(tabInfo.m_strName);

	}
	m_pRecordSet=new CDaoRecordset(m_pDB);
    m_bTF=TRUE;
	m_bCR=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{CDialog::OnPaint();
	//	CPaintDC dc(this);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	CDC dcMem; 
	//	dcMem.CreateCompatibleDC(&dc); 
	//	BITMAP bitMap;
	//	m_Bitmap.GetBitmap(&bitMap);
	//	CBitmap *pbmpOld=dcMem.SelectObject(&m_Bitmap);
	//	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitMap.bmWidth,bitMap.bmHeight,SRCCOPY);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListDlg::OnClosebutton() 
{
	// TODO: Add your control notification handler code here
	m_pDB->Close();

	CDialog::OnCancel();
}

void CListDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
}

void CListDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString m_string;
    m_Com.GetLBText(m_Com.GetCurSel(),m_string);
	if(m_GetString!=m_string)
	GetDlgItem(IDC_STRAT)->EnableWindow(TRUE);
	this->Enable(FALSE);
}

void CListDlg::OnStrat() 
{  
	if(m_pRecordSet->IsOpen())
    m_pRecordSet->Close();
  
    m_List1.DeleteAllItems();
    if(nField!=0)
	{
	for(long i=0;i<nField;i++)
	{
	m_List1.DeleteColumn(0);
	} 
	}
    
	m_Com.GetLBText(m_Com.GetCurSel(),m_GetString);
	if(m_GetString=="关闭班级")
    {   
		m_bTF=TRUE;
	    m_bCR=FALSE;
		return ;
	}
	m_bTF=FALSE;
	m_bCR=TRUE;
	CString strSQL="SELECT * FROM " + m_GetString;

try{
		m_pRecordSet->Open(dbOpenDynaset, strSQL);
		m_pRecordSet->m_strFilter.Empty();
	}
	catch(CDaoException *e)
	{   
		AfxMessageBox(e->m_pErrorInfo->m_strDescription,MB_ICONEXCLAMATION);
		delete m_pRecordSet;
		m_pDB->Close();
		delete m_pDB;
		e->Delete();
		return ;
	}
	 
	if(m_pRecordSet != NULL)
	{
		m_pImageList = new CImageList();
		m_pImageList->Create(IDB_BITMAP4, 16, 1, RGB(255,0,0));
		m_List1.SetImageList(m_pImageList, LVSIL_SMALL);	/* set extended stlyes*/
		
		DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | /*LVS_EX_SUBITEMIMAGES |*/
		m_List1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);						LVS_EX_HEADERDRAGDROP | LVS_EX_TRACKSELECT;

		LV_COLUMN lvColumn;
		lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
		lvColumn.fmt = LVCFMT_LEFT;	lvColumn.cx = 67;
	    nField=m_pRecordSet->GetFieldCount();
		for(int i = 0; i < nField; i++) // set up columns
		{    
			CDaoFieldInfo m_fieldinfo;
			m_pRecordSet->GetFieldInfo(i, m_fieldinfo);//get field name
			int len = m_fieldinfo.m_strName.GetLength();
			CString temp = m_fieldinfo.m_strName;
			TCHAR* szBuffer = new TCHAR[len + 1];
			strcpy(szBuffer, temp.GetBuffer(len));
			temp.ReleaseBuffer();
			lvColumn.pszText = szBuffer;
		    m_List1.InsertColumn(i, &lvColumn);//insert column		
			delete szBuffer;
		}
		/*set number of items in ListView*/
		m_pRecordSet->MoveFirst();
		m_pRecordSet->MoveLast();
        long count =m_pRecordSet->GetRecordCount();//Get number of records
	
        this->OnGetdispinfoList( count, nField);
	
	}
	GetDlgItem(IDC_STRAT)->EnableWindow(FALSE);
	this->Enable(TRUE);
}

void CListDlg::OnGetdispinfoList(long row,long column) 
{  
   
	if(!m_pRecordSet)
	return;
    COleVariant varValue;
	for(long i=0;i<row;i++)
	{	
		try
		{
	    m_pRecordSet->SetAbsolutePosition(i);//Set the file to desired index

		}
		catch(CDaoException* e)
		{
		AfxMessageBox(e->m_pErrorInfo->m_strDescription, 
				    MB_ICONEXCLAMATION );
		e->Delete();
		return;
		}
	
    	for(long j=0;j<column;j++)
		{   
		try	{
	   	     if(j)	
			 m_pRecordSet->GetFieldValue(j, varValue);
		   	 else
			 m_pRecordSet->GetFieldValue(0, varValue);
		}
		catch(CDaoException* e)
		{
			AfxMessageBox(e->m_pErrorInfo->m_strDescription, 
				    MB_ICONEXCLAMATION );
			e->Delete();
			return;
		}
	

		const VARIANT* variant = LPCVARIANT(varValue);
		
		if(variant->vt & VT_BYREF)
			return;
		CString st;
		switch(variant->vt)
		{  
			case VT_ERROR:{	
							st="Error";					
							break;
						  }
			case VT_I2:{ 	
				            st.Format("%d", variant->iVal);
							break;
					   }
			case VT_I4:{ 
				           st.Format( "%d", variant->lVal);
							break;
					   }
			case VT_R4:{   
						   st.Format( "%.2f", variant->fltVal);
                           
						    break;}
					
			case VT_R8:{	st.Format( "%.2f", variant->dblVal);
							break;
					   }
			case VT_CY:{	COleCurrency c(varValue);
						   st = c.Format();//ie. 1.00
							break;
					   }
			case VT_DATE:{	COleDateTime t(variant->date);
							st = t.Format( "%B %d, %Y" );//Day of Week, Month Day, Year
							
							break;
						 }
			case VT_BSTR:{   st = V_BSTRT( &varValue );//convert BSTR to CString
							
							break;
						}
			case VT_BOOL:{	if(variant->boolVal)
							st="TRUE";
							else
								st= "FALSE";
							break;
						 }
			case VT_UI1:{st=(CString)((char*)variant->bVal);
							break;
						}

				default:{
							
							break;
						}

		}
      if(j==0)		
      m_List1.InsertItem(i,st,0);
      else
      m_List1.SetItemText(i,j,st);
		}
    

  	
}
}

void CListDlg::Enable(BOOL b)
{
	GetDlgItem(IDC_ADD)->EnableWindow(b);
	GetDlgItem(IDC_DELE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT)->EnableWindow(b);
	GetDlgItem(IDC_DELE)->EnableWindow(b);
	GetDlgItem(IDC_ALL)->EnableWindow(b);
    GetDlgItem(IDC_SERCH)->EnableWindow(b);

}



void CListDlg::OnDeleobject() 
{
	// TODO: Add your control notification handler code here
	CDeleObject dlg;
	dlg.GetSet(m_pDB);
	dlg.DoModal();


}

void CListDlg::OnAdd() 
{   
	if(m_pRecordSet->IsOpen())
	{
	m_pRecordSet->m_strFilter.Empty();
	m_pRecordSet->Close();
	} 
    CString strSQL="SELECT * FROM " + m_GetString;
    m_pRecordSet->Open(dbOpenDynaset, strSQL);
	CAdd dlg;
	dlg.GetSet(m_pRecordSet,m_pDB,nField,m_GetString);
	dlg.DoModal();
	this->OnStrat();

}

void CListDlg::OnAddbut() 
{
	// TODO: Add your command handler code here
  CCreateDialog dlg;
  dlg.GetSet(m_pDB,m_pRecordSet,nField);
  dlg.DoModal();	
  
}

void CListDlg::OnDelebut() 
{
	// TODO: Add your command handler code here
	CDisDialog dlg;
	dlg.GetSet(m_pDB);
	dlg.DoModal();
}

void CListDlg::OnAddobjcet() 
{
	// TODO: Add your command handler code here
    
	CAddObject dlg;
	dlg.GetSet(m_pDB);
	dlg.DoModal();
}

void CListDlg::OnUpdateAddobjcet(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	pCmdUI->Enable(m_bTF);
}

void CListDlg::OnUpdateDeleobject(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bTF);
}

void CListDlg::OnUpdateAddbut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bCR);
}

void CListDlg::OnUpdateDelebut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bTF);
}

void CListDlg::OnDele() 
{
	// TODO: Add your control notification handler code here
	CDel dlg;
if(m_pRecordSet->IsOpen())
{
	m_pRecordSet->m_strFilter.Empty();
	m_pRecordSet->Close();
} 
  CString strSQL="SELECT * FROM " + m_GetString;
  m_pRecordSet->Open(dbOpenDynaset, strSQL);
	
	if(dlg.DoModal()==IDOK)
	{
	 
     
	if(dlg.m_Pass!=1234)
	AfxMessageBox("密码不正确!你没有权限删除记录");
    else
	{
		m_pRecordSet->m_strFilter.Format("[学号]=%d",dlg.m_xue);
	    m_pRecordSet->Requery();
		if(m_pRecordSet->IsEOF())
		{AfxMessageBox("没有此人");
		return;}
		else 
		{	m_pRecordSet->Delete();
          m_pRecordSet->m_strFilter.Empty();
         this->OnStrat();
		}
	}

}
}
void CListDlg::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;  
    	
	   
	CDaoFieldInfo m_fieldinfo;
			
	    
	    switch ( pNMListView -> iSubItem ) {
		case 0:
			LoadSortList ( CString ( "[学号]" ) );
			break;
		case 1:
			LoadSortList ( CString ( "[姓名]" ) );
			break;
		case 2:
           m_pRecordSet->GetFieldInfo(2, m_fieldinfo);
			LoadSortList ( CString ( m_fieldinfo.m_strName ) );
			break;
		case 3:
          m_pRecordSet->GetFieldInfo(3, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
			break;
		case 4:
			m_pRecordSet->GetFieldInfo(4, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
			break;
		case 5:
		m_pRecordSet->GetFieldInfo(5, m_fieldinfo);
		LoadSortList ( CString (m_fieldinfo.m_strName ) );
		break;
		case 6:
           m_pRecordSet->GetFieldInfo(6, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
			break;
	     case 7:
           m_pRecordSet->GetFieldInfo(7, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
			break;
case 8:
           m_pRecordSet->GetFieldInfo(8, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
	       break;
	  case 9:
           m_pRecordSet->GetFieldInfo(9, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
	       break; 
case 10:
           m_pRecordSet->GetFieldInfo(10, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
	       break;
case 11:
           m_pRecordSet->GetFieldInfo(11, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
	       break;
case 12:
           m_pRecordSet->GetFieldInfo(12, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
           break;
case 13:
           m_pRecordSet->GetFieldInfo(13, m_fieldinfo);
			LoadSortList ( CString (m_fieldinfo.m_strName ) );
	       break;	      
		   
		default:
			LoadSortList ( CString ( "" ) ); // default: no sort.
			break;
	}
	
	
	*pResult = 0;
}
void CListDlg::LoadSortList ( CString& strSortBy )
{
	// clear out the listbox
	m_List1.DeleteAllItems ();
	if(m_bIsAsc)
	{
		m_pRecordSet->m_strSort=strSortBy+" ASC";
       m_bIsAsc=FALSE;
	}
	else
	{
		m_pRecordSet->m_strSort=strSortBy+" DESC";
		m_bIsAsc=TRUE;
	}

	this->OnStrat();
}

void CListDlg::OnAll() 
{
	// TODO: Add your control notification handler code here
	this->OnStrat();
}

void CListDlg::OnSerch() 
{
	// TODO: Add your control notification handler code here
CSeer dlg;
  
if( dlg.DoModal()==IDOK)
{ 
m_pRecordSet->m_strFilter.Format("[%s]%s%.2f",dlg.m_str1,dlg.m_str2,dlg.m_fEdit);

m_List1.DeleteAllItems();
try
{m_pRecordSet->Requery();}
catch(CDaoException *e)
	{   
		AfxMessageBox(e->m_pErrorInfo->m_strDescription,MB_ICONEXCLAMATION);
	    m_pRecordSet->m_strFilter.Empty();
		e->Delete();
		return ;}
if(m_pRecordSet->IsEOF())
{ 
 AfxMessageBox("没有符合条件的记录");

 return ;
 }
else
{      
	m_pRecordSet->MoveLast();
    long count =m_pRecordSet->GetRecordCount();
    this->OnGetdispinfoList( count, nField);
}
m_pRecordSet->m_strFilter.Empty();
}
}

void CListDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	CEditDialog dlg;
	dlg.GetSet(m_pRecordSet,m_pDB,nField,m_GetString);
    COleVariant varValue;
	int nItemIndex = -1;

	if ( ( m_List1.GetNextItem ( -1, LVNI_SELECTED ) ) != -1 ) {
		
			while ( ( nItemIndex = m_List1.GetNextItem ( nItemIndex, LVNI_SELECTED ) ) != -1 ) {
				    m_pRecordSet->m_strFilter =
					CString ( "[学号] = " ) +
					CString ( m_List1.GetItemText ( nItemIndex, 0 ) ); // put the ID into the query string
				    m_pRecordSet->Requery();
		         	for(long j=0;j<nField-2;j++)
					{ m_pRecordSet->GetFieldValue(j, varValue);
		   		     const VARIANT* variant = LPCVARIANT(varValue);
		              if(variant->vt & VT_BYREF)
                      return;
					  else
					  { 
						  switch(variant->vt)
		
						  {  
		
                        case VT_I4:{ 
				           dlg.m_xue=variant->lVal;
							break;
					   }
			
						  case VT_R4:{ 
							  if(j==2&&j<nField-2)
							  dlg.m_f1=variant->fltVal;
							  if(j==3&&j<nField-2)
							  dlg.m_f2=variant->fltVal;
                              if(j==4&&j<nField-2)
							  dlg.m_f3=variant->fltVal;
                              if(j==5&&j<nField-2)
							  dlg.m_f4=variant->fltVal;
                              if(j==6&&j<nField-2)
							  dlg.m_f5=variant->fltVal;
                              if(j==7&&j<nField-2)
							  dlg.m_f6=variant->fltVal;
                              if(j==8&&j<nField-2)
							  dlg.m_f7=variant->fltVal;
                              if(j==9&&j<nField-2)
							  dlg.m_f8=variant->fltVal;
                              if(j==10&&j<nField-2)
							   dlg.m_f9=variant->fltVal;
                               if(j==11&&j<nField-2)
							  dlg.m_f10=variant->fltVal;
							   break;
									 }
       	case VT_BSTR:{  dlg.m_strName = V_BSTRT( &varValue );//convert BSTR to CString
							
							break;
						}
						  }
                 
						  }

					  }
				 dlg.DoModal();	
}
	}
	m_pRecordSet->m_strFilter.Empty();
	this->OnStrat();
}
	
