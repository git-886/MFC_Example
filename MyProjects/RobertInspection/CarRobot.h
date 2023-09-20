#if !defined(AFX_CARROBOT_H__86AAC162_CB42_4F79_9BF4_929B7DF5D646__INCLUDED_)
#define AFX_CARROBOT_H__86AAC162_CB42_4F79_9BF4_929B7DF5D646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarRobot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarRobot window
typedef struct
{
	float w;//角速度
	float r;//圆半径
	float angle;//
	float MaxND;
	float MinND;
	CPoint Max;
	CPoint Min;
	float x,y;//圆心坐标
	float ND;//小车当前位置浓度
}SRotateMethedCircle;

class CCarRobot : public CWnd
{
// Construction
public:
	CCarRobot();

// Attributes
public:
	CPoint m_YD;//场景原点
	float m_x,m_y;//画小车机器人原点
	float m_w;//小车宽(m)
	float m_v;//小车匀速移动速度（m/s）

	float m_r;//小车旋转运动半径-m
	float m_wv;//小车旋转运动角速度（rad/s）
	int m_Flag_SN;//小车选择运动顺时针-1，逆时针-2
	int m_dir;//小车选择运动方向，1~12
	float m_YXx;//小车转动的圆心坐标
	float m_YXy;

	SRotateMethedCircle RotCircle;

	int m_nd;//小车50m范围的浓度值

	

	CPoint m_YSYDpoint;//匀速移动目标点像素坐标点

	CPoint m_PointGJ[100];//路径指定方式移动-存储过程点
	int m_nPointGJ;//过程点个数
	int m_nCur;//已经达到点的个数

	float m_JD;//旋转方式下当前角度

	float m_kx;
	float m_ky;//转换系数

	int m_flag_MoveWay;//标记小车机器人移动方式-直接移动到指定点（1）-匀速移动到指定点（2）-转圈移动（3）-指定路径移动（4）默认为1

	CDC *pDC;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarRobot)
	//}}AFX_VIRTUAL

// Implementation
public:
	void RotCircleInit(float nd,float m_x,float m_y);//初始化转圈圆参数
	void RotateMethodFindLeakPoint(float n);
	void MoveToLeakPoint(int x);
	void DrawSpecifyPointPath();//画指定路径
	void InitSpecifyPoint(float x,float y);
	int MoveSpecifyPath();//按照指定路径移动
	void QuiYunaXin();
	void LBDProcess(CPoint point);
	int Move();
	void MoveRotate();
	void MoveBySpecifiedPoint(int x,int y);//参数为视图目标点像素坐标
	int MoveByUniform();
	void DrawCar();
	void Draw(CDC *p);
	virtual ~CCarRobot();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCarRobot)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARROBOT_H__86AAC162_CB42_4F79_9BF4_929B7DF5D646__INCLUDED_)
