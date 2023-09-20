#if !defined(AFX_DLGINITCARPOSLEAKPOINTCHECK_H__8897A828_FB6C_4CAD_89C2_0B41848B7DC5__INCLUDED_)
#define AFX_DLGINITCARPOSLEAKPOINTCHECK_H__8897A828_FB6C_4CAD_89C2_0B41848B7DC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInitCarPosLeakPointCheck.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgInitCarPosLeakPointCheck dialog

class CDlgInitCarPosLeakPointCheck : public CDialog
{
// Construction
public:
	CDlgInitCarPosLeakPointCheck(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgInitCarPosLeakPointCheck)
	enum { IDD = IDD_DIALOGInitCarPosLeakPointCheck };
	float	m_X;
	float	m_Y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInitCarPosLeakPointCheck)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInitCarPosLeakPointCheck)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINITCARPOSLEAKPOINTCHECK_H__8897A828_FB6C_4CAD_89C2_0B41848B7DC5__INCLUDED_)
