; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RobertInspection.h"
LastPage=0

ClassCount=9
Class1=CRobertInspectionApp
Class2=CRobertInspectionDoc
Class3=CRobertInspectionView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CScene
Class7=CCarRobot
Resource2=IDD_ABOUTBOX
Class8=CDlgRotateParameterSet
Resource3=IDD_DIALOG1
Class9=CDlgInitCarPosLeakPointCheck
Resource4=IDD_DIALOGInitCarPosLeakPointCheck

[CLS:CRobertInspectionApp]
Type=0
HeaderFile=RobertInspection.h
ImplementationFile=RobertInspection.cpp
Filter=N

[CLS:CRobertInspectionDoc]
Type=0
HeaderFile=RobertInspectionDoc.h
ImplementationFile=RobertInspectionDoc.cpp
Filter=N

[CLS:CRobertInspectionView]
Type=0
HeaderFile=RobertInspectionView.h
ImplementationFile=RobertInspectionView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CRobertInspectionView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEMMapControl




[CLS:CAboutDlg]
Type=0
HeaderFile=RobertInspection.cpp
ImplementationFile=RobertInspection.cpp
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
Command17=ID_MENUITEMMoveSpecifiedPoint
Command18=ID_MENUITEMMoveUniform
Command19=ID_MENUITEMMoveRotate
Command20=ID_MENUITEMMapControl
Command21=ID_MENUITEMStop
Command22=ID_MENUITEMSpecifyPath
Command23=ID_MENUITEMSpecifyPathStart
Command24=ID_MENUITEMSpecifyPathStop
Command25=ID_MENUITEMParticleStart
Command26=ID_MENUITEMParticleStop
Command27=ID_MENUITEMTestParticleConcentration
Command28=ID_MENUITEMCheckStart
Command29=ID_MENUITEMCheckStop
Command30=ID_MENUITEMInitCarPos
Command31=ID_MENUITEMUAVStartCheck
Command32=ID_MENUITEMUAVStopCheck
CommandCount=32

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

[CLS:CScene]
Type=0
HeaderFile=Scene.h
ImplementationFile=Scene.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CScene

[CLS:CCarRobot]
Type=0
HeaderFile=CarRobot.h
ImplementationFile=CarRobot.cpp
BaseClass=generic CWnd
Filter=W

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgRotateParameterSet
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_m_R,edit,1350631552
Control7=IDC_M_W,edit,1350631552
Control8=IDC_Direction,edit,1350631552
Control9=IDC_S,static,1342308352
Control10=IDC_SSZOrNSZ,edit,1350631552

[CLS:CDlgRotateParameterSet]
Type=0
HeaderFile=DlgRotateParameterSet.h
ImplementationFile=DlgRotateParameterSet.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgRotateParameterSet
VirtualFilter=dWC

[DLG:IDD_DIALOGInitCarPosLeakPointCheck]
Type=1
Class=CDlgInitCarPosLeakPointCheck
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_m_X,edit,1350631552
Control6=IDC_m_Y,edit,1350631552

[CLS:CDlgInitCarPosLeakPointCheck]
Type=0
HeaderFile=DlgInitCarPosLeakPointCheck.h
ImplementationFile=DlgInitCarPosLeakPointCheck.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgInitCarPosLeakPointCheck

