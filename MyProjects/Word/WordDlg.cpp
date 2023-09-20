// WordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Word.h"
#include "msword.h"
#include "AtlBase.h"
#include "WordDlg.h"



// 在代码中使用该类型


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
// CWordDlg dialog

CWordDlg::CWordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordDlg, CDialog)
	//{{AFX_MSG_MAP(CWordDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENWORD, OnOpenword)
	ON_BN_CLICKED(IDC_GENERATEWORD, OnGenerateword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordDlg message handlers

BOOL CWordDlg::OnInitDialog()
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

void CWordDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWordDlg::OnPaint() 
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
HCURSOR CWordDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWordDlg::OnOpenword() 
{
	// TODO: Add your control notification handler code here
	_Application app; //创建word应用程序对象

	if(!app.CreateDispatch("Word.Application")){
		AfxMessageBox("word soft error");
	}
	Documents docs = app.GetDocuments();// 获取doc文档对象
	CComVariant Template(_T(""));//未使用模版
	CComVariant NewTemplate(false),DocumentType(0),Visible; //定义数据类型
	_Document doc;
	doc = docs.Add(&Template,&NewTemplate,&DocumentType,&Visible);
/////////////////////////////////////////////////////////////////////////以上建立空白文档
	CString DatabaseName="ACCESS、SQL Server和Oracle";
	Selection sel = app.GetSelection();
	sel.TypeText("第三章 数据库与Excel、word文档存取");
	sel.TypeParagraph();
	sel.TypeText("一般常用的数据有:"+DatabaseName);

	sel.TypeText("\t\t\t\t\t\t\t");
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR),vtTrue((short)TRUE),vtFalse((short)FALSE);// 使用COleVariant类，定义变量
//	sel.InsertDateTime(COleVariant("yyyy-MM-dd HH-mm-ss"),vtFalse,vtOptional,vtOptional,vtOptional);//设置当前时间

	sel.TypeParagraph();
	sel.TypeText(_T("3.1创建一个数据库\r\n"));

	sel.TypeParagraph();
	sel.TypeText(_T("  以教务管理系统为例，需要四个基本表：学生表、教师表、教室表和课程表\r\n"));

	Paragraphs paras = doc.GetParagraphs();
	Paragraph para = paras.Item(1);//paras.Item(1)  选定文档第一段
	para.SetAlignment(1);//居中对齐（函数参数值可以改变）
	para.SetSpaceAfter(6);//设置段落行距
	Range range = para.GetRange();
	_Font font = range.GetFont();// 获取字体对象
	font.SetSize(20);//设置字体大小
	font.SetBold(1);//粗体
	range.SetFont(font);//绑定
	

	para = paras.Item(2);
	para.SetAlignment(0);//左对齐
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(10); 
	range.SetFont(font); 

	para = paras.Item(3);
	para.SetAlignment(0);//左对齐
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(20); 
	font.SetBold(1);//粗体
	range.SetFont(font);//绑定

	para = paras.Item(4);
	para.SetAlignment(0);//左对齐
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(5); 
	range.SetFont(font);//绑定
	
	//设置时间（同上）
	/*
	COleDateTime dt=COleDateTime::GetCurrentTime();  
	CString strDT=dt.Format("%Y-%m-%d");  
	CString str("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");  
	str+=strDT;  
	str+="\r\n";  
	sel.TypeText(str);  
	*/

	//添加表格
	sel.TypeParagraph();
	sel.TypeText(_T("学生表字段\r\n"));
	para = paras.Item(5);
	para.SetAlignment(1);//居中对齐
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(15); 
	range.SetFont(font);//绑定
	_Document saveDoc=app.GetActiveDocument();  
	Tables tables=saveDoc.GetTables();  
	CComVariant defaultBehavior(1),AutoFitBehavior(1);  
	tables.Add(sel.GetRange(),7,6,&defaultBehavior,&AutoFitBehavior);  
	Table table=tables.Item(1);  
	sel.TypeText(_T("学号"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("姓名"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("性别"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("年龄"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("系"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("班级")); 
	
	

	//单元格合并操作
	/*
	for(int i=1;i<7;i+=2)  
	{  
		Cell c1=table.Cell(i,1);  // Cell对象代表表格中的一个单元格
		Cell c2=table.Cell(i+1,1);  
		c1.Merge(c2);  
		c1.ReleaseDispatch();  
		c2.ReleaseDispatch();  
	}  */

 
	app.SetVisible(TRUE);  
	table.ReleaseDispatch();  
	tables.ReleaseDispatch();  
	sel.ReleaseDispatch();  
	docs.ReleaseDispatch();  
	saveDoc.ReleaseDispatch();  
	app.ReleaseDispatch(); 
	
	app.SetVisible(true);//word应用程序可视化
}

void CWordDlg::OnGenerateword() 
{
	// TODO: Add your control notification handler code here
	_Application app; //创建word应用程序对象
	if(!app.CreateDispatch("Word.Application")){
		AfxMessageBox("word soft error");
	}
	Documents docs = app.GetDocuments();// 获取doc文档对象
	CComVariant Template(_T(""));//未使用模版
	CComVariant NewTemplate(false),DocumentType(0),Visible; //定义数据类型
	_Document doc;
	doc = docs.Add(&Template,&NewTemplate,&DocumentType,&Visible);
	CString strName="小猪",strSex="男",strAge="24";
	Selection sel = app.GetSelection();
	sel.TypeText("安徽工业大学计算机科学与技术学院\r\n209教研室");
	sel.TypeParagraph();
	sel.TypeText("姓名:"+strName+"\t性别:"+strSex+"\t\t 年龄:"+strAge+"\t");

	sel.TypeText("\t\t\t\t\t\t\t");
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR),vtTrue((short)TRUE),vtFalse((short)FALSE);// 使用COleVariant类，定义变量
	sel.InsertDateTime(COleVariant("yyyy-MM-dd HH-mm-ss"),vtFalse,vtOptional,vtOptional,vtOptional);//设置当前时间

	
	Paragraphs paras = doc.GetParagraphs();
	Paragraph para = paras.Item(1);//paras.Item(1)  选定文档第一段
	para.SetAlignment(1);//居中对齐（函数参数值可以改变）
	para.SetSpaceAfter(6);//设置段落行距
	Range range = para.GetRange();
	_Font font = range.GetFont();// 获取字体对象
	font.SetSize(18);//设置字体大小
	font.SetBold(1);//粗体
	range.SetFont(font);//绑定
	

	para = paras.Item(2);
	para.SetAlignment(2); 
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(12); 
	range.SetFont(font); 


	sel.TypeParagraph();sel.TypeParagraph();sel.TypeParagraph();
	sel.TypeText(_T("\t\t\t\t\t\t\t--------------成绩表\r\n"));  
	//设置时间（同上）
	COleDateTime dt=COleDateTime::GetCurrentTime();  
	CString strDT=dt.Format("%Y-%m-%d");  
	CString str("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");  
	str+=strDT;  
	str+="\r\n";  
	sel.TypeText(str);  

	//添加表格
	_Document saveDoc=app.GetActiveDocument();  
	Tables tables=saveDoc.GetTables();  
	CComVariant defaultBehavior(1),AutoFitBehavior(1);  
	tables.Add(sel.GetRange(),7,11,&defaultBehavior,&AutoFitBehavior);  
	Table table=tables.Item(1);  
	sel.TypeText(_T("Test1"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test2"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test3"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test4"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test5"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test6"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test7"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test8"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test9"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test10"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test11"));  
	for(int i=2;i<7;i+=2)  
	{  
		Cell c1=table.Cell(i,1);  // Cell对象代表表格中的一个单元格
		Cell c2=table.Cell(i+1,1);  
		c1.Merge(c2);  
		c1.ReleaseDispatch();  
		c2.ReleaseDispatch();  
	}  

	app.SetVisible(TRUE);  
	table.ReleaseDispatch();  
	tables.ReleaseDispatch();  
	sel.ReleaseDispatch();  
	docs.ReleaseDispatch();  
	saveDoc.ReleaseDispatch();  
	app.ReleaseDispatch(); 
	app.SetVisible(true);//word应用程序可视化
}
