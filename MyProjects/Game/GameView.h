// GameView.h : interface of the CGameView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEVIEW_H__52C9CB42_2D2A_4B32_AF6A_09E7136B4324__INCLUDED_)
#define AFX_GAMEVIEW_H__52C9CB42_2D2A_4B32_AF6A_09E7136B4324__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PlaneWar.h"

class CGameView : public CView
{
protected: // create from serialization only
	CGameView();
	DECLARE_DYNCREATE(CGameView)

// Attributes
public:
	CGameDoc* GetDocument();
	CPlaneWar plane;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameView)
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
	virtual ~CGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGameView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMENUITEMStart();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GameView.cpp
inline CGameDoc* CGameView::GetDocument()
   { return (CGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEVIEW_H__52C9CB42_2D2A_4B32_AF6A_09E7136B4324__INCLUDED_)
