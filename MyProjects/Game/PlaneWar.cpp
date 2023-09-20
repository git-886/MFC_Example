// PlaneWar.cpp : implementation file
//

#include "stdafx.h"
#include "Game.h"
#include "PlaneWar.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaneWar

CPlaneWar::CPlaneWar()
{
	m_xBJ = 100;
	m_yBJ = 50;
	m_wBJ = 600;
	pDC = NULL;
	m_x = 400;
	m_y = 610;
	m_d = 80;
	m_Score = 0;
	m_nBul = 0;
	m_nCir = 0;

	
}

CPlaneWar::~CPlaneWar()
{
}


BEGIN_MESSAGE_MAP(CPlaneWar, CWnd)
	//{{AFX_MSG_MAP(CPlaneWar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPlaneWar message handlers

void CPlaneWar::Draw(CDC *p)
{
	pDC = p;
	DrawBJ();
	PlaneDraw();
	BulletDraw();
	CircleDraw();
	CString str;
	str.Format("当前得分为%d",m_Score);
	pDC->TextOut(600,70,str);

	
}

void CPlaneWar::DrawBJ()
{
	int x,y,w;
	x = m_xBJ;
	y = m_yBJ;
	w = m_wBJ;
	pDC->Rectangle(x,y,x+w,y+w);
}

void CPlaneWar::PlaneDraw()
{
	int x,y,d;
	x = m_x;
	y = m_y;
	d = m_d;
	int x1 = x - d/2;
	int y1 = y + d/2;
	int x2 = x + d/2;
	int y2 = y + d/2;

	pDC->MoveTo(x,y);
	pDC->LineTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->LineTo(x,y);
	
	/*
	CClientDC dc(this);
	CPen pen(PS_SOLID,1,RGB(0,255,0));
	CPen *oldPen = dc.SelectObject(&pen);

	CPoint pt[4];
	pt[0].x = x;
	pt[0].y = y;
	pt[1].x = x1;
	pt[1].y = y1;
	pt[2].x = x2;
	pt[2].y = y2;
	pt[3].x = x;
	pt[3].y = y;

	dc.Polygon(pt,3);

	CRgn rgn;
	CBrush brush;
	rgn.CreatePolygonRgn(pt,3,ALTERNATE);//创建区域
	brush.CreateSolidBrush(RGB(0,255,0));//创建画笔
	dc.FillRgn(&rgn,&brush);//填充区域

	brush.DeleteObject();
	rgn.DeleteObject();

	dc.SelectObject(oldPen);
	*/

}





void CPlaneWar::PlaneMove(int nChar)
{
	switch(nChar)
	{
	case 37:
		m_x -= 5;
		break;
	case 38:
		m_y -= 5;
		break;
	case 39:
		m_x += 5;
		break;
	case 40:
		m_y +=5;
	}
	if(m_x - m_d/2 <= 100)//飞机越界修正
	{
		m_x = 140;
	}
	if(m_x + m_d/2 >= 700)
	{
		m_x = 660;
	}
	if(m_y + m_d/2>=650)
	{
		m_y = 610;
	}
}







void CPlaneWar::BulletProduce()
{
	int i = m_nBul;
	m_Bul[i].r = 10;
	m_Bul[i].x = m_x;
	m_Bul[i].y = m_y - m_Bul[i].r;
	m_Bul[i].vy = rand()%15 + 100;
	m_nBul++;
}

void CPlaneWar::BulletDraw()
{
	int i;
	int x,y,r;
	for(i = 0 ; i < m_nBul ; i++)
	{
		x = m_Bul[i].x;
		y = m_Bul[i].y;
		r = m_Bul[i].r;
		pDC->Ellipse(x-r,y-r,x+r,y+r);
	}
}

void CPlaneWar::BulletMove()
{
	int i;
	float deltat = 0.1;
	for(i = 0 ; i< m_nBul ; i++)
	{
		//m_Bul[i].y -=10;
		m_Bul[i].y = m_Bul[i].y - m_Bul[i].vy * deltat;
	}
}

void CPlaneWar::BulletDelete(int n)
{
	m_Bul[n] = m_Bul[m_nBul - 1];
	m_nBul--;
}



void CPlaneWar::BulletOut()
{
	int i;
	for(i = 0 ; i < m_nBul ; i++)
	{
		if(m_Bul[i].y - m_Bul[i].r <= 50)
		{
			BulletDelete(i);
		}
	}
}

void CPlaneWar::ProduceTargets()
{
	int n = rand()%3;
	switch(n)
	{
	case 0:
		CircleProduce();
		break;
		/*
	case 1:
		RectangleProduce();
		break;
	case 2:
		TriangleProduce();
		break;
		*/
	}
}

void CPlaneWar::CircleProduce()
{
	int i = m_nCir;
	m_Cir[i].x = 120 + rand()%521;
	m_Cir[i].y = 70;
	m_Cir[i].r = 15 + rand()%10;
	m_Cir[i].vy = rand()%100 + 100;
	m_Cir[i].fs = 0.1*m_Cir[i].vy + 100/m_Cir[i].r;
	m_nCir++;
}

void CPlaneWar::CircleMove()
{
	int i;
	float deltat = 0.1;
	for(i = 0 ; i < m_nCir ; i++)
	{
		m_Cir[i].y += m_Cir[i].vy * deltat;
	}
}

void CPlaneWar::CircleDraw()
{
	int i;
	int x,y,r;
	for(i = 0 ; i < m_nCir ; i++)
	{
		x = m_Cir[i].x;
		y = m_Cir[i].y;
		r = m_Cir[i].r;
		pDC->Ellipse(x-r,y-r,x+r,y+r);
	}
}

void CPlaneWar::CircleOut()
{
	int i;
	for(i = 0 ; i < m_nCir ; i++)
	{
		if(m_Cir[i].y + m_Cir[i].r >=650)
		{
			CircleDelete(i);
		}
	}
}

void CPlaneWar::CircleHit()
{
	int i,j;
	float d;
	for(i = 0 ; i < m_nCir ; i++)
	{
		for(j = 0 ; j < m_nBul ; j++)
		{
			d = sqrt((m_Cir[i].x - m_Bul[j].x) * (m_Cir[i].x - m_Bul[j].x) + (m_Cir[i].y - m_Bul[j].y) * (m_Cir[i].y - m_Bul[j].y));
			if(d < m_Cir[i].r + m_Bul[j].r)
			{
				BulletDelete(j);
				CircleDelete(i);
				m_Score += m_Cir[i].fs;
			}
		}
	}
}

void CPlaneWar::CircleDelete(int n)
{
	m_Cir[n] = m_Cir[m_nCir - 1];
	m_nCir--;
}

int CPlaneWar::CircleCollision()
{
	int i,j;
	float d = m_d;
	float dist;
	CPoint dd[3];
	dd[0].x = m_x;
	dd[0].y = m_y;
	dd[1].x = m_x - d/2;
	dd[1].y = m_y + d/2;
	dd[2].x = m_x + d/2;
	dd[2].y = m_y + d/2;
	for(i = 0 ; i < m_nCir ; i++)
	{
		for(j = 0 ; j < 3 ;j++)
		{
			dist = sqrt((m_Cir[i].x - dd[j].x) * (m_Cir[i].x - dd[j].x) + (m_Cir[i].y - dd[j].y) * (m_Cir[i].y - dd[j].y));
			if(dist < m_Cir[i].r)
			{
				return 1;
			}
		}
	}
	return 0;
	
}
