; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgParameterSetting
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SinxCosx.h"
LastPage=0

ClassCount=8
Class1=CSinxCosxApp
Class2=CSinxCosxDoc
Class3=CSinxCosxView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDlgParameterSet
Class7=CTest
Resource2=IDR_MAINFRAME
Class8=CDlgParameterSetting
Resource3=IDD_DlgParameterSet

[CLS:CSinxCosxApp]
Type=0
HeaderFile=SinxCosx.h
ImplementationFile=SinxCosx.cpp
Filter=N

[CLS:CSinxCosxDoc]
Type=0
HeaderFile=SinxCosxDoc.h
ImplementationFile=SinxCosxDoc.cpp
Filter=N

[CLS:CSinxCosxView]
Type=0
HeaderFile=SinxCosxView.h
ImplementationFile=SinxCosxView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MENUITEMParameterSet


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=SinxCosx.cpp
ImplementationFile=SinxCosx.cpp
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

[CLS:CDlgParameterSet]
Type=0
HeaderFile=DlgParameterSet.h
ImplementationFile=DlgParameterSet.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgParameterSet
VirtualFilter=dWC

[CLS:CTest]
Type=0
HeaderFile=Test.h
ImplementationFile=Test.cpp
BaseClass=CDialog
Filter=D
LastObject=CTest

[DLG:IDD_DlgParameterSet]
Type=1
Class=CDlgParameterSetting
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_XW,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_W,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ZF,edit,1350631552

[CLS:CDlgParameterSetting]
Type=0
HeaderFile=DlgParameterSetting.h
ImplementationFile=DlgParameterSetting.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgParameterSetting
VirtualFilter=dWC

