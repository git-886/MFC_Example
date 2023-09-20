// Robots.cpp: implementation of the CRobots class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SetRobot.h"
#include "Robots.h"
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

CRobots::CRobots()
{
	m_nRob = 0;
	m_YDX = 300;//像素
	m_YDY = 700;

	m_ky = -864/10.0;
	m_kx = 1536/20.0;//10m
}

CRobots::~CRobots()
{

}

BOOL CRobots::CreateRobot()
{
	//创建一个机器人对象
	InitRobot();
	m_Robots[m_nRob] = m_robot;
	m_nRob++;
	//把机器人参数存入到数据库中

	CString sql,temp;
	float id,eyelr,eyerr,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,footll,footlw,footrl,footrw,X,Y;

	m_Ado.OnInitADOConn(".\\CAdo\\Robot1.mdb");
	/*
	sql="insert into robots (RID,eyelr,eyerr,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,footll,footlw,footrl,footrw,X,Y) values(";
	temp.Format("'%d','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f')",
		m_nRob,m_Robots[m_nRob-1].eyelr,m_Robots[m_nRob-1].eyerr,m_Robots[m_nRob-1].mouthr,m_Robots[m_nRob-1].headr,m_Robots[m_nRob-1].neckl,m_Robots[m_nRob-1].neckw,m_Robots[m_nRob-1].bodyl,m_Robots[m_nRob-1].bodyw,m_Robots[m_nRob-1].armll,m_Robots[m_nRob-1].armlw,m_Robots[m_nRob-1].armrl,m_Robots[m_nRob-1].armrw,m_Robots[m_nRob-1].legll,m_Robots[m_nRob-1].leglw,m_Robots[m_nRob-1].legrl,m_Robots[m_nRob-1].legrw,m_Robots[m_nRob-1].footll,m_Robots[m_nRob-1].footlw,m_Robots[m_nRob-1].footrl,m_Robots[m_nRob-1].footrw,m_Robots[m_nRob-1].x,m_Robots[m_nRob-1].y);
	sql += temp;

	sql.Format("insert into robots (RID,eyelr,eyerr,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,footll,footlw,footrl,footrw,X,Y) values('%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f','%f')",
		m_nRob,m_Robots[m_nRob-1].eyelr,m_Robots[m_nRob-1].eyerr,m_Robots[m_nRob-1].mouthr,m_Robots[m_nRob-1].headr,m_Robots[m_nRob-1].neckl,m_Robots[m_nRob-1].neckw,m_Robots[m_nRob-1].bodyl,m_Robots[m_nRob-1].bodyw,m_Robots[m_nRob-1].armll,m_Robots[m_nRob-1].armlw,m_Robots[m_nRob-1].armrl,m_Robots[m_nRob-1].armrw,m_Robots[m_nRob-1].legll,m_Robots[m_nRob-1].leglw,m_Robots[m_nRob-1].legrl,m_Robots[m_nRob-1].legrw,m_Robots[m_nRob-1].footll,m_Robots[m_nRob-1].footlw,m_Robots[m_nRob-1].footrl,m_Robots[m_nRob-1].footrw,m_Robots[m_nRob-1].x,m_Robots[m_nRob-1].y);
		*/
	
	sql="insert into robots (RID,eyelr,eyerr,mouthr) values(";
	temp.Format("'%d','%f','%f','%f')",
		m_nRob,m_Robots[m_nRob-1].eyelr,m_Robots[m_nRob-1].eyerr,m_Robots[m_nRob-1].mouthr);
	sql += temp;

	//sql.Format("insert into robots (RID,eyelr,eyerr,mouthr) values('%d','%f','%f','%f')",
		//m_nRob,m_Robots[m_nRob-1].eyelr,m_Robots[m_nRob-1].eyerr,m_Robots[m_nRob-1].mouthr);

	
	m_Ado.ExecuteSQL(sql);

	m_Ado.ExitConnect();

	AfxMessageBox("OK!");

	return true;
}

BOOL CRobots::DeleteRobot()
{
	//删除一个机器人
    m_nRob--;
	//从数据库中删除该机器人数据条目
	CAdo m_Ado;
	m_Ado.OnInitADOConn(".\\CAdo\\Robot1.mdb");
	//m_Ado.OnInitADOConn();

	CString sql;
	sql.Format("delete from robots where RID = %d",m_nRob+1);
	m_Ado.ExecuteSQL(sql);
	m_Ado.ExitConnect();

	AfxMessageBox("OK!");
	return true;
}
void CRobots::Draw(CDC *p)
{
	pDC = p;
	DrawRobot();
}

