// TankGameView.cpp : implementation of the CTankGameView class
//

#include "stdafx.h"
#include "TankGame.h"

#include "TankGameDoc.h"
#include "TankGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankGameView

IMPLEMENT_DYNCREATE(CTankGameView, CView)

BEGIN_MESSAGE_MAP(CTankGameView, CView)
	//{{AFX_MSG_MAP(CTankGameView)
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankGameView construction/destruction

CTankGameView::CTankGameView()
{
	// TODO: add construction code here

}

CTankGameView::~CTankGameView()
{
}

BOOL CTankGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTankGameView drawing

void CTankGameView::OnDraw(CDC* pDC)
{
	CTankGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_TankWar.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CTankGameView printing

BOOL CTankGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTankGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTankGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTankGameView diagnostics

#ifdef _DEBUG
void CTankGameView::AssertValid() const
{
	CView::AssertValid();
}

void CTankGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTankGameDoc* CTankGameView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTankGameDoc)));
	return (CTankGameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankGameView message handlers

void CTankGameView::OnMENUITEMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
	SetTimer(2,1000,NULL);
}

void CTankGameView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//nIDEvent:时钟标识
	switch(nIDEvent)
	{
	case 1:
		m_TankWar.CircleMove();
		m_TankWar.RectangleMove();
		m_TankWar.TriangleMove();
		m_TankWar.BulletMove();
		m_TankWar.CircleHit();
		m_TankWar.RectangleHit();
		m_TankWar.TriangleHit();

		if(m_TankWar.CircleGameOver() == 1 || m_TankWar.RectangleGameOver() == 1 || m_TankWar.TriangleGameOver() == 1)
		{
			
            KillTimer(1);
			KillTimer(2);
			AfxMessageBox("坦克被击毁，游戏结束！");
			
		}
		break;
	case 2:
		m_TankWar.Produce();//产生一个随机数，根据随机数来产生目标图像，保存图像产生的随机性
		break;
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CTankGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	m_TankWar.TankMove(nChar);
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
