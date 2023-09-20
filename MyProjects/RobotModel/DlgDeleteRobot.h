#if !defined(AFX_DLGDELETEROBOT_H__16863D81_8F77_44AF_8C6C_040A4856AAD3__INCLUDED_)
#define AFX_DLGDELETEROBOT_H__16863D81_8F77_44AF_8C6C_040A4856AAD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDeleteRobot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDeleteRobot dialog

class CDlgDeleteRobot : public CDialog
{
// Construction
public:
	CDlgDeleteRobot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDeleteRobot)
	enum { IDD = IDD_DlgDeleteRobot };
	CString	m_DeletedRobotName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDeleteRobot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDeleteRobot)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDELETEROBOT_H__16863D81_8F77_44AF_8C6C_040A4856AAD3__INCLUDED_)
