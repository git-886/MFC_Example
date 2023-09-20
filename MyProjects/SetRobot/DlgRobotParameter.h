#if !defined(AFX_DLGROBOTPARAMETER_H__54B4BC3B_B1C1_4528_B372_6F92DE7E42B3__INCLUDED_)
#define AFX_DLGROBOTPARAMETER_H__54B4BC3B_B1C1_4528_B372_6F92DE7E42B3__INCLUDED_
#include "Ado.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRobotParameter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRobotParameter dialog

class CDlgRobotParameter : public CDialog
{
// Construction
public:
	void ListData();
	CDlgRobotParameter(CWnd* pParent = NULL);   // standard constructor
	CAdo m_Ado;

	
	//CString m_RID,m_eyelr,m_eyerr,m_mouthr;
	
// Dialog Data
	//{{AFX_DATA(CDlgRobotParameter)
	enum { IDD = IDD_DIlgRobotParameter };
	CListCtrl	m_ListCtr;
	float	m_eyelr;
	float	m_eyerr;
	float	m_mouthr;
	int		m_RidSel;
	int		m_ridUpdate;
	float	m_mouthSel;
	float	m_eyelrSel;
	float	m_eyerrSel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRobotParameter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRobotParameter)
	afx_msg void OnSelchangeListall();
	afx_msg void OnBUTRefresh();
	afx_msg void OnBUTSelect();
	afx_msg void OnBUTUpdate();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP(
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGROBOTPARAMETER_H__54B4BC3B_B1C1_4528_B372_6F92DE7E42B3__INCLUDED_)
