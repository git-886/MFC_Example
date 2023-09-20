// HuaCirTriRecDoc.h : interface of the CHuaCirTriRecDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUACIRTRIRECDOC_H__52040521_C5F2_49DC_ADAC_B01AA14C12DF__INCLUDED_)
#define AFX_HUACIRTRIRECDOC_H__52040521_C5F2_49DC_ADAC_B01AA14C12DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHuaCirTriRecDoc : public CDocument
{
protected: // create from serialization only
	CHuaCirTriRecDoc();
	DECLARE_DYNCREATE(CHuaCirTriRecDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaCirTriRecDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHuaCirTriRecDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuaCirTriRecDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUACIRTRIRECDOC_H__52040521_C5F2_49DC_ADAC_B01AA14C12DF__INCLUDED_)
