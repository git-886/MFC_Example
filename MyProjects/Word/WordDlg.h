// WordDlg.h : header file
//

#if !defined(AFX_WORDDLG_H__664484CF_2517_421E_A1F8_EF89E39001E7__INCLUDED_)
#define AFX_WORDDLG_H__664484CF_2517_421E_A1F8_EF89E39001E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWordDlg dialog

class CWordDlg : public CDialog
{
// Construction
public:
	CWordDlg(CWnd* pParent = NULL);	// standard constructor

	int m_flag;//标记生产文档0不生成，1生成
// Dialog Data
	//{{AFX_DATA(CWordDlg)
	enum { IDD = IDD_WORD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenword();
	afx_msg void OnGenerateword();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDDLG_H__664484CF_2517_421E_A1F8_EF89E39001E7__INCLUDED_)
