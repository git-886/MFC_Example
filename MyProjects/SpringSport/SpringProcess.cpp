// SpringProcess.cpp : implementation file
//

#include "stdafx.h"
#include "SpringSport.h"
#include "SpringProcess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpringProcess

CSpringProcess::CSpringProcess()
{
	m_k = 10;//弹性系数初始值
	m_zn = 0.9;//阻尼初始值
	m_L0 = 0.4;//弹簧原长
	m_L = 0.2;//弹簧长度初始值
	m_m = 0.2;//小球质量

	m_kZH = 200;//距离像素转换系数-定值
	m_w = 0.1;//弹簧宽-定值
	m_LUp = 0.2;//上绳长-定值
	m_LDown = 0.2;//下绳长-定值
	m_r = 0.05;//小球半径-定值

	m_x0 = 100;
	m_y0 = 50;

	m_f = 0;
	m_a = 0;
	m_v = 0;
	m_y = m_LUp + m_LDown + m_r + m_y0 + m_L;

	m_nfGJ = 0;
	m_naGJ = 0;
	m_nyGJ = 0;
	m_nvGJ = 0;
}

CSpringProcess::~CSpringProcess()
{
}


BEGIN_MESSAGE_MAP(CSpringProcess, CWnd)
	//{{AFX_MSG_MAP(CSpringProcess)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSpringProcess message handlers

void CSpringProcess::Draw(CDC *p)
{
	pDC = p;
	DrawSpring();
	DrawACurve();
	DrawFCurve();
	DrawVCurve();
	DrawYCurve();
}

void CSpringProcess::DrawACurve()
{
	int i,x0,y0;
	DrawXAndXkd(100,500,300);
	DrawYAndYkd(100,500,100);
	DrawName(220,580,"加速度曲线");

	CString str;
	str.Format("20m/s^2");
	pDC->TextOut(100,380,str);
	str.Format("-20m/s^2");
	pDC->TextOut(100,610,str);

	x0 = 100;
	y0 = 500;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_naGJ ; i++)//一米每平方秒对应5px,最大加速度接近20m/s^2
	{
		x0 +=5;
		y0 = 500-m_aGJ[i]*5;
		pDC->LineTo(x0,y0);
	}



}

void CSpringProcess::DrawFCurve()
{
	int x0,y0,i;
	DrawXAndXkd(600,500,300);
	DrawYAndYkd(600,500,100);
	DrawName(720,580,"合外力曲线");
	CString str;
	str.Format("4N");
	pDC->TextOut(600,380,str);
	str.Format("-4N");
	pDC->TextOut(600,610,str);

	x0 = 600;
	y0 = 500;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_nfGJ ; i++)//1N对应25px,最大加速度接近4N
	{
		x0 +=5;
		y0 = 500 - m_fGJ[i]*25;
		pDC->LineTo(x0,y0);
	}


}

void CSpringProcess::DrawVCurve()
{
	int x0,y0,i;
	DrawXAndXkd(600,200,300);
	DrawYAndYkd(600,200,100);
	DrawName(720,280,"小球速度曲线");
	CString str;
	str.Format("2m/s");
	pDC->TextOut(600,80,str);
	str.Format("-2m/s");
	pDC->TextOut(600,310,str);

	
	x0 = 600;
	y0 = 200;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_nvGJ ; i++)//1m/s对应50px,最大速度不超过2m/s
	{
		x0 +=5;
		y0 = 200 - m_vGJ[i]*50;
		pDC->LineTo(x0,y0);
	}
	

}

void CSpringProcess::DrawYCurve()
{
	int x0,y0,i;
	DrawXAndXkd(1100,500,300);
	DrawYAndYkd(1100,500,100);
	DrawName(1220,580,"位移曲线");

	CString str;
	str.Format("1m");
	pDC->TextOut(1100,380,str);


	x0 = 1100;
	y0 = 500;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_nyGJ ; i++)//1m对应100px,最大位移不超过1m
	{
		x0 +=5;
		y0 = 500 - m_yGJ[i]*100;
		pDC->LineTo(x0,y0);
	}


}

void CSpringProcess::DrawName(int x0, int y0, char str[])
{
	CString s = str;
	pDC->TextOut(x0,y0,s);
}

