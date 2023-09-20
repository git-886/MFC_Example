// RobotView.h : interface of the CRobotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTVIEW_H__8317A0B0_15C8_4E34_B97C_771DF696C0D1__INCLUDED_)
#define AFX_ROBOTVIEW_H__8317A0B0_15C8_4E34_B97C_771DF696C0D1__INCLUDED_
#include "Robot.h"
#include "Robot1.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobotView : public CView
{
protected: // create from serialization only
	CRobotView();
	DECLARE_DYNCREATE(CRobotView)

// Attributes
public:
	CRobotDoc* GetDocument();
	CRobot m_Robot;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotView)
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
	virtual ~CRobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotView)
	afx_msg void OnMENOpenRobot();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobotView.cpp
inline CRobotDoc* CRobotView::GetDocument()
   { return (CRobotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTVIEW_H__8317A0B0_15C8_4E34_B97C_771DF696C0D1__INCLUDED_)
