// CarRobot.cpp : implementation file
//

#include "stdafx.h"
#include "RobertInspection.h"
#include "CarRobot.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926
/////////////////////////////////////////////////////////////////////////////
// CCarRobot

CCarRobot::CCarRobot()
{
	m_YD.x = 300;
	m_YD.y = 700;

	
	m_x = -260 + rand()%861;//ʵ��λ�õ�λm
	m_y = -120 + rand()%911;


	m_w = 5;//5m
	m_v = 20;//5m/s

	m_r = 50;
	m_wv = PI/180 * 50;//50��/s
	m_dir = 12;
	m_Flag_SN = 1;

	m_nPointGJ = 0;
	m_nCur = 0;

	
	RotCircle.r = 25;//m
	RotCircle.w = 300;//30��ÿ0.1��
	RotCircle.x = m_x -  RotCircle.r;//Բ����С�������
	RotCircle.y = m_y;
	RotCircle.angle = 0;
	RotCircle.MaxND = 0;
	RotCircle.MinND = 0;
	RotCircle.Max.x = m_x;
	RotCircle.Max.y = m_y;
	RotCircle.Min.x = m_x;
	RotCircle.Min.y = m_y;

	

	m_flag_MoveWay = 0;

	m_ky = -864/1000.0;
	m_kx = 1536/1000.0;

	m_nd = 0;
}

CCarRobot::~CCarRobot()
{
}


BEGIN_MESSAGE_MAP(CCarRobot, CWnd)
	//{{AFX_MSG_MAP(CCarRobot)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCarRobot message handlers

void CCarRobot::Draw(CDC *p)
{
	pDC = p;
	DrawCar();
	DrawSpecifyPointPath();

	//Draw��ǰ�³�����λ��Ũ��
	CString str;
	str.Format("�Զ����й©��С����ǰŨ�ȣ�%d",m_nd);
	pDC->TextOut(1200,40,str);

	//DrawŨ�����ֵ�㼰Ũ����Сֵ��
	int x,y,r;
	x = m_YD.x + RotCircle.Max.x * m_kx;
	y = m_YD.y + RotCircle.Max.y * m_ky;
	r = 5;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	x = m_YD.x + RotCircle.Min.x * m_kx;
	y = m_YD.y + RotCircle.Min.y * m_ky;
	r = 3;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	
}

void CCarRobot::DrawCar()
{
	int x,y;
	float w,l,r;
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	w = m_w * m_kx;
	l = w * 2.0;
	pDC->Rectangle(x,y,x+l,y+w);
	x = x + l + w/2.0;
	r = w/2.0;
	y = y + r;
	pDC->Ellipse(x-r,y-r,x+r,y+r);	
}

void CCarRobot::DrawSpecifyPointPath()
{
	int i,x,y;
	for(i = 0 ; i < m_nPointGJ ; i++)
	{
		x = m_YD.x + m_PointGJ[i].x * m_kx;
		y = m_YD.y + m_PointGJ[i].y * m_ky;
		if(i == 0)
		pDC->MoveTo(x,y);
		pDC->LineTo(x,y);
	}
}
void CCarRobot::MoveBySpecifiedPoint(int x,int y)//����Ϊ��ͼĿ�������
{
	m_x = (x - m_YD.x) / m_kx;//����������ʵ������
	m_y = (y - m_YD.y) / m_ky;
}

int CCarRobot::MoveByUniform()
{
	float x_tar = (m_YSYDpoint.x - m_YD.x) / m_kx;
	float y_tar = (m_YSYDpoint.y - m_YD.y) / m_ky;
	float deltat = 0.1;
	float dx = x_tar - m_x;
	float dy = y_tar - m_y;
	float d = sqrt(dx * dx + dy * dy);
	float vx = dx/d * m_v;
	float vy = dy/d * m_v;

	m_x = m_x + vx * deltat;
	m_y = m_y + vy * deltat;
	if(abs(dx) == 0 && abs(dy) == 0)
	{
		return 1;//�ƶ���ָ����
	}
	return 0;
}
///////////////////////////////////
void CCarRobot::MoveRotate()
{
	float deltat = 0.1;
	m_x = m_YXx + cos(m_JD) * m_r;
	m_y = m_YXy + sin(m_JD) * m_r;
	if(m_Flag_SN == 2)
	{
		m_JD += m_wv * deltat;
	}else if(m_Flag_SN == 1)
	{
		m_JD -= m_wv * deltat;
	}
	
}

