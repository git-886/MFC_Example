// WordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Word.h"
#include "msword.h"
#include "AtlBase.h"
#include "WordDlg.h"



// �ڴ�����ʹ�ø�����


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
	_Application app; //����wordӦ�ó������

	if(!app.CreateDispatch("Word.Application")){
		AfxMessageBox("word soft error");
	}
	Documents docs = app.GetDocuments();// ��ȡdoc�ĵ�����
	CComVariant Template(_T(""));//δʹ��ģ��
	CComVariant NewTemplate(false),DocumentType(0),Visible; //������������
	_Document doc;
	doc = docs.Add(&Template,&NewTemplate,&DocumentType,&Visible);
/////////////////////////////////////////////////////////////////////////���Ͻ����հ��ĵ�
	CString DatabaseName="ACCESS��SQL Server��Oracle";
	Selection sel = app.GetSelection();
	sel.TypeText("������ ���ݿ���Excel��word�ĵ���ȡ");
	sel.TypeParagraph();
	sel.TypeText("һ�㳣�õ�������:"+DatabaseName);

	sel.TypeText("\t\t\t\t\t\t\t");
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR),vtTrue((short)TRUE),vtFalse((short)FALSE);// ʹ��COleVariant�࣬�������
//	sel.InsertDateTime(COleVariant("yyyy-MM-dd HH-mm-ss"),vtFalse,vtOptional,vtOptional,vtOptional);//���õ�ǰʱ��

	sel.TypeParagraph();
	sel.TypeText(_T("3.1����һ�����ݿ�\r\n"));

	sel.TypeParagraph();
	sel.TypeText(_T("  �Խ������ϵͳΪ������Ҫ�ĸ�������ѧ������ʦ�����ұ�Ϳγ̱�\r\n"));

	Paragraphs paras = doc.GetParagraphs();
	Paragraph para = paras.Item(1);//paras.Item(1)  ѡ���ĵ���һ��
	para.SetAlignment(1);//���ж��루��������ֵ���Ըı䣩
	para.SetSpaceAfter(6);//���ö����о�
	Range range = para.GetRange();
	_Font font = range.GetFont();// ��ȡ�������
	font.SetSize(20);//���������С
	font.SetBold(1);//����
	range.SetFont(font);//��
	

	para = paras.Item(2);
	para.SetAlignment(0);//�����
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(10); 
	range.SetFont(font); 

	para = paras.Item(3);
	para.SetAlignment(0);//�����
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(20); 
	font.SetBold(1);//����
	range.SetFont(font);//��

	para = paras.Item(4);
	para.SetAlignment(0);//�����
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(5); 
	range.SetFont(font);//��
	
	//����ʱ�䣨ͬ�ϣ�
	/*
	COleDateTime dt=COleDateTime::GetCurrentTime();  
	CString strDT=dt.Format("%Y-%m-%d");  
	CString str("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");  
	str+=strDT;  
	str+="\r\n";  
	sel.TypeText(str);  
	*/

	//��ӱ��
	sel.TypeParagraph();
	sel.TypeText(_T("ѧ�����ֶ�\r\n"));
	para = paras.Item(5);
	para.SetAlignment(1);//���ж���
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(15); 
	range.SetFont(font);//��
	_Document saveDoc=app.GetActiveDocument();  
	Tables tables=saveDoc.GetTables();  
	CComVariant defaultBehavior(1),AutoFitBehavior(1);  
	tables.Add(sel.GetRange(),7,6,&defaultBehavior,&AutoFitBehavior);  
	Table table=tables.Item(1);  
	sel.TypeText(_T("ѧ��"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("����"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("�Ա�"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("����"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("ϵ"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("�༶")); 
	
	

	//��Ԫ��ϲ�����
	/*
	for(int i=1;i<7;i+=2)  
	{  
		Cell c1=table.Cell(i,1);  // Cell����������е�һ����Ԫ��
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
	
	app.SetVisible(true);//wordӦ�ó�����ӻ�
}

void CWordDlg::OnGenerateword() 
{
	// TODO: Add your control notification handler code here
	_Application app; //����wordӦ�ó������
	if(!app.CreateDispatch("Word.Application")){
		AfxMessageBox("word soft error");
	}
	Documents docs = app.GetDocuments();// ��ȡdoc�ĵ�����
	CComVariant Template(_T(""));//δʹ��ģ��
	CComVariant NewTemplate(false),DocumentType(0),Visible; //������������
	_Document doc;
	doc = docs.Add(&Template,&NewTemplate,&DocumentType,&Visible);
	CString strName="С��",strSex="��",strAge="24";
	Selection sel = app.GetSelection();
	sel.TypeText("���չ�ҵ��ѧ�������ѧ�뼼��ѧԺ\r\n209������");
	sel.TypeParagraph();
	sel.TypeText("����:"+strName+"\t�Ա�:"+strSex+"\t\t ����:"+strAge+"\t");

	sel.TypeText("\t\t\t\t\t\t\t");
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR),vtTrue((short)TRUE),vtFalse((short)FALSE);// ʹ��COleVariant�࣬�������
	sel.InsertDateTime(COleVariant("yyyy-MM-dd HH-mm-ss"),vtFalse,vtOptional,vtOptional,vtOptional);//���õ�ǰʱ��

	
	Paragraphs paras = doc.GetParagraphs();
	Paragraph para = paras.Item(1);//paras.Item(1)  ѡ���ĵ���һ��
	para.SetAlignment(1);//���ж��루��������ֵ���Ըı䣩
	para.SetSpaceAfter(6);//���ö����о�
	Range range = para.GetRange();
	_Font font = range.GetFont();// ��ȡ�������
	font.SetSize(18);//���������С
	font.SetBold(1);//����
	range.SetFont(font);//��
	

	para = paras.Item(2);
	para.SetAlignment(2); 
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(12); 
	range.SetFont(font); 


	sel.TypeParagraph();sel.TypeParagraph();sel.TypeParagraph();
	sel.TypeText(_T("\t\t\t\t\t\t\t--------------�ɼ���\r\n"));  
	//����ʱ�䣨ͬ�ϣ�
	COleDateTime dt=COleDateTime::GetCurrentTime();  
	CString strDT=dt.Format("%Y-%m-%d");  
	CString str("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");  
	str+=strDT;  
	str+="\r\n";  
	sel.TypeText(str);  

	//��ӱ��
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
		Cell c1=table.Cell(i,1);  // Cell����������е�һ����Ԫ��
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
	app.SetVisible(true);//wordӦ�ó�����ӻ�
}
