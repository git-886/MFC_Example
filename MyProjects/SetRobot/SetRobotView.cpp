// SetRobotView.cpp : implementation of the CSetRobotView class
//

#include "stdafx.h"
#include "SetRobot.h"
#include "SetRobotDoc.h"
#include "SetRobotView.h"
#include "DlgControlPanel.h"
#include "DlgRobotParameter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetRobotView

IMPLEMENT_DYNCREATE(CSetRobotView, CView)

BEGIN_MESSAGE_MAP(CSetRobotView, CView)
	//{{AFX_MSG_MAP(CSetRobotView)
	ON_COMMAND(ID_MENUITEMOpenControlPanel, OnMENUITEMOpenControlPanel)
	ON_COMMAND(ID_MENUITEMCreateRobot, OnMENUITEMCreateRobot)
	ON_COMMAND(ID_MENUITEMDeleteRobot, OnMENUITEMDeleteRobot)
	ON_COMMAND(ID_MENUITEMRobotParameterSet, OnMENUITEMRobotParameterSet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetRobotView construction/destruction

CSetRobotView::CSetRobotView()
{
	// TODO: add construction code here

}

CSetRobotView::~CSetRobotView()
{

}

BOOL CSetRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSetRobotView drawing

void CSetRobotView::OnDraw(CDC* pDC)
{
	CSetRobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_robot.Draw(pDC);

}

/////////////////////////////////////////////////////////////////////////////
// CSetRobotView printing

BOOL CSetRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSetRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSetRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSetRobotView diagnostics

#ifdef _DEBUG
void CSetRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CSetRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSetRobotDoc* CSetRobotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSetRobotDoc)));
	return (CSetRobotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSetRobotView message handlers

void CSetRobotView::OnBUTCreateRobot() 
{
	// TODO: Add your control notification handler code here
	m_robot.CreateRobot();
	Invalidate(true);
	if(dlg.Do() == 'create')
}

void CSetRobotView::OnMENUITEMOpenControlPanel() 
{
	// TODO: Add your command handler code here
	CDlgControlPanel dlg;
	dlg.DoModal();
}

void CSetRobotView::OnMENUITEMCreateRobot() 
{
	// TODO: Add your command handler code here
	m_robot.CreateRobot();
	Invalidate(true);
}

void CSetRobotView::OnMENUITEMDeleteRobot() 
{
	// TODO: Add your command handler code here
	m_robot.DeleteRobot();
	Invalidate(true);
}

void CSetRobotView::OnMENUITEMRobotParameterSet() 
{
	// TODO: Add your command handler code here
	CDlgRobotParameter dlg;
	if(dlg.DoModal() == 1)
	{
		/*if(dlg.m_ridUpdate - 1 > m_robot.m_nRob )
		{
			AfxMessageBox("不存在该机器人，请重新输入！");
		}
		else
		{
			m_robot.m_Robots[dlg.m_ridUpdate - 1].eyelr = dlg.m_eyelr;
			m_robot.m_Robots[dlg.m_ridUpdate - 1].eyerr = dlg.m_eyerr;
			m_robot.m_Robots[dlg.m_ridUpdate - 1].mouthr = dlg.m_mouthr;
			Invalidate(true);
			//dlg.UpdateData();
		}
		*/
		
	}
}