void CCarRobot::QuiYunaXin()
{
	m_YXx = m_x - cos(m_JD) * m_r;
	m_YXy = m_y - sin(m_JD) * m_r;
}
///////////////////////////////////////
//��ָ��·���ƶ���غ���
int CCarRobot::MoveSpecifyPath()
{
	int i;
	float deltat = 0.1;
	float dx,dy,d,vx,vy;
	dx = m_PointGJ[m_nCur+1].x - m_PointGJ[m_nCur].x;
	dy = m_PointGJ[m_nCur+1].y - m_PointGJ[m_nCur].y;
	d = sqrt(dx * dx + dy * dy);
	vx = dx/d * m_v;
	vy = dy/d * m_v;
	m_x = m_x + vx * deltat;
	m_y = m_y + vy * deltat;
	if(abs(m_x - m_PointGJ[m_nCur+1].x) == 0 && abs(m_y - m_PointGJ[m_nCur+1].y) == 0)
	{
		m_nCur++;
	}
	if(m_nCur+1 == m_nPointGJ)
		return 1;
	return 0;
}
void CCarRobot::InitSpecifyPoint(float x, float y)
{
	m_x = x;
	m_y = y;
}
/////////////////////////////////////////////////////////
void CCarRobot::MoveToLeakPoint(int x)//���ݼ�������ĵ�ǰС���������Ũ�ȷ��򣬽����ƶ�
{
	
	float deltat = 0.1;
	float vx,vy;
	vx = cos((12 + 3 - x) * PI / 6.0) * m_v;
	vy = sin((12 + 3 - x) * PI / 6.0) * m_v;
	m_x = m_x + vx * deltat;
	m_y = m_y + vy * deltat;
}
/////////////////////////////////////////////////////////
int CCarRobot::Move()
{
	int i = 0;
	if(m_flag_MoveWay == 2)
	{
		i = MoveByUniform();
	}
	if(m_flag_MoveWay == 3)
	{
		MoveRotate();
	}
	if(m_flag_MoveWay == 4)
	{
		i = MoveSpecifyPath();
	}
	return i;
}

void CCarRobot::LBDProcess(CPoint point)
{
	if(m_flag_MoveWay == 2)
	{
		m_YSYDpoint = point;
	}
}

void CCarRobot::RotateMethodFindLeakPoint(float nd)//����ΪС����ǰλ�õ�Ũ��
{
	float deltat = 0.1;
	float dx,dy,d;
	
		if(RotCircle.angle >= 360)
		{
			if(abs(RotCircle.Max.x - m_x) == 0 && abs(RotCircle.Max.y - m_y) == 0)
			{
				RotCircleInit(nd,m_x,m_y);//ת��һȦ���ƶ������Ũ�ȵ����ʼ��Բ�Ĳ���
			}else
			{
				//�ƶ������Ũ�ȵ�
				dx = RotCircle.Max.x - m_x;
				dy = RotCircle.Max.y - m_y;
				d = sqrt(dx * dx + dy * dy);
				m_x += dx/d * m_v * deltat;
				m_y += dy/d * m_v * deltat;
			}
		}
		else
		{
			RotCircle.angle += RotCircle.w * deltat;
			m_x = RotCircle.x + cos(RotCircle.angle / 180.0 * PI ) * RotCircle.r;
			m_y = RotCircle.y + sin(PI / 180.0 * RotCircle.angle) * RotCircle.r;

			if(RotCircle.MaxND < nd)
			{
				RotCircle.MaxND = nd;
				RotCircle.Max.x = m_x;
				RotCircle.Max.y = m_y;
			}
			if(RotCircle.MinND > nd)
			{
				RotCircle.MinND = nd;
				RotCircle.Min.x = m_x;
				RotCircle.Min.y = m_y;
			}
		}
}

void CCarRobot::RotCircleInit(float nd,float m_x,float m_y)
{
	RotCircle.w = 300;//30��ÿ0.1��
	RotCircle.x = m_x -  RotCircle.r;//Բ����С�������
	RotCircle.y = m_y;
	RotCircle.r *= 0.95;
	RotCircle.angle = 0;
	RotCircle.MaxND = nd;
	RotCircle.MinND = nd;
	RotCircle.Max.x = m_x;
	RotCircle.Max.y = m_y;
	RotCircle.Min.x = m_x;
	RotCircle.Min.y = m_y;
}
