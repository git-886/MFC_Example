; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpringSportView
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SpringSport.h"
LastPage=0

ClassCount=7
Class1=CSpringSportApp
Class2=CSpringSportDoc
Class3=CSpringSportView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDlgParameterSet
Class7=CSpringProcess
Resource3=IDD_ParameterSet

[CLS:CSpringSportApp]
Type=0
HeaderFile=SpringSport.h
ImplementationFile=SpringSport.cpp
Filter=N

[CLS:CSpringSportDoc]
Type=0
HeaderFile=SpringSportDoc.h
ImplementationFile=SpringSportDoc.cpp
Filter=N

[CLS:CSpringSportView]
Type=0
HeaderFile=SpringSportView.h
ImplementationFile=SpringSportView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CSpringSportView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=SpringSport.cpp
ImplementationFile=SpringSport.cpp
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

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_MENUITEMStart
Command18=ID_MENUITEMParameterSet
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_ParameterSet]
Type=1
Class=CDlgParameterSet
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_M,edit,1350631552
Control9=IDC_L0,edit,1350631552
Control10=IDC_L,edit,1350631552
Control11=IDC_K,edit,1350631552
Control12=IDC_Z,edit,1350631552

[CLS:CDlgParameterSet]
Type=0
HeaderFile=DlgParameterSet.h
ImplementationFile=DlgParameterSet.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgParameterSet
VirtualFilter=dWC

[CLS:CSpringProcess]
Type=0
HeaderFile=SpringProcess.h
ImplementationFile=SpringProcess.cpp
BaseClass=generic CWnd
Filter=W

