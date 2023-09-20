// TankWarView.cpp : implementation of the CTankWarView class
//

#include "stdafx.h"
#include "TankWar.h"

#include "TankWarDoc.h"
#include "TankWarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankWarView

IMPLEMENT_DYNCREATE(CTankWarView, CView)

BEGIN_MESSAGE_MAP(CTankWarView, CView)
	//{{AFX_MSG_MAP(CTankWarView)
	ON_COMMAND(ID_MENUITEMStarGame, OnMENUITEMStarGame)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankWarView construction/destruction

CTankWarView::CTankWarView()
{
	// TODO: add construction code here

}

CTankWarView::~CTankWarView()
{
}

BOOL CTankWarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTankWarView drawing

void CTankWarView::OnDraw(CDC* pDC)
{
	CTankWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_target.DrawTargetAndBK(pDC);
	m_tank.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CTankWarView printing

BOOL CTankWarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTankWarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTankWarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTankWarView diagnostics

#ifdef _DEBUG
void CTankWarView::AssertValid() const
{
	CView::AssertValid();
}

void CTankWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTankWarDoc* CTankWarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTankWarDoc)));
	return (CTankWarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankWarView message handlers

void CTankWarView::OnMENUITEMStarGame() 
{
	// TODO: Add your command handler code here
	SetTimer(1,1000,NULL);
}

void CTankWarView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_target.ProduceSquare();
	m_target.ProduceCircle();
	m_target.ProduceTriangle();
	m_tank.MoveBullet();
	Invalidate(true);
	m_target.HitAndOutSquare();
	CView::OnTimer(nIDEvent);
}

void CTankWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case 37:
		m_tank.m_direction = 4;
		break;
	case 38:
		m_tank.m_direction = 8;
		break;
	case 39:
		m_tank.m_direction = 6;
		break;
	case 40:
		m_tank.m_direction = 2;
		break;
	case VK_SPACE:
		m_tank.ProduceBullet();
	default:
		break;
	}
	m_tank.MoveTank();
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


