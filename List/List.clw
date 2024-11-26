; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdd
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "List.h"

ClassCount=11
Class1=CListApp
Class2=CListDlg
Class3=CAboutDlg

ResourceCount=13
Resource1=IDD_ADDOBJECT
Resource2=IDR_MAINFRAME
Resource3=IDD_DELEOBJECT
Resource4=IDD_ADD
Resource5=IDD_DISDIALOG
Class4=CCreateDialog
Resource6=IDD_CREATDIALOG
Class5=CDisDialog
Resource7=IDD_SER
Class6=CAddObject
Resource8=IDD_ADDDIALOG
Class7=CDeleObject
Resource9=IDD_ABOUTBOX
Class8=CAdd
Resource10=IDD_LIST_DIALOG
Class9=CDel
Resource11=IDD_DEL
Resource12=IDD_EDIT
Class10=CEditDialog
Class11=CSeer
Resource13=IDR_MENU1

[CLS:CListApp]
Type=0
HeaderFile=List.h
ImplementationFile=List.cpp
Filter=N

[CLS:CListDlg]
Type=0
HeaderFile=ListDlg.h
ImplementationFile=ListDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT

[CLS:CAboutDlg]
Type=0
HeaderFile=ListDlg.h
ImplementationFile=ListDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIST_DIALOG]
Type=1
Class=CListDlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1342242817
Control2=IDC_COMBO1,combobox,1344339971
Control3=IDC_STRAT,button,1342242827
Control4=IDC_ADD,button,1342242827
Control5=IDC_DELE,button,1342242827
Control6=IDC_EDIT,button,1342242827
Control7=IDC_SERCH,button,1342242827
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ALL,button,1342242827

[DLG:IDD_ADDDIALOG]
Type=1
Class=?
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT4,edit,1350631552

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_ADDBUT
Command2=ID_DELEBUT
Command3=ID_ADDOBJCET
Command4=ID_DELEOBJECT
CommandCount=4

[DLG:IDD_CREATDIALOG]
Type=1
Class=CCreateDialog
ControlCount=4
Control1=ID_CREATE,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_STATIC,static,1342308352

[CLS:CCreateDialog]
Type=0
HeaderFile=CreateDialog.h
ImplementationFile=CreateDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CCreateDialog
VirtualFilter=dWC

[DLG:IDD_DISDIALOG]
Type=1
Class=CDisDialog
ControlCount=4
Control1=ID_DELE,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_STATIC,static,1342308352

[CLS:CDisDialog]
Type=0
HeaderFile=DisDialog.h
ImplementationFile=DisDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDCANCEL
VirtualFilter=dWC

[DLG:IDD_ADDOBJECT]
Type=1
Class=CAddObject
ControlCount=4
Control1=ID_ADD,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO1,combobox,1344339971

[CLS:CAddObject]
Type=0
HeaderFile=AddObject.h
ImplementationFile=AddObject.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddObject

[DLG:IDD_DELEOBJECT]
Type=1
Class=CDeleObject
ControlCount=4
Control1=ID_DELE,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_STATIC,static,1342308352

[CLS:CDeleObject]
Type=0
HeaderFile=DeleObject.h
ImplementationFile=DeleObject.cpp
BaseClass=CDialog
Filter=D
LastObject=CDeleObject
VirtualFilter=dWC

[DLG:IDD_ADD]
Type=1
Class=CAdd
ControlCount=26
Control1=ID_ADD,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_STATIC,static,1342308352
Control4=IDC_XUE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NAME,edit,1350631552
Control7=IDC_STATIC1,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_STATIC2,static,1342308352
Control11=IDC_STATIC3,static,1342308352
Control12=IDC_STATIC4,static,1342308352
Control13=IDC_EDIT3,edit,1350631552
Control14=IDC_EDIT4,edit,1350631552
Control15=IDC_EDIT5,edit,1350631552
Control16=IDC_STATIC5,static,1342308352
Control17=IDC_EDIT6,edit,1350631552
Control18=IDC_STATIC6,static,1342308352
Control19=IDC_EDIT7,edit,1350631552
Control20=IDC_STATIC7,static,1342308352
Control21=IDC_STATIC8,static,1342308352
Control22=IDC_EDIT8,edit,1350631552
Control23=IDC_STATIC9,static,1342308352
Control24=IDC_EDIT9,edit,1350631552
Control25=IDC_STATIC10,static,1342308352
Control26=IDC_EDIT10,edit,1350631552

[CLS:CAdd]
Type=0
HeaderFile=Add.h
ImplementationFile=Add.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT3
VirtualFilter=dWC

[DLG:IDD_DEL]
Type=1
Class=CDel
ControlCount=6
Control1=IDOK,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631584
Control6=IDC_STATIC,static,1342308352

[CLS:CDel]
Type=0
HeaderFile=Del.h
ImplementationFile=Del.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDel

[DLG:IDD_SER]
Type=1
Class=CSeer
ControlCount=6
Control1=IDOK,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_COMBO2,combobox,1344339971
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_EDIT]
Type=1
Class=CEditDialog
ControlCount=26
Control1=ID_EDIT,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350633600
Control6=IDC_EDIT2,edit,1350633600
Control7=IDC_STATIC1,static,1342308352
Control8=IDC_STATIC2,static,1342308352
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_EDIT4,edit,1350631552
Control11=IDC_STATIC3,static,1342308352
Control12=IDC_EDIT5,edit,1350631552
Control13=IDC_EDIT6,edit,1350631552
Control14=IDC_STATIC4,static,1342308352
Control15=IDC_EDIT7,edit,1350631552
Control16=IDC_STATIC5,static,1342308352
Control17=IDC_EDIT8,edit,1350631552
Control18=IDC_STATIC6,static,1342308352
Control19=IDC_EDIT9,edit,1350631552
Control20=IDC_STATIC7,static,1342308352
Control21=IDC_EDIT10,edit,1350631552
Control22=IDC_STATIC8,static,1342308352
Control23=IDC_STATIC9,static,1342308352
Control24=IDC_EDIT11,edit,1350631552
Control25=IDC_STATIC10,static,1342308352
Control26=IDC_EDIT12,edit,1350631552

[CLS:CEditDialog]
Type=0
HeaderFile=EditDialog.h
ImplementationFile=EditDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CEditDialog
VirtualFilter=dWC

[CLS:CSeer]
Type=0
HeaderFile=Seer.h
ImplementationFile=Seer.cpp
BaseClass=CDialog
Filter=D
LastObject=CSeer
VirtualFilter=dWC

