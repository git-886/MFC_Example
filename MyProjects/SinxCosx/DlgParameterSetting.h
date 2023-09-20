#if !defined(AFX_DLGPARAMETERSETTING_H__E083C4C7_1FC7_4E44_BFAA_8AE63769C71E__INCLUDED_)
#define AFX_DLGPARAMETERSETTING_H__E083C4C7_1FC7_4E44_BFAA_8AE63769C71E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgParameterSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgParameterSetting dialog

class CDlgParameterSetting : public CDialog
{
// Construction
public:
	CDlgParameterSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgParameterSetting)
	enum { IDD = IDD_DlgParameterSet };
	float	m_W;
	float	m_XW;
	float	m_ZF;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgParameterSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgParameterSetting)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMETERSETTING_H__E083C4C7_1FC7_4E44_BFAA_8AE63769C71E__INCLUDED_)
