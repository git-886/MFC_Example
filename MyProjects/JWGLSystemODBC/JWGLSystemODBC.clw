; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CJWGLSystemODBCView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "JWGLSystemODBC.h"
LastPage=0

ClassCount=6
Class1=CJWGLSystemODBCApp
Class2=CJWGLSystemODBCDoc
Class3=CJWGLSystemODBCView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CJWGLSystemODBCSet
Resource7=IDD_JWGLSYSTEMODBC_FORM

[CLS:CJWGLSystemODBCApp]
Type=0
HeaderFile=JWGLSystemODBC.h
ImplementationFile=JWGLSystemODBC.cpp
Filter=N

[CLS:CJWGLSystemODBCDoc]
Type=0
HeaderFile=JWGLSystemODBCDoc.h
ImplementationFile=JWGLSystemODBCDoc.cpp
Filter=N

[CLS:CJWGLSystemODBCView]
Type=0
HeaderFile=JWGLSystemODBCView.h
ImplementationFile=JWGLSystemODBCView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CJWGLSystemODBCView


[CLS:CJWGLSystemODBCSet]
Type=0
HeaderFile=JWGLSystemODBCSet.h
ImplementationFile=JWGLSystemODBCSet.cpp
Filter=N

[DB:CJWGLSystemODBCSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[sid], 4, 4
Column2=[sage], 4, 4
Column3=[snmae], 12, 255
Column4=[spro], 12, 255
Column5=[sclass], 12, 255
Column6=[ssex], 12, 255


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=JWGLSystemODBC.cpp
ImplementationFile=JWGLSystemODBC.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_JWGLSYSTEMODBC_FORM]
Type=1
Class=CJWGLSystemODBCView
ControlCount=18
Control1=IDC_BUTInsert,button,1342242816
Control2=IDC_BUTUpdate,button,1342242816
Control3=IDC_BUTDelete,button,1342242816
Control4=IDC_BUTQuery,button,1342242816
Control5=IDC_BUTClear,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ID,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_SEX,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_Name,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_PRO,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_AGE,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_CLASS,edit,1350631552
Control18=IDC_LIST1,listbox,1352728835

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

