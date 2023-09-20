// RobertInspectionView.cpp : implementation of the CRobertInspectionView class
//

#include "stdafx.h"
#include "RobertInspection.h"

#include "RobertInspectionDoc.h"
#include "RobertInspectionView.h"
#include "DlgRotateParameterSet.h"
#include "DlgInitCarPosLeakPointCheck.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionView

IMPLEMENT_DYNCREATE(CRobertInspectionView, CView)

BEGIN_MESSAGE_MAP(CRobertInspectionView, CView)
	//{{AFX_MSG_MAP(CRobertInspectionView)
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENUITEMMoveUniform, OnMENUITEMMoveUniform)
	ON_COMMAND(ID_MENUITEMMoveSpecifiedPoint, OnMENUITEMMoveSpecifiedPoint)
	ON_COMMAND(ID_MENUITEMMoveRotate, OnMENUITEMMoveRotate)
	ON_COMMAND(ID_MENUITEMMapControl, OnMENUITEMMapControl)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMStop, OnMENUITEMStop)
	ON_COMMAND(ID_MENUITEMSpecifyPath, OnMENUITEMSpecifyPath)
	ON_COMMAND(ID_MENUITEMSpecifyPathStart, OnMENUITEMSpecifyPathStart)
	ON_COMMAND(ID_MENUITEMSpecifyPathStop, OnMENUITEMSpecifyPathStop)
	ON_COMMAND(ID_MENUITEMParticleStart, OnMENUITEMParticleStart)
	ON_COMMAND(ID_MENUITEMParticleStop, OnMENUITEMParticleStop)
	ON_COMMAND(ID_MENUITEMTestParticleConcentration, OnMENUITEMTestParticleConcentration)
	ON_COMMAND(ID_MENUITEMCheckStart, OnMENUITEMCheckStart)
	ON_COMMAND(ID_MENUITEMCheckStop, OnMENUITEMCheckStop)
	ON_COMMAND(ID_MENUITEMInitCarPos, OnMENUITEMInitCarPos)
	ON_COMMAND(ID_MENUITEMUAVStartCheck, OnMENUITEMUAVStartCheck)
	ON_COMMAND(ID_MENUITEMUAVStopCheck, OnMENUITEMUAVStopCheck)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionView construction/destruction

CRobertInspectionView::CRobertInspectionView()
{
	// TODO: add construction code here

	m_flag_LBD = 0;
	m_flag_Map = 0;
	m_flag_Test = 1;
	m_LBDNdTest.x = 0;
	m_LBDNdTest.y = 0;

}

CRobertInspectionView::~CRobertInspectionView()
{
}

BOOL CRobertInspectionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionView drawing

void CRobertInspectionView::OnDraw(CDC* pDC)
{
	CRobertInspectionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	m_scene.Draw(pDC);
	m_car.Draw(pDC);
	m_uav.Draw(pDC);

}

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionView printing

BOOL CRobertInspectionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobertInspectionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobertInspectionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionView diagnostics

#ifdef _DEBUG
void CRobertInspectionView::AssertValid() const
{
	CView::AssertValid();
}

void CRobertInspectionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobertInspectionDoc* CRobertInspectionView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobertInspectionDoc)));
	return (CRobertInspectionDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionView message handlers

BOOL CRobertInspectionView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flag_Map == 1)
	{
		if(zDelta > 0)
		{
			m_scene.m_kx = m_scene.m_kx * 1.2;
			m_scene.m_ky = m_scene.m_ky * 1.2;

			m_car.m_kx = m_car.m_kx * 1.2;
			m_car.m_ky = m_car.m_ky * 1.2;

			m_uav.m_kx = m_uav.m_kx * 1.2;
			m_uav.m_ky = m_uav.m_ky * 1.2;
			
		}
		if(zDelta < 0)
		{
			m_scene.m_kx = m_scene.m_kx * 0.8;
			m_scene.m_ky = m_scene.m_ky * 0.8;

			m_car.m_kx = m_car.m_kx * 0.8;
			m_car.m_ky = m_car.m_ky * 0.8;

			m_uav.m_kx = m_uav.m_kx * 0.8;
			m_uav.m_ky = m_uav.m_ky * 0.8;
		}
		Invalidate(true);
	}
	
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CRobertInspectionView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(m_car.m_flag_MoveWay == 1)
	{
		m_car.MoveBySpecifiedPoint(point.x,point.y);
		Invalidate(true);
	}
	if(m_car.m_flag_MoveWay == 2)
	{
		m_car.LBDProcess(point);
		Invalidate(true);
	}
	if(m_car.m_flag_MoveWay == 4)
	{ 	
		m_car.m_PointGJ[m_car.m_nPointGJ].x = (point.x - m_car.m_YD.x)/m_car.m_kx;
		m_car.m_PointGJ[m_car.m_nPointGJ].y = (point.y - m_car.m_YD.y)/m_car.m_ky;
		Invalidate(true);
		m_car.m_nPointGJ++;
	}

	if(m_flag_Map == 1)
	{
		m_flag_LBD = 1;
		m_xInit = m_scene.m_YD.x;
		m_yInit = m_scene.m_YD.y;

		m_yInitCar = m_car.m_YD.y;
		m_xInitCar = m_car.m_YD.x;

		m_xInitUAV = m_uav.m_YD.x;
		m_yInitUAV = m_uav.m_YD.y;
		m_LBD = point;
	}
	if(m_flag_Test == 1)
	{
		m_LBDNdTest = point;
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CRobertInspectionView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flag_Map == 1)
	{
		m_flag_LBD = 0;
	}
	

	CView::OnLButtonUp(nFlags, point);
}

void CRobertInspectionView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_flag_Map == 1)
	{
		if(m_flag_LBD == 1)
		{
			m_scene.m_YD.x = m_xInit + point.x - m_LBD.x;
			m_scene.m_YD.y = m_yInit + point.y - m_LBD.y;

			m_car.m_YD.x = m_xInitCar + point.x - m_LBD.x;
			m_car.m_YD.y = m_yInitCar + point.y - m_LBD.y;

			m_uav.m_YD.x = m_xInitUAV + point.x - m_LBD.x;
			m_uav.m_YD.y = m_yInitUAV + point.y - m_LBD.y;
			Invalidate(true);
		}
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CRobertInspectionView::OnMENUITEMMoveUniform() 
{
	// TODO: Add your command handler code here
	m_flag_Map = 0;
	m_car.m_flag_MoveWay = 2;
	SetTimer(1,100,NULL);
	
}

void CRobertInspectionView::OnMENUITEMMoveSpecifiedPoint() 
{
	// TODO: Add your command handler code here
	m_flag_Map = 0;
	m_car.m_flag_MoveWay = 1;
	KillTimer(1);
	
}

void CRobertInspectionView::OnMENUITEMMoveRotate() 
{
	// TODO: Add your command handler code here
	m_flag_Map = 0;
	CDlgRotateParameterSet dlg;
	dlg.m_direction = m_car.m_dir;
	dlg.m_r = m_car.m_r;
	dlg.m_SSZNSZ = m_car.m_Flag_SN;
	dlg.m_w = m_car.m_wv * 180.0/PI;
	if(dlg.DoModal() == 1)
	{
		m_car.m_Flag_SN = dlg.m_SSZNSZ;
		m_car.m_r = dlg.m_r;
		m_car.m_dir = dlg.m_direction;
		m_car.m_wv = dlg.m_w * PI/180.0;
	}
	m_car.m_flag_MoveWay = 3;
    //m_car.m_InitJD = (12 + 3 - m_car.m_dir) * PI/6.0;
	m_car.m_JD = (12 + 3 - m_car.m_dir) * PI/6.0;
	m_car.QuiYunaXin();
	SetTimer(1,100,NULL);
	
}

void CRobertInspectionView::OnMENUITEMMapControl() 
{
	// TODO: Add your command handler code here
	m_flag_Map = 1;
	//m_car.m_flag_MoveWay = 0;
	
}

void CRobertInspectionView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		int i;
		i = m_car.Move();
		Invalidate(true);
		if(i == 1 && m_car.m_flag_MoveWay == 4)
		{
			m_car.m_nPointGJ = 0;//移动到终点，重置数组
			m_car.m_nCur = 0;
		}
		if(i == 1)
		{
			KillTimer(1);
		}
	}
	if(nIDEvent == 2)//2号时钟为泄露粒子移动时钟
	{
		m_scene.ParticleCreate();
		m_scene.ParticleMove();
		m_scene.m_nd = m_scene.GetConcentration((m_LBDNdTest.x - m_scene.m_YD.x) / m_scene.m_kx,(m_LBDNdTest.y - m_scene.m_YD.y) / m_scene.m_ky);
		m_car.m_nd = m_scene.GetConcentration(m_car.m_x,m_car.m_y);
		//Invalidate(true);
	}
	if(nIDEvent == 3)//3号时钟为检测泄露小车移动时钟
	{
		//m_car.MoveToLeakPoint(m_scene.GetMaxConcentrationDirection(m_car.m_x,m_car.m_y));
		m_car.RotateMethodFindLeakPoint(m_scene.GetConcentration(m_car.m_x,m_car.m_y));
		m_car.m_nd = m_scene.GetConcentration(m_car.m_x,m_car.m_y);//用于显示当前小车所在点浓度值
		Invalidate(true);
	}
	if(nIDEvent == 4)//4号时钟为检测泄露无人机移动时钟
	{
		m_uav.PropellerRotate();
		m_uav.m_nd = m_scene.GetConcentration(m_uav.m_x,m_uav.m_y);//用于显示当前小车所在点浓度值
		Invalidate(true);
	}
	
	CView::OnTimer(nIDEvent);
}

