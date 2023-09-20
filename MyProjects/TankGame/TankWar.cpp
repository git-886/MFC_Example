// TankWar.cpp : implementation file
//

#include "stdafx.h"
#include "TankGame.h"
#include "TankWar.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankWar

CTankWar::CTankWar()
{
	m_xBK = 100;
	m_yBK = 50;
	m_wBK = 600;
	m_nCir = 0;
	m_nRec = 0;
	m_nTri = 0;
	m_nBul = 0;
	m_x = 400;
	m_r = 20;
	m_y = 590;
	m_Score = 0;
}

CTankWar::~CTankWar()
{
}


BEGIN_MESSAGE_MAP(CTankWar, CWnd)
	//{{AFX_MSG_MAP(CTankWar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTankWar message handlers

void CTankWar::DrawBK()
{
	int x,y,w;
	x = m_xBK;
	y = m_yBK;
	w = m_wBK;
	pDC->Rectangle(x,y,x+w,y+w);
}

void CTankWar::Draw(CDC *p)
{
	pDC = p;
	DrawBK();
	TankDraw();
	CircleDraw();
	RectangleDraw();
	TriangleDraw();
	BulletDraw();

	CString str;
	str.Format("当前得分：%d",m_Score);
	pDC->TextOut(600,60,str);
	
}

void CTankWar::Produce()
{
	int n;
	n = rand()%3;
	switch(n)
	{
	case 0:
		CircleProduce();
		break;
	case 1:
		RectangleProduce();
		break;
	case 2:
		TriangleProduce();
		break;
	}
}

void CTankWar::CircleMove()
{
	int i;
	float deltat = 0.1;
	for(i = 0 ; i < m_nCir ; i++)
	{
		m_Cir[i].y += m_Cir[i].vy * deltat;
	}
	CirOut();
}

void CTankWar::CircleDelete(int i)
{
	m_Cir[i] = m_Cir[m_nCir - 1];
	m_nCir--;
}

void CTankWar::CircleProduce()
{
	int i  = m_nCir;
	m_Cir[i].x = 110 + rand()%601;
	m_Cir[i].y = 70;
	m_Cir[i].r = rand()%11 + 10;
	m_Cir[i].vy = rand()%11 + 10;
	m_Cir[i].fs = m_Cir[i].vy + 10/m_Cir[i].r;
	m_nCir++;
}
void CTankWar::CircleDraw()
{
    int i;
	for(i = 0 ; i < m_nCir ; i++)
	{
		CBrush brush,*bru;
		brush.CreateSolidBrush(RGB(193,210,240));
		bru = pDC->SelectObject(&brush);
		int x = m_Cir[i].x;
		int y = m_Cir[i].y;
		int r = m_Cir[i].r;
		pDC->Ellipse(x - r,y - r,x + r,y + r);
		pDC->SelectStockObject(NULL_BRUSH);
	}
}
void CTankWar::CirOut()
{
	int i;
	for(i = 0 ; i < m_nCir ; i++)//出下界删除
	{
		if(m_Cir[i].y + m_Cir[i].r >= 650)
		{
			CircleDelete(i);
		}
	}
}
void CTankWar::TankMove(int nChar)
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
		m_y += 5;
		break;
	case 32:
		BulletProduce();
		break;
	default:
		break;
	}
	if(m_x <= 140)//坦克越界修正
	{
		m_x = 140;
	}
	if(m_x >= 660)
	{
		m_x = 660;
	}
	if(m_y >= 590)
	{
		m_y = 590;
	}
}

void CTankWar::CircleHit()
{
	int i,j;
	float d;
	for(i = 0 ; i < m_nBul ; i++)
	{
		for(j = 0 ; j <m_nCir ; j++)
		{
			d = sqrt((m_Bul[i].x - m_Cir[j].x) * (m_Bul[i].x - m_Cir[j].x) + (m_Bul[i].y - m_Cir[j].y) * (m_Bul[i].y - m_Cir[j].y));
			if(m_Bul[i].r + m_Cir[j].r > d)
			{
				BulletDelete(i);
				CircleDelete(j);
				m_Score += m_Cir[j].fs;
			}
		}
		
	}	
}