void CSpringProcess::DrawYAndYkd(int x0, int y0, int y_Lpx)//每一个小刻度5px
{
	int x,y;
	pDC->MoveTo(x0, y0);//画y轴
	pDC->LineTo(x0, y0 - y_Lpx);
	pDC->MoveTo(x0, y0);
	pDC->LineTo(x0, y0 + y_Lpx);

	//y轴正方向箭头
	x = x0;
	y = y0 - y_Lpx;
	pDC->MoveTo(x,y);
	x -= 5;
	y += 10;
	pDC->LineTo(x,y);
	x = x0;
	y = y0 - y_Lpx;
	pDC->MoveTo(x,y);
	x += 5;
	y += 10;
	pDC->LineTo(x,y);
	//y轴负方向箭头
	x = x0;
	y = y0 + y_Lpx;
	pDC->MoveTo(x,y);
	x -= 5;
	y -= 10;
	pDC->LineTo(x,y);
	x = x0;
	y = y0 + y_Lpx;
	pDC->MoveTo(x,y);
	x += 5;
	y -= 10;
	pDC->LineTo(x,y);

	//画y轴刻度
	int i,j;
	for(i = 1 ; i <=y_Lpx/5 ;i++)
	{
		pDC->MoveTo(x0,y0 + i * 5 );
		x = x0+3;
		y = y0 + i * 5;
		pDC->LineTo(x,y);
		pDC->MoveTo(x0,y0 - i * 5 );
		x = x0+3;
		y = y0 - i * 5;
		pDC->LineTo(x,y);
	}
	
}

void CSpringProcess::DrawXAndXkd(int x0, int y0,int x_Lpx)//画X轴及x刻度,参数x0,y0为原点坐标，x_Lpx为x 轴像素长度
{
	int x,y;
	pDC->MoveTo(x0, y0);
	pDC->LineTo(x0 + x_Lpx, y0);//根据x0,y0画x轴

	//x轴箭头
	x = x0 + x_Lpx;
	y = y0;
	pDC->MoveTo(x,y);
	x = x - 10;
	y = y - 5;
	pDC->LineTo(x,y);
	x = x0 + x_Lpx;
	y = y0;
	pDC->MoveTo(x,y);
	x = x - 10;
	y = y + 5;
	pDC->LineTo(x,y);

	//画x轴刻度，0.1秒对应刻度为5像素
	CString str;
	float t = 0.1;
	int i,j;
	for(i = 1 ; i < 61 ;i++)
	{
		pDC->MoveTo(x0 + i * 5,y0);
		pDC->LineTo(x0 + i * 5,y0 - 5);
		if(i%10 == 0)
		{
			pDC->LineTo(x0 + i * 5,y0 - 10);
			str.Format("%d",i/10);
			pDC->TextOut(x0 + i * 5 - 5,y0 + 10,str);
		}
		pDC->LineTo(x0 + i * 5,y0 - 5);
	}
	str.Format("单位s");
	pDC->TextOut(x0 + x_Lpx+10,y0,str);

}

void CSpringProcess::DrawSpring()
{
	float x,y,w,h,r; 
	x = m_x0 - 40;
	y = m_y0;
	pDC->MoveTo(x,y);
	x = m_x0 + 40;
	pDC->LineTo(x,y);

	x = m_x0;
	y = m_y0;
	pDC->MoveTo(x,y);
	y += m_LUp * m_kZH;
	pDC->LineTo(x,y);

	x = m_x0 - m_w * m_kZH /2;
	w = m_w * m_kZH;
	h = m_L * m_kZH;
	pDC->Rectangle(x,y,x+w,y+h);

	x = m_x0;
	y += m_L * m_kZH;
	pDC->MoveTo(x,y);
	y += m_LDown * m_kZH;
	pDC->LineTo(x,y);

	x = m_x0;
	y += m_r * m_kZH;
	r = m_r * m_kZH;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
}

void CSpringProcess::Move()
{
	//float dis;
	float deltat=0.1;
	m_f = m_m*0.98 - (m_L - m_L0)*m_k;//正方向为向下
	m_a = m_f/m_m;
	m_v += m_a*deltat;
	m_v *= m_zn;
	m_y += m_v*deltat;//m_y表示的是每个0.1秒后所在坐标相对于原点坐标的距离
	//dis = abs(m_v*deltat);//位移量
	m_L = m_y - m_LUp -m_LDown - m_y0 - m_r;

	m_fGJ[m_nfGJ++] = m_f;
	m_aGJ[m_naGJ++] = m_a;
	m_vGJ[m_nvGJ++] = m_v;
	m_yGJ[m_nyGJ++] = m_y - m_y0;
}

int CSpringProcess::PanDunaPH()
{
	if((m_v >=-0.01&&m_v <=0.01) && (m_f>=-0.0001&&m_f<0.01))
	{
		return 1;
	}
	return 0;
}













