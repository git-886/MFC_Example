#if !defined(AFX_DLGROTATEPARAMETERSET_H__F6B74662_01CE_4652_886E_15F8C00E5C59__INCLUDED_)
#define AFX_DLGROTATEPARAMETERSET_H__F6B74662_01CE_4652_886E_15F8C00E5C59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRotateParameterSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRotateParameterSet dialog

class CDlgRotateParameterSet : public CDialog
{
// Construction
public:
	CDlgRotateParameterSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgRotateParameterSet)
	enum { IDD = IDD_DIALOG1 };
	float	m_r;
	int		m_direction;
	float	m_w;
	int		m_SSZNSZ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRotateParameterSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRotateParameterSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGROTATEPARAMETERSET_H__F6B74662_01CE_4652_886E_15F8C00E5C59__INCLUDED_)
