// HuaCirTriRecView.h : interface of the CHuaCirTriRecView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUACIRTRIRECVIEW_H__DD7BE909_63C5_4CA2_9A04_49CDC9C0F1E0__INCLUDED_)
#define AFX_HUACIRTRIRECVIEW_H__DD7BE909_63C5_4CA2_9A04_49CDC9C0F1E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	float x;
	float y;
	float r;
	float vx;
	float vy;
}SCircle;

typedef struct
{
	float x;
	float y;
	float h;
	float w;

	float vx;
	float vy;
}SRectangle;

typedef struct
{
	float xd;
	float yd;
	float xu;
	float yu;

	float vx;
	float vy;
}STriangle;

class CHuaCirTriRecView : public CView
{
protected: // create from serialization only
	CHuaCirTriRecView();
	DECLARE_DYNCREATE(CHuaCirTriRecView)

// Attributes
public:
	CHuaCirTriRecDoc* GetDocument();

// Operations
public:
	SCircle Cir[100];
	int m_nCir;//圆的个数

	SRectangle Rec[100];
	int m_nRec;

	STriangle Tri[100];
	int m_nTri;

	CPoint PointD;
	CPoint PointU;
	CPoint PointTemp;

	int m_BJ_LBD;//决定何时画
	
	int m_nPic;//决定画什么图像

	float m_BK_x;
	float m_BK_y;
	float m_BK_w;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaCirTriRecView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void Move();
	void InsertRectangel();
	void InsertRectangle();
	void InsertCircle();
	virtual ~CHuaCirTriRecView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuaCirTriRecView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMENUITEMHuaY();
	afx_msg void OnMENUITEMHuaJX();
	afx_msg void OnMENUITEMHuaSJX();
	afx_msg void OnMENUITEMStart();
	afx_msg void OnMENUITEMStop();
	afx_msg void OnMENUITEMMoveBK();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMENUITEMChangeBK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HuaCirTriRecView.cpp
inline CHuaCirTriRecDoc* CHuaCirTriRecView::GetDocument()
   { return (CHuaCirTriRecDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUACIRTRIRECVIEW_H__DD7BE909_63C5_4CA2_9A04_49CDC9C0F1E0__INCLUDED_)
