// RobotView.cpp : implementation of the CRobotView class
//

#include "stdafx.h"
#include "Robot.h"
#include "DlgOpenRobot.h"

#include "RobotDoc.h"
#include "RobotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotView

IMPLEMENT_DYNCREATE(CRobotView, CView)

BEGIN_MESSAGE_MAP(CRobotView, CView)
	//{{AFX_MSG_MAP(CRobotView)
	ON_COMMAND(ID_MENOpenRobot, OnMENOpenRobot)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotView construction/destruction

CRobotView::CRobotView()
{
	// TODO: add construction code here

}

CRobotView::~CRobotView()
{
}

BOOL CRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotView drawing

void CRobotView::OnDraw(CDC* pDC)
{
	CRobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_Robot.RobotInit("robot1");
	m_Robot.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotView printing

BOOL CRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobotView diagnostics

#ifdef _DEBUG
void CRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobotDoc* CRobotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotDoc)));
	return (CRobotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotView message handlers

void CRobotView::OnMENOpenRobot() 
{
	// TODO: Add your command handler code here
	CDlgOpenRobot dlg;
	if(dlg.DoModal() == 'IDC_BUTOpenRobot')
	{
	//	dlg
		m_Robot.RobotInit("");
		
	}
}
