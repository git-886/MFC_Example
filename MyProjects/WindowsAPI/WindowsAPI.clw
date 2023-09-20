; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWindowsAPIDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WindowsAPI.h"

ClassCount=3
Class1=CWindowsAPIApp
Class2=CWindowsAPIDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WINDOWSAPI_DIALOG

[CLS:CWindowsAPIApp]
Type=0
HeaderFile=WindowsAPI.h
ImplementationFile=WindowsAPI.cpp
Filter=N

[CLS:CWindowsAPIDlg]
Type=0
HeaderFile=WindowsAPIDlg.h
ImplementationFile=WindowsAPIDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CopyFile

[CLS:CAboutDlg]
Type=0
HeaderFile=WindowsAPIDlg.h
ImplementationFile=WindowsAPIDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WINDOWSAPI_DIALOG]
Type=1
Class=CWindowsAPIDlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_GetCurrentPath,button,1342242816
Control4=IDC_GetSystemInformation,button,1342242816
Control5=IDC_FIndAllFilesFormDir,button,1342242816
Control6=IDC_CopyFile,button,1342242816
Control7=IDC_DeleteFile,button,1342242816
Control8=IDC_CopyFileCurrentPath,edit,1350631552
Control9=IDC_CopyFileTargetPath,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_DeleteFilePath,edit,1350631552
Control13=IDC_CreateDirectoryPath,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_CreateDirectory,button,1342242816
Control17=IDC_DeleteDirctoryPath,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_DeleteDirectory,button,1342242816

