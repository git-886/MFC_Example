// UAV.cpp: implementation of the CUAV class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RobertInspection.h"
#include "UAV.h"
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

CUAV::CUAV()
{
	m_x = 350;
	m_y = 200;
	m_w = 10;//无人机骨架长度m
	m_ProAngle = 0;
	m_wv = 30;//30°/ 0.1s



	m_nProp = 4;


}

CUAV::~CUAV()
{

}

void CUAV::Draw(CDC *p)
{
	pDC = p;
	DrawCUAV();
	DrawPropeller();
	CString str;
	str.Format("手动检测泄漏点无人机当前浓度：%d",m_nd);
	pDC->TextOut(1200,60,str);
}

void CUAV::DrawCUAV()//画无人机
{
	int x,y,r;
	int i = 0;
	r = m_w / 3.0 * m_kx;
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

	x = m_YD.x + (m_x - m_w) * m_kx;
	pDC->MoveTo(x,y);

	m_x -= m_w;
	m_Prop[i].x = m_x;
	m_Prop[i].y = m_y;
	i++;
	
	x = m_YD.x + (m_x + m_w * 2) * m_kx;
	pDC->LineTo(x,y);

	m_x += m_w * 2;
	m_Prop[i].x = m_x;
	m_Prop[i].y = m_y;
	i++;
	

	x = m_YD.x + (m_x - m_w) * m_kx;
	y = m_YD.y + m_y * m_ky + m_w * -m_kx;
	pDC->MoveTo(x,y);

	m_y += m_w;
	m_x -= m_w;
	m_Prop[i].x = m_x;
	m_Prop[i].y = m_y;
	i++;

	y -= m_w * 2 * -m_kx;
	pDC->LineTo(x,y);

	m_y -= m_w * 2;
	m_Prop[i].x = m_x;
	m_Prop[i].y = m_y;

	m_y += m_w;
}

void CUAV::DrawPropeller()//画螺旋桨-参数为螺旋桨中心点位置坐标
{
	int x,y;
	int i;
	float d = m_w / 2.0;//d为螺旋桨单支一半距离

	

	for(i = 0 ; i < m_nProp ; i++)
	{
		float sj_x,sj_y;
		sj_x = m_Prop[i].x - cos(m_ProAngle * PI/180.0) * d;
		sj_y = m_Prop[i].y - sin(m_ProAngle * PI/180.0) * d;

		x = m_YD.x + sj_x * m_kx;
		y = m_YD.y + sj_y * m_ky;
		pDC->MoveTo(x,y);

		sj_x = m_Prop[i].x + cos(m_ProAngle * PI/180.0) * d;
		sj_y = m_Prop[i].y + sin(m_ProAngle * PI/180.0) * d; 

		x = m_YD.x + sj_x * m_kx;
		y = m_YD.y + sj_y * m_ky;
		pDC->LineTo(x,y);
	}
	for(i = 0 ; i < m_nProp ; i++)
	{
		float sj_x,sj_y;
		sj_x = m_Prop[i].x - cos((m_ProAngle + 90) * PI/180.0) * d;
		sj_y = m_Prop[i].y - sin((m_ProAngle + 90) * PI/180.0) * d;

		x = m_YD.x + sj_x * m_kx;
		y = m_YD.y + sj_y * m_ky;
		pDC->MoveTo(x,y);

		sj_x = m_Prop[i].x + cos((m_ProAngle + 90) * PI/180.0) * d;
		sj_y = m_Prop[i].y + sin((m_ProAngle + 90) * PI/180.0) * d; 

		x = m_YD.x + sj_x * m_kx;
		y = m_YD.y + sj_y * m_ky;
		pDC->LineTo(x,y);
	}
	


}

void CUAV::PropellerRotate()
{
	float delatat = 0.1;
	m_ProAngle += m_wv * delatat;
}
