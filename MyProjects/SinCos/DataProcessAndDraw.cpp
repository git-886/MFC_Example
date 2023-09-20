// DataProcessAndDraw.cpp : implementation file
//

#include "stdafx.h"
#include "SinCos.h"
#include "DataProcessAndDraw.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define pi 3.1415926

/////////////////////////////////////////////////////////////////////////////
// CDataProcessAndDraw

CDataProcessAndDraw::CDataProcessAndDraw()
{
	m_nXl = 0;
	m_nYl = 0;
	deg = 0;

	m_xl = 100;
	m_yl = 0;
}

CDataProcessAndDraw::~CDataProcessAndDraw()
{
}


BEGIN_MESSAGE_MAP(CDataProcessAndDraw, CWnd)
	//{{AFX_MSG_MAP(CDataProcessAndDraw)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDataProcessAndDraw message handlers

void CDataProcessAndDraw::Draw(CDC *p)
{
	pDC = p;
	CString str;
	CircleDraw(110,200);
	DrawZbzAndKd(210,200);
	SinxDraw(210,200);
	str.Format("sinx");
	pDC->TextOut(410,300,str);

	

	CircleDraw(110,600);
	DrawZbzAndKd(210,600);
	CosxDraw(210,600);
	str.Format("cosx");
	pDC->TextOut(410,700,str);

}

void CDataProcessAndDraw::Move()
{

	
	m_xl = cos(deg)*100;
	m_yl = - sin(deg)*100;
	//deg+=pi/36;//每0.1秒增加旋转5度，角度单位换算为弧度
	deg += 0.0837;//

	m_Xl[m_nXl] = m_xl;
	m_Yl[m_nYl] = m_yl;
	m_nXl++;
	m_nYl++;
	
}
void CDataProcessAndDraw::CircleDraw(float x0,float y0)
{
	float x,y;
	int r = 100;
	x = x0;
	y = y0;

	pDC->Ellipse(x-r,y-r,x+r,y+r);

	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	


	pDC->MoveTo(x,y);
	x = x + m_xl;
	y = y + m_yl;
	pDC->LineTo(x,y);

	pDC->SelectObject(pOldPen);
	delete pPen;
}

void CDataProcessAndDraw::SinxDraw(float x0,float y0)
{
	
	int i,x,y;
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	for(i = 0 ; i < m_nYl ; i++)
	{
		y = y0 + m_Yl[i];
		x += 2.8;
		pDC->LineTo(x,y);
	}
}

void CDataProcessAndDraw::CosxDraw(float x0,float y0)
{
	int i,x,y;
	x = x0;
	y = y0 - 100;
    pDC->MoveTo(x,y);
	for(i = 0 ; i < m_nXl ; i++)
	{
		y = y0 - m_Xl[i];
		x += 2.777;
		pDC->LineTo(x,y);
	}
}

void CDataProcessAndDraw::DrawZbzAndKd(float x0,float y0)
{
	float x,y;
	//画x轴
	x = x0 - 200;
	y = y0;
	pDC->MoveTo(x,y);
	x = x + 600;
	pDC->LineTo(x,y);

	//画x轴箭头
	pDC->MoveTo(x,y);
	x = x - 5;
	y = y - 5;
	pDC->LineTo(x,y);
	x = x + 5;
	y = y + 5;
	pDC->MoveTo(x,y);
	x = x - 5;
	y = y + 5;
	pDC->LineTo(x,y);

	//画x刻度
	x = x0;
	y = y0;
	int i;
	for(i = 0 ; i < 8 ; i++)
	{
		x += 37.5;
		y = y0;
		pDC->MoveTo(x,y);
		y = y + 5;
		pDC->LineTo(x,y);
	}
	x = x0;
	y = y0;
	for(i = 1 ; i < 5 ; i++)
	{
		x += 70;
		y = y0 + 10;
		pDC->MoveTo(x,y);
		CString str;
		str.Format("%d pai",i);
		pDC->TextOut(x,y,str);
	}

	//画y轴
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y + 150;
	pDC->LineTo(x,y);
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y - 150;
	pDC->LineTo(x,y);
	
	//画y轴箭头
	x = x - 5;
	y = y + 5;
	pDC->LineTo(x,y);
	x = x + 5;
	y = y - 5;
	pDC->MoveTo(x,y);
	x = x + 5;
	y = y + 5;
	pDC->LineTo(x,y);

	//画y轴刻度
	x = x0;
	y = y0;
	y = y - 100;
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	CString str;
	str.Format("1");
	pDC->TextOut(x,y,str);

	x = x0;
	y = y0;
	y = y + 100;
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	str.Format("-1");
	pDC->TextOut(x,y,str);

}


