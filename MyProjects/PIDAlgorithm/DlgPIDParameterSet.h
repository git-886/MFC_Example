#if !defined(AFX_DLGPIDPARAMETERSET_H__1242281F_4650_4036_8A65_4CE45D57426B__INCLUDED_)
#define AFX_DLGPIDPARAMETERSET_H__1242281F_4650_4036_8A65_4CE45D57426B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPIDParameterSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPIDParameterSet dialog

class CDlgPIDParameterSet : public CDialog
{
// Construction
public:
	CDlgPIDParameterSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPIDParameterSet)
	enum { IDD = IDD_DIALOGPIDParamCont };
	float	m_KPDis;
	float	m_KPSpe;
	float	m_KPAcc;
	float	m_KDDis;
	float	m_KDSpe;
	float	m_KDAcc;
	float	m_KIDis;
	float	m_KISpe;
	float	m_KIAcc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPIDParameterSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPIDParameterSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPIDPARAMETERSET_H__1242281F_4650_4036_8A65_4CE45D57426B__INCLUDED_)
