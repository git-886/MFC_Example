// JWGLSystemODBCView.cpp : implementation of the CJWGLSystemODBCView class
//

#include "stdafx.h"
#include "JWGLSystemODBC.h"

#include "JWGLSystemODBCSet.h"
#include "JWGLSystemODBCDoc.h"
#include "JWGLSystemODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCView

IMPLEMENT_DYNCREATE(CJWGLSystemODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CJWGLSystemODBCView, CRecordView)
	//{{AFX_MSG_MAP(CJWGLSystemODBCView)
	ON_BN_CLICKED(IDC_BUTClear, OnBUTClear)
	ON_BN_CLICKED(IDC_BUTInsert, OnBUTInsert)
	ON_BN_CLICKED(IDC_BUTDelete, OnBUTDelete)
	ON_BN_CLICKED(IDC_BUTUpdate, OnBUTUpdate)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCView construction/destruction

CJWGLSystemODBCView::CJWGLSystemODBCView()
	: CRecordView(CJWGLSystemODBCView::IDD)
{
	//{{AFX_DATA_INIT(CJWGLSystemODBCView)
	m_pSet = NULL;
	m_age = 0;
	m_class = _T("");
	m_id = 0;
	m_name = _T("");
	m_pro = _T("");
	m_sex = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CJWGLSystemODBCView::~CJWGLSystemODBCView()
{
}

void CJWGLSystemODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJWGLSystemODBCView)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_AGE, m_age);
	DDX_Text(pDX, IDC_CLASS, m_class);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_Name, m_name);
	DDX_Text(pDX, IDC_PRO, m_pro);
	DDX_Text(pDX, IDC_SEX, m_sex);
	//}}AFX_DATA_MAP
}

BOOL CJWGLSystemODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CJWGLSystemODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_jWGLSystemODBCSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCView printing

BOOL CJWGLSystemODBCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJWGLSystemODBCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJWGLSystemODBCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCView diagnostics

#ifdef _DEBUG
void CJWGLSystemODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CJWGLSystemODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CJWGLSystemODBCDoc* CJWGLSystemODBCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJWGLSystemODBCDoc)));
	return (CJWGLSystemODBCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCView database support
CRecordset* CJWGLSystemODBCView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCView message handlers

void CJWGLSystemODBCView::OnBUTClear() 
{
	// TODO: Add your control notification handler code here
	CWnd* c1;
	c1 = CWnd::GetDlgItem(IDC_ID);
	c1->SetWindowText("");

	c1 = CWnd::GetDlgItem(IDC_Name);
	c1->SetWindowText("");

	c1 = CWnd::GetDlgItem(IDC_AGE);
	c1->SetWindowText("");

	c1 = CWnd::GetDlgItem(IDC_SEX);
	c1->SetWindowText("");

	c1 = CWnd::GetDlgItem(IDC_PRO);
	c1->SetWindowText("");

	c1 = CWnd::GetDlgItem(IDC_CLASS);
	c1->SetWindowText("");
}
//插入一条记录
void CJWGLSystemODBCView::OnBUTInsert() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_name == "" || m_id == "")
	{
		AfxMessageBox("学号和姓名信息不能为空！");
		return;
	}
	try
	{
		m_pSet->AddNew();
		m_pSet->PutCollect()
	}
}

void CJWGLSystemODBCView::OnBUTDelete() 
{
	// TODO: Add your control notification handler code here
	m_pSet->Delete();
	m_pSet->Requery();
	UpdateData(FALSE);
}

void CJWGLSystemODBCView::OnBUTUpdate() 
{
	// TODO: Add your control notification handler code here
	m_pSet->Edit();
	UpdateData();
	m_pSet->Update();
	m_pSet->Requery();
	UpdateData(FALSE);
}
