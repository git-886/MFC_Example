// PingPongSportView.h : interface of the CPingPongSportView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINGPONGSPORTVIEW_H__FC688349_1773_46C4_81DE_5A5853E506EE__INCLUDED_)
#define AFX_PINGPONGSPORTVIEW_H__FC688349_1773_46C4_81DE_5A5853E506EE__INCLUDED_
#include "DataProcess.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPingPongSportView : public CView
{
protected: // create from serialization only
	CPingPongSportView();
	DECLARE_DYNCREATE(CPingPongSportView)

// Attributes
public:
	CPingPongSportDoc* GetDocument();
	CDataProcess m_dp;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingPongSportView)
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
	virtual ~CPingPongSportView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPingPongSportView)
	afx_msg void OnMENUITEMStart();
	afx_msg void OnMENUITEMStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMENUITEMParameterSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PingPongSportView.cpp
inline CPingPongSportDoc* CPingPongSportView::GetDocument()
   { return (CPingPongSportDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGPONGSPORTVIEW_H__FC688349_1773_46C4_81DE_5A5853E506EE__INCLUDED_)
