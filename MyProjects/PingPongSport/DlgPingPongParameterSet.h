#if !defined(AFX_DLGPINGPONGPARAMETERSET_H__0AA04B95_9476_440A_A868_E96ADAF6BD44__INCLUDED_)
#define AFX_DLGPINGPONGPARAMETERSET_H__0AA04B95_9476_440A_A868_E96ADAF6BD44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPingPongParameterSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPingPongParameterSet dialog

class CDlgPingPongParameterSet : public CDialog
{
// Construction
public:
	CDlgPingPongParameterSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPingPongParameterSet)
	enum { IDD = IDD_PingPongParameterSet };
	float	m_SdX;
	float	m_SdY;
	float	m_SdZ;
	float	m_ZbX;
	float	m_ZbY;
	float	m_ZbZ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPingPongParameterSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPingPongParameterSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPINGPONGPARAMETERSET_H__0AA04B95_9476_440A_A868_E96ADAF6BD44__INCLUDED_)
