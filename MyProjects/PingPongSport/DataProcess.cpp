// DataProcess.cpp : implementation file
//

#include "stdafx.h"
#include "PingPongSport.h"
#include "DataProcess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataProcess

CDataProcess::CDataProcess()
{

	m_YD1.x = 114;//����ͼ��ͼԭ��
	m_YD1.y = 292;

	m_YD2.x = 900;//����ͼ��ͼԭ��
	m_YD2.y = 60;

	

	m_x0 = 0;
	m_y0 = 0;
	m_z0 = 0.3;

	m_x = m_x0;
	m_y = m_y0;
	m_z = m_z0;

	m_m = 0.0025;//ƹ��������25g
	m_r = 0.02;//ƹ����뾶20mm

	m_Ftsum = 0;//��������

	m_vx0 = 1;
	m_vy0 = 1;
	m_vz0 = 1;

	m_vx = m_vx0;//m/s
	m_vy = m_vy0;//һ��15-20m/s;
	m_vz = m_vz0;

	m_length = 2.7;//ƹ��������
	m_weight = 1.5;//ƹ��������
	m_LWheight = 0.15;//�����߶�
	m_ZTheight = 0.7;//���ȸ߶�

	m_nxGj = 0;
	m_nyGj = 0;
	m_nzGj = 0;

	m_nvxGj = 0;
	m_nvyGj = 0;
	m_nvzGj = 0;

	m_PowerReducek = 0.9;

	m_k = 200;
	m_ktx = 30;
	

}

CDataProcess::~CDataProcess()
{
}


BEGIN_MESSAGE_MAP(CDataProcess, CWnd)
	//{{AFX_MSG_MAP(CDataProcess)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDataProcess message handlers

void CDataProcess::Draw(CDC *p)
{
	
	pDC = p;
	DrawRegion();
	DrawCSTSport();
	DrawZBZ(10,580,"m","��ɫΪx����-��ɫΪy����-��ɫΪz����");
	DrawZBZ(390,580,"m/s","��ɫΪx����-��ɫΪy����-��ɫΪz����");

	DrawDisplacementCurve(10,580);
	DrawSpeedCurve(390,580);

	DrawFSTSport();
}

void CDataProcess::DrawRegion()
{
	float x,y;
	int iWidth = GetSystemMetrics(SM_CXSCREEN);
	int iHegiht = GetSystemMetrics(SM_CYSCREEN);
	x = 0;
	y = iHegiht/2.0;
	pDC->MoveTo(x,y);
	x = iWidth;
	pDC->LineTo(x,y);
	x = iWidth/2.0;
	y = 0;
	pDC->MoveTo(x,y);
	y = iHegiht;
	pDC->LineTo(x,y);
}

void CDataProcess::DrawCSTSport()
{
	////////////////////Draw ����ͼƹ������
	int iWidth = GetSystemMetrics(SM_CXSCREEN);
	int iHegiht = GetSystemMetrics(SM_CYSCREEN);
	float x,y;
	x = m_YD1.x;
	y = m_YD1.y;
	pDC->MoveTo(x,y);
	x += m_length * m_k;
	pDC->LineTo(x,y);
	x = iWidth / 4.0;
	pDC->MoveTo(x,y);
	y -= m_LWheight * m_k;
	pDC->LineTo(x,y);
	y = iHegiht / 2.0 - m_ZTheight * m_k;
	x = (iWidth/2.0 - m_length * m_k) / 2.0 + m_length * m_k / 4.0;
	pDC->MoveTo(x,y);
	y += m_ZTheight * m_k;
	pDC->LineTo(x,y);
	x = (iWidth/2.0 - m_length * m_k) / 2.0 + (m_length * m_k / 4.0) * 3;
	pDC->MoveTo(x,y);
	y -= m_ZTheight * m_k;
	pDC->LineTo(x,y);

	//////////////////////////////
	x = m_YD1.x;
	y = m_YD1.y;

	
	y -= m_z * m_k;
	x += m_y * m_k;
	float r = m_r*m_k;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

}

