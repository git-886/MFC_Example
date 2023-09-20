// Scene.cpp : implementation file
//

#include "stdafx.h"
#include "cstdlib"
#include "RobertInspection.h"
#include "Scene.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PI 3.1415926
/////////////////////////////////////////////////////////////////////////////
// CScene

CScene::CScene()
{
	m_YD.x = 300;//像素
	m_YD.y = 700;
	
	srand((unsigned)time(NULL));
	m_Leak.x = -260 + rand()%861;//实际位置单位m
	m_Leak.y = -120 + rand()%911;

	m_nd = 0;

	m_ky = -864/1000.0;
	m_kx = 1536/1000.0;
	
	m_nBuilding = InitBuildings();
	m_nRoad = InitRoads();
	m_nParticle = 0;

}

CScene::~CScene()
{
}


BEGIN_MESSAGE_MAP(CScene, CWnd)
	//{{AFX_MSG_MAP(CScene)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CScene message handlers

void CScene::Draw(CDC *p)
{
	pDC = p;
	int x,y,r;
	x = m_YD.x;
	y = m_YD.y;
	r = 5;
	
	DrawBuilding();
	DrawRoad();
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//ParticleDraw();刷新太快，不显示屏幕效果即可

	
	
}

void CScene::DrawBuilding()
{
	int i,j,x,y;
	CString str;
	CPoint dd[4];
	for(i = 0 ; i < m_nBuilding ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			dd[j].x = m_YD.x + building[i].zb[j][0] * m_kx;
			dd[j].y = m_YD.y + building[i].zb[j][1] * m_ky;
		}
		pDC->Polygon(dd,4);
		x = m_YD.x + building[i].pos[0] * m_kx;
		y = m_YD.y + building[i].pos[1] * m_ky;
		str = building[i].name;
		pDC->TextOut(x,y,str);

	}
} 

int CScene::InitBuildings()
{
	int i,j,SumLine;
	fp = fopen("E://buildings.txt","r");
	if(fp == NULL)
	{
		printf("打开初始数据文件失败!\n");
		return 0;
	}
	SumLine = 0;
	i = 0;
	char ch;
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch == '\n')
		{
			SumLine++;
		}
	}
	rewind(fp);
	/*
	AllocConsole();
	freopen("CONOUT$","w",stdout);
	*/
	while(!feof(fp) && i <= SumLine)
	{
		fscanf(fp,"%s %d %d %d %d %d %d %d %d %d %d",
			building[i].name,
			&building[i].zb[0][0],&building[i].zb[0][1],
			&building[i].zb[1][0],&building[i].zb[1][1],
			&building[i].zb[2][0],&building[i].zb[2][1],
			&building[i].zb[3][0],&building[i].zb[3][1],
			&building[i].pos[0],&building[i].pos[1]);
		
		    /*printf("%s %d %d %d %d %d %d %d %d %d %d\n",
			building[i].name,
			building[i].zb[0][0],building[i].zb[0][1],
			building[i].zb[1][0],building[i].zb[1][1],
			building[i].zb[2][0],building[i].zb[2][1],
			building[i].zb[3][0],building[i].zb[3][1],
			building[i].pos[0],building[i].pos[1]);*/
		
		i++;

	}
	fclose(fp);
	
	return i;

}


int CScene::InitRoads()
{
	int i,j,SumLine;
	fp = fopen("E://roads.txt","r");
	if(fp == NULL)
	{
		printf("打开初始数据文件失败!\n");
		return 0;
	}
	SumLine = 0;
	i = 0;
	char ch;
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch == '\n')
		{
			SumLine++;
		}
	}
	rewind(fp);
	while(!feof(fp) && i <= SumLine)
	{
		fscanf(fp,"%d %d %d %d %d %d %d %d",
			&road[i].zb[0][0],&road[i].zb[0][1],
			&road[i].zb[1][0],&road[i].zb[1][1],
			&road[i].zb[2][0],&road[i].zb[2][1],
			&road[i].zb[3][0],&road[i].zb[3][1]);
		i++;

	}
	fclose(fp);
	return i;
}

void CScene::DrawRoad()
{
	int i,j;
	CPoint dd[4];
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,0));
	CGdiObject *OldPen = pDC->SelectObject(pPen);
	for(i = 0 ; i < m_nRoad ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			dd[j].x = m_YD.x + road[i].zb[j][0] * m_kx;
			dd[j].y = m_YD.y + road[i].zb[j][1] * m_ky;
		}
		pDC->Polyline(dd,4);
	}
	pDC->SelectObject(OldPen);
	delete pPen;
}

void CScene::ParticleCreate()
{
	int i;
	for(i = 0 ; i < 100 ; i++)
	{
		m_Particle[m_nParticle].x = m_Leak.x;
		m_Particle[m_nParticle].y = m_Leak.y;
		m_Particle[m_nParticle].vx = rand()%101 - 50;
		m_Particle[m_nParticle].vy = rand()%101 - 50;
		m_Particle[m_nParticle].lifecycle = rand()%10;
		m_Particle[m_nParticle].statue = 0;
		m_nParticle++;
	}
}

void CScene::ParticleMove()
{
	int i;
	float delata = 0.1;
	for(i = 0 ; i < m_nParticle ; i++)
	{
		m_Particle[i].x += delata * m_Particle[i].vx;
		m_Particle[i].y += delata * m_Particle[i].vy;
		m_Particle[i].statue += delata;
		if(m_Particle[i].statue > m_Particle[i].lifecycle)
			ParticleDelete(i);

	}
}

void CScene::ParticleDelete(int i)
{
	m_Particle[i] = m_Particle[m_nParticle - 1];
	m_nParticle--;
}

void CScene::ParticleDraw()
{
	int i;
	int r = 5;//固定粒子半径，单位像素
	int x;
	int y;
	for(i = 0 ; i < m_nParticle ; i++)
	{
		x = m_YD.x + m_Particle[i].x * m_kx;
		y = m_YD.y + m_Particle[i].y * m_ky;
		pDC->Ellipse(x-r,y-r,x+r,y+r);
	}
}


int CScene::GetConcentration(float x, float y)
{
	int i;
	float dx,dy,d;
	m_nd = 0;
	for(i = 0 ; i < m_nParticle ; i++)
	{
		dx = abs(m_Particle[i].x - x);
		dy = abs(m_Particle[i].y - y);
		d = sqrt(dx * dx + dy * dy);
		if(d < 50)
		{
			m_nd++;
		}
	}
	return m_nd;
}


int CScene::GetMaxConcentrationDirection(float x, float y)//根据参数位置返回当前位置1~12方向中的浓度最大方向，以小车为圆心
{
	int i;
	float dep;
	float r = 50;//五十米为半径
	float x0,y0;//每个方向以50m为半径的圆心
	for(i = 1 ; i <= 12 ; i++)
	{
		dep = (12 + 3 - i) * PI / 6.0;
		x0 = x + cos(dep) * r;
		y0 = y + sin(dep) * r;
		m_Nd[i] = GetConcentration(x0,y0);
	}
	int maxdirection = 1;
	for(i = 1 ; i <= 12 ; i++)
	{
		if(m_Nd[i] > m_Nd[maxdirection])
		{
			maxdirection = i;
		}
	}
	return maxdirection;
}
