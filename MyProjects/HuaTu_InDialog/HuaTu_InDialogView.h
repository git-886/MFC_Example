// HuaTu_InDialogView.h : interface of the CHuaTu_InDialogView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUATU_INDIALOGVIEW_H__953DAB6D_A18F_45C2_8D03_41AA5422D255__INCLUDED_)
#define AFX_HUATU_INDIALOGVIEW_H__953DAB6D_A18F_45C2_8D03_41AA5422D255__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHuaTu_InDialogView : public CView
{
protected: // create from serialization only
	CHuaTu_InDialogView();
	DECLARE_DYNCREATE(CHuaTu_InDialogView)

// Attributes
public:
	CHuaTu_InDialogDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaTu_InDialogView)
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
	virtual ~CHuaTu_InDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuaTu_InDialogView)
	afx_msg void OnMENUITEMHuaTuInDIalog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HuaTu_InDialogView.cpp
inline CHuaTu_InDialogDoc* CHuaTu_InDialogView::GetDocument()
   { return (CHuaTu_InDialogDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUATU_INDIALOGVIEW_H__953DAB6D_A18F_45C2_8D03_41AA5422D255__INCLUDED_)
