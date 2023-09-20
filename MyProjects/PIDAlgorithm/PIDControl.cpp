// PIDControl.cpp : implementation file
//

#include "stdafx.h"
#include "PIDAlgorithm.h"
#include "PIDControl.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPIDControl

CPIDControl::CPIDControl()
{
	m_way = 1;

	m_YD.x = 50;//屏幕左下角为原点
	m_YD.y = 700;

	m_t = 4.712;//3PI/2

	m_Con_Dis.w = 10;
	m_Con_Spe.w = 10;
	m_Con_Acc.w = 10;
	m_Tar.w = 10;

	m_Con_Dis.x = 0;
	m_Con_Spe.x = 0;
	m_Con_Acc.x = 0;
	m_Tar.x = 20;

	m_DisPid.Ki = 0.1;
	m_DisPid.Kp = 1;
	m_DisPid.Kd = 0.001;
	m_DisPid.err_last = 0;

	m_SpePid.Ki = 5;
	m_SpePid.Kp = 5;
	m_SpePid.Kd = 0.5;
	m_SpePid.err_last = 0;

	m_AccPid.Ki = 0.2;
	m_AccPid.Kp = 0.5;
	m_AccPid.Kd = 10;
	m_AccPid.err_last = 0;
	


	m_ky = -864/1000.0;
	m_kx = 1536/1000.0;

	m_nTarX = 0;
	m_nDisX = 0;
	m_nSpeX = 0;
	m_nAccX = 0;

	m_nTarV = 0;
	m_nSpeV = 0;
	m_nAccV = 0;

	m_nTarA = 0;
	m_nAccA = 0;
}

CPIDControl::~CPIDControl()
{
}


BEGIN_MESSAGE_MAP(CPIDControl, CWnd)
	//{{AFX_MSG_MAP(CPIDControl)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPIDControl message handlers

void CPIDControl::Draw(CDC *p)
{
	pDC = p;
	DrawScene();
	DrawControlCar_Displacement();
	DrawControCar_Speed();
	DrawControlCar_Acceleration();
	DrawTargetCar();
	int x = m_YD.x;
	int y = m_YD.y;
	int r = 5;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

	CurveDrawZBZ(50,500,"位移曲线","800m");
	CurveDrawZBZ(550,500,"速度曲线","200m/s");
	CurveDrawZBZ(1050,550,"加速度曲线","200m/s^2");
	pDC->TextOut(600,270,"蓝色目标小车-绿色加速度控制小车-红色速度控制小车");

	CurveDrawDisplacement(50,500);
	CurveDrawSpeed(550,500);
	CurveDrawAcceleration(1050,550);
}

void CPIDControl::DrawScene()//绘画场景
{
	int x,y;
	float sj_x,sj_y;
	sj_x = 0;//m
	sj_y = 700;
	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + sj_y * m_ky;
	pDC->MoveTo(x,y);
	
	x = m_YD.x + (sj_x + 800) * m_kx;//800米赛道
	pDC->LineTo(x,y);

	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + (sj_y - 50) * m_ky;
	pDC->MoveTo(x,y);

	y = m_YD.y + (sj_y + 100) * m_ky;
	pDC->LineTo(x,y);
////////////////////////////
	sj_x = 0;//m
	sj_y = 650;
	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + sj_y * m_ky;
	pDC->MoveTo(x,y);
	
	x = m_YD.x + (sj_x + 800) * m_kx;//800米赛道
	pDC->LineTo(x,y);

	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + (sj_y - 50) * m_ky;
	pDC->MoveTo(x,y);

	y = m_YD.y + (sj_y + 100) * m_ky;
	pDC->LineTo(x,y);
//////////////////////////////
	sj_x = 0;//m
	sj_y = 600;
	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + sj_y * m_ky;
	pDC->MoveTo(x,y);
	
	x = m_YD.x + (sj_x + 800) * m_kx;//800米赛道
	pDC->LineTo(x,y);

	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + (sj_y - 50) * m_ky;
	pDC->MoveTo(x,y);

	y = m_YD.y + (sj_y + 100) * m_ky;
	pDC->LineTo(x,y);
///////////////////////////////
	sj_x = 0;//m
	sj_y = 550;
	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + sj_y * m_ky;
	pDC->MoveTo(x,y);
	
	x = m_YD.x + (sj_x + 800) * m_kx;//800米赛道
	pDC->LineTo(x,y);

	x = m_YD.x + sj_x * m_kx;
	y = m_YD.y + (sj_y - 50) * m_ky;
	pDC->MoveTo(x,y);

	y = m_YD.y + (sj_y + 100) * m_ky;
	pDC->LineTo(x,y);
}

