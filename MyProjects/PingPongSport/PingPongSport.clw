; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPingPongSportView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PingPongSport.h"
LastPage=0

ClassCount=7
Class1=CPingPongSportApp
Class2=CPingPongSportDoc
Class3=CPingPongSportView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDataProcess
Resource2=IDD_ABOUTBOX
Class7=CDlgPingPongParameterSet
Resource3=IDD_PingPongParameterSet

[CLS:CPingPongSportApp]
Type=0
HeaderFile=PingPongSport.h
ImplementationFile=PingPongSport.cpp
Filter=N

[CLS:CPingPongSportDoc]
Type=0
HeaderFile=PingPongSportDoc.h
ImplementationFile=PingPongSportDoc.cpp
Filter=N

[CLS:CPingPongSportView]
Type=0
HeaderFile=PingPongSportView.h
ImplementationFile=PingPongSportView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MENUITEMParameterSet


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEMStart




[CLS:CAboutDlg]
Type=0
HeaderFile=PingPongSport.cpp
ImplementationFile=PingPongSport.cpp
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
Command18=ID_MENUITEMStop
Command19=ID_MENUITEMParameterSet
CommandCount=19

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

[CLS:CDataProcess]
Type=0
HeaderFile=DataProcess.h
ImplementationFile=DataProcess.cpp
BaseClass=generic CWnd
Filter=W

[DLG:IDD_PingPongParameterSet]
Type=1
Class=CDlgPingPongParameterSet
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ZbX,edit,1350631552
Control12=IDC_Zby,edit,1350631552
Control13=IDC_ZbZ,edit,1350631552
Control14=IDC_SdX,edit,1350631552
Control15=IDC_SdY,edit,1350631552
Control16=IDC_SdZ,edit,1350631552

[CLS:CDlgPingPongParameterSet]
Type=0
HeaderFile=DlgPingPongParameterSet.h
ImplementationFile=DlgPingPongParameterSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgPingPongParameterSet

