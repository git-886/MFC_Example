// TargetProcess.cpp : implementation file
//

#include "stdafx.h"
#include "TankWar.h"
#include "TargetProcess.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTargetProcess

CTargetProcess::CTargetProcess()
{
	m_bk_x = 100;
	m_bk_y = 50;
	m_bk_w = 650;
	pDC = NULL;
	m_sqnum = 0;
	m_cinum = 0;
	m_trnum = 0;
}

CTargetProcess::~CTargetProcess()
{
}


BEGIN_MESSAGE_MAP(CTargetProcess, CWnd)
	//{{AFX_MSG_MAP(CTargetProcess)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTargetProcess message handlers



void CTargetProcess::DrawTargetAndBK(CDC *p)
{
	pDC = p;
	DrawBK();//画边框
	DrawSquareTarget();//画正方形目标
	DrawCircleTarget();//画圆目标
	DrawTriangleTarget();//画三角形目标
}

void CTargetProcess::DrawBK()
{
	int x = m_bk_x;
	int y = m_bk_y;
	int w = m_bk_w;
	pDC->Rectangle(x,y,x + w,y + w);
}

void CTargetProcess::DrawSquareTarget()
{
	int i;
	for(i = 0; i < m_sqnum ; i++)
	{
		int x = m_square[i].x;
		int y = m_square[i].y;
		int w = m_square[i].w;
		if(i % 2 == 0)
		pDC->Rectangle(x,y,x + w,y + w);
	}
}

void CTargetProcess::ProduceSquare()
{
	int i;
	int m= m_sqnum;
	for(i = 0 ; i <= m ; i++)
	{
		m_square[i].x = 205;
	    m_square[i].y = 50 + i * 50;
	    m_square[i].w = 50;
	}
	if(m_sqnum < 19)
	m_sqnum++;
}



void CTargetProcess::ProduceCircle()
{
	m_circle[m_cinum].x = (rand()%651+100);
	m_circle[m_cinum].y = 50;
	m_circle[m_cinum].r = rand()%21 + 5;
	m_cinum++;
}

void CTargetProcess::DrawCircleTarget()
{
	int i;
	for(i = 0; i < m_cinum ; i++)
	{
		int x = m_circle[i].x;
		int y = m_circle[i].y;
		int r = m_circle[i].r;
		pDC->Ellipse(x - r,y - r,x + r,y + r);
	}
}



void CTargetProcess::DrawTriangleTarget()
{
	int i;
	for(i = 0; i < m_trnum ; i++)
	{
		int x = m_triangle[i].x;
		int y = m_triangle[i].y;
		int d = m_triangle[i].d;;
		if(i % 2 == 0)
		{
			double h = 50;
			double x1 = x;
			double y1 = y - h / 2;
			double x2 = x - d / 2;
			double y2 = y + h / 2;
			double x3 = x + d / 2;
			double y3 = y + h / 2;

			/*CBrush brush,*bru;
			brush.CreateSolidBrush(RGB(0,255,0));
			bru = pDC->SelectObject(&brush);
			*/
            pDC->MoveTo(x1,y1);
			pDC->LineTo(x2,y2);
			pDC->LineTo(x3,y3);
			pDC->LineTo(x1,y1);
			//pDC->SelectStockObject(NULL_BRUSH);
		}
	}
}

void CTargetProcess::ProduceTriangle()
{
	int m= m_trnum;
	int i;
	for(i = 0 ; i <= m ; i++)
	{
		m_triangle[i].x = 650;
		m_triangle[i].y = 75 + i * 50;
		m_triangle[i].d = 100*sqrt(3);
	}
	if(m_trnum < 19)
	m_trnum++;
}

void CTargetProcess::HitAndOutSquare()
{
	int i;
	if(m_square[0].y == m_bk_y + m_bk_w)//出界
	{
		for(i = 0 ; i < m_sqnum - 1 ; i++)
		{
			m_square[i].y = m_square[i+1].y;
		}
	}
	//if()击中判断
}