void CPIDControl::DrawTargetCar()
{
	int x,y;
	int w,h;
	float InitY = 710;
	x = m_YD.x + m_Tar.x * m_kx;
	y = m_YD.y + InitY * m_ky;
	h = m_Tar.w;
	w = h * 2;
	pDC->Rectangle(x,y,x+w,y+h);
}

void CPIDControl::DrawControlCar_Displacement()
{
	int x,y;
	int w,h;
	float InitY = 660;
	x = m_YD.x + m_Con_Dis.x * m_kx;
	y = m_YD.y + InitY * m_ky;
	h = m_Con_Dis.w;
	w = h * 2;
	pDC->Rectangle(x,y,x+w,y+h);
}

void CPIDControl::DrawControCar_Speed()
{
	int x,y;
	int w,h;
	float InitY = 610;
	x = m_YD.x + m_Con_Spe.x * m_kx;
	y = m_YD.y + InitY * m_ky;
	h = m_Con_Spe.w;
	w = h * 2;
	pDC->Rectangle(x,y,x+w,y+h);
}

void CPIDControl::DrawControlCar_Acceleration()
{
	int x,y;
	int w,h;
	float InitY = 560; 
	x = m_YD.x + m_Con_Acc.x * m_kx;
	y = m_YD.y + InitY * m_ky;
	h = m_Con_Acc.w;
	w = h * 2;
	pDC->Rectangle(x,y,x+w,y+h);
}


void CPIDControl::InitTarAndCon()//初始化目标与控制车
{
	switch(m_way)
	{
	case 1:
		m_Con_Dis.x = 0;
		m_Con_Dis.v = 0;
		m_Con_Dis.a = 0;

		m_Con_Spe.x = 0;
		m_Con_Spe.v = 0;
		m_Con_Spe.a = 0;

		m_Con_Acc.x = 0;
		m_Con_Acc.v = 0;
		m_Con_Acc.a = 0;

		m_Tar.x = 0;
		m_Tar.a = 0;
		m_Tar.v = 100;
		break;
	case 2:
		m_Con_Dis.x = 0;
		m_Con_Dis.v = 0;
		m_Con_Dis.a = 0;

		m_Con_Spe.x = 0;
		m_Con_Spe.v = 0;
		m_Con_Spe.a = 0;

		m_Con_Acc.x = 0;
		m_Con_Acc.v = 0;
		m_Con_Acc.a = 0;
		
		m_Tar.x = 20;
		m_Tar.a = 5;
		m_Tar.v = 0;
		break;
	case 3:
		m_Con_Dis.x = 0;
		m_Con_Dis.v = 0;
		m_Con_Dis.a = 0;

		m_Con_Spe.x = 0;
		m_Con_Spe.v = 0;
		m_Con_Spe.a = 0;

		m_Con_Acc.x = 0;
		m_Con_Acc.v = 0;
		m_Con_Acc.a = 0;
		
		m_Tar.x = 20;
		m_Tar.a = 5;
		m_Tar.v = 0;
		break;
	} 
}
void CPIDControl::InitPIDParameter()
{
	m_DisPid.Ki = 0.1;
	m_DisPid.Kp = 1;
	m_DisPid.Kd = 0.001;
	m_DisPid.Act_val = 0;
	m_DisPid.Tar_val = 20;
	m_DisPid.err = 0;
	m_DisPid.err_sum = 0;
	m_DisPid.err_last = 20;

	m_SpePid.Ki = 5;
	m_SpePid.Kp = 5;
	m_SpePid.Kd = 0.5;
	m_SpePid.Act_val = 0;
	m_SpePid.Tar_val = 20;
	m_SpePid.err = 0;
	m_SpePid.err_sum = 0;
	m_SpePid.err_last = 20;

	m_AccPid.Ki = 0.2;
	m_AccPid.Kp = 0.5;
	m_AccPid.Kd = 10;
	m_AccPid.Act_val = 0;
	m_AccPid.Tar_val = 20;
	m_AccPid.err = 0;
	m_AccPid.err_sum = 0;
	m_AccPid.err_last = 20;
}
void CPIDControl::MoveUniform()//匀速移动
{
	int i;
	float delata = 0.1;
	m_Tar.x += m_Tar.v * delata;

	
	if(m_nTarX >= 60)
	{
		for(i = 0 ; i < m_nTarX - 1 ; i++)
		{
			m_TarX[i] = m_TarX[i+1];
		}
		m_nTarX--;
	}
	m_TarX[m_nTarX] = m_Tar.x;
	m_nTarX++;

	if(m_nTarV >= 60)
	{
		for(i = 0 ; i < m_nTarV - 1 ; i++)
		{
			m_TarV[i] = m_TarV[i+1];
		}
		m_nTarV--;
	}
	m_TarV[m_nTarV] = m_Tar.v;
	m_nTarV++;

	if(m_nTarA >= 60)
	{
		for(i = 0 ; i < m_nTarA - 1 ; i++)
		{
			m_TarA[i] = m_TarA[i+1];
		}
		m_nTarA--;
	}
	m_TarA[m_nTarA] = m_Tar.a;
	m_nTarA++;
}

