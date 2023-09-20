// DataProcess.cpp: implementation of the CDataProcess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SinxCosx.h"
#include "DataProcess.h"
#include "math.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define PI 3.1415926

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataProcess::CDataProcess()
{
	m_X = 500;
	m_Y = 500;
	m_k = 200;

	
	m_Initdeg = 0;
	m_deg = m_Initdeg;
	m_r = 0.5;
	m_x = m_r * cos(m_deg/180.0*PI);
	m_y = m_r * sin(m_deg/180.0*PI);

	m_Initx = m_x;
	m_Inity = m_y;

	m_nxGj = 0;
	m_nyGj = 0;

	m_nVx = 0;
	m_nVy = 0;
	m_nAx = 0;
	m_nAy = 0;

	m_vx = m_x/0.1;//
	m_vy = m_y/0.1;

	m_ax = 0;
	m_ay = 0;

	
	

	m_w = 50*PI/180.0;//初始角速度为50度每秒

	

}

CDataProcess::~CDataProcess()
{

}

void CDataProcess::Move()
{
	float delata = 0.1;
	m_deg +=m_w*delata;
	float past_x = m_x;
	float past_y = m_y;
	m_x = m_r * cos(m_deg);
	m_y = m_r * sin(m_deg);

	m_xGj[m_nxGj] = m_x;
	m_yGj[m_nyGj] = m_y;
	m_nxGj++;
	m_nyGj++;

	float past_vx = m_vx;
	float past_vy = m_vy;
	m_vx = (m_x - past_x)/delata;
	m_vy = (m_y - past_y)/delata;
	m_Vx[m_nVx] = m_vx;
	m_Vy[m_nVy] = m_vy;
	m_nVx++;
	m_nVy++;

	m_ax = (m_vx - past_vx)/delata;
	m_ay = (m_vy - past_vy)/delata;
	m_Ax[m_nAx] = m_ax;
	m_Ay[m_nAy] = m_ay;
	m_nAx++;
	m_nAy++;

}

void CDataProcess::Draw(CDC *p)
{
	pDC = p;
	CString str;
	CircleDraw(310,400);
	DrawZbzAndKd(510,400);
	SinxDraw(510,400);
	CosxDraw(510,400);
	str.Format("sinx-红色 cosx-蓝色");
	pDC->TextOut(610,500,str);

	DrawZBZ(1000,180,"1m/s");
	DrawSpeedCurve(1000,180);
	str.Format("速度曲线-蓝色x方向 黑色y方向");
	pDC->TextOut(1200,320,str);

	DrawZBZ(1000,550,"1m/s^2");
	DrawAccelerationCurve(1000,550);
	str.Format("加速度曲线-蓝色x方向 黑色y方向");
	pDC->TextOut(1200,690,str);

	
}

void CDataProcess::CircleDraw(float x0,float y0)
{
	float x,y;
	int r = m_r*m_k;
	x = x0;
	y = y0;

	pDC->Ellipse(x-r,y-r,x+r,y+r);

	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	


	pDC->MoveTo(x,y);
	x = x + m_x*m_k;
	y = y - m_y*m_k;
	pDC->LineTo(x,y);

	pDC->SelectObject(pOldPen);
	delete pPen;
}

void CDataProcess::SinxDraw(float x0, float y0)
{
	int i,x,y;
	x = x0;
	y = y0 - m_Inity * m_k;
	pDC->MoveTo(x,y);

	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(255,0,0));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	for(i = 0 ; i < m_nyGj ; i++)
	{
		y = y0 - m_yGj[i]*m_k;
		x += 5;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen);
	delete pPen;
}

void CDataProcess::CosxDraw(float x0, float y0)
{
	int i,x,y;
	x = x0;
	y = y0 - m_Initx * m_k;
    pDC->MoveTo(x,y);
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,255));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	for(i = 0 ; i < m_nxGj ; i++)
	{
		y = y0 - m_xGj[i]*m_k;
		x += 5;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen);
	delete pPen;
}

void CDataProcess::DrawZbzAndKd(float x0, float y0)
{
	float x,y;
	//画x轴
	x = x0 - 500;
	y = y0;
	pDC->MoveTo(x,y);
	x = x + 900;
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
	for(i = 1 ; i <= 60 ; i++)
	{
		x += 5;
		y = y0;
		pDC->MoveTo(x,y);
		if(i % 10 == 0)
		y = y + 10;
		y = y + 5;
		pDC->LineTo(x,y);
	}
	x = x0;
	y = y0;
	for(i = 1 ; i < 7 ; i++)
	{
		x += 50;
		y = y0 + 10;
		pDC->MoveTo(x,y);
		CString str;
		str.Format("%d s",i);
		pDC->TextOut(x,y,str);
	}

	//画y轴
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y + 300;
	pDC->LineTo(x,y);
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y - 300;
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
	y = y - 1*m_k;//最大振幅为1m
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	CString str;
	str.Format("1 m");
	pDC->TextOut(x,y,str);

	x = x0;
	y = y0;
	y = y + 1*m_k;
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	str.Format("-1 m");
	pDC->TextOut(x,y,str);
}

void CDataProcess::DrawZBZ(float x0, float y0, char str[])
{
	float x = x0;
	float y = y0;
	pDC->MoveTo(x,y);
	x = x + 500;
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
	for(i = 1 ; i <= 60 ; i++)
	{
		x += 5;
		y = y0;
		pDC->MoveTo(x,y);
		if(i % 10 == 0)
		y = y + 10;
		y = y + 5;
		pDC->LineTo(x,y);
	}
	x = x0;
	y = y0;
	for(i = 1 ; i < 7 ; i++)
	{
		x += 50;
		y = y0 + 10;
		pDC->MoveTo(x,y);
		CString str;
		str.Format("%d s",i);
		pDC->TextOut(x,y,str);
	}

	//画y轴
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y + 180;
	pDC->LineTo(x,y);
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y - 180;
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
	y = y0 - 170;
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	pDC->TextOut(x,y,str);

	x = x0;
	y = y0 + 170;
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	CString s;
	s.Format("-");
	pDC->TextOut(x,y,s);
	pDC->TextOut(x+5,y,str);
}

void CDataProcess::DrawSpeedCurve(float x0,float y0)
{
	int i;
	float x = x0;
	float y = y0 - m_Vx[0] * m_k;
	pDC->MoveTo(x,y);
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,255));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	for(i = 1 ; i < m_nVx ; i++)
	{
		x += 5;
		y = y0 - m_Vx[i] * m_k;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen);
	delete pPen;
	//
	x = x0;
	y = y0 - m_Vy[0] * m_k;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nVy ; i++)
	{
		x += 5;
		y = y0 - m_Vy[i] * m_k;
		pDC->LineTo(x,y);
	}
	
}

void CDataProcess::DrawAccelerationCurve(float x0,float y0)
{
	int i;
	float x = x0;
	float y = y0 - m_Ax[0] * m_k;
	pDC->MoveTo(x,y);
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,255));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	for(i = 2 ; i < m_nAx ; i++)
	{
		x += 5;
		y = y0 - m_Ax[i] * m_k;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen);
	delete pPen;
	//
	x = x0;
	y = y0 - m_Ay[0] * m_k;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nAy ; i++)
	{
		x += 5;
		y = y0 - m_Ay[i] * m_k;
		pDC->LineTo(x,y);
	}
}
