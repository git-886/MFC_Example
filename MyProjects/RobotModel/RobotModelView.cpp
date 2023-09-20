// RobotModelView.cpp : implementation of the CRobotModelView class
//

#include "stdafx.h"
#include "RobotModel.h"

#include "RobotModelDoc.h"
#include "RobotModelView.h"
#include "OpenRobot.h"
#include "DlgCreateRobot.h"
#include "DlgDeleteRobot.h"
#include "DlgSaveRobotToFile.h"
#include "DlgRobotParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView

IMPLEMENT_DYNCREATE(CRobotModelView, CView)

BEGIN_MESSAGE_MAP(CRobotModelView, CView)
	//{{AFX_MSG_MAP(CRobotModelView)
	ON_COMMAND(ID_MENOpenRobot, OnMENOpenRobot)
	ON_COMMAND(ID_MENCreateRobot, OnMENCreateRobot)
	ON_COMMAND(ID_MENDelete, OnMENDelete)
	ON_COMMAND(ID_MENSaveToFile, OnMENSaveToFile)
	ON_COMMAND(ID_MENOpenParameterSetPanel, OnMENOpenParameterSetPanel)
	ON_COMMAND(ID_MENRobotMove, OnMENRobotMove)
	ON_COMMAND(ID_MENRobotJump, OnMENRobotJump)
	ON_COMMAND(ID_MENRobotWink, OnMENRobotWink)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENWaveHand, OnMENWaveHand)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView construction/destruction

CRobotModelView::CRobotModelView()
{
	// TODO: add construction code here

}

CRobotModelView::~CRobotModelView()
{
}

BOOL CRobotModelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView drawing

void CRobotModelView::OnDraw(CDC* pDC)
{
	CRobotModelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//m_Robot.RobotInit("robot1");
	m_Robot.Draw(pDC);
	
}

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView printing

BOOL CRobotModelView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobotModelView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobotModelView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView diagnostics

#ifdef _DEBUG
void CRobotModelView::AssertValid() const
{
	CView::AssertValid();
}

void CRobotModelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobotModelDoc* CRobotModelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotModelDoc)));
	return (CRobotModelDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView message handlers

//选择机器人进行打开
void CRobotModelView::OnMENOpenRobot() 
{
	// TODO: Add your command handler code here
	COpenRobot dlg;
	if(dlg.DoModal() == IDOK)
	{
		CString SelRobotName;
		SelRobotName = dlg.m_RobotName;
	//	GetDlgItemText(IDC_RobotName, SelRobotName);
		m_Robot.RobotInit(SelRobotName);
		Invalidate(true);
	}
}
//新建机器人
void CRobotModelView::OnMENCreateRobot() 
{
	// TODO: Add your command handler code here
	//存入数据到数据库
	CDlgCreateRobot dlg;
	m_Robot.InitCreateRobot();
	dlg.m_RobotName = m_Robot.RobotName;
	
	//将int转换为CString
	dlg.m_ZX_x.Format(_T("%d"), m_Robot.ZX_x);
	dlg.m_ZX_y.Format(_T("%d"), m_Robot.ZX_y);
	//将float转换为CString
	dlg.m_eyelr.Format(_T("%.4f"), m_Robot.eyelr);
	dlg.m_eyerr.Format(_T("%.4f"), m_Robot.eyerr);
	dlg.m_nosed.Format(_T("%.4f"), m_Robot.nosed);
	dlg.m_mouthr.Format(_T("%.4f"), m_Robot.mouthr);
	dlg.m_neckl.Format(_T("%.4f"), m_Robot.neckl);
	dlg.m_neckw.Format(_T("%.4f"), m_Robot.neckw);
	dlg.m_bodyl.Format(_T("%.4f"), m_Robot.bodyl);
	dlg.m_bodyw.Format(_T("%.4f"), m_Robot.bodyw);
	dlg.m_armll.Format(_T("%.4f"), m_Robot.armll);
	dlg.m_armlw.Format(_T("%.4f"), m_Robot.armlw);
	dlg.m_armrl.Format(_T("%.4f"), m_Robot.armrl);
	dlg.m_armrw.Format(_T("%.4f"), m_Robot.armrw);
	dlg.m_legll.Format(_T("%.4f"), m_Robot.legll);
	dlg.m_leglw.Format(_T("%.4f"), m_Robot.leglw);
	dlg.m_legrl.Format(_T("%.4f"), m_Robot.legrl);
	dlg.m_legrw.Format(_T("%.4f"), m_Robot.legrw);
	dlg.m_headr.Format(_T("%.4f"),m_Robot.headr);
	if(dlg.DoModal() == IDOK)
	{
		m_Robot.RobotName = dlg.m_RobotName;
		// 转换为 int 类型
		m_Robot.ZX_x = _ttoi(dlg.m_ZX_x);
		m_Robot.ZX_y = _ttoi(dlg.m_ZX_y);
		// 转换为 float类型
		m_Robot.eyelr = atof(dlg.m_eyelr);
		m_Robot.eyerr = atof(dlg.m_eyerr);
		m_Robot.nosed = atof(dlg.m_nosed);
		m_Robot.mouthr = atof(dlg.m_mouthr);
		m_Robot.neckw = atof(dlg.m_neckw);
		m_Robot.neckl = atof(dlg.m_neckl);
		m_Robot.bodyl = atof(dlg.m_bodyl);
		m_Robot.bodyw = atof(dlg.m_bodyw);
		m_Robot.armll = atof(dlg.m_armll);
		m_Robot.armlw = atof(dlg.m_armlw);
		m_Robot.armrw = atof(dlg.m_armrw);
		m_Robot.armrl = atof(dlg.m_armrl);
		m_Robot.legll = atof(dlg.m_legll);
		m_Robot.leglw = atof(dlg.m_leglw);
		m_Robot.headr = atof(dlg.m_headr);

		m_Robot.RobotCreate();
	}
}

void CRobotModelView::OnMENDelete() 
{
	// TODO: Add your command handler code here
	//删除数据库中机器人数据
	CDlgDeleteRobot dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_Robot.RobotDelete(dlg.m_DeletedRobotName);
	}
}

