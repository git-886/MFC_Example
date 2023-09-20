// Spring.cpp: implementation of the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpringSport.h"
#include "Spring.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpring::CSpring()
{
	//弹簧
	m_initL = 170;
	m_nowL = m_initL;
	m_phL = 150;  //平衡长度
	m_LeftUp.x = 200;  //弹簧左上角坐标
	m_LeftUp.y = 100;
	m_wSpring = 50;  //弹簧宽度
	m_kSpring = 5;  //弹簧的弹性系数
	m_znSpring = 0.95; //弹簧的阻尼系数

	m_Line = 20;  //弹簧与小球之间的连线长度

	//小球
	m_rCir = 10; //小球半径
	m_xCenter = m_LeftUp.x + m_wSpring / 2; //小球中心坐标
	m_yCenter = m_LeftUp.y + m_nowL + m_Line + m_rCir;
	m_initV = 5; //初速度

	m_mCir = 5; //小球质量

	m_nyCir = 0;
	m_nvCir = 0;
	m_naCir = 0;
	m_nfCir = 0;
}

CSpring::~CSpring()
{

}

void CSpring::Draw(CDC *p)
{
	pDC = p;

	DrawSpring();
	DrawCircle();

	DrawYQuXian();
	DrawVQuXian();
	DrawAQuXian();
	DrawFQuXian();
}

//画弹簧
void CSpring::DrawSpring()
{
	int x, y, w, h;

	//弹簧悬挂顶部
	w = 200;
	x = (m_LeftUp.x + m_LeftUp.x + m_wSpring) / 2 - w / 2;
	y = m_LeftUp.y - 50;
	pDC->MoveTo(x, y);
	pDC->LineTo(x + w, y);
	pDC->MoveTo(x + w / 2, y);
	pDC->LineTo(x + w / 2, y + 50);

	//弹簧
	x = m_LeftUp.x;
	y = m_LeftUp.y;
	w = m_wSpring;
	h = m_nowL;
	pDC->Rectangle(x, y, x + w, y + h);
}

//画小球
void CSpring::DrawCircle()
{
	int x, y, r;

	//弹簧与小球连接的线
	pDC->MoveTo(m_xCenter, m_yCenter);
	pDC->LineTo(m_xCenter, m_yCenter - m_Line - m_rCir);

	//小球
	x = m_xCenter;
	y = m_yCenter;
	r = m_rCir;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
}

//画小球运动的y曲线
void CSpring::DrawYQuXian()
{
	//画刻度
	int initX = 500;
	int initY = 125;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "轨迹曲线");

	//画曲线
	int i;
	int x = initX;
	int y = initY + m_yCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nyCir; i++)
	{
		x += 1;
		y = initY + m_yCir[i];
		pDC->LineTo(x, y);
	}
}

//画小球运动的速度曲线
void CSpring::DrawVQuXian()
{
	//画刻度
	int initX = 900;
	int initY = 125;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "速度曲线");

	//画曲线
	int i;
	int x = initX;
	int y = initY + m_vCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nvCir; i++)
	{
		x += 1;
		y = initY + m_vCir[i];
		pDC->LineTo(x, y);
	}

}

//画小球的加速度曲线
void CSpring::DrawAQuXian()
{
	//画刻度
	int initX = 500;
	int initY = 425;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "加速度曲线");

	//画曲线
	int i;
	int x = initX;
	int y = initY + m_aCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_naCir; i++)
	{
		x += 1;
		y = initY + m_aCir[i];
		pDC->LineTo(x, y);
	}

}

//画小球的受力曲线
void CSpring::DrawFQuXian()
{
	//画刻度
	int initX = 900;
	int initY = 425;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "受力曲线");

	//画曲线
	int i;
	int x = initX;
	int y = initY + m_fCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nfCir; i++)
	{
		x += 1;
		y = initY + m_fCir[i];
		pDC->LineTo(x, y);
	}
}

//弹簧伸缩、小球运动
void CSpring::Move()
{
	float x = m_nowL - m_phL;  //弹簧的伸长量，伸长为正，缩短为负

	m_fCir[m_nfCir] = m_mCir * 9.8 - m_kSpring * x;    //F = mg - kx

	m_aCir[m_naCir] = m_fCir[m_nfCir] / m_mCir;  //a = F / m

	if (m_nvCir == 0)
	{
		m_vCir[m_nvCir] = m_initV;
	}
	else
	{
		m_vCir[m_nvCir] = m_vCir[m_nvCir - 1] + m_aCir[m_naCir - 1] * 0.1; //v = v0 + at
		x = m_vCir[m_nvCir - 1] * 0.1 + m_aCir[m_naCir - 1] * 0.1 * 0.1 / 2;    //x = v0 * t + 1/2 * a * t^2
		x *= m_znSpring;  //阻尼系数
	}

	m_nowL += x;

	m_yCenter = m_LeftUp.y + m_nowL + m_Line + m_rCir;;

	m_yCir[m_nyCir] = m_yCenter - m_LeftUp.y - m_initL - m_Line - m_rCir;

	m_nvCir++;
	m_naCir++;
	m_nfCir++;
	m_nyCir++;
}