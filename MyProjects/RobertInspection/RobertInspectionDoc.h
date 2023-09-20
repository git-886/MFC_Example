// RobertInspectionDoc.h : interface of the CRobertInspectionDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBERTINSPECTIONDOC_H__C4585961_C55D_4812_B62A_AF840096A976__INCLUDED_)
#define AFX_ROBERTINSPECTIONDOC_H__C4585961_C55D_4812_B62A_AF840096A976__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobertInspectionDoc : public CDocument
{
protected: // create from serialization only
	CRobertInspectionDoc();
	DECLARE_DYNCREATE(CRobertInspectionDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobertInspectionDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobertInspectionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobertInspectionDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBERTINSPECTIONDOC_H__C4585961_C55D_4812_B62A_AF840096A976__INCLUDED_)
