#if !defined(AFX_DATAPROCESS_H__8FFF7B08_374D_40F4_B1B7_C696D4589181__INCLUDED_)
#define AFX_DATAPROCESS_H__8FFF7B08_374D_40F4_B1B7_C696D4589181__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataProcess.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataProcess window

class CDataProcess : public CWnd
{
// Construction
public:
	CDataProcess();

// Attributes
public:
	CDC *pDC;

	CPoint m_YD1;//���Ͻǻ�ͼԭ��
	CPoint m_YD2;//���Ͻǻ�ͼԭ��

	float m_x0;
	float m_y0;
	float m_z0;

	float m_vx0;
	float m_vy0;
	float m_vz0;

	float m_length;//ƹ��������
	float m_weight;//ƹ��������
	float m_LWheight;//�����߶�
	float m_ZTheight;//�����߶�
	
	float m_m;//ƹ����������kg
	float m_r;//ƹ����뾶m

	float m_PowerReducek;//����������ʧϵ��


	int m_Ftsum;//��¼��������
	


	

	float m_xGj[1000];//��¼ƹ����λ��
	float m_yGj[1000];
	float m_zGj[1000];

	float m_x;//x����λ��
	float m_y;//y����λ��
	float m_z;//z����λ��

	int m_nxGj;
	int m_nyGj;
	int m_nzGj;

	float m_vxGj[1000];//��¼ƹ�����ٶ�
	float m_vyGj[1000];
	float m_vzGj[1000];

	float m_vx;//x�����ٶ�
	float m_vy;//y�����ٶ�
	float m_vz;//z�����ٶ�

	int m_nvxGj;
	int m_nvyGj;
	int m_nvzGj;

	float m_k;//����ת��ϵ��,��ƹ��������ƹ����
	float m_ktx;//����ת��ϵ������x��y��z�����λ�Ƽ��ٶ�ͼ��
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataProcess)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawFSTSport();
	int FGPanDuan();
	int ZWPanDuan();
	void DrawSpeedCurve(float x0, float y0);
	void DrawDisplacementCurve(float x0, float y0);
	void DrawZBZ(float x0, float y0, char str[],char strname[]);
	int CJPanDuan();
	void Move();
	void DrawCSTSport();
	void DrawRegion();
	void Draw(CDC *p);
	virtual ~CDataProcess();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDataProcess)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAPROCESS_H__8FFF7B08_374D_40F4_B1B7_C696D4589181__INCLUDED_)
