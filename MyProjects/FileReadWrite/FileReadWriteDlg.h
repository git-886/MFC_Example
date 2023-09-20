// FileReadWriteDlg.h : header file
//

#if !defined(AFX_FILEREADWRITEDLG_H__7651152A_65B3_44CF_9856_C32C5025E086__INCLUDED_)
#define AFX_FILEREADWRITEDLG_H__7651152A_65B3_44CF_9856_C32C5025E086__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileReadWriteDlg dialog

class CFileReadWriteDlg : public CDialog
{
// Construction
public:
	CFileReadWriteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileReadWriteDlg)
	enum { IDD = IDD_FILEREADWRITE_DIALOG };
	CString	m_path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileReadWriteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileReadWriteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTReadFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEREADWRITEDLG_H__7651152A_65B3_44CF_9856_C32C5025E086__INCLUDED_)