void CTankWar::TankDraw()
{
	int x = m_x;
	int y = m_y;
	int r = m_r;
	CBrush brush,*bru;
	brush.CreateSolidBrush(RGB(255,0,0));
	bru = pDC->SelectObject(&brush);
	
	pDC->Rectangle(x - r,y - r,x - r+2*r,y - r+2*r);
	pDC->Ellipse(x - r/2,y - r/2,x + r/2,y + r/2);
	x = x - 2*r;
	y = y + r;
	pDC->Rectangle(x,y,x+4*r,y+2*r);
	pDC->SelectStockObject(NULL_BRUSH);

}

void CTankWar::BulletProduce()
{
	int i = m_nBul;
	m_Bul[i].x = m_x;
	m_Bul[i].y = m_y;
	m_Bul[i].r = m_r/2;
	m_Bul[i].vy = rand()%16 + 100;
	m_nBul++;
}

void CTankWar::BulletDraw()
{
	int i;
	int x,y,r;
	
	for(i = 0 ; i < m_nBul ; i++)
	{
		CBrush brush,*bru;
		brush.CreateSolidBrush(RGB(0,255,0));
		bru = pDC->SelectObject(&brush);
		x = m_Bul[i].x;
		y = m_Bul[i].y;
		r = m_Bul[i].r;
		pDC->Ellipse(x - r,y - r,x + r,y + r);
		pDC->SelectStockObject(NULL_BRUSH);

	}
}

void CTankWar::BulletMove()
{
	float deltat = 0.1;
	int i;
	for(i = 0 ; i < m_nBul ; i++)
	{
		m_Bul[i].y -= deltat *  m_Bul[i].vy;
	}
	BulleOut();
}

void CTankWar::BulletDelete(int n)
{
	m_Bul[n] = m_Bul[m_nBul - 1];
	m_nBul--;
}

void CTankWar::BulleOut()
{
	int i;
	for(i = 0 ; i < m_nBul ; i++)
	{
		if(m_Bul[i].y - m_r/2 <= 50)
		{
			BulletDelete(i);
		}
	}
}

int CTankWar::CircleGameOver()
{
	int i,j;
	float d1,d2,d3,d4,d5,d6,d7;
	CPoint dd[4];
	dd[0].x = m_x - m_r;
	dd[0].y = m_y - m_r;
	dd[1].x = m_x + m_r;
	dd[1].y = m_y - m_r;
	dd[2].x = m_x - 2*m_r;
	dd[2].y = m_y + m_r;
	dd[3].x = m_x + 2*m_r;
	dd[3].y = m_y + m_r;
	for(i = 0 ; i < m_nCir ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			d1 = sqrt((m_Cir[i].x - dd[0].x) * (m_Cir[i].x - dd[0].x) + (m_Cir[i].y - dd[0].y) * (m_Cir[i].y - dd[0].y));
			d2 = sqrt((m_Cir[i].x - dd[1].x) * (m_Cir[i].x - dd[1].x) + (m_Cir[i].y - dd[1].y) * (m_Cir[i].y - dd[1].y));
			d3 = sqrt((m_Cir[i].x - dd[2].x) * (m_Cir[i].x - dd[2].x) + (m_Cir[i].y - dd[2].y) * (m_Cir[i].y - dd[2].y));
			d4 = sqrt((m_Cir[i].x - dd[3].x) * (m_Cir[i].x - dd[3].x) + (m_Cir[i].y - dd[3].y) * (m_Cir[i].y - dd[3].y));
			if(d1<m_Cir[i].r || d2<m_Cir[i].r || d3<m_Cir[i].r || d4<m_Cir[i].r)
			{
				return 1;
			}
		}
		if(m_Cir[i].r < m_r)
		{
			d5 = sqrt((m_Cir[i].x - m_x) * (m_Cir[i].x - m_x) + (m_Cir[i].y - m_y) * (m_Cir[i].y - m_y));//撞到上面的正方形
			if(d5 < m_r + m_Cir[i].r)
			{
				return 1;
			}
		}
		//d6 = sqrt((m_Cir[i].x - m_x - m_r) * (m_Cir[i].x - m_x - m_r) + (m_Cir[i].y - m_y + 2 * m_r ) * (m_Cir[i].y - m_y + 2 * m_r));
		//if(d6 < m_r + m_Cir[i].r)
		//{
		//	return 1;
		//}
		
	}
	return 0;
}
/**************************************************/
void CTankWar::RectangleDraw()
{
	int x,y,w,h,i;
	for(i = 0 ; i < m_nRec ; i++)
	{
		CBrush brush,*bru;
		brush.CreateSolidBrush(RGB(0,0,255));
		bru = pDC->SelectObject(&brush);
		x = m_Rec[i].x;
		y = m_Rec[i].y;
		w = m_Rec[i].w;
		h = m_Rec[i].h;
		pDC->Rectangle(x,y,x+w,y+h);
		pDC->SelectStockObject(NULL_BRUSH);
	}

}

