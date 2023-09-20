// PIDAlgorithmDoc.h : interface of the CPIDAlgorithmDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIDALGORITHMDOC_H__AD2E420E_D79B_4213_99B1_D727CE7D6B59__INCLUDED_)
#define AFX_PIDALGORITHMDOC_H__AD2E420E_D79B_4213_99B1_D727CE7D6B59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPIDAlgorithmDoc : public CDocument
{
protected: // create from serialization only
	CPIDAlgorithmDoc();
	DECLARE_DYNCREATE(CPIDAlgorithmDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPIDAlgorithmDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPIDAlgorithmDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPIDAlgorithmDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIDALGORITHMDOC_H__AD2E420E_D79B_4213_99B1_D727CE7D6B59__INCLUDED_)
