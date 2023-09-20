// SetRobotDoc.h : interface of the CSetRobotDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SETROBOTDOC_H__43B342B9_2617_458D_AF62_79668FE4ED96__INCLUDED_)
#define AFX_SETROBOTDOC_H__43B342B9_2617_458D_AF62_79668FE4ED96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSetRobotDoc : public CDocument
{
protected: // create from serialization only
	CSetRobotDoc();
	DECLARE_DYNCREATE(CSetRobotDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetRobotDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSetRobotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSetRobotDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETROBOTDOC_H__43B342B9_2617_458D_AF62_79668FE4ED96__INCLUDED_)
