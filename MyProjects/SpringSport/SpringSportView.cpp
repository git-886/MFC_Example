// SpringSportView.cpp : implementation of the CSpringSportView class
//

#include "stdafx.h"
#include "SpringSport.h"

#include "SpringSportDoc.h"
#include "SpringSportView.h"
#include "DlgParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView

IMPLEMENT_DYNCREATE(CSpringSportView, CView)

BEGIN_MESSAGE_MAP(CSpringSportView, CView)
	//{{AFX_MSG_MAP(CSpringSportView)
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_COMMAND(ID_MENUITEMParameterSet, OnMENUITEMParameterSet)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView construction/destruction

CSpringSportView::CSpringSportView()
{
	// TODO: add construction code here

}

CSpringSportView::~CSpringSportView()
{
}

BOOL CSpringSportView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView drawing

void CSpringSportView::OnDraw(CDC* pDC)
{
	CSpringSportDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_Spring.Draw(pDC);

}

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView printing

BOOL CSpringSportView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSpringSportView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSpringSportView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView diagnostics

#ifdef _DEBUG
void CSpringSportView::AssertValid() const
{
	CView::AssertValid();
}

void CSpringSportView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSpringSportDoc* CSpringSportView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpringSportDoc)));
	return (CSpringSportDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView message handlers

void CSpringSportView::OnMENUITEMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
}

void CSpringSportView::OnMENUITEMParameterSet() 
{
	// TODO: Add your command handler code here
	CDlgParameterSet m_dlg;//初始参数显示
	
	m_dlg.m_M = m_Spring.m_m;
	m_dlg.m_L = m_Spring.m_L;
	m_dlg.m_L0 = m_Spring.m_L0;
	m_dlg.m_K = m_Spring.m_k;
	m_dlg.m_Z = m_Spring.m_zn;
	//m_dlg.DoModal();

	if(m_dlg.DoModal() == 1)//设置参数
	{
		m_Spring.m_m = m_dlg.m_M;
		m_Spring.m_L = m_dlg.m_L;
		m_Spring.m_L0 = m_dlg.m_L0 ;
		m_Spring.m_k = m_dlg.m_K;
		m_Spring.m_zn = m_dlg.m_Z;

		m_Spring.m_naGJ = 0;
		m_Spring.m_nfGJ = 0;
		m_Spring.m_nvGJ = 0;
		m_Spring.m_nyGJ = 0;
	}
	
}

void CSpringSportView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_Spring.Move();
	Invalidate(true);
	m_Spring.m_f;
	m_Spring.m_v;
	if(m_Spring.PanDunaPH() == 1)
	{
		KillTimer(1);
	}
	CView::OnTimer(nIDEvent);
}
