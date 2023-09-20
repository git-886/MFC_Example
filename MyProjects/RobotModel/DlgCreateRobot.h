#if !defined(AFX_DLGCREATEROBOT_H__C2A5E4C7_9CE2_4932_B0C0_B85BD79E1C1E__INCLUDED_)
#define AFX_DLGCREATEROBOT_H__C2A5E4C7_9CE2_4932_B0C0_B85BD79E1C1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCreateRobot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateRobot dialog

class CDlgCreateRobot : public CDialog
{
// Construction
public:
	CDlgCreateRobot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCreateRobot)
	enum { IDD = IDD_DlgCreateRobot };
	CString	m_armll;
	CString	m_armlw;
	CString	m_armrl;
	CString	m_armrw;
	CString	m_bodyl;
	CString	m_bodyw;
	CString	m_eyerr;
	CString	m_eyelr;
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
	//{{AFX_VIRTUAL(CDlgCreateRobot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCreateRobot)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCREATEROBOT_H__C2A5E4C7_9CE2_4932_B0C0_B85BD79E1C1E__INCLUDED_)
