// SnakeGameView.cpp : implementation of the CSnakeGameView class
//

#include "stdafx.h"
#include "SnakeGame.h"

#include "SnakeGameDoc.h"
#include "SnakeGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameView

IMPLEMENT_DYNCREATE(CSnakeGameView, CView)

BEGIN_MESSAGE_MAP(CSnakeGameView, CView)
	//{{AFX_MSG_MAP(CSnakeGameView)
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
// CSnakeGameView construction/destruction

CSnakeGameView::CSnakeGameView()
{
	// TODO: add construction code here

}

CSnakeGameView::~CSnakeGameView()
{
}

BOOL CSnakeGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameView drawing

void CSnakeGameView::OnDraw(CDC* pDC)
{
	CSnakeGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	tcs.pDC = pDC;
	tcs.Draw();
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameView printing

BOOL CSnakeGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnakeGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnakeGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameView diagnostics

#ifdef _DEBUG
void CSnakeGameView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeGameDoc* CSnakeGameView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeGameDoc)));
	return (CSnakeGameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameView message handlers

void CSnakeGameView::OnMENUITEMStarGame() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
}

void CSnakeGameView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	tcs.SnakeMove();
	int x = tcs.collision();
	if(x == 1)
	{
		KillTimer(1);
		AfxMessageBox("撞墙游戏结束！");
		
		
	}
	else if(x == 2)
	{
		KillTimer(1);
		AfxMessageBox("撞自己游戏结束！");
	}
	if(x != 1 && x != 2)
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CSnakeGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case 37:
		tcs.m_direct = 4;//左
		break;
	case 38:
		tcs.m_direct = 8;//上
		break;
	case 39:
		tcs.m_direct = 6;//右
		break;
	case 40:
		tcs.m_direct = 2;//下
		break;
	default:
		break;
	}
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}





    
