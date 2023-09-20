#if !defined(AFX_CDLGPCURVE_H__1743CDC6_13BB_42E8_9312_E84495D0D1ED__INCLUDED_)
#define AFX_CDLGPCURVE_H__1743CDC6_13BB_42E8_9312_E84495D0D1ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgpCurve.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCDlgpCurve dialog

class CCDlgpCurve : public CDialog
{
// Construction
public:
	void WriteX(CDC *pDC);
	CCDlgpCurve(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCDlgpCurve)
	enum { IDD = IDD_DIALOG_HuaTu };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDlgpCurve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCDlgpCurve)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLGPCURVE_H__1743CDC6_13BB_42E8_9312_E84495D0D1ED__INCLUDED_)
