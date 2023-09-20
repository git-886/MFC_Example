// TankGameDoc.h : interface of the CTankGameDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANKGAMEDOC_H__8A506190_615F_4133_BD6E_2C78A736C931__INCLUDED_)
#define AFX_TANKGAMEDOC_H__8A506190_615F_4133_BD6E_2C78A736C931__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTankGameDoc : public CDocument
{
protected: // create from serialization only
	CTankGameDoc();
	DECLARE_DYNCREATE(CTankGameDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankGameDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTankGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTankGameDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKGAMEDOC_H__8A506190_615F_4133_BD6E_2C78A736C931__INCLUDED_)
