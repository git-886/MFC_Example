// AdoDataBaseDlg.h : header file
//

#if !defined(AFX_ADODATABASEDLG_H__BAB151D7_C0BD_4003_A721_1846E06F66FB__INCLUDED_)
#define AFX_ADODATABASEDLG_H__BAB151D7_C0BD_4003_A721_1846E06F66FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdoDataBaseDlg dialog

class CAdoDataBaseDlg : public CDialog
{
// Construction
public:
	CAdoDataBaseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdoDataBaseDlg)
	enum { IDD = IDD_ADODATABASE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdoDataBaseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdoDataBaseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSel();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSelSqlserver();
	afx_msg void OnBUTTONConSQLSERVER();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATABASEDLG_H__BAB151D7_C0BD_4003_A721_1846E06F66FB__INCLUDED_)
