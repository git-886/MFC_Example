// JWGLSystemODBCView.h : interface of the CJWGLSystemODBCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JWGLSYSTEMODBCVIEW_H__B6AF4C37_AD62_4299_9F35_E57A39AD7DD4__INCLUDED_)
#define AFX_JWGLSYSTEMODBCVIEW_H__B6AF4C37_AD62_4299_9F35_E57A39AD7DD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CJWGLSystemODBCSet;

class CJWGLSystemODBCView : public CRecordView
{
protected: // create from serialization only
	CJWGLSystemODBCView();
	DECLARE_DYNCREATE(CJWGLSystemODBCView)

public:
	//{{AFX_DATA(CJWGLSystemODBCView)
	enum { IDD = IDD_JWGLSYSTEMODBC_FORM };
	CListBox	m_List;
	CJWGLSystemODBCSet* m_pSet;
	int		m_age;
	CString	m_class;
	int		m_id;
	CString	m_name;
	CString	m_pro;
	CString	m_sex;
	//}}AFX_DATA

// Attributes
public:
	CJWGLSystemODBCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJWGLSystemODBCView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJWGLSystemODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJWGLSystemODBCView)
	afx_msg void OnBUTClear();
	afx_msg void OnBUTInsert();
	afx_msg void OnBUTDelete();
	afx_msg void OnBUTUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JWGLSystemODBCView.cpp
inline CJWGLSystemODBCDoc* CJWGLSystemODBCView::GetDocument()
   { return (CJWGLSystemODBCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JWGLSYSTEMODBCVIEW_H__B6AF4C37_AD62_4299_9F35_E57A39AD7DD4__INCLUDED_)
