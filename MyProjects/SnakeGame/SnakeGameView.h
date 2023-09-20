// SnakeGameView.h : interface of the CSnakeGameView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKEGAMEVIEW_H__E5100B00_A6BB_4881_869E_4970DD7529D9__INCLUDED_)
#define AFX_SNAKEGAMEVIEW_H__E5100B00_A6BB_4881_869E_4970DD7529D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TCSGameProcess.h"
class CSnakeGameView : public CView
{
protected: // create from serialization only
	CSnakeGameView();
	DECLARE_DYNCREATE(CSnakeGameView)

// Attributes
public:
	CSnakeGameDoc* GetDocument();
	CTCSGameProcess tcs;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeGameView)
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
	virtual ~CSnakeGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnakeGameView)
	afx_msg void OnMENUITEMStarGame();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SnakeGameView.cpp
inline CSnakeGameDoc* CSnakeGameView::GetDocument()
   { return (CSnakeGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEGAMEVIEW_H__E5100B00_A6BB_4881_869E_4970DD7529D9__INCLUDED_)
