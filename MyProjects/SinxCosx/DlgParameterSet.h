#if !defined(AFX_DLGPARAMETERSET_H__98549B1F_8109_45E4_8B35_0459B2B0F213__INCLUDED_)
#define AFX_DLGPARAMETERSET_H__98549B1F_8109_45E4_8B35_0459B2B0F213__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgParameterSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgParameterSet dialog

class CDlgParameterSet : public CDialog
{
// Construction
public:
	CDlgParameterSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgParameterSet)
	enum { IDD = IDD_DlgParameterSet };
	float	m_W;
	float	m_XW;
	float	m_ZF;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgParameterSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgParameterSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMETERSET_H__98549B1F_8109_45E4_8B35_0459B2B0F213__INCLUDED_)
