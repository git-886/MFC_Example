// WindowsAPIDlg.h : header file
//

#if !defined(AFX_WINDOWSAPIDLG_H__A470E07C_181D_4670_B2A3_10FC5C6A36FC__INCLUDED_)
#define AFX_WINDOWSAPIDLG_H__A470E07C_181D_4670_B2A3_10FC5C6A36FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CWindowsAPIDlg dialog

class CWindowsAPIDlg : public CDialog
{
// Construction
public:
	CWindowsAPIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWindowsAPIDlg)
	enum { IDD = IDD_WINDOWSAPI_DIALOG };
	CString	m_TargetPath;
	CString	m_CurrentPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsAPIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWindowsAPIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetCurrentPath();
	afx_msg void OnGetSystemInformation();
	afx_msg void OnFIndAllFilesFormDir();
	afx_msg void OnSetCurrentDirectory();
	afx_msg void OnCopyFile();
	afx_msg void OnDeleteFile();
	afx_msg void OnCreateDirectory();
	afx_msg void OnDeleteDirectory();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSAPIDLG_H__A470E07C_181D_4670_B2A3_10FC5C6A36FC__INCLUDED_)
