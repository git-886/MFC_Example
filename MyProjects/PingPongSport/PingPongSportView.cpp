// PingPongSportView.cpp : implementation of the CPingPongSportView class
//

#include "stdafx.h"
#include "PingPongSport.h"

#include "PingPongSportDoc.h"
#include "PingPongSportView.h"
#include "DlgPingPongParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportView

IMPLEMENT_DYNCREATE(CPingPongSportView, CView)

BEGIN_MESSAGE_MAP(CPingPongSportView, CView)
	//{{AFX_MSG_MAP(CPingPongSportView)
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_COMMAND(ID_MENUITEMStop, OnMENUITEMStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMParameterSet, OnMENUITEMParameterSet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportView construction/destruction

CPingPongSportView::CPingPongSportView()
{
	// TODO: add construction code here

}

CPingPongSportView::~CPingPongSportView()
{
}

BOOL CPingPongSportView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportView drawing

void CPingPongSportView::OnDraw(CDC* pDC)
{
	CPingPongSportDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_dp.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportView printing

BOOL CPingPongSportView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPingPongSportView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPingPongSportView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportView diagnostics

#ifdef _DEBUG
void CPingPongSportView::AssertValid() const
{
	CView::AssertValid();
}

void CPingPongSportView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPingPongSportDoc* CPingPongSportView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPingPongSportDoc)));
	return (CPingPongSportDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportView message handlers

void CPingPongSportView::OnMENUITEMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
	
}

void CPingPongSportView::OnMENUITEMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CPingPongSportView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_dp.Move();
	if(m_dp.CJPanDuan() || m_dp.FGPanDuan() || m_dp.ZWPanDuan())
	{
		KillTimer(1);
	}
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CPingPongSportView::OnMENUITEMParameterSet() 
{
	// TODO: Add your command handler code here
	CDlgPingPongParameterSet dlg;
	dlg.m_SdX = m_dp.m_vx0;
	dlg.m_SdY = m_dp.m_vy0;
	dlg.m_SdZ = m_dp.m_vz0;

	dlg.m_ZbX = m_dp.m_x0;
	dlg.m_ZbY = m_dp.m_y0;
	dlg.m_ZbZ = m_dp.m_z0;

	if(dlg.DoModal() == 1)
	{
		m_dp.m_x0 = dlg.m_ZbX;
		m_dp.m_y0 = dlg.m_ZbY;
		m_dp.m_z0 = dlg.m_ZbZ;

		m_dp.m_vx0 = dlg.m_SdX;
		m_dp.m_vy0 = dlg.m_SdY;
		m_dp.m_vz0 = dlg.m_SdZ;

		m_dp.m_x = dlg.m_ZbX;
		m_dp.m_y = dlg.m_ZbY;
		m_dp.m_z = dlg.m_ZbZ;

		m_dp.m_vx = dlg.m_SdX;
		m_dp.m_vy = dlg.m_SdY;
		m_dp.m_vz = dlg.m_SdZ;


		m_dp.m_nxGj = 0;
		m_dp.m_nyGj = 0;
		m_dp.m_nzGj = 0;

		m_dp.m_nvxGj = 0;
		m_dp.m_nvyGj = 0;
		m_dp.m_nvzGj = 0;

		m_dp.m_Ftsum = 0;
		Invalidate(true);

	}

	
}
