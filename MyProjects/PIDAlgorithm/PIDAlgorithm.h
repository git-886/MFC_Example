// PIDAlgorithm.h : main header file for the PIDALGORITHM application
//

#if !defined(AFX_PIDALGORITHM_H__09AAEF88_AAD5_4CFD_BB44_1EEC679F275F__INCLUDED_)
#define AFX_PIDALGORITHM_H__09AAEF88_AAD5_4CFD_BB44_1EEC679F275F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmApp:
// See PIDAlgorithm.cpp for the implementation of this class
//

class CPIDAlgorithmApp : public CWinApp
{
public:
	CPIDAlgorithmApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPIDAlgorithmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPIDAlgorithmApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIDALGORITHM_H__09AAEF88_AAD5_4CFD_BB44_1EEC679F275F__INCLUDED_)
