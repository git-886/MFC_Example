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
	float w;//小车宽度
	float x;
	float v;
	float a;
}SCar;

typedef struct
{
	float Tar_val;//目标值（目标小车值）
	float Act_val;//实际值（控制小车值）
	float err;//当前偏差
	float err_last;//上次偏差
	float err_sum;//误差累计值
	float Kp,Ki,Kd;//比例，积分，微分系数(Ki用于快速产生稳态误差，Kd用于消除稳态误差)
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
	CPoint m_YD;//像素原点
	SCar m_Tar;//目标小车
	SCar m_Con_Dis;//控制小车-位移
	SCar m_Con_Spe;//控制小车-速度
	SCar m_Con_Acc;//控制小车-加速度

	SPID m_DisPid;//pid控制结构体变量
	SPID m_SpePid;//pid控制结构体变量
	SPID m_AccPid;//pid控制结构体变量

	float m_t;

	int m_way;//移动方式（默认为1-匀速移动，2-匀加速移动，3正弦移动）

	float m_kp;//控制系数

	float m_kx;//比例尺
	float m_ky;

	

	CDC *pDC;


	float m_TarX[10000];//用于画位移曲线
	float m_DisX[10000];
	float m_SpeX[10000];
	float m_AccX[10000];

	int m_nTarX;
	int m_nDisX;
	int m_nSpeX;
	int m_nAccX;

	float m_TarV[10000];//用于画速度曲线
	float m_SpeV[10000];
	float m_AccV[10000];

	int m_nTarV;
	int m_nSpeV;
	int m_nAccV;

	float m_TarA[10000];//用于画加速度曲线
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
