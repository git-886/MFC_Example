// GameView.cpp : implementation of the CGameView class
//

#include "stdafx.h"
#include "Game.h"

#include "GameDoc.h"
#include "GameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameView

IMPLEMENT_DYNCREATE(CGameView, CView)

BEGIN_MESSAGE_MAP(CGameView, CView)
	//{{AFX_MSG_MAP(CGameView)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameView construction/destruction

CGameView::CGameView()
{
	// TODO: add construction code here

}

CGameView::~CGameView()
{
}

BOOL CGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGameView drawing

void CGameView::OnDraw(CDC* pDC)
{
	CGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	plane.Draw(pDC);
	
}

/////////////////////////////////////////////////////////////////////////////
// CGameView printing

BOOL CGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGameView diagnostics

#ifdef _DEBUG
void CGameView::AssertValid() const
{
	CView::AssertValid();
}

void CGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGameDoc* CGameView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameDoc)));
	return (CGameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGameView message handlers

void CGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar == 32)
	{
		plane.BulletProduce();
	}
	else
	{
		plane.PlaneMove(nChar);
	}
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CGameView::OnMENUITEMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
	SetTimer(2,1000,NULL);
}

void CGameView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		plane.BulletMove();
		plane.BulletOut();
		plane.CircleMove();
		plane.CircleOut();
		plane.CircleHit();
		if(plane.CircleCollision() == 1)
		{
			KillTimer(1);
			KillTimer(2);
			AfxMessageBox("”Œœ∑Ω· ¯¡À£°");
			

		}
		break;
	case 2:
		plane.ProduceTargets();
		break;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}
