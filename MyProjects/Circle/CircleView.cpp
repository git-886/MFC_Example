// CircleView.cpp : implementation of the CCircleView class
//

#include "stdafx.h"
#include "Circle.h"
#include "resource.h"
#include "CircleDoc.h"
#include "CircleView.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleView

IMPLEMENT_DYNCREATE(CCircleView, CView)

BEGIN_MESSAGE_MAP(CCircleView, CView)
	//{{AFX_MSG_MAP(CCircleView)
	
	ON_WM_TIMER()
	ON_COMMAND(ID_MDongHua, OnMDongHua)
	ON_COMMAND(ID_MStop, OnMStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleView construction/destruction

CCircleView::CCircleView()
{
	m_x=50;
	m_nPic=1;
	// TODO: add construction code here

}

CCircleView::~CCircleView()
{

}

BOOL CCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCircleView drawing



/////////////////////////////////////////////////////////////////////////////
// CCircleView printing

BOOL CCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCircleView diagnostics

#ifdef _DEBUG
void CCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCircleDoc* CCircleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCircleDoc)));
	return (CCircleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleView message handlers

//动画与停止响应处理函数

void CCircleView::OnMDongHua() //菜单动画消息响应函数
{
	SetTimer(1,100,NULL);
	// TODO: Add your command handler code here
}

void CCircleView::OnMStop() //菜单停止消息响应函数
{
	KillTimer(1);
	// TODO: Add your command handler code here
}
void CCircleView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_x+=10;
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CCircleView::DrawCircle(CDC *pDC, int x, int y, int r)
{
	pDC->Ellipse(x-r,y-r,x+r,y+r);
}
void CCircleView::OnMCircle()
{
	
	Invalidate(true);
}
void CCircleView::OnDraw(CDC* pDC)
{
	CCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(m_nPic==1)
	{
		DrawCircle(pDC,m_x,100,30);
	}
}








