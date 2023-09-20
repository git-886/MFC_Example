#if !defined(AFX_TARGETPROCESS_H__B6420950_1C9D_466D_8683_BE03393AC852__INCLUDED_)
#define AFX_TARGETPROCESS_H__B6420950_1C9D_466D_8683_BE03393AC852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TargetProcess.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTargetProcess window
typedef struct //正方形目标结构体
{
	int x;
	int y;
	int w;
}SSquareNode;

typedef struct//圆形目标结构体
{
	int x;
	int y;
	int r;
}SCircleNode;

typedef struct//三角形目标结构体
{
	int x;
	int y;
	int d;
}STriangleNode;


class CTargetProcess : public CWnd
{
// Construction
public:
	CTargetProcess();

// Attributes
public:
	int m_bk_x,m_bk_y,m_bk_w;//边框相关数据
	CDC *pDC;
	SSquareNode m_square[20];
	SCircleNode m_circle[20];
	STriangleNode m_triangle[20];
	int m_sqnum;//m_nSquare
	int m_cinum;
	int m_trnum;


	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTargetProcess)
	//}}AFX_VIRTUAL

// Implementation
public:
	void ProduceTriangle();
	void DrawTriangleTarget();
	void DrawCircleTarget();
	void ProduceCircle();
	void HitAndOutSquare();
	void ProduceSquare();
	void DrawSquareTarget();
	void DrawBK();
	void DrawTargetAndBK(CDC *p);
	virtual ~CTargetProcess();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTargetProcess)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TARGETPROCESS_H__B6420950_1C9D_466D_8683_BE03393AC852__INCLUDED_)
