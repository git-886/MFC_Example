// TankProcess.cpp : implementation file
//

#include "stdafx.h"
#include "TankWar.h"
#include "TankProcess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankProcess

CTankProcess::CTankProcess()
{
	m_tank_x = 365;
	m_tank_y = 650;
	m_tank_w = 50;
	m_pt_x = 415;
	m_pt_y = 610;
	m_direction = 0;
	m_bullet_num = 0;
	m_score = 0;
}

CTankProcess::~CTankProcess()
{
}


BEGIN_MESSAGE_MAP(CTankProcess, CWnd)
	//{{AFX_MSG_MAP(CTankProcess)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTankProcess message handlers

void CTankProcess::Draw(CDC *p)
{
	pDC = p;
	DrawTank();//画坦克
	DrawBullet();//画子弹

	CString str_score;
	str_score.Format("当前得分为：%d",m_score);	
	pDC->TextOut(800,100,str_score);
}

void CTankProcess::DrawTank()
{
	int x = m_tank_x;
	int y = m_tank_y;
	int w = m_tank_w;
	pDC->Rectangle(x,y,x + 2 * w,y + w);
	int x_up = x + w / 2;
	int y_up = y - w/2;
	pDC->Rectangle(x_up,y_up,x_up + w,y_up + w);
	int pt_x = x_up + w / 4;//402
	int pt_y = y_up - w / 2;//600
	m_pt_x = pt_x + 8;
	m_pt_y = pt_y + 10;
	pDC->Rectangle(pt_x,pt_y,pt_x + w / 2,pt_y + w / 2);
	
}



void CTankProcess::MoveTank()
{
	//
	if(m_direction == 4)//左移
	{
		m_tank_x -=5;
	}else if(m_direction == 8)//上移
	{
		m_tank_y -=5;
	}else if(m_direction == 6)//右移
	{
		m_tank_x +=5;
	}else if(m_direction == 2)//下移
	{
		m_tank_y +=5;
	}
	MoveTankBoundaryDetermine();
}
void CTankProcess::MoveTankBoundaryDetermine()//坦克出界修正
{
    if(m_tank_x <= 100)
	{
		m_tank_x = 100;
	}
	if(m_tank_y + 50 >= 700)
	{
		m_tank_y = 650;
	}
	if(m_tank_x + 100 >= 750)
	{
		m_tank_x = 650;
	}


	/*
	m_bk_x = 100;
	m_bk_y = 50;
	m_bk_w = 650;
	*/
}

void CTankProcess::ProduceBullet()//依据坦克炮筒位置生成子弹
{
	int i = m_bullet_num;
	m_bullet[i].x = m_pt_x;
	m_bullet[i].y = m_pt_y;
	m_bullet[i].r = 10;
	m_bullet_num++;
}

void CTankProcess::MoveBullet()//每隔一个时钟子弹移动一次
{
	int i;
	for(i = 0 ; i < m_bullet_num ; i++)//m_nBullet
	{
		m_bullet[i].y -= 20;
	}
}

void CTankProcess::DrawBullet()
{
	int i;
	int x,y,r;
	for(i = 0 ; i < m_bullet_num ; i++)
	{
		x = m_bullet[i].x;
		y = m_bullet[i].y;
		r = m_bullet[i].r;
		pDC->Ellipse(x - r,y - r,x + r,y + r);
	}
}

void CTankProcess::BulletHitAndOut()//子弹出界或击中处理
{
	
}


