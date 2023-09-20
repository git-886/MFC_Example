// SinCosView.h : interface of the CSinCosView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINCOSVIEW_H__3DAFB7A2_3998_4FE1_ADDA_9C2E641987C1__INCLUDED_)
#define AFX_SINCOSVIEW_H__3DAFB7A2_3998_4FE1_ADDA_9C2E641987C1__INCLUDED_
#include "DataProcessAndDraw.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinCosView : public CView
{
protected: // create from serialization only
	CSinCosView();
	DECLARE_DYNCREATE(CSinCosView)

// Attributes
public:
	CSinCosDoc* GetDocument();
	CDataProcessAndDraw m_data;

// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinCosView)
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
	virtual ~CSinCosView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinCosView)
	afx_msg void OnMENUITEMStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMENUITEMStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SinCosView.cpp
inline CSinCosDoc* CSinCosView::GetDocument()
   { return (CSinCosDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINCOSVIEW_H__3DAFB7A2_3998_4FE1_ADDA_9C2E641987C1__INCLUDED_)
