// Spring.h: interface for the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRING_H__4A701468_652F_4B9F_8296_E38396724B10__INCLUDED_)
#define AFX_SPRING_H__4A701468_652F_4B9F_8296_E38396724B10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpring  
{
public:
	void DrawFQuXian();
	void DrawAQuXian();
	void DrawVQuXian();
	void DrawYQuXian();
	void Move();
	void DrawCircle();
	void DrawSpring();
	void Draw(CDC *p);
	CSpring();
	virtual ~CSpring();

	CDC *pDC;

	//����
	float m_initL;
	float m_phL;  //ƽ�ⳤ��
	float m_nowL; //ʵʱ����
	CPoint m_LeftUp;  //�������Ͻ�����
	float m_wSpring;  //���ɿ��
	float m_kSpring;  //���ɵĵ���ϵ��
	float m_znSpring; //���ɵ�����ϵ��

	float m_Line;  //������С��֮������߳���

	//С��
	float m_xCenter, m_yCenter; //С����������
	float m_rCir; //С��뾶
	float m_mCir; //С������
	float m_initV; //С���ٶ�

	float m_yCir[1000];  //С���˶��켣
	float m_vCir[1000];  //С���˶��ٶ�
	float m_aCir[1000];  //С����ٶ�
	float m_fCir[1000];  //С������

	int m_nyCir, m_nvCir, m_naCir, m_nfCir;
};

#endif // !defined(AFX_SPRING_H__4A701468_652F_4B9F_8296_E38396724B10__INCLUDED_)