void CRobots::DrawRobot()
{
	int i;
	float x,y,w,l,r;
	for(i = 0 ; i < m_nRob ; i++)
	{
		x = m_YDX + m_Robots[i].headx * m_kx;
		y = m_YDY + m_Robots[i].heady * m_ky;
		r = m_Robots[i].headr * -m_ky;
		pDC->Ellipse(x-r,y-r,x+r,y+r);


		x = m_YDX + m_Robots[i].neckx * m_kx;
		y = m_YDY + m_Robots[i].necky * m_ky;
		l = m_Robots[i].neckl * m_ky;
		w = m_Robots[i].neckw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].eyelx * m_kx;
		y = m_YDY + m_Robots[i].eyely * m_ky;
		r = m_Robots[i].eyelr * -m_ky;
		pDC->Ellipse(x-r,y-r,x+r,y+r);

		x = m_YDX + m_Robots[i].eyerx * m_kx;
		y = m_YDY + m_Robots[i].eyery * m_ky;
		r = m_Robots[i].eyerr * -m_ky;
		pDC->Ellipse(x-r,y-r,x+r,y+r);

		CPoint pt[3] = {CPoint(m_Robots[i].nosex * m_kx,m_Robots[i].nosey * m_ky),
						CPoint((m_Robots[i].nosex + cos(PI/3.0)*m_Robots[i].noseb) * m_kx,(m_Robots[i].nosey-sin(PI/3.0)*m_Robots[i].noseb) * m_ky),
						CPoint((m_Robots[i].nosex - cos(PI/3.0)*m_Robots[i].noseb) * m_kx,(m_Robots[i].nosey-sin(PI/3.0)*m_Robots[i].noseb) * m_ky)};
		pDC->Polygon(pt,3);

		x = m_YDX + m_Robots[i].mouthx * m_kx;
		y = m_YDY + m_Robots[i].mouthy * m_ky;
		r = m_Robots[i].mouthr * -m_ky;
		pDC->Ellipse(x-r,y-r,x+r,y+r);

		x = m_YDX + m_Robots[i].bodyx * m_kx;
		y = m_YDY + m_Robots[i].bodyy * m_ky;
		l = m_Robots[i].bodyl * m_kx;
		w = m_Robots[i].bodyw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].armlx * m_kx;
		y = m_YDY + m_Robots[i].armly * m_ky;
		l = m_Robots[i].armll * m_kx;
		w = m_Robots[i].armlw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].armrx * m_kx;
		y = m_YDY + m_Robots[i].armry * m_ky;
		l = m_Robots[i].armrl * m_kx;
		w = m_Robots[i].armrw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].leglx * m_kx;
		y = m_YDY + m_Robots[i].legly * m_ky;
		l = m_Robots[i].legll * m_kx;
		w = m_Robots[i].leglw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].legrx * m_kx;
		y = m_YDY + m_Robots[i].legry * m_ky;
		l = m_Robots[i].legrl * m_kx;
		w = m_Robots[i].legrw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].footlx * m_kx;
		y = m_YDY + m_Robots[i].footly * m_ky;
		l = m_Robots[i].footll * m_kx;
		w = m_Robots[i].footlw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);

		x = m_YDX + m_Robots[i].footrx * m_kx;
		y = m_YDY + m_Robots[i].footry * m_ky;
		l = m_Robots[i].footrl * m_kx;
		w = m_Robots[i].footrw * m_kx;
		pDC->Rectangle(x,y,x+w,y+l);
	}
}

void CRobots::InitRobot()
{
	//初始中心点
	m_robot.x = 0.2 * (m_nRob * 6 + 1);
	m_robot.y = 1.52 ;

	//初始脖子
	m_robot.neckw = 0.15;
	m_robot.neckl = 0.20;
	m_robot.neckx = m_robot.x -  0.15/2.0;
	m_robot.necky = m_robot.y + m_robot.neckl;

	//初始头
	m_robot.headr = 0.275;
	m_robot.headx = m_robot.x;
	m_robot.heady = m_robot.y + m_robot.neckl + m_robot.headr * 1.7;

	//初始化眼睛
	m_robot.eyelx = m_robot.headx - 0.1;
	m_robot.eyely = m_robot.heady + 0.02;
	m_robot.eyelr = 0.05;

	m_robot.eyerx = m_robot.headx + 0.1;
	m_robot.eyery = m_robot.heady + 0.02;
	m_robot.eyerr = 0.05;

	//初始化鼻子
	m_robot.noseb = 0.1;
	m_robot.nosex = m_robot.headx;
	m_robot.nosey = m_robot.heady + 0.1;

	//初始化嘴巴
	m_robot.mouthx = m_robot.headx;
	m_robot.mouthy = m_robot.heady - 0.14;
	m_robot.mouthr = 0.06;

	//初始化身体
	m_robot.bodyl = 0.8;
	m_robot.bodyw = 0.6;
	m_robot.bodyx = m_robot.x - m_robot.bodyw / 2.0;
	m_robot.bodyy = m_robot.y * 1.13;
	
	//初始化手臂
	m_robot.armll = 0.3;
	m_robot.armlw = 0.2;
	m_robot.armlx = m_robot.bodyx - m_robot.armlw;
	m_robot.armly = m_robot.bodyy;

	m_robot.armrl = 0.3;
	m_robot.armrw = 0.2;
	m_robot.armrx = m_robot.bodyx + m_robot.bodyw;
	m_robot.armry = m_robot.bodyy;

	//初始化腿
	m_robot.legll = 0.5;
	m_robot.leglw = 0.2;
	m_robot.leglx = m_robot.bodyx;
	m_robot.legly = m_robot.bodyy - m_robot.bodyl * 0.9;


	m_robot.legrl = 0.5;
	m_robot.legrw = 0.2;
	m_robot.legrx = m_robot.bodyx + m_robot.bodyw - m_robot.legrw;
	m_robot.legry = m_robot.bodyy - m_robot.bodyl * 0.9;

	//初始化脚
	m_robot.footll = 0.15;
	m_robot.footlw = 0.25;
	m_robot.footlx = m_robot.leglx;
	m_robot.footly = m_robot.legly - m_robot.legll * 0.9;

	m_robot.footrl = 0.15;
	m_robot.footrw = 0.25;
	m_robot.footrx = m_robot.legrx;
	m_robot.footry = m_robot.legry - m_robot.legrl * 0.9;

}


