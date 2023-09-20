#if !defined(AFX_DLGSAVEROBOTTOFILE_H__B4D99579_88B3_4900_A192_9D861C95669D__INCLUDED_)
#define AFX_DLGSAVEROBOTTOFILE_H__B4D99579_88B3_4900_A192_9D861C95669D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSaveRobotToFile.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSaveRobotToFile dialog

class CDlgSaveRobotToFile : public CDialog
{
// Construction
public:
	CDlgSaveRobotToFile(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSaveRobotToFile)
	enum { IDD = IDD_DIALOG1 };
	CString	m_FilePath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSaveRobotToFile)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSaveRobotToFile)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSAVEROBOTTOFILE_H__B4D99579_88B3_4900_A192_9D861C95669D__INCLUDED_)