void CPIDControl::MoveUniformAcceleration()//匀加速移动
{
	float delata = 0.1;
	m_Tar.v += m_Tar.a * delata;
	m_Tar.x += m_Tar.v * delata + 1/2.0 * m_Tar.a * delata * delata;
	

	int i;
	if(m_nTarX >= 60)
	{
		for(i = 0 ; i < m_nTarX - 1 ; i++)
		{
			m_TarX[i] = m_TarX[i+1];
		}
		m_nTarX--;
	}
	m_TarX[m_nTarX] = m_Tar.x;
	m_nTarX++;

	if(m_nTarV >= 60)
	{
		for(i = 0 ; i < m_nTarV - 1 ; i++)
		{
			m_TarV[i] = m_TarV[i+1];
		}
		m_nTarV--;
	}
	m_TarV[m_nTarV] = m_Tar.v;
	m_nTarV++;

	if(m_nTarA >= 60)
	{
		for(i = 0 ; i < m_nTarA - 1 ; i++)
		{
			m_TarA[i] = m_TarA[i+1];
		}
		m_nTarA--;
	}
	m_TarA[m_nTarA] = m_Tar.a;
	m_nTarA++;
}

void CPIDControl::MoveSine()//正弦移动
{

	m_Tar.x = 400 * sin(m_t) + 400 + 20;
	m_t += 0.05;

	int i;
	if(m_nTarV >= 60)
	{
		for(i = 0 ; i < m_nTarV - 1 ; i++)
		{
			m_TarV[i] = m_TarV[i+1];
		}
		m_nTarV--;
	}
	m_TarV[m_nTarV] = m_Tar.v;
	m_nTarV++;

	if(m_nTarA >= 60)
	{
		for(i = 0 ; i < m_nTarA - 1 ; i++)
		{
			m_TarA[i] = m_TarA[i+1];
		}
		m_nTarA--;
	}
	m_TarA[m_nTarA] = m_Tar.a;
	m_nTarA++;
	
	
}

void CPIDControl::MoveTargetCar()//目标小车移动
{
	switch(m_way)
	{
	case 1:
		MoveUniform();
		break;
	case 2:
		MoveUniformAcceleration();
		break;
	case 3:
		MoveSine();
		break;
	}
}

void CPIDControl::MoveControlCar_Displacement()//控制小车移动-控制位移
{
	//m_Con_Dis.x += (m_Tar.x - m_Con_Dis.x) * m_kp;

	int i;
	float delata = 0.1;
	m_DisPid.Tar_val = m_Tar.x;
	m_DisPid.Act_val = m_Con_Dis.x;
	m_DisPid.err = m_DisPid.Tar_val - m_DisPid.Act_val;
	m_DisPid.err_sum += m_DisPid.err * delata;
	m_Con_Dis.x += m_DisPid.err * m_DisPid.Kp + m_DisPid.err_sum * m_DisPid.Ki + m_DisPid.Kd * (m_DisPid.err - m_DisPid.err_last) / delata;
	m_DisPid.err_last = m_DisPid.err;

	
	if(m_nDisX >= 60)
	{
		for(i = 0 ; i < m_nDisX - 1 ; i++)
		{
			m_DisX[i] = m_DisX[i+1];
		}
		m_nDisX--;
	}
	m_DisX[m_nDisX] = m_Con_Dis.x;
	m_nDisX++;

	


}

