// SinCosDoc.h : interface of the CSinCosDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINCOSDOC_H__6338FF65_6667_43B8_91C7_F2547758A858__INCLUDED_)
#define AFX_SINCOSDOC_H__6338FF65_6667_43B8_91C7_F2547758A858__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinCosDoc : public CDocument
{
protected: // create from serialization only
	CSinCosDoc();
	DECLARE_DYNCREATE(CSinCosDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinCosDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSinCosDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinCosDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINCOSDOC_H__6338FF65_6667_43B8_91C7_F2547758A858__INCLUDED_)
