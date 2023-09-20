// CircleView.h : interface of the CCircleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLEVIEW_H__2867F001_945F_466F_92F1_8052313E3649__INCLUDED_)
#define AFX_CIRCLEVIEW_H__2867F001_945F_466F_92F1_8052313E3649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCircleView : public CView
{

	
protected: // create from serialization only
	CCircleView();
	DECLARE_DYNCREATE(CCircleView)

// Attributes
public:
	CCircleDoc* GetDocument();

// Operations
public:
	int m_x;
    int m_nPic; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

	void CCircleView::OnMCircle();
	void CCircleView::OnTomer(UINT nIDEvent);
	
// Implementation
public:
	void DrawCircle(CDC*pDC,int x,int y,int r);
	virtual ~CCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCircleView)
	afx_msg void OnMenuitem32771();
	afx_msg void OnMenuitem32772();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMDongHua();
	afx_msg void OnMStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CircleView.cpp
inline CCircleDoc* CCircleView::GetDocument()
   { return (CCircleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEVIEW_H__2867F001_945F_466F_92F1_8052313E3649__INCLUDED_)
