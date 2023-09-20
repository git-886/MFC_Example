// PingPongSportDoc.h : interface of the CPingPongSportDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINGPONGSPORTDOC_H__CE9823FC_4AF2_4412_B678_FC5C766BC4B8__INCLUDED_)
#define AFX_PINGPONGSPORTDOC_H__CE9823FC_4AF2_4412_B678_FC5C766BC4B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPingPongSportDoc : public CDocument
{
protected: // create from serialization only
	CPingPongSportDoc();
	DECLARE_DYNCREATE(CPingPongSportDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingPongSportDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPingPongSportDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPingPongSportDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGPONGSPORTDOC_H__CE9823FC_4AF2_4412_B678_FC5C766BC4B8__INCLUDED_)
