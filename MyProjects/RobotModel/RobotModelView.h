// RobotModelView.h : interface of the CRobotModelView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTMODELVIEW_H__F9209CBA_44D2_4B89_9E65_5E555FA4EB5F__INCLUDED_)
#define AFX_ROBOTMODELVIEW_H__F9209CBA_44D2_4B89_9E65_5E555FA4EB5F__INCLUDED_
#include "Robot.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobotModelView : public CView
{
protected: // create from serialization only
	CRobotModelView();
	DECLARE_DYNCREATE(CRobotModelView)

// Attributes
public:
	CRobotModelDoc* GetDocument();
	CRobot m_Robot;
	int m_flg;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotModelView)
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
	virtual ~CRobotModelView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotModelView)
	afx_msg void OnMENOpenRobot();
	afx_msg void OnMENCreateRobot();
	afx_msg void OnMENDelete();
	afx_msg void OnMENSaveToFile();
	afx_msg void OnMENOpenParameterSetPanel();
	afx_msg void OnMENRobotMove();
	afx_msg void OnMENRobotJump();
	afx_msg void OnMENRobotWink();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMENWaveHand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobotModelView.cpp
inline CRobotModelDoc* CRobotModelView::GetDocument()
   { return (CRobotModelDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTMODELVIEW_H__F9209CBA_44D2_4B89_9E65_5E555FA4EB5F__INCLUDED_)
