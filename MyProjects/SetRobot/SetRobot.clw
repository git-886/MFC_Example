; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgRobotParameter
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "setrobot.h"
LastPage=0

ClassCount=7
Class1=CDlgControlPanel
Class2=CMainFrame
Class3=CSetRobotApp
Class4=CAboutDlg
Class5=CSetRobotDoc
Class6=CSetRobotView

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIgControlPanel
Class7=CDlgRobotParameter
Resource4=IDD_DIlgRobotParameter

[CLS:CDlgControlPanel]
Type=0
BaseClass=CDialog
HeaderFile=DlgControlPanel.h
ImplementationFile=DlgControlPanel.cpp
Filter=D
VirtualFilter=dWC
LastObject=CDlgControlPanel

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CSetRobotApp]
Type=0
BaseClass=CWinApp
HeaderFile=SetRobot.h
ImplementationFile=SetRobot.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=SetRobot.cpp
ImplementationFile=SetRobot.cpp
LastObject=CAboutDlg

[CLS:CSetRobotDoc]
Type=0
BaseClass=CDocument
HeaderFile=SetRobotDoc.h
ImplementationFile=SetRobotDoc.cpp

[CLS:CSetRobotView]
Type=0
BaseClass=CView
HeaderFile=SetRobotView.h
ImplementationFile=SetRobotView.cpp
LastObject=ID_MENUITEMRobotParameterSet
Filter=C
VirtualFilter=VWC

[DLG:IDD_DIgControlPanel]
Type=1
Class=CDlgControlPanel
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTConDatabase,button,1342242816
Control4=IDC_BUTDisConDatabase,button,1342242816

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
Class=CSetRobotView
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
Command17=ID_MENUITEMOpenControlPanel
Command18=ID_MENUITEMCreateRobot
Command19=ID_MENUITEMDeleteRobot
Command20=ID_MENUITEMRobotParameterSet
CommandCount=20

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

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[DLG:IDD_DIlgRobotParameter]
Type=1
Class=CDlgRobotParameter
ControlCount=22
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTUpdate,button,1342242816
Control4=IDC_BUTSelect,button,1342242816
Control5=IDC_RIDSelect,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_RIDUpdate,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_eyelrUpdate,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_eyerUpdate,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_mouthrUpdate,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_BUTRefresh,button,1342242816
Control16=IDC_eyelrSel,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_eyerSel,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_mouthrSel,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_LISTALL,SysListView32,1350631425

[CLS:CDlgRobotParameter]
Type=0
HeaderFile=DlgRobotParameter.h
ImplementationFile=DlgRobotParameter.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTUpdate
VirtualFilter=dWC

