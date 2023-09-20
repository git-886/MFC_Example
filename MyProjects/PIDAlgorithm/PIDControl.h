#if !defined(AFX_PIDCONTROL_H__4AC7FBCD_E1E2_4780_92F9_787F93BB3D18__INCLUDED_)
#define AFX_PIDCONTROL_H__4AC7FBCD_E1E2_4780_92F9_787F93BB3D18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PIDControl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPIDControl window
typedef struct
{
	float w;//С�����
	float x;
	float v;
	float a;
}SCar;

typedef struct
{
	float Tar_val;//Ŀ��ֵ��Ŀ��С��ֵ��
	float Act_val;//ʵ��ֵ������С��ֵ��
	float err;//��ǰƫ��
	float err_last;//�ϴ�ƫ��
	float err_sum;//����ۼ�ֵ
	float Kp,Ki,Kd;//���������֣�΢��ϵ��(Ki���ڿ��ٲ�����̬��Kd����������̬���)
}SPID;
class CPIDControl : public CWnd
{
// Construction
public:
	CPIDControl();

// Attributes
public:

// Operations
public:
	CPoint m_YD;//����ԭ��
	SCar m_Tar;//Ŀ��С��
	SCar m_Con_Dis;//����С��-λ��
	SCar m_Con_Spe;//����С��-�ٶ�
	SCar m_Con_Acc;//����С��-���ٶ�

	SPID m_DisPid;//pid���ƽṹ�����
	SPID m_SpePid;//pid���ƽṹ�����
	SPID m_AccPid;//pid���ƽṹ�����

	float m_t;

	int m_way;//�ƶ���ʽ��Ĭ��Ϊ1-�����ƶ���2-�ȼ����ƶ���3�����ƶ���

	float m_kp;//����ϵ��

	float m_kx;//������
	float m_ky;

	

	CDC *pDC;


	float m_TarX[10000];//���ڻ�λ������
	float m_DisX[10000];
	float m_SpeX[10000];
	float m_AccX[10000];

	int m_nTarX;
	int m_nDisX;
	int m_nSpeX;
	int m_nAccX;

	float m_TarV[10000];//���ڻ��ٶ�����
	float m_SpeV[10000];
	float m_AccV[10000];

	int m_nTarV;
	int m_nSpeV;
	int m_nAccV;

	float m_TarA[10000];//���ڻ����ٶ�����
	float m_AccA[10000];

	int m_nTarA;
	int m_nAccA;



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPIDControl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitPIDParameter();
	void CurveInit();
	void CurveDrawAcceleration(float x0,float y0);
	void CurveDrawSpeed(float x0,float y0);
	void CurveDrawDisplacement(float x0,float y0);
	void CurveDrawZBZ(float x0, float y0, char StrName[],char StrMax[]);
	void DrawControlCar_Acceleration();
	void DrawControCar_Speed();
	void MoveControlCar_Acceleration();
	void MoveControlCar_Speed();
	void MoveTargetCar();
	void DrawTargetCar();
	void DrawControlCar_Displacement();
	void MoveControlCar_Displacement();
	void MoveSine();
	void MoveUniformAcceleration();
	void MoveUniform();
	void InitTarAndCon();
	void DrawScene();
	void Draw(CDC *p);
	virtual ~CPIDControl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPIDControl)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIDCONTROL_H__4AC7FBCD_E1E2_4780_92F9_787F93BB3D18__INCLUDED_)
