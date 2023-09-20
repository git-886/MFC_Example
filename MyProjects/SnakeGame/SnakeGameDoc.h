// SnakeGameDoc.h : interface of the CSnakeGameDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKEGAMEDOC_H__8441F604_D372_4C0F_A3E6_A0A71E9F83FB__INCLUDED_)
#define AFX_SNAKEGAMEDOC_H__8441F604_D372_4C0F_A3E6_A0A71E9F83FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnakeGameDoc : public CDocument
{
protected: // create from serialization only
	CSnakeGameDoc();
	DECLARE_DYNCREATE(CSnakeGameDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeGameDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnakeGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnakeGameDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEGAMEDOC_H__8441F604_D372_4C0F_A3E6_A0A71E9F83FB__INCLUDED_)