void CTankWar::RectangleProduce()
{
	int i = m_nRec;
	m_Rec[i].x = rand()%536 + 120;
	m_Rec[i].y = 70;
	m_Rec[i].w = rand()%16+30;
	m_Rec[i].h = rand()%16+20;
	m_Rec[i].vy = rand()%16 + 25;
	m_Rec[i].fs = m_Rec[i].vy+10/m_Rec[i].w*m_Rec[i].h;
	m_nRec++;
}

void CTankWar::RectangleMove()
{
	float deltat = 0.1;
	int i;
	for(i = 0 ; i < m_nRec ; i++)
	{
		m_Rec[i].y += deltat *  m_Rec[i].vy;
	}
	RectangleOut();
}


void CTankWar::RectangleDelete(int n)
{
	m_Rec[n] = m_Rec[m_nRec - 1];
	m_nRec--;
}

void CTankWar::RectangleHit()
{
	int i,j;
	float x1,y1,d;
	for(i = 0 ; i < m_nRec ; i++)
	{
		x1 = (m_Rec[i].x + (m_Rec[i].x + m_Rec[i].w)) / 2;
		y1 = (m_Rec[i].y + (m_Rec[i].y + m_Rec[i].h)) / 2;
		for(j = 0 ; j < m_nBul ; j++)
		{
			d = sqrt((m_Bul[j].x - x1)*(m_Bul[j].x - x1) + (m_Bul[j].y - y1) * (m_Bul[j].y - y1)) ;
			if(d < m_Rec[i].y + m_Rec[i].h - y1 + m_Bul[j].r)
			{
				BulletDelete(j);
				RectangleDelete(i);
				m_Score += m_Rec[i].fs;
			}
		}
	}
}

void CTankWar::RectangleOut()
{
	int i;
	for(i = 0 ; i < m_nRec ; i++)
	{
		if(m_Rec[i].y + m_Rec[i].h >= 650)
		{
			RectangleDelete(i);
		}
	}
}



int CTankWar::RectangleGameOver()
{
	int i,j;
	float d1,d2,d3,d4,d5,d6,d7,t,x1,y1;
	CPoint dd[4];
	dd[0].x = m_x - m_r;
	dd[0].y = m_y - m_r;
	dd[1].x = m_x + m_r;
	dd[1].y = m_y - m_r;
	dd[2].x = m_x - 2*m_r;
	dd[2].y = m_y + m_r;
	dd[3].x = m_x + 2*m_r;
	dd[3].y = m_y + m_r;
	for(i = 0 ; i < m_nRec ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			x1 = (m_Rec[i].x + (m_Rec[i].x + m_Rec[i].w)) / 2;
		    y1 = (m_Rec[i].y + (m_Rec[i].y + m_Rec[i].h)) / 2;
			d1 = sqrt((x1 - dd[0].x) * (x1 - dd[0].x) + (y1 - dd[0].y) * (y1 - dd[0].y));
			d2 = sqrt((x1 - dd[1].x) * (x1 - dd[1].x) + (y1 - dd[1].y) * (y1 - dd[1].y));
			d3 = sqrt((x1 - dd[2].x) * (x1 - dd[2].x) + (y1 - dd[2].y) * (y1 - dd[2].y));
			d4 = sqrt((x1 - dd[3].x) * (x1 - dd[3].x) + (y1 - dd[3].y) * (y1 - dd[3].y));
			t = sqrt(m_Rec[i].h /2 * m_Rec[i].h /2 + m_Rec[i].w / 2 * m_Rec[i].w / 2);
			if(d1<t || d2<t || d3<t || d4<t)
			{
				return 1;
			}
		}	
	}
	return 0;
}
/*************************************************/
void CTankWar::TriangleProduce()
{
	int i = m_nTri;
	m_Tri[i].x = rand()%536 + 120;
	m_Tri[i].y = 70;
	m_Tri[i].d = rand()%16 + 40;
	m_Tri[i].vy = rand()%16 + 25;
	m_Tri[i].fs = m_Tri[i].vy + 10/m_Tri[i].d;
	m_nTri++;
}

