// PIDAlgorithmView.h : interface of the CPIDAlgorithmView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIDALGORITHMVIEW_H__FFFAF25C_6D03_4C2B_AA58_8AA93EA72151__INCLUDED_)
#define AFX_PIDALGORITHMVIEW_H__FFFAF25C_6D03_4C2B_AA58_8AA93EA72151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PIDControl.h"
#include "DlgPIDParameterSet.h"

class CPIDAlgorithmView : public CView
{
protected: // create from serialization only
	CPIDAlgorithmView();
	DECLARE_DYNCREATE(CPIDAlgorithmView)

// Attributes
public:
	CPIDAlgorithmDoc* GetDocument();

// Operations
public:
	CPIDControl m_pid;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPIDAlgorithmView)
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
	virtual ~CPIDAlgorithmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPIDAlgorithmView)
	afx_msg void OnMENUITEMSineMove();
	afx_msg void OnMENUITEMUniformAccelerationMove();
	afx_msg void OnMENUITEMUniformMove();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMENUITEMPIDParametersControl();
	afx_msg void OnMENUITEMStop();
	afx_msg void OnMENUITEMContinue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PIDAlgorithmView.cpp
inline CPIDAlgorithmDoc* CPIDAlgorithmView::GetDocument()
   { return (CPIDAlgorithmDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIDALGORITHMVIEW_H__FFFAF25C_6D03_4C2B_AA58_8AA93EA72151__INCLUDED_)
