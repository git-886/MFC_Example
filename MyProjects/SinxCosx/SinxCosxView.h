// SinxCosxView.h : interface of the CSinxCosxView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINXCOSXVIEW_H__6725AE76_FF26_4F42_94C6_2A0788723096__INCLUDED_)
#define AFX_SINXCOSXVIEW_H__6725AE76_FF26_4F42_94C6_2A0788723096__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DataProcess.h"

class CSinxCosxView : public CView
{
protected: // create from serialization only
	CSinxCosxView();
	DECLARE_DYNCREATE(CSinxCosxView)

// Attributes
public:
	CSinxCosxDoc* GetDocument();
	CDataProcess m_dp;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinxCosxView)
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
	virtual ~CSinxCosxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinxCosxView)
	afx_msg void OnMENUITEMStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMENUITEMStop();
	afx_msg void OnMENUITEMParameterSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SinxCosxView.cpp
inline CSinxCosxDoc* CSinxCosxView::GetDocument()
   { return (CSinxCosxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINXCOSXVIEW_H__6725AE76_FF26_4F42_94C6_2A0788723096__INCLUDED_)