void CTankWar::TriangleDraw()
{
	int i;
	for(i = 0; i < m_nTri ; i++)
	{
		
		int x = m_Tri[i].x;
		int y = m_Tri[i].y;
		int d = m_Tri[i].d;;
		double h = 50;
		double x1 = x;
		double y1 = y - h / 2;
		double x2 = x - d / 2;
		double y2 = y + h / 2;
		double x3 = x + d / 2;
		double y3 = y + h / 2;	
        
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);
		pDC->LineTo(x3,y3);
		pDC->LineTo(x1,y1);
		/*
		CPaintDC dc(this);
		dc.MoveTo(x1,y1);
		dc.LineTo(x2,y2);
		dc.LineTo(x3,y3);
		dc.LineTo(x1,y1);
		CPoint points[3] = {{x1,y1},{x2,y2},{x3,y3}};
		CRgn rgn;
		rgn.CreatePolygonRgn(points,3,WINDING);
		dc.FillRgn(&rgn,&CBrush(RGB(0,0,230)));
		*/
		
	}
}

void CTankWar::TriangleMove()
{
	float deltat = 0.1;
	int i;
	for(i = 0 ; i < m_nTri ; i++)
	{
		m_Tri[i].y += deltat *  m_Tri[i].vy;
	}
	TriangleOut();
}

void CTankWar::TriangleDelete(int n)
{
	m_Tri[n] = m_Tri[m_nTri - 1];
	m_nTri--;
}

void CTankWar::TriangleOut()
{
	int i;
	for(i = 0 ; i < m_nTri ; i++)
	{
		if(m_Tri[i].y + 25 >= 650)
		{
			TriangleDelete(i);
		}
	}
}

void CTankWar::TriangleHit()
{
	int i,j;
	float d;
	for(i = 0 ; i < m_nTri ; i++)
	{
		for(j = 0 ; j < m_nBul ; j++)
		{
			d = sqrt((m_Tri[i].x - m_Bul[j].x) * (m_Tri[i].x - m_Bul[j].x) + (m_Tri[i].y - m_Bul[j].y) * (m_Tri[i].y - m_Bul[j].y));
			if(d < m_Bul[j].r + 25)
			{
				BulletDelete(j);
				TriangleDelete(i);
				m_Score += m_Tri[i].fs;
			}
		}
	}
}



int CTankWar::TriangleGameOver()
{
	int i,j;
	float d1,d2,d3,d4,d5,d6,d7,t;
	CPoint dd[4];
	dd[0].x = m_x - m_r;
	dd[0].y = m_y - m_r;
	dd[1].x = m_x + m_r;
	dd[1].y = m_y - m_r;
	dd[2].x = m_x - 2*m_r;
	dd[2].y = m_y + m_r;
	dd[3].x = m_x + 2*m_r;
	dd[3].y = m_y + m_r;
	for(i = 0 ; i < m_nTri ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			d1 = sqrt((m_Tri[i].x - dd[0].x) * (m_Tri[i].x - dd[0].x) + (m_Tri[i].y - dd[0].y) * (m_Tri[i].y - dd[0].y));
			d2 = sqrt((m_Tri[i].x - dd[1].x) * (m_Tri[i].x - dd[1].x) + (m_Tri[i].y - dd[1].y) * (m_Tri[i].y - dd[1].y));
			d3 = sqrt((m_Tri[i].x - dd[2].x) * (m_Tri[i].x - dd[2].x) + (m_Tri[i].y - dd[2].y) * (m_Tri[i].y - dd[2].y));
			d4 = sqrt((m_Tri[i].x - dd[3].x) * (m_Tri[i].x - dd[3].x) + (m_Tri[i].y - dd[3].y) * (m_Tri[i].y - dd[3].y));
			t = sqrt((m_Tri[i].x - m_Tri[i].x + m_Tri[i].d / 2)* (m_Tri[i].x - m_Tri[i].x + m_Tri[i].d / 2) +(m_Tri[i].y - m_Tri[i].y + 25) * (m_Tri[i].y - m_Tri[i].y + 25));
			if(d1<t || d2<t || d3<t || d4<t)
			{
				return 1;
			}
		}	
	}
	return 0;
}