void CDataProcess::DrawFSTSport()
{
	//////////////////////Draw����ͼƹ������
	int x,y;
	x = m_YD2.x;
	y = m_YD2.y;
	float weight,length;
	weight = m_length * m_k;
	length = m_weight * m_k;
	pDC->Rectangle(x,y,x+weight,y+length);
	x = m_YD2.x + (m_length * m_k)/2;
	y = m_YD2.y - 20;
	pDC->MoveTo(x,y);
	y += m_weight * m_k + 40;
	pDC->LineTo(x,y);

	////////////////////////////Draw ƹ����

	x = m_YD2.x;
	y = m_YD2.y + m_weight * m_k / 2;

	float r = m_r*m_k;
	x += m_y * m_k;
	y += m_x * m_k;
	pDC->Ellipse(x-r,y-r,x+r,y+r);




}





void CDataProcess::Move()
{
	float deltat = 0.1;
	float a = - 9.8; 
	
	//z�������ȱ���ֱ���˶�,x,y����������ֱ���˶�
	m_vxGj[m_nvxGj] = m_vx;
	m_vyGj[m_nvyGj] = m_vy;
	m_vzGj[m_nvzGj] = m_vz;
	
	m_nvxGj++;
	m_nvyGj++;
	m_nvzGj++;

	
	m_vz = m_vzGj[m_nvzGj - 1] + a * deltat;
	

	m_x += m_vx * deltat;
	m_y += m_vy * deltat;
	m_z += m_vzGj[m_nvzGj - 1] * deltat + 1/2.0 * a * deltat * deltat;

	if(m_z <= 0)
	{
		m_z = 0;
		m_vz = -m_vz * m_PowerReducek;
		m_Ftsum++;
	}
	
	m_xGj[m_nxGj] = m_x;
	m_yGj[m_nyGj] = m_y;
	m_zGj[m_nzGj] = m_z;

	m_nxGj++;
	m_nyGj++;
	m_nzGj++;
	
	
	
	
}



