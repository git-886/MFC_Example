// TankGameView.h : interface of the CTankGameView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANKGAMEVIEW_H__ED33572D_6F66_48C8_BC72_6621E334C44F__INCLUDED_)
#define AFX_TANKGAMEVIEW_H__ED33572D_6F66_48C8_BC72_6621E334C44F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TankWar.h"
class CTankGameView : public CView
{
protected: // create from serialization only
	CTankGameView();
	DECLARE_DYNCREATE(CTankGameView)

// Attributes
public:
	CTankGameDoc* GetDocument();
	CTankWar m_TankWar;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankGameView)
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
	virtual ~CTankGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTankGameView)
	afx_msg void OnMENUITEMStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TankGameView.cpp
inline CTankGameDoc* CTankGameView::GetDocument()
   { return (CTankGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKGAMEVIEW_H__ED33572D_6F66_48C8_BC72_6621E334C44F__INCLUDED_)
