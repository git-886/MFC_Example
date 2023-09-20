; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSnakeGameView
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SnakeGame.h"
LastPage=0

ClassCount=6
Class1=CSnakeGameApp
Class2=CSnakeGameDoc
Class3=CSnakeGameView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CTCSGameProcess
Resource2=IDD_ABOUTBOX

[CLS:CSnakeGameApp]
Type=0
HeaderFile=SnakeGame.h
ImplementationFile=SnakeGame.cpp
Filter=N

[CLS:CSnakeGameDoc]
Type=0
HeaderFile=SnakeGameDoc.h
ImplementationFile=SnakeGameDoc.cpp
Filter=N

[CLS:CSnakeGameView]
Type=0
HeaderFile=SnakeGameView.h
ImplementationFile=SnakeGameView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CSnakeGameView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEMStarGame




[CLS:CAboutDlg]
Type=0
HeaderFile=SnakeGame.cpp
ImplementationFile=SnakeGame.cpp
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
Command17=ID_MENUITEMStarGame
CommandCount=17

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

[CLS:CTCSGameProcess]
Type=0
HeaderFile=TCSGameProcess.h
ImplementationFile=TCSGameProcess.cpp
BaseClass=generic CWnd
Filter=W

