// SinCosView.cpp : implementation of the CSinCosView class
//

#include "stdafx.h"
#include "SinCos.h"

#include "SinCosDoc.h"
#include "SinCosView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinCosView

IMPLEMENT_DYNCREATE(CSinCosView, CView)

BEGIN_MESSAGE_MAP(CSinCosView, CView)
	//{{AFX_MSG_MAP(CSinCosView)
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMStop, OnMENUITEMStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinCosView construction/destruction

CSinCosView::CSinCosView()
{
	// TODO: add construction code here

}

CSinCosView::~CSinCosView()
{
}

BOOL CSinCosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSinCosView drawing

void CSinCosView::OnDraw(CDC* pDC)
{
	CSinCosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_data.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CSinCosView printing

BOOL CSinCosView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSinCosView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSinCosView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSinCosView diagnostics

#ifdef _DEBUG
void CSinCosView::AssertValid() const
{
	CView::AssertValid();
}

void CSinCosView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSinCosDoc* CSinCosView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSinCosDoc)));
	return (CSinCosDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinCosView message handlers

void CSinCosView::OnMENUITEMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
}

void CSinCosView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_data.Move();
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CSinCosView::OnMENUITEMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}
