// JWGLSystemODBCDoc.h : interface of the CJWGLSystemODBCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JWGLSYSTEMODBCDOC_H__AD604D4E_B821_442B_894C_98A439F38C8C__INCLUDED_)
#define AFX_JWGLSYSTEMODBCDOC_H__AD604D4E_B821_442B_894C_98A439F38C8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "JWGLSystemODBCSet.h"


class CJWGLSystemODBCDoc : public CDocument
{
protected: // create from serialization only
	CJWGLSystemODBCDoc();
	DECLARE_DYNCREATE(CJWGLSystemODBCDoc)

// Attributes
public:
	CJWGLSystemODBCSet m_jWGLSystemODBCSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJWGLSystemODBCDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJWGLSystemODBCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJWGLSystemODBCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JWGLSYSTEMODBCDOC_H__AD604D4E_B821_442B_894C_98A439F38C8C__INCLUDED_)
