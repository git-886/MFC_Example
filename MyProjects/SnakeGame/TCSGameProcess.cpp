// TCSGameProcess.cpp : implementation file
//

#include "stdafx.h"
#include "SnakeGame.h"
#include "TCSGameProcess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCSGameProcess

CTCSGameProcess::CTCSGameProcess()
{
	m_bj_x = 100;
	m_bj_y = 10;
	m_bj_w = 700;
	m_s_w = 20;
	pDC = NULL;
	m_num = 0;
	m_food.f_x = 100;
	m_food.f_y = 100;
	m_score = 0;
	m_direct = 6;
	InitSnake();
	FoodStatue = 1;
	srand(time(NULL));//播种一次
}

CTCSGameProcess::~CTCSGameProcess()
{
}


BEGIN_MESSAGE_MAP(CTCSGameProcess, CWnd)
	//{{AFX_MSG_MAP(CTCSGameProcess)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTCSGameProcess message handlers

void CTCSGameProcess::DrawBJ()
{
	int x,y,w;
	x = m_bj_x;
	y = m_bj_y;
	w = m_bj_w;
	pDC->Rectangle(x,y,x + w,y + w);
}

void CTCSGameProcess::InitSnake()
{
	int i;
	for(i = 0 ; i < 3 ; i++)//初始化蛇长度为3，从左上角开始
	{
		m_s[i].s_x = m_bj_x + (2 - i) * m_s_w;
		m_s[i].s_y = m_bj_y;
		m_num++;
	}
}

void CTCSGameProcess::DrawSnake()
{
	int i;
	for(i = m_num-1 ; i >= 0 ; i--)
	{
		int x = m_s[i].s_x;
		int y = m_s[i].s_y;
		CBrush brush;
		brush.CreateSolidBrush(RGB(255,0,0));
		pDC->SelectObject(&brush);
		CRect rect(x,y,x + m_s_w,y + m_s_w);
		pDC->Rectangle(&rect);
		pDC->SelectStockObject(NULL_BRUSH);
		//pDC->EndPath();
		//pDC->FillPath();
	}
}

void CTCSGameProcess::SnakeMove()
{
	int i;
	if(m_direct == 6)
	{
	    for(i = m_num - 1 ; i > 0 ;i--)//右移
		{
			m_s[i].s_x = m_s[i - 1].s_x;
			m_s[i].s_y = m_s[i - 1].s_y;
		}
		m_s[0].s_x += m_s_w;
	}
	if(m_direct == 4)
	{
		for(i = m_num - 1 ; i > 0 ; i--)//左移
		{
			m_s[i].s_x = m_s[i - 1].s_x;
			m_s[i].s_y = m_s[i - 1].s_y;		
		}
		m_s[0].s_x -= m_s_w;
	}
	if(m_direct == 8)
	{
		for(i = m_num - 1 ; i > 0 ;i--)//上移
		{
			m_s[i].s_x = m_s[i - 1].s_x;
			m_s[i].s_y = m_s[i - 1].s_y;
		}
	    m_s[0].s_y -= m_s_w;
	}
	if(m_direct == 2)
	{
		for(i = m_num - 1 ; i > 0 ;i--)//下移
		{		
			m_s[i].s_x = m_s[i - 1].s_x;
			m_s[i].s_y = m_s[i - 1].s_y;
		}
		m_s[0].s_y += m_s_w;
	}
	EatFood();
}

void CTCSGameProcess::Draw()
{
	DrawSnake();
	DrawBJ();
	ProduceFood();
	CString str_score;
	str_score.Format("当前得分为：%d",m_score);	
	pDC->TextOut(800,100,str_score);

}

void CTCSGameProcess::ProduceFood()
{
	if(FoodStatue == 1)
	{
		m_food.f_x =100 + (rand()%30)*20;
		m_food.f_y =10 + (rand()%30)*20;
	} 
	

	CBrush brush,*bru;
	brush.CreateSolidBrush(RGB(0,255,0));
	bru = pDC->SelectObject(&brush);
	pDC->Rectangle(m_food.f_x,m_food.f_y,m_food.f_x + m_s_w,m_food.f_y + m_s_w);
	//brush.DeleteObject();
	//pDC->SelectObject(bru);
	pDC->SelectStockObject(NULL_BRUSH);
	FoodStatue = 0;
}

void CTCSGameProcess::EatFood()
{
	if((m_s[0].s_x == m_food.f_x)&&(m_s[0].s_y == m_food.f_y))
	{
		m_num++;
		FoodStatue = 1;
		//ProduceFood();
		m_score += 10;
	}
}

int CTCSGameProcess::collision()//碰撞判断
{
	int i;
	if((m_s[0].s_x < m_bj_x) || (m_s[0].s_x == (m_bj_x + m_bj_w)) || (m_s[0].s_y < m_bj_y) || (m_s[0].s_y == (m_bj_y + m_bj_w)))
	{
		return 1;
	}

	for(i = 1 ; i < m_num ; i++)
	{
		if((m_s[0].s_x == m_s[i].s_x) && (m_s[0].s_y == m_s[i].s_y))
		{
			return 2;
		}
	}
	return 0;
}
