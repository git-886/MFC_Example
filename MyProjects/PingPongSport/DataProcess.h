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

	CPoint m_YD1;//左上角绘图原心
	CPoint m_YD2;//右上角绘图原心

	float m_x0;
	float m_y0;
	float m_z0;

	float m_vx0;
	float m_vy0;
	float m_vz0;

	float m_length;//乒乓球桌长
	float m_weight;//乒乓球桌宽
	float m_LWheight;//拦网高度
	float m_ZTheight;//拦网高度
	
	float m_m;//乒乓球球质量kg
	float m_r;//乒乓球半径m

	float m_PowerReducek;//反弹动量损失系数


	int m_Ftsum;//记录反弹次数
	


	

	float m_xGj[1000];//记录乒乓球位移
	float m_yGj[1000];
	float m_zGj[1000];

	float m_x;//x方向位移
	float m_y;//y方向位移
	float m_z;//z方向位移

	int m_nxGj;
	int m_nyGj;
	int m_nzGj;

	float m_vxGj[1000];//记录乒乓球速度
	float m_vyGj[1000];
	float m_vzGj[1000];

	float m_vx;//x方向速度
	float m_vy;//y方向速度
	float m_vz;//z方向速度

	int m_nvxGj;
	int m_nvyGj;
	int m_nvzGj;

	float m_k;//像素转换系数,画乒乓球桌及乒乓球
	float m_ktx;//像素转换系数，画x、y、z方向的位移及速度图像
	

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
