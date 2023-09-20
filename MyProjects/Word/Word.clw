; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWordDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Word.h"

ClassCount=3
Class1=CWordApp
Class2=CWordDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WORD_DIALOG

[CLS:CWordApp]
Type=0
HeaderFile=Word.h
ImplementationFile=Word.cpp
Filter=N

[CLS:CWordDlg]
Type=0
HeaderFile=WordDlg.h
ImplementationFile=WordDlg.cpp
Filter=D
LastObject=CWordDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=WordDlg.h
ImplementationFile=WordDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WORD_DIALOG]
Type=1
Class=CWordDlg
ControlCount=2
Control1=IDC_OPENWORD,button,1342242816
Control2=IDC_GENERATEWORD,button,1342242816

