// AdoDataBaseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdoDataBase.h"
#include "AdoDataBaseDlg.h"

#include "./cado/Ado.h"

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
// CAdoDataBaseDlg dialog

CAdoDataBaseDlg::CAdoDataBaseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdoDataBaseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdoDataBaseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdoDataBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdoDataBaseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdoDataBaseDlg, CDialog)
	//{{AFX_MSG_MAP(CAdoDataBaseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SEL, OnButtonSel)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SEL_SQLSERVER, OnButtonSelSqlserver)
	ON_BN_CLICKED(IDC_BUTTON_Con_SQLSERVER, OnBUTTONConSQLSERVER)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdoDataBaseDlg message handlers

BOOL CAdoDataBaseDlg::OnInitDialog()
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

void CAdoDataBaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdoDataBaseDlg::OnPaint() 
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
HCURSOR CAdoDataBaseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdoDataBaseDlg::OnButtonUpdate() 
{
	CAdo m_Ado;
	m_Ado.OnInitADOConn();

	CString sql,value;

//	sql.Format("update s set sname ='王五' where sno = '9602' ");

	sql.Format("update s1 set grade = (select grade from s2 where s2.sno=s1.sno)");
	m_Ado.GetRecordSet(sql);


	m_Ado.ExitConnect();

	AfxMessageBox("OK!");
	
}

void CAdoDataBaseDlg::OnButtonSel() 
{
	CAdo m_Ado;
	m_Ado.OnInitADOConn(".\\CAdo\\student.mdb");

	CString sql,value;

	sql.Format("select * from s where sno = '9601' ");
	m_Ado.GetRecordSet(sql);
	if(!m_Ado.m_pRecordset->adoEOF)
	{
		value=m_Ado.GetCollect("sname");

	}

	m_Ado.ExitConnect();

	AfxMessageBox(value);
}

void CAdoDataBaseDlg::OnButtonAdd() 
{
	CString str1,str2,str3,str4,sql,temp;
	CAdo m_Ado;
	m_Ado.OnInitADOConn(".\\CAdo\\student.mdb");
	
	str1 = "9608";
	str2 = "李四";
	str3 = "23";
	str4 = "男";

	sql="insert into s (sno,sname,sage,ssex) values(";
	temp.Format("'%s','%s','%s','%s')",str1,str2,str3,str4);
	sql += temp;

	sql.Format("insert into s (sno,sname,sage,ssex) values('%s','%s',%s,'%s')",str1,str2,str3,str4);
	m_Ado.ExecuteSQL(sql);

	m_Ado.ExitConnect();

	AfxMessageBox("OK!");
	
}

void CAdoDataBaseDlg::OnButtonDelete() 
{
	CAdo m_Ado;
	m_Ado.OnInitADOConn();

	CString sql;
	sql.Format("delete from s where sno = '9602' ");
	m_Ado.ExecuteSQL(sql);


	m_Ado.ExitConnect();

	AfxMessageBox("OK!");

}

void CAdoDataBaseDlg::OnButtonSelSqlserver() 
{
	
}

void CAdoDataBaseDlg::OnBUTTONConSQLSERVER() 
{
	// TODO: Add your control notification handler code here
	CAdo m_Ado;
	m_Ado.OnInitADOConnSQLServer();
}
