// SinxCosx.h : main header file for the SINXCOSX application
//

#if !defined(AFX_SINXCOSX_H__37C63EFE_B8B6_49FF_90B0_D71B6DD8B894__INCLUDED_)
#define AFX_SINXCOSX_H__37C63EFE_B8B6_49FF_90B0_D71B6DD8B894__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxApp:
// See SinxCosx.cpp for the implementation of this class
//

class CSinxCosxApp : public CWinApp
{
public:
	CSinxCosxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinxCosxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSinxCosxApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINXCOSX_H__37C63EFE_B8B6_49FF_90B0_D71B6DD8B894__INCLUDED_)
