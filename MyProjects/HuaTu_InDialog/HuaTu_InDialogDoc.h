// HuaTu_InDialogDoc.h : interface of the CHuaTu_InDialogDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUATU_INDIALOGDOC_H__DE722057_0DF1_4953_99B8_3AD85FFE24BC__INCLUDED_)
#define AFX_HUATU_INDIALOGDOC_H__DE722057_0DF1_4953_99B8_3AD85FFE24BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHuaTu_InDialogDoc : public CDocument
{
protected: // create from serialization only
	CHuaTu_InDialogDoc();
	DECLARE_DYNCREATE(CHuaTu_InDialogDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaTu_InDialogDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHuaTu_InDialogDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuaTu_InDialogDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUATU_INDIALOGDOC_H__DE722057_0DF1_4953_99B8_3AD85FFE24BC__INCLUDED_)