void CRobotModelView::OnMENSaveToFile() 
{
	// TODO: Add your command handler code here
	CDlgSaveRobotToFile dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_Robot.RobotSaveToFile(dlg.m_FilePath);
	}
}

void CRobotModelView::OnMENOpenParameterSetPanel() 
{
	// TODO: Add your command handler code here
	CDlgRobotParameterSet dlg;

	//将当前机器人参数显示到文本框中
	dlg.m_RobotName = m_Robot.RobotName;
	
	//将int转换为CString
	dlg.m_ZX_x.Format(_T("%d"), m_Robot.ZX_x);
	dlg.m_ZX_y.Format(_T("%d"), m_Robot.ZX_y);
	//将float转换为CString
	dlg.m_eyelr.Format(_T("%.4f"), m_Robot.eyelr);
	dlg.m_eyerr.Format(_T("%.4f"), m_Robot.eyerr);
	dlg.m_nosed.Format(_T("%.4f"), m_Robot.nosed);
	dlg.m_mouthr.Format(_T("%.4f"), m_Robot.mouthr);
	dlg.m_neckl.Format(_T("%.4f"), m_Robot.neckl);
	dlg.m_neckw.Format(_T("%.4f"), m_Robot.neckw);
	dlg.m_bodyl.Format(_T("%.4f"), m_Robot.bodyl);
	dlg.m_bodyw.Format(_T("%.4f"), m_Robot.bodyw);
	dlg.m_armll.Format(_T("%.4f"), m_Robot.armll);
	dlg.m_armlw.Format(_T("%.4f"), m_Robot.armlw);
	dlg.m_armrl.Format(_T("%.4f"), m_Robot.armrl);
	dlg.m_armrw.Format(_T("%.4f"), m_Robot.armrw);
	dlg.m_legll.Format(_T("%.4f"), m_Robot.legll);
	dlg.m_leglw.Format(_T("%.4f"), m_Robot.leglw);
	dlg.m_legrl.Format(_T("%.4f"), m_Robot.legrl);
	dlg.m_legrw.Format(_T("%.4f"), m_Robot.legrw);
	dlg.m_headr.Format(_T("%.4f"),m_Robot.headr);
	if(dlg.DoModal() == IDOK)
	{
		m_Robot.RobotName = dlg.m_RobotName;
		//修改将当前机器人参数
		// 转换为 int 类型
		m_Robot.ZX_x = _ttoi(dlg.m_ZX_x);
		m_Robot.ZX_y = _ttoi(dlg.m_ZX_y);
		// 转换为 float类型
		m_Robot.eyelr = atof(dlg.m_eyelr);
		m_Robot.eyerr = atof(dlg.m_eyerr);
		m_Robot.nosed = atof(dlg.m_nosed);
		m_Robot.mouthr = atof(dlg.m_mouthr);
		m_Robot.neckw = atof(dlg.m_neckw);
		m_Robot.neckl = atof(dlg.m_neckl);
		m_Robot.bodyl = atof(dlg.m_bodyl);
		m_Robot.bodyw = atof(dlg.m_bodyw);
		m_Robot.armll = atof(dlg.m_armll);
		m_Robot.armlw = atof(dlg.m_armlw);
		m_Robot.armrw = atof(dlg.m_armrw);
		m_Robot.armrl = atof(dlg.m_armrl);
		m_Robot.legll = atof(dlg.m_legll);
		m_Robot.leglw = atof(dlg.m_leglw);
		m_Robot.legrl = atof(dlg.m_legrl);
		m_Robot.legrw = atof(dlg.m_legrw);
		m_Robot.headr = atof(dlg.m_headr);
		m_Robot.RobotUpdate();
		Invalidate(true);
	}
}

void CRobotModelView::OnMENRobotMove() 
{
	// TODO: Add your command handler code here
	m_Robot.m_t = 0;
	m_flg = 1;
	SetTimer(1,100,NULL);
	
}

void CRobotModelView::OnMENRobotJump() 
{
	// TODO: Add your command handler code here
	m_Robot.m_t = 0;
	m_flg = 2;
	SetTimer(1,100,NULL);
	
}

void CRobotModelView::OnMENRobotWink() 
{
	// TODO: Add your command handler code here
	m_flg = 3;
	m_Robot.RobotWink();
	SetTimer(1,100,NULL);
}

void CRobotModelView::OnMENWaveHand() 
{
	// TODO: Add your command handler code here
	m_flg = 4;
	SetTimer(1,100,NULL);
}

void CRobotModelView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flg == 1)
		m_Robot.RobotMove();
	if(m_flg == 2)
		m_Robot.RobotJump();
	if(m_flg == 4)
		m_Robot.RobotWaveHand();
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}