void CRobertInspectionView::OnMENUITEMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CRobertInspectionView::OnMENUITEMSpecifyPath() //指定路径移动-设置路径
{
	// TODO: Add your command handler code here
	m_car.m_flag_MoveWay = 4;
}

void CRobertInspectionView::OnMENUITEMSpecifyPathStart() //指定路径开始移动
{
	// TODO: Add your command handler code here
	m_car.InitSpecifyPoint(m_car.m_PointGJ[0].x,m_car.m_PointGJ[0].y);//将小车移动到初始点
	Invalidate(true);
	SetTimer(1,100,NULL);
}

void CRobertInspectionView::OnMENUITEMSpecifyPathStop() //指定路径停止移动
{
	// TODO: Add your command handler code here
	KillTimer(1);	
}

void CRobertInspectionView::OnMENUITEMParticleStart() 
{
	// TODO: Add your command handler code here
	SetTimer(2,100,NULL);
}

void CRobertInspectionView::OnMENUITEMParticleStop() 
{
	// TODO: Add your command handler code here
	KillTimer(2);
	
}

void CRobertInspectionView::OnMENUITEMTestParticleConcentration() 
{
	// TODO: Add your command handler code here
	m_flag_Test = 1;
}

void CRobertInspectionView::OnMENUITEMCheckStart() 
{
	// TODO: Add your command handler code here
	SetTimer(3,100,NULL);
}

void CRobertInspectionView::OnMENUITEMCheckStop() 
{
	// TODO: Add your command handler code here
	KillTimer(3);
}

void CRobertInspectionView::OnMENUITEMInitCarPos() 
{
	// TODO: Add your command handler code here
	CDlgInitCarPosLeakPointCheck dlg;
	dlg.m_X = m_car.m_x;
	dlg.m_Y = m_car.m_y;
	if(dlg.DoModal() == 1)
	{
		m_car.m_x = dlg.m_X;
		m_car.m_y = dlg.m_Y;
		m_car.RotCircleInit(m_scene.GetConcentration(m_car.m_x,m_car.m_y),m_car.m_x,m_car.m_y);
		Invalidate(true);
	}
}

void CRobertInspectionView::OnMENUITEMUAVStartCheck() 
{
	// TODO: Add your command handler code here
	SetTimer(4,100,NULL);
}

void CRobertInspectionView::OnMENUITEMUAVStopCheck() 
{
	// TODO: Add your command handler code here
	KillTimer(4);
}

void CRobertInspectionView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case VK_LEFT:
		m_uav.m_x -= 5;
		break;
	case VK_RIGHT:
		m_uav.m_x += 5;
		break;
	case VK_UP:
		m_uav.m_y += 5;
		break;
	case VK_DOWN:
		m_uav.m_y -= 5;
		break;
	}
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
