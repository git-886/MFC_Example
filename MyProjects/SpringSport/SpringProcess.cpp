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
	m_k = 10;//����ϵ����ʼֵ
	m_zn = 0.9;//�����ʼֵ
	m_L0 = 0.4;//����ԭ��
	m_L = 0.2;//���ɳ��ȳ�ʼֵ
	m_m = 0.2;//С������

	m_kZH = 200;//��������ת��ϵ��-��ֵ
	m_w = 0.1;//���ɿ�-��ֵ
	m_LUp = 0.2;//������-��ֵ
	m_LDown = 0.2;//������-��ֵ
	m_r = 0.05;//С��뾶-��ֵ

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
	DrawName(220,580,"���ٶ�����");

	CString str;
	str.Format("20m/s^2");
	pDC->TextOut(100,380,str);
	str.Format("-20m/s^2");
	pDC->TextOut(100,610,str);

	x0 = 100;
	y0 = 500;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_naGJ ; i++)//һ��ÿƽ�����Ӧ5px,�����ٶȽӽ�20m/s^2
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
	DrawName(720,580,"����������");
	CString str;
	str.Format("4N");
	pDC->TextOut(600,380,str);
	str.Format("-4N");
	pDC->TextOut(600,610,str);

	x0 = 600;
	y0 = 500;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_nfGJ ; i++)//1N��Ӧ25px,�����ٶȽӽ�4N
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
	DrawName(720,280,"С���ٶ�����");
	CString str;
	str.Format("2m/s");
	pDC->TextOut(600,80,str);
	str.Format("-2m/s");
	pDC->TextOut(600,310,str);

	
	x0 = 600;
	y0 = 200;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_nvGJ ; i++)//1m/s��Ӧ50px,����ٶȲ�����2m/s
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
	DrawName(1220,580,"λ������");

	CString str;
	str.Format("1m");
	pDC->TextOut(1100,380,str);


	x0 = 1100;
	y0 = 500;
	pDC->MoveTo(x0,y0);
	for(i = 0 ; i< m_nyGJ ; i++)//1m��Ӧ100px,���λ�Ʋ�����1m
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

void CSpringProcess::DrawYAndYkd(int x0, int y0, int y_Lpx)//ÿһ��С�̶�5px
{
	int x,y;
	pDC->MoveTo(x0, y0);//��y��
	pDC->LineTo(x0, y0 - y_Lpx);
	pDC->MoveTo(x0, y0);
	pDC->LineTo(x0, y0 + y_Lpx);

	//y���������ͷ
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
	//y�Ḻ�����ͷ
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

	//��y��̶�
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

void CSpringProcess::DrawXAndXkd(int x0, int y0,int x_Lpx)//��X�ἰx�̶�,����x0,y0Ϊԭ�����꣬x_LpxΪx �����س���
{
	int x,y;
	pDC->MoveTo(x0, y0);
	pDC->LineTo(x0 + x_Lpx, y0);//����x0,y0��x��

	//x���ͷ
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

	//��x��̶ȣ�0.1���Ӧ�̶�Ϊ5����
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
	str.Format("��λs");
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
	m_f = m_m*0.98 - (m_L - m_L0)*m_k;//������Ϊ����
	m_a = m_f/m_m;
	m_v += m_a*deltat;
	m_v *= m_zn;
	m_y += m_v*deltat;//m_y��ʾ����ÿ��0.1����������������ԭ������ľ���
	//dis = abs(m_v*deltat);//λ����
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













