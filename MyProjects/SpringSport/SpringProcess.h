#if !defined(AFX_SPRINGPROCESS_H__5952CAA7_A0DE_46CC_AA7F_22364ADC9933__INCLUDED_)
#define AFX_SPRINGPROCESS_H__5952CAA7_A0DE_46CC_AA7F_22364ADC9933__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpringProcess.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpringProcess window

class CSpringProcess : public CWnd
{
// Construction
public:
	CSpringProcess();

// Attributes
public:
	float m_m;//小球质量
	float m_k;//弹性系数
	float m_r;//小球半径
	float m_zn;//阻尼
	float m_kZH;//像素转换系数
	

	float m_w;//弹簧宽
	float m_L0;//弹簧原长
	float m_L;//弹簧长度

	float m_LUp,m_LDown;//上端与下端绳长
	
	float m_x0,m_y0;//坐标原点

	CDC *pDC;

	float m_f;
	float m_a;
	float m_y;
	float m_v;

	float m_fGJ[1000];
	float m_aGJ[1000];
	float m_yGJ[1000];
	float m_vGJ[1000];

	int m_nfGJ;
	int m_naGJ;
	int m_nyGJ;
	int m_nvGJ; 


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpringProcess)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawName(int x0,int y0,char str[100]);
	void DrawYAndYkd(int x0,int y0,int y_Lpx);
	void DrawYCurve();
	void DrawVCurve();
	void DrawFCurve();
	void DrawACurve();
	void DrawXAndXkd(int x0,int y0,int x_Lpx);
	int PanDunaPH();
	void Move();
	void DrawSpring();
	void Draw(CDC *p);
	virtual ~CSpringProcess();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpringProcess)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPRINGPROCESS_H__5952CAA7_A0DE_46CC_AA7F_22364ADC9933__INCLUDED_)
