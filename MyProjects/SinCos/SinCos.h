// SinCos.h : main header file for the SINCOS application
//

#if !defined(AFX_SINCOS_H__DB2B53EC_5E5B_4A1C_BDA7_C4BC8F4BF6C4__INCLUDED_)
#define AFX_SINCOS_H__DB2B53EC_5E5B_4A1C_BDA7_C4BC8F4BF6C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSinCosApp:
// See SinCos.cpp for the implementation of this class
//

class CSinCosApp : public CWinApp
{
public:
	CSinCosApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinCosApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSinCosApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINCOS_H__DB2B53EC_5E5B_4A1C_BDA7_C4BC8F4BF6C4__INCLUDED_)
