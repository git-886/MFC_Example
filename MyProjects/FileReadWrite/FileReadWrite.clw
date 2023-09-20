; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileReadWriteDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileReadWrite.h"

ClassCount=3
Class1=CFileReadWriteApp
Class2=CFileReadWriteDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILEREADWRITE_DIALOG

[CLS:CFileReadWriteApp]
Type=0
HeaderFile=FileReadWrite.h
ImplementationFile=FileReadWrite.cpp
Filter=N

[CLS:CFileReadWriteDlg]
Type=0
HeaderFile=FileReadWriteDlg.h
ImplementationFile=FileReadWriteDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFileReadWriteDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FileReadWriteDlg.h
ImplementationFile=FileReadWriteDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILEREADWRITE_DIALOG]
Type=1
Class=CFileReadWriteDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDITFilePath,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTReadFile,button,1342242816