void CDataProcess::DrawZBZ(float x0, float y0, char str[],char strname[])
{
	float x = x0;
	float y = y0;
	pDC->MoveTo(x,y);
	x = x + 300;
	pDC->LineTo(x,y);

	//��x���ͷ
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

	//��x�̶�
	x = x0;
	y = y0;
	int i;
	for(i = 1 ; i <= 60 ; i++)
	{
		x += 5;
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

	//��y��
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y + 150;
	pDC->LineTo(x,y);
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	y = y - 150;
	pDC->LineTo(x,y);
	
	//��y���ͷ
	x = x - 5;
	y = y + 5;
	pDC->LineTo(x,y);
	x = x + 5;
	y = y - 5;
	pDC->MoveTo(x,y);
	x = x + 5;
	y = y + 5;
	pDC->LineTo(x,y);

	//��y��̶�
	x = x0;
	y = y0;
	for(i = 1 ; i <= 10 ; i++)
	{
		y -= 15;
		x = x0;
		pDC->MoveTo(x,y);
		if(i % 2  == 0)
		x = x + 10;
		x = x + 5;
		pDC->LineTo(x,y);
	}
	x = x0;
	y = y0;
	for(i = 1 ; i < 6 ; i++)
	{
		y -= 31;
		x = x0 - 10;
		pDC->MoveTo(x,y);
		CString str;
		str.Format("%d",i);
		pDC->TextOut(x,y,str);
	}

	x = x0 + 8;
	y = y0 - 146;
	pDC->TextOut(x,y,str);


	//��������������
	x = 50 + x0;
	y = 100 + y0;
	pDC->TextOut(x,y,strname);


}

void CDataProcess::DrawDisplacementCurve(float x0, float y0)
{
	float x,y;
	int i;
/////////////////////////////////xλ��ͼ��
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	CPen *pPen1 = new CPen;
	pPen1->CreatePen(PS_SOLID,1,RGB(255,0,0));
	CGdiObject *OldPen1 = pDC->SelectObject(pPen1);
	for(i = 0 ; i < m_nxGj ; i++)
	{
		x += 5;
		y = y0 - m_xGj[i] * m_ktx;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(OldPen1);
	delete pPen1;
//////////////////////////////////yλ��ͼ��
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	CPen *pPen2 = new CPen;
	pPen2->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *OldPen2 = pDC->SelectObject(pPen2);
	for(i = 0 ; i < m_nyGj ; i++)
	{
		x += 5;
		y = y0 - m_yGj[i] * m_ktx;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(OldPen2);
	delete pPen2;
///////////////////////////////////zλ��ͼ��
	x = x0;
	y = y0;
	pDC->MoveTo(x,y);
	CPen *pPen3 = new CPen;
	pPen3->CreatePen(PS_SOLID,2,RGB(0,0,255));
	CGdiObject *pOldPen3 = pDC->SelectObject(pPen3);
	for(i = 0 ; i < m_nzGj ; i++)
	{
		x += 5;
		y = y0 - m_zGj[i] * m_ktx;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen3);
	delete pPen3;

}

void CDataProcess::DrawSpeedCurve(float x0, float y0)
{
	float x,y;
	int i;
/////////////////////////////////x�ٶ�ͼ��
	x = x0;
	y = y0 - m_vx0 * m_ktx;
	pDC->MoveTo(x,y);
	CPen *pPen1 = new CPen;
	pPen1->CreatePen(PS_SOLID,1,RGB(255,0,0));
	CGdiObject *OldPen1 = pDC->SelectObject(pPen1);
	for(i = 0 ; i < m_nvxGj ; i++)
	{
		x += 5;
		y = y0 - m_vxGj[i] * m_ktx;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(OldPen1);
	delete pPen1;
//////////////////////////////////y�ٶ�ͼ��
	x = x0;
	y = y0 - m_vy0 * m_ktx;
	pDC->MoveTo(x,y);
	CPen *pPen2 = new CPen;
	pPen2->CreatePen(PS_SOLID,1,RGB(0,255,0));
	CGdiObject *OldPen2 = pDC->SelectObject(pPen2);
	for(i = 0 ; i < m_nvyGj ; i++)
	{
		x += 5;
		y = y0 - m_vyGj[i] * m_ktx;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(OldPen2);
	delete pPen2;
///////////////////////////////////z�ٶ�ͼ��
	x = x0;
	y = y0 - m_vz0 * m_ktx;
	pDC->MoveTo(x,y);
	CPen *pPen3 = new CPen;
	pPen3->CreatePen(PS_SOLID,2,RGB(0,0,255));
	CGdiObject *pOldPen3 = pDC->SelectObject(pPen3);
	for(i = 0 ; i < m_nvzGj ; i++)
	{
		x += 5;
		y = y0 - m_vzGj[i] * m_ktx;
		pDC->LineTo(x,y);
	}
	pDC->SelectObject(pOldPen3);
	delete pPen3;

}

int CDataProcess::ZWPanDuan()
{
	/*
	if(m_y < m_LWheight)
	{
		return 1;
	}
	
	*/
	return 0;
}
int CDataProcess::CJPanDuan()//�������ж�
{
	
	if(m_y >= m_length - m_y0)
	{
		return 1;
	}
	if(m_x0 > 0)
	{
		if(m_x >= m_weight/2.0 - m_x0)
			return 1;
	}
	if(m_x0 < 0)
	{
		if(m_x <= -m_weight/2.0 + m_x0)
			return 1;
	}
	if(m_x0 == 0)
	{
		if(m_x >= m_weight/2.0 || m_x <= -m_weight/2.0)
		{
			return 1;
		}	
	}
	return 0;


}

int CDataProcess::FGPanDuan()
{
	if(m_Ftsum > 1 && ((m_y - m_y0) < m_length/2.0))//����������̨�������������򷸹�
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


