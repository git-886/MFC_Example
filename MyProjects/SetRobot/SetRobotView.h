// SetRobotView.h : interface of the CSetRobotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SETROBOTVIEW_H__C0C4D1D2_C6F2_4D0F_B216_192BFDF8EF2A__INCLUDED_)
#define AFX_SETROBOTVIEW_H__C0C4D1D2_C6F2_4D0F_B216_192BFDF8EF2A__INCLUDED_
#include "Robots.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSetRobotView : public CView
{
protected: // create from serialization only
	CSetRobotView();
	DECLARE_DYNCREATE(CSetRobotView)

// Attributes
public:
	CSetRobotDoc* GetDocument();

// Operations
public:
	CRobots m_robot;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetRobotView)
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
	virtual ~CSetRobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSetRobotView)
	afx_msg void OnBUTCreateRobot();
	afx_msg void OnMENUITEMOpenControlPanel();
	afx_msg void OnMENUITEMCreateRobot();
	afx_msg void OnMENUITEMDeleteRobot();
	afx_msg void OnMENUITEMRobotParameterSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SetRobotView.cpp
inline CSetRobotDoc* CSetRobotView::GetDocument()
   { return (CSetRobotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETROBOTVIEW_H__C0C4D1D2_C6F2_4D0F_B216_192BFDF8EF2A__INCLUDED_)