void CPIDControl::MoveControlCar_Speed()//控制小车移动-控制速度
{
	float delata = 0.1;
//	m_Con_Spe.v += (m_Tar.x - m_Con_Spe.x) * m_kp;
//	m_Con_Spe.x += m_Con_Spe.v * delata;

	m_SpePid.Tar_val = m_Tar.x;
	m_SpePid.Act_val = m_Con_Spe.x;
	m_SpePid.err = m_SpePid.Tar_val - m_SpePid.Act_val;
	m_SpePid.err_sum += m_SpePid.err * delata;
	m_Con_Spe.v = 10 + m_SpePid.err * m_SpePid.Kp + m_SpePid.err_sum * m_SpePid.Ki + m_SpePid.Kd * (m_SpePid.err - m_SpePid.err_last) / delata;
	m_SpePid.err_last = m_SpePid.err;
	m_Con_Spe.x += m_Con_Spe.v * delata;

	
	

	
	int i;
	if(m_nSpeX >= 60)
	{
		for(i = 0 ; i < m_nSpeX - 1 ; i++)
		{
			m_SpeX[i] = m_SpeX[i+1];
		}
		m_nSpeX--;
	}
	m_SpeX[m_nSpeX] = m_Con_Spe.x;
	m_nSpeX++;

	if(m_nSpeV >= 60)
	{
		for(i = 0 ; i < m_nSpeV - 1 ; i++)
		{
			m_SpeV[i] = m_SpeV[i+1];
		}
		m_nSpeV--;
	}
	m_SpeV[m_nSpeV] = m_Con_Spe.v;
	m_nSpeV++;
	
}

void CPIDControl::MoveControlCar_Acceleration()//控制小车移动-控制加速度
{
	float delata = 0.1;
//	m_Con_Acc.a = 10 + (m_Tar.x - m_Con_Acc.x) * m_kp;
//	m_Con_Acc.v += m_Con_Acc.a * delata;
//	m_Con_Acc.x += m_Con_Acc.v * delata;

	m_AccPid.Tar_val = m_Tar.x;
	m_AccPid.Act_val = m_Con_Acc.x;
	m_AccPid.err = m_AccPid.Tar_val - m_AccPid.Act_val;
	m_AccPid.err_sum += m_AccPid.err * delata;
	m_Con_Acc.a = 10 + m_AccPid.err * m_AccPid.Kp + m_AccPid.err_sum * m_AccPid.Ki + m_AccPid.Kd * (m_AccPid.err - m_AccPid.err_last) / delata;
//	m_Con_Acc.a += m_pid.err * m_pid.Kp + m_pid.err_sum * m_pid.Ki + m_pid.Kd * (m_pid.err - m_pid.err_last);
	m_Con_Acc.v += m_Con_Acc.a * delata;
	m_Con_Acc.x += m_Con_Acc.v * delata;
	m_AccPid.err_last = m_AccPid.err;


	int i;
	if(m_nAccX >= 60)
	{
		for(i = 0 ; i < m_nAccX - 1 ; i++)
		{
			m_AccX[i] = m_AccX[i+1];
		}
		m_nAccX--;
	}
	m_AccX[m_nAccX] = m_Con_Acc.x;
	m_nAccX++;

	if(m_nAccV >= 60)
	{
		for(i = 0 ; i < m_nAccV - 1 ; i++)
		{
			m_AccV[i] = m_AccV[i+1];
		}
		m_nAccV--;
	}
	m_AccV[m_nAccV] = m_Con_Acc.v;
	m_nAccV++;

	if(m_nAccA >= 60)
	{
		for(i = 0 ; i < m_nAccA - 1 ; i++)
		{
			m_AccA[i] = m_AccA[i+1];
		}
		m_nAccA--;
	}
	m_AccA[m_nAccA] = m_Con_Acc.a;
	m_nAccA++;
}



