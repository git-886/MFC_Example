#if !defined(AFX_DLGCONTROLPANEL_H__F6C257C3_6246_44D6_9CF9_632D3BFE2D91__INCLUDED_)
#define AFX_DLGCONTROLPANEL_H__F6C257C3_6246_44D6_9CF9_632D3BFE2D91__INCLUDED_
#include "Ado.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgControlPanel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgControlPanel dialog

class CDlgControlPanel : public CDialog
{
// Construction
public:
	CDlgControlPanel(CWnd* pParent = NULL);   // standard constructor

	CAdo m_ado;
// Dialog Data
	//{{AFX_DATA(CDlgControlPanel)
	enum { IDD = IDD_DIgControlPanel };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgControlPanel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgControlPanel)
	afx_msg void OnBUTConDatabase();
	afx_msg void OnBUTDisConDatabase();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONTROLPANEL_H__F6C257C3_6246_44D6_9CF9_632D3BFE2D91__INCLUDED_)
