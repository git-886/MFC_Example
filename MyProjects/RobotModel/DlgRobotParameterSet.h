#if !defined(AFX_DLGROBOTPARAMETERSET_H__F30AA92D_E671_452F_A845_A926D47D1709__INCLUDED_)
#define AFX_DLGROBOTPARAMETERSET_H__F30AA92D_E671_452F_A845_A926D47D1709__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRobotParameterSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRobotParameterSet dialog

class CDlgRobotParameterSet : public CDialog
{
// Construction
public:
	CDlgRobotParameterSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgRobotParameterSet)
	enum { IDD = IDD_DIALOG2 };
	CString	m_armll;
	CString	m_armlw;
	CString	m_armrw;
	CString	m_armrl;
	CString	m_bodyl;
	CString	m_bodyw;
	CString	m_eyelr;
	CString	m_eyerr;
	CString	m_headr;
	CString	m_legll;
	CString	m_leglw;
	CString	m_legrl;
	CString	m_legrw;
	CString	m_mouthr;
	CString	m_neckl;
	CString	m_neckw;
	CString	m_nosed;
	CString	m_RobotName;
	CString	m_ZX_x;
	CString	m_ZX_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRobotParameterSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRobotParameterSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGROBOTPARAMETERSET_H__F30AA92D_E671_452F_A845_A926D47D1709__INCLUDED_)