void CPIDControl::CurveDrawZBZ(float x0, float y0, char StrName[],char StrMax[])
{
	float x = x0;
	float y = y0;
	pDC->MoveTo(x,y);
	x = x + 350;
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
		x += 5;//5像素对于0.1秒
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
	pDC->TextOut(x,y,StrMax);
	pDC->TextOut(x,y-20,StrName);

	x = x0;
	y = y0 + 170;
	pDC->MoveTo(x,y);
	x = x + 5;
	pDC->LineTo(x,y);
	CString s;
	s.Format("-");
	pDC->TextOut(x,y,s);
	pDC->TextOut(x+5,y,StrMax);
	
}
void CPIDControl::CurveInit()
{
	m_nTarX = 0;
	m_nDisX = 0;
	m_nSpeX = 0;
	m_nAccX = 0;

	m_nTarV = 0;
	m_nSpeV = 0;
	m_nAccV = 0;

	m_nTarA = 0;
	m_nAccA = 0;
}

void CPIDControl::CurveDrawDisplacement(float x0, float y0)
{
	int x,y,i;
	float ky = 170 / 800.0;//画位移曲线比例尺

	
	x = x0;
	y = y0 - m_TarX[0] * ky;
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,255));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nTarX ; i++)
	{
		x += 5;
		y = y0;
		y -= m_TarX[i] * ky;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen);
	delete pPen;

	x = x0;
	y = y0 - m_DisX[0] * ky;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nDisX ; i++)
	{
		x += 5;
		y = y0;
		y -= m_DisX[i] * ky;
		pDC->LineTo(x,y);
	}

	CPen *pPen1 = new CPen;
	pPen1->CreatePen(PS_SOLID,1,RGB(255,0,0));
	CGdiObject *pOldPen1 = pDC->SelectObject(pPen1);
	x = x0;
	y = y0 - m_SpeX[0] * ky;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nSpeX ; i++)
	{
		x += 5;
		y = y0;
		y -= m_SpeX[i] * ky;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pPen1);
	delete(pPen1);

	CPen *pPen3 = new CPen;
	pPen3->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *pOldPen3 = pDC->SelectObject(pPen3);
	x = x0;
	y = y0 - m_AccX[0] * ky;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nAccX ; i++)
	{
		x += 5;
		y = y0;
		y -= m_AccX[i] * ky;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen3);
	delete pPen3;

}

void CPIDControl::CurveDrawSpeed(float x0, float y0)
{
	int x,y,i;
	float ky = 170 / 200.0;//画速度曲线比例尺
	x = x0;
	y = y0 - m_TarV[0] * ky;
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,255));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nTarV ; i++)
	{
		
		y = y0;
		y -= m_TarV[i] * ky;
		pDC->LineTo(x,y);
		x += 5;
	}
	pDC->SelectObject(pOldPen);
	delete pPen;

	CPen *pPen1 = new CPen;
	pPen1->CreatePen(PS_SOLID,1,RGB(255,0,0));
	CGdiObject *pOldPen1 = pDC->SelectObject(pPen1);
	x = x0;
	y = y0 - m_SpeV[0] * ky;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nSpeV ; i++)
	{
		x += 5;
		y = y0;
		y -= m_SpeV[i] * ky;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen1);
	delete pPen1;

	CPen *pPen2 = new CPen;
	pPen2->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *pOldPen2 = pDC->SelectObject(pPen2);
	x = x0;
	y = y0 - m_AccV[0] * ky;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nAccV ; i++)
	{
		x += 5;
		y = y0;
		y -= m_AccV[i] * ky;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen2);
	delete pPen2;
}

void CPIDControl::CurveDrawAcceleration(float x0, float y0)
{
	int x,y,i;
	float ky = 170 / 200.0;//画加速度曲线比例尺
	x = x0;
	y = y0 - m_TarA[0] * ky;
	CPen *pPen = new CPen;
	pPen->CreatePen(PS_SOLID,1,RGB(0,0,255));
	CGdiObject *pOldPen = pDC->SelectObject(pPen);
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nTarA ; i++)
	{
		y = y0;
		y -= m_TarA[i] * ky;
		pDC->LineTo(x,y);
		x += 5;
	}
	pDC->SelectObject(pOldPen);
	delete pPen;
	

	CPen *pPen2 = new CPen;
	pPen2->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *pOldPen2 = pDC->SelectObject(pPen2);
	x = x0;
	y = y0 - m_AccA[0] * ky;
	pDC->MoveTo(x,y);
	for(i = 1 ; i < m_nAccA ; i++)
	{
		x += 5;
		y = y0;
		y -= m_AccA[i] * ky;
		pDC->LineTo(x,y);
		
	}
	pDC->SelectObject(pOldPen2);
	delete pPen2;
	
}



