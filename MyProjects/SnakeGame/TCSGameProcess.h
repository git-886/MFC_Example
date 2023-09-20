#if !defined(AFX_TCSGAMEPROCESS_H__3A31CE7F_BF3B_4EE8_AEE5_6820B4C97363__INCLUDED_)
#define AFX_TCSGAMEPROCESS_H__3A31CE7F_BF3B_4EE8_AEE5_6820B4C97363__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TCSGameProcess.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTCSGameProcess window

typedef struct
{
	int s_x;
	int s_y;
}STCSNode;//蛇结构体
typedef struct
{
	int f_x;
	int f_y;
}SFoodNode;//食物结构体

class CTCSGameProcess : public CWnd
{
// Construction
public:
	CTCSGameProcess();

// Attributes
public:
	int m_bj_x,m_bj_y,m_bj_w;//边界坐标与宽
	int m_s_w;//贪吃蛇方块宽
	CDC *pDC;
	int m_num;//贪吃蛇长度
	STCSNode m_s[100];//贪吃蛇结构体数组，存储左上角坐标（s_x,s_y）
	int m_direct;
	SFoodNode m_food;
	int FoodStatue;//标识当前是否食物被吃被吃重新产生食物坐标
	int m_score;//分数

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCSGameProcess)
	//}}AFX_VIRTUAL

// Implementation
public:
	int collision();
	void EatFood();
	void ProduceFood();
	void Draw();
	void SnakeMove();
	void DrawSnake();
	void InitSnake();
	void DrawBJ();
	virtual ~CTCSGameProcess();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTCSGameProcess)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCSGAMEPROCESS_H__3A31CE7F_BF3B_4EE8_AEE5_6820B4C97363__INCLUDED_)
