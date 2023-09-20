// SinxCosxView.cpp : implementation of the CSinxCosxView class
//

#include "stdafx.h"
#include "SinxCosx.h"

#include "SinxCosxDoc.h"
#include "SinxCosxView.h"
#include "DlgParameterSetting.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxView

IMPLEMENT_DYNCREATE(CSinxCosxView, CView)

BEGIN_MESSAGE_MAP(CSinxCosxView, CView)
	//{{AFX_MSG_MAP(CSinxCosxView)
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMStop, OnMENUITEMStop)
	ON_COMMAND(ID_MENUITEMParameterSet, OnMENUITEMParameterSet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxView construction/destruction

CSinxCosxView::CSinxCosxView()
{
	// TODO: add construction code here

}

CSinxCosxView::~CSinxCosxView()
{
}

BOOL CSinxCosxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxView drawing

void CSinxCosxView::OnDraw(CDC* pDC)
{
	CSinxCosxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_dp.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxView printing

BOOL CSinxCosxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSinxCosxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSinxCosxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxView diagnostics

#ifdef _DEBUG
void CSinxCosxView::AssertValid() const
{
	CView::AssertValid();
}

void CSinxCosxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSinxCosxDoc* CSinxCosxView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSinxCosxDoc)));
	return (CSinxCosxDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxView message handlers

void CSinxCosxView::OnMENUITEMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
}

void CSinxCosxView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_dp.Move();
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CSinxCosxView::OnMENUITEMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	
}

void CSinxCosxView::OnMENUITEMParameterSet() 
{
	// TODO: Add your command handler code here
	CDlgParameterSetting dlg;
	dlg.m_W = m_dp.m_w*180.0/PI;
	dlg.m_ZF = m_dp.m_r;
	dlg.m_XW = m_dp.m_Initdeg * 180.0/PI;

	if(dlg.DoModal() == 1)
	{
		m_dp.m_w = dlg.m_W * PI / 180.0;
		m_dp.m_r = dlg.m_ZF;
		m_dp.m_Initdeg = dlg.m_XW * PI / 180.0;

		m_dp.m_nxGj = 0;
		m_dp.m_nyGj = 0;
		m_dp.m_deg = m_dp.m_Initdeg;

		m_dp.m_Initx = m_dp.m_r * cos(m_dp.m_Initdeg);
	    m_dp.m_Inity = m_dp.m_r * sin(m_dp.m_Initdeg); 

		m_dp.m_x = m_dp.m_r * cos(m_dp.m_Initdeg);
		m_dp.m_y = m_dp.m_r * sin(m_dp.m_Initdeg);
        m_dp.m_nVx = 0;
		m_dp.m_nVy = 0;
		m_dp.m_nAx = 0;
		m_dp.m_nAy = 0;

	}
	
	
}
