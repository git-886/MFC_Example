// Spring.cpp: implementation of the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpringSport.h"
#include "Spring.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpring::CSpring()
{
	//����
	m_initL = 170;
	m_nowL = m_initL;
	m_phL = 150;  //ƽ�ⳤ��
	m_LeftUp.x = 200;  //�������Ͻ�����
	m_LeftUp.y = 100;
	m_wSpring = 50;  //���ɿ��
	m_kSpring = 5;  //���ɵĵ���ϵ��
	m_znSpring = 0.95; //���ɵ�����ϵ��

	m_Line = 20;  //������С��֮������߳���

	//С��
	m_rCir = 10; //С��뾶
	m_xCenter = m_LeftUp.x + m_wSpring / 2; //С����������
	m_yCenter = m_LeftUp.y + m_nowL + m_Line + m_rCir;
	m_initV = 5; //���ٶ�

	m_mCir = 5; //С������

	m_nyCir = 0;
	m_nvCir = 0;
	m_naCir = 0;
	m_nfCir = 0;
}

CSpring::~CSpring()
{

}

void CSpring::Draw(CDC *p)
{
	pDC = p;

	DrawSpring();
	DrawCircle();

	DrawYQuXian();
	DrawVQuXian();
	DrawAQuXian();
	DrawFQuXian();
}

//������
void CSpring::DrawSpring()
{
	int x, y, w, h;

	//�������Ҷ���
	w = 200;
	x = (m_LeftUp.x + m_LeftUp.x + m_wSpring) / 2 - w / 2;
	y = m_LeftUp.y - 50;
	pDC->MoveTo(x, y);
	pDC->LineTo(x + w, y);
	pDC->MoveTo(x + w / 2, y);
	pDC->LineTo(x + w / 2, y + 50);

	//����
	x = m_LeftUp.x;
	y = m_LeftUp.y;
	w = m_wSpring;
	h = m_nowL;
	pDC->Rectangle(x, y, x + w, y + h);
}

//��С��
void CSpring::DrawCircle()
{
	int x, y, r;

	//������С�����ӵ���
	pDC->MoveTo(m_xCenter, m_yCenter);
	pDC->LineTo(m_xCenter, m_yCenter - m_Line - m_rCir);

	//С��
	x = m_xCenter;
	y = m_yCenter;
	r = m_rCir;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
}

//��С���˶���y����
void CSpring::DrawYQuXian()
{
	//���̶�
	int initX = 500;
	int initY = 125;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "�켣����");

	//������
	int i;
	int x = initX;
	int y = initY + m_yCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nyCir; i++)
	{
		x += 1;
		y = initY + m_yCir[i];
		pDC->LineTo(x, y);
	}
}

//��С���˶����ٶ�����
void CSpring::DrawVQuXian()
{
	//���̶�
	int initX = 900;
	int initY = 125;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "�ٶ�����");

	//������
	int i;
	int x = initX;
	int y = initY + m_vCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nvCir; i++)
	{
		x += 1;
		y = initY + m_vCir[i];
		pDC->LineTo(x, y);
	}

}

//��С��ļ��ٶ�����
void CSpring::DrawAQuXian()
{
	//���̶�
	int initX = 500;
	int initY = 425;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "���ٶ�����");

	//������
	int i;
	int x = initX;
	int y = initY + m_aCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_naCir; i++)
	{
		x += 1;
		y = initY + m_aCir[i];
		pDC->LineTo(x, y);
	}

}

//��С�����������
void CSpring::DrawFQuXian()
{
	//���̶�
	int initX = 900;
	int initY = 425;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "��������");

	//������
	int i;
	int x = initX;
	int y = initY + m_fCir[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nfCir; i++)
	{
		x += 1;
		y = initY + m_fCir[i];
		pDC->LineTo(x, y);
	}
}

//����������С���˶�
void CSpring::Move()
{
	float x = m_nowL - m_phL;  //���ɵ��쳤�����쳤Ϊ��������Ϊ��

	m_fCir[m_nfCir] = m_mCir * 9.8 - m_kSpring * x;    //F = mg - kx

	m_aCir[m_naCir] = m_fCir[m_nfCir] / m_mCir;  //a = F / m

	if (m_nvCir == 0)
	{
		m_vCir[m_nvCir] = m_initV;
	}
	else
	{
		m_vCir[m_nvCir] = m_vCir[m_nvCir - 1] + m_aCir[m_naCir - 1] * 0.1; //v = v0 + at
		x = m_vCir[m_nvCir - 1] * 0.1 + m_aCir[m_naCir - 1] * 0.1 * 0.1 / 2;    //x = v0 * t + 1/2 * a * t^2
		x *= m_znSpring;  //����ϵ��
	}

	m_nowL += x;

	m_yCenter = m_LeftUp.y + m_nowL + m_Line + m_rCir;;

	m_yCir[m_nyCir] = m_yCenter - m_LeftUp.y - m_initL - m_Line - m_rCir;

	m_nvCir++;
	m_naCir++;
	m_nfCir++;
	m_nyCir++;
}