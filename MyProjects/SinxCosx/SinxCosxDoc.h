// SinxCosxDoc.h : interface of the CSinxCosxDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINXCOSXDOC_H__C526E8E5_0846_4277_BBCD_C5A277281EA7__INCLUDED_)
#define AFX_SINXCOSXDOC_H__C526E8E5_0846_4277_BBCD_C5A277281EA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinxCosxDoc : public CDocument
{
protected: // create from serialization only
	CSinxCosxDoc();
	DECLARE_DYNCREATE(CSinxCosxDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinxCosxDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSinxCosxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinxCosxDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINXCOSXDOC_H__C526E8E5_0846_4277_BBCD_C5A277281EA7__INCLUDED_)
