#if !defined(AFX_PIDPARAMETERSET_H__51C36A8F_FBC8_4B94_8D28_0FE2DD27F9D1__INCLUDED_)
#define AFX_PIDPARAMETERSET_H__51C36A8F_FBC8_4B94_8D28_0FE2DD27F9D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PIDParameterSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPIDParameterSet dialog

class CPIDParameterSet : public CDialog
{
// Construction
public:
	CPIDParameterSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPIDParameterSet)
	enum { IDD = IDD_DIALOGPIDParamCont };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPIDParameterSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPIDParameterSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIDPARAMETERSET_H__51C36A8F_FBC8_4B94_8D28_0FE2DD27F9D1__INCLUDED_)
