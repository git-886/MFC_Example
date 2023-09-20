// PIDAlgorithmView.cpp : implementation of the CPIDAlgorithmView class
//

#include "stdafx.h"
#include "PIDAlgorithm.h"

#include "PIDAlgorithmDoc.h"
#include "PIDAlgorithmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmView

IMPLEMENT_DYNCREATE(CPIDAlgorithmView, CView)

BEGIN_MESSAGE_MAP(CPIDAlgorithmView, CView)
	//{{AFX_MSG_MAP(CPIDAlgorithmView)
	ON_COMMAND(ID_MENUITEMSineMove, OnMENUITEMSineMove)
	ON_COMMAND(ID_MENUITEMUniformAccelerationMove, OnMENUITEMUniformAccelerationMove)
	ON_COMMAND(ID_MENUITEMUniformMove, OnMENUITEMUniformMove)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMPIDParametersControl, OnMENUITEMPIDParametersControl)
	ON_COMMAND(ID_MENUITEMStop, OnMENUITEMStop)
	ON_COMMAND(ID_MENUITEMContinue, OnMENUITEMContinue)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmView construction/destruction

CPIDAlgorithmView::CPIDAlgorithmView()
{
	// TODO: add construction code here

}

CPIDAlgorithmView::~CPIDAlgorithmView()
{
}

BOOL CPIDAlgorithmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmView drawing

void CPIDAlgorithmView::OnDraw(CDC* pDC)
{
	CPIDAlgorithmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_pid.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmView printing

BOOL CPIDAlgorithmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPIDAlgorithmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPIDAlgorithmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmView diagnostics

#ifdef _DEBUG
void CPIDAlgorithmView::AssertValid() const
{
	CView::AssertValid();
}

void CPIDAlgorithmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPIDAlgorithmDoc* CPIDAlgorithmView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPIDAlgorithmDoc)));
	return (CPIDAlgorithmDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmView message handlers

void CPIDAlgorithmView::OnMENUITEMSineMove() 
{
	// TODO: Add your command handler code here
	m_pid.m_way = 3;
	m_pid.InitTarAndCon();
	m_pid.InitPIDParameter();
	m_pid.CurveInit();
	SetTimer(1,100,NULL);
}

void CPIDAlgorithmView::OnMENUITEMUniformAccelerationMove() 
{
	// TODO: Add your command handler code here
	m_pid.m_way = 2;
	m_pid.InitTarAndCon();
	m_pid.InitPIDParameter();
	m_pid.CurveInit();
	SetTimer(1,100,NULL);
}

void CPIDAlgorithmView::OnMENUITEMUniformMove() 
{
	// TODO: Add your command handler code here
	m_pid.m_way = 1;
	m_pid.InitTarAndCon();
	m_pid.InitPIDParameter();
	m_pid.CurveInit();
	SetTimer(1,100,NULL);
}

void CPIDAlgorithmView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_pid.MoveTargetCar();
	m_pid.MoveControlCar_Displacement();
	m_pid.MoveControlCar_Speed();
	m_pid.MoveControlCar_Acceleration();
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CPIDAlgorithmView::OnMENUITEMPIDParametersControl() 
{
	// TODO: Add your command handler code here
	CDlgPIDParameterSet dlg;
	dlg.m_KPDis = m_pid.m_DisPid.Kp;
	dlg.m_KIDis = m_pid.m_DisPid.Ki;
	dlg.m_KDDis = m_pid.m_DisPid.Kd;

	dlg.m_KPSpe = m_pid.m_SpePid.Kp;
	dlg.m_KISpe = m_pid.m_SpePid.Ki;
	dlg.m_KDSpe = m_pid.m_SpePid.Kd;

	dlg.m_KPAcc = m_pid.m_AccPid.Kp;
	dlg.m_KIAcc = m_pid.m_AccPid.Ki;
	dlg.m_KDAcc = m_pid.m_AccPid.Kd;

	if(dlg.DoModal() == IDOK)
	{
		
		m_pid.m_DisPid.Kp = dlg.m_KPDis;
		m_pid.m_DisPid.Ki = dlg.m_KIDis;
		m_pid.m_DisPid.Kd = dlg.m_KDDis;

		m_pid.m_SpePid.Kp = dlg.m_KPSpe;
		m_pid.m_SpePid.Ki = dlg.m_KISpe;
		m_pid.m_SpePid.Kd = dlg.m_KDSpe;

		m_pid.m_AccPid.Kp = dlg.m_KPAcc;
		m_pid.m_AccPid.Ki = dlg.m_KIAcc;
		m_pid.m_AccPid.Kd = dlg.m_KDAcc;

		m_pid.InitTarAndCon();
	    m_pid.CurveInit();
		Invalidate(true);
	}
}

void CPIDAlgorithmView::OnMENUITEMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CPIDAlgorithmView::OnMENUITEMContinue() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
}
