// HuaTu_InDialogView.cpp : implementation of the CHuaTu_InDialogView class
//

#include "stdafx.h"
#include "HuaTu_InDialog.h"

#include "HuaTu_InDialogDoc.h"
#include "HuaTu_InDialogView.h"
#include "CDlgpCurve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogView

IMPLEMENT_DYNCREATE(CHuaTu_InDialogView, CView)

BEGIN_MESSAGE_MAP(CHuaTu_InDialogView, CView)
	//{{AFX_MSG_MAP(CHuaTu_InDialogView)
	ON_COMMAND(ID_MENUITEMHuaTu_InDIalog, OnMENUITEMHuaTuInDIalog)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogView construction/destruction

CHuaTu_InDialogView::CHuaTu_InDialogView()
{
	// TODO: add construction code here

}

CHuaTu_InDialogView::~CHuaTu_InDialogView()
{
}

BOOL CHuaTu_InDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogView drawing

void CHuaTu_InDialogView::OnDraw(CDC* pDC)
{
	CHuaTu_InDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogView printing

BOOL CHuaTu_InDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHuaTu_InDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHuaTu_InDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogView diagnostics

#ifdef _DEBUG
void CHuaTu_InDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CHuaTu_InDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHuaTu_InDialogDoc* CHuaTu_InDialogView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHuaTu_InDialogDoc)));
	return (CHuaTu_InDialogDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogView message handlers

void CHuaTu_InDialogView::OnMENUITEMHuaTuInDIalog() 
{
	CCDlgpCurve cd;
	cd.DoModal();
	// TODO: Add your command handler code here
	
}
