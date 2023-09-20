// Robot1.cpp: implementation of the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robot.h"
#include "Robot1.h"
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

CRobot::CRobot()
{
	m_kx = 100;
	m_ky = -m_kx;
	ZX_y = -ZX_y;
}

CRobot::~CRobot()
{

}

void CRobot::RobotCreate()
{

}

void CRobot::RobotDelete()
{

}

void CRobot::RobotUpdate()
{

}

void CRobot::RobotSelect()
{

}

void CRobot::Draw(CDC *p)
{
	pDC = p;
	DrawRobot();
}

void CRobot::DrawRobot()
{
	float x,y,r;
	CPoint point[3];
	float a,b;//ÍÖÔ²µÄ³¤ÖáºÍ¶ÌÖá
	float w,l;//¾ØÐÎµÄ³¤ºÍ¿í

	
	
	//»­Í·
	x = ZX_x;
	y = ZX_y + (neckl + headr)* m_ky;
	r = headr * m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//»­ÑÛ¾¦-×ó
	x = ZX_x - headr/2.0 * m_kx;
	y = ZX_y + (neckl + headr * 3.0/2.0) * m_ky;
	r = eyelr * m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//»­ÑÛ¾¦-ÓÒ
	x = ZX_x + headr/2.0 * m_kx;
	y = ZX_y + (neckl + headr * 3.0/2.0) * m_ky;
	r = eyelr * m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//»­±Ç×Ó
	point[0].x = ZX_x;
	point[0].y = ZX_y + (neckl + headr)* m_ky + nosed * m_ky;
	point[1].x = ZX_x + (nosed * cos(PI / 6.0))*m_kx;
	point[1].y = ZX_y + (neckl + headr)* m_ky -(nosed * sin(PI / 6.0))*m_ky;
	point[2].x = ZX_x - (nosed * cos(PI / 6.0))*m_kx;
	point[2].y = ZX_y + (neckl + headr)* m_ky -(nosed * sin(PI / 6.0))*m_ky;
	pDC->Polygon(point, 3);
	//»­×ì°Í
	x = ZX_x;
	y = ZX_y + (neckl + headr / 2.0) * m_ky;
	r = mouthr * m_kx;
	pDC->Ellipse(x-r,y-r/2.0,x+r,y+r/2.0);
	//»­²±×Ó
	x = ZX_x - neckw / 2.0 * m_kx ;
	y = ZX_y + neckl * m_ky;
	w = neckw * m_kx;
	l = neckl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//»­ÉíÌå
	x = ZX_x - bodyw * m_kx / 2.0;
	y = ZX_y;
	w = bodyw * m_kx;
	l = bodyl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//»­¸ì²²-×ó±ß
	x = ZX_x - (bodyw/2.0 + armlw) * m_kx;
	y = ZX_y;
	w = armlw * m_kx;
	l = armll * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//»­¸ì²²-ÓÒ±ß
	x = ZX_x + (bodyw/2.0) * m_kx;
	y = ZX_y;
	w = armrw * m_kx;
	l = armrl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//»­ÍÈ-×ó±ß
	x = ZX_x - bodyw/2.0 * m_kx;
	y = ZX_y -bodyl * m_ky;
	w = leglw * m_kx;
	l = legll * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//»­ÍÈ-ÓÒ±ß
	x = ZX_x + (bodyw/2.0 - armrw) * m_kx;
	y = ZX_y -bodyl * m_ky;
	w = legrw * m_kx;
	l = legrl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
}

void CRobot::RobotInit(CString m_CurRobotName)
{
	m_Ado.OnInitADOConn(".\\Ado\\robots.mdb");
	CString sql,value;
	float a;

	sql.Format("select * from robots where RobotName = '%s'",m_CurRobotName);
	
	//»ñÈ¡¼ÇÂ¼¼¯
	m_Ado.GetRecordSet(sql);
	if(!m_Ado.m_pRecordset->adoEOF)
	{//m_Ado.m_pRecordset->MoveNext();//ÒÆ¶¯µ½ÏÂÒ»Ìõ¼ÇÂ¼
		
		
		RobotName = m_Ado.GetCollect("RobotName");
		
		value = m_Ado.GetCollect("eyelr");
		eyelr = atof(value);
		value = m_Ado.GetCollect("eyerr");
		eyerr = atof(value);
		value = m_Ado.GetCollect("nosed");
		nosed = atof(value);
		value = m_Ado.GetCollect("mouthr");
		mouthr = atof(value);
		value = m_Ado.GetCollect("headr");
		headr = atof(value);
		value = m_Ado.GetCollect("neckl");
		neckl = atof(value);
		value = m_Ado.GetCollect("neckw");
		neckw = atof(value);
		value = m_Ado.GetCollect("bodyw");
		bodyw = atof(value);
		value = m_Ado.GetCollect("bodyl");
		bodyl = atof(value);
		value = m_Ado.GetCollect("armll");
		armll = atof(value);
		value = m_Ado.GetCollect("armlw");
		armlw = atof(value);
		value = m_Ado.GetCollect("armrl");
		armrl = atof(value);
		value = m_Ado.GetCollect("armrw");
		armrw = atof(value);
		value = m_Ado.GetCollect("legll");
		legll = atof(value);
		value = m_Ado.GetCollect("leglw");
		leglw = atof(value);
		value = m_Ado.GetCollect("legrl");
		legrl = atof(value);
		value = m_Ado.GetCollect("legrw");
		legrw = atof(value);
	
		value = m_Ado.GetCollect("ZX_x");
		ZX_x = atoi(value);
		value = m_Ado.GetCollect("ZX_y");
		ZX_y = atoi(value);
	}


	m_Ado.ExitConnect();

}
