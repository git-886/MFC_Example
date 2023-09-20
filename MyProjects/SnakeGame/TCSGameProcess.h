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
}STCSNode;//�߽ṹ��
typedef struct
{
	int f_x;
	int f_y;
}SFoodNode;//ʳ��ṹ��

class CTCSGameProcess : public CWnd
{
// Construction
public:
	CTCSGameProcess();

// Attributes
public:
	int m_bj_x,m_bj_y,m_bj_w;//�߽��������
	int m_s_w;//̰���߷����
	CDC *pDC;
	int m_num;//̰���߳���
	STCSNode m_s[100];//̰���߽ṹ�����飬�洢���Ͻ����꣨s_x,s_y��
	int m_direct;
	SFoodNode m_food;
	int FoodStatue;//��ʶ��ǰ�Ƿ�ʳ�ﱻ�Ա������²���ʳ������
	int m_score;//����

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
