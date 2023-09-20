// WindowsAPIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WindowsAPI.h"
#include "WindowsAPIDlg.h"
#include "afx.h"
#include <iostream>
#include <afxdlgs.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowsAPIDlg dialog

CWindowsAPIDlg::CWindowsAPIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWindowsAPIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWindowsAPIDlg)
	m_TargetPath = _T("");
	m_CurrentPath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWindowsAPIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWindowsAPIDlg)
	DDX_Text(pDX, IDC_CopyFileTargetPath, m_TargetPath);
	DDX_Text(pDX, IDC_CopyFileCurrentPath, m_CurrentPath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWindowsAPIDlg, CDialog)
	//{{AFX_MSG_MAP(CWindowsAPIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GetCurrentPath, OnGetCurrentPath)
	ON_BN_CLICKED(IDC_GetSystemInformation, OnGetSystemInformation)
	ON_BN_CLICKED(IDC_FIndAllFilesFormDir, OnFIndAllFilesFormDir)
	ON_BN_CLICKED(IDC_CopyFile, OnCopyFile)
	ON_BN_CLICKED(IDC_DeleteFile, OnDeleteFile)
	ON_BN_CLICKED(IDC_CreateDirectory, OnCreateDirectory)
	ON_BN_CLICKED(IDC_DeleteDirectory, OnDeleteDirectory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowsAPIDlg message handlers

BOOL CWindowsAPIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWindowsAPIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWindowsAPIDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWindowsAPIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWindowsAPIDlg::OnGetCurrentPath() 
{
	// TODO: Add your control notification handler code here
	CString strAppPath;
	TCHAR szBuffer[MAX_PATH];
    GetCurrentDirectory(MAX_PATH,szBuffer);
    strAppPath.Format("%s",szBuffer);
	AfxMessageBox(strAppPath);

}

void CWindowsAPIDlg::OnGetSystemInformation() 
{
	// TODO: Add your control notification handler code here
	CString str,temp;
	//---------------内存---------------
	_MEMORYSTATUS m;
	::GlobalMemoryStatus(&m);

	temp.Format("%d\n",m.dwMemoryLoad);
	str += temp;
	temp.Format("%d\n",m.dwTotalPhys);
	str += temp;
	temp.Format("%d\n",m.dwTotalVirtual);
	str += temp;

	//-----------硬盘-----------------
	_ULARGE_INTEGER disk1,disk2,disk3;
	GetDiskFreeSpaceEx("c:",&disk1,&disk2,&disk3);

	int a1,a2,a3;
	a1 =  (disk1.QuadPart)/1024/1024;
	a2 =  (disk2.QuadPart)/1024/1024;
	a3 =  (disk3.QuadPart)/1024/1024;
	temp.Format("%d,%d,%d,\n",a1,a2,a3);
	str += temp;

	//-------------cpu------------
	SYSTEM_INFO sysinfo;
	int n_cpu;
	GetSystemInfo(&sysinfo);
	n_cpu = sysinfo.dwNumberOfProcessors;
	temp.Format("%d\n",n_cpu);
	str += temp;
	AfxMessageBox(str);

}

void CWindowsAPIDlg::OnFIndAllFilesFormDir() 
{
	// TODO: Add your control notification handler code here
	CFileFind finder;
	CString filename,wfilename;//filename表示文件名不包括路径，wfilename包括路径
	CString filelist;

	BOOL bworking=finder.FindFile("D:\\*.*");
	while(bworking)
	{
		bworking=finder.FindNextFile();
		wfilename = finder.GetFilePath();
		filename = finder.GetFileName();
		if(filename.Compare(".")==0||filename.Compare("..")==0)
			continue;

		filelist+=filename+"\n";
		if( finder.IsDirectory() )
		{
			filelist += "文件夹："+filename+"\n";
		}	
	}
	finder.Close();	
	AfxMessageBox(filelist);

}



void CWindowsAPIDlg::OnCopyFile() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_CopyFileCurrentPath, m_CurrentPath);
	GetDlgItemText(IDC_CopyFileTargetPath, m_TargetPath);
    // 使用CFile::Copy方法将源文件复制到目标文件
    if (CopyFile(m_CurrentPath,m_TargetPath,TRUE))
    {
        MessageBox("文件复制成功!", "提示", MB_OK | MB_ICONINFORMATION);
    }
    else
    {
        MessageBox("文件复制失败!", "提示", MB_OK | MB_ICONINFORMATION);
    }

}

void CWindowsAPIDlg::OnDeleteFile() 
{
	// TODO: Add your control notification handler code here
    // 获取文本框中的文件路径信息
    CString filePath;
    GetDlgItemText(IDC_DeleteFilePath, filePath);
    // 使用 CFile 的 Remove 方法删除文件
    
        // 删除文件
	if(DeleteFile(filePath))
	{
		MessageBox("文件已成功删除!", "提示", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBox("删除文件失败!", "提示", MB_OK | MB_ICONINFORMATION);
	}
	
    
}

void CWindowsAPIDlg::OnCreateDirectory() 
{
	// TODO: Add your control notification handler code here
	CString DirectoryPath;
    GetDlgItemText(IDC_CreateDirectoryPath, DirectoryPath);
	if(CreateDirectory(DirectoryPath,NULL))
	{
		MessageBox("文件夹创建成功!", "提示", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBox("文件夹创建失败!", "提示", MB_OK | MB_ICONINFORMATION);
	}
	
}

void CWindowsAPIDlg::OnDeleteDirectory() 
{
	// TODO: Add your control notification handler code here
	CString DirectoryPath;
    GetDlgItemText(IDC_DeleteDirctoryPath, DirectoryPath);
	if (DirectoryPath.IsEmpty())
	{
		::RemoveDirectory(DirectoryPath);
		MessageBox("文件夹删除成功!", "提示", MB_OK | MB_ICONINFORMATION);
		return;
	}
	CFileFind fileFinder;
	BOOL bFind = fileFinder.FindFile(DirectoryPath + _T("\\*.*"));
	while (bFind)
	{
		bFind = fileFinder.FindNextFile();
		if (fileFinder.IsDirectory()) //递归进行子文件夹的删除
			continue;
		CString FilePath = fileFinder.GetFilePath();
		DeleteFile(FilePath);
	}
	::RemoveDirectory(DirectoryPath);
	MessageBox("文件夹删除成功!", "提示", MB_OK | MB_ICONINFORMATION);
}
