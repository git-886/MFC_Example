#if !defined(AFX_OPENROBOT_H__FC00CF1E_2665_4289_A538_6245DD8E03AB__INCLUDED_)
#define AFX_OPENROBOT_H__FC00CF1E_2665_4289_A538_6245DD8E03AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenRobot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpenRobot dialog

class COpenRobot : public CDialog
{
// Construction
public:
	COpenRobot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpenRobot)
	enum { IDD = IDD_DlgOpenRobot };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenRobot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenRobot)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENROBOT_H__FC00CF1E_2665_4289_A538_6245DD8E03AB__INCLUDED_)
