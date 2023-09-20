// WindowsAPI.h : main header file for the WINDOWSAPI application
//

#if !defined(AFX_WINDOWSAPI_H__2C7C8432_9097_4BC9_96AD_3596A468D53A__INCLUDED_)
#define AFX_WINDOWSAPI_H__2C7C8432_9097_4BC9_96AD_3596A468D53A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWindowsAPIApp:
// See WindowsAPI.cpp for the implementation of this class
//

class CWindowsAPIApp : public CWinApp
{
public:
	CWindowsAPIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsAPIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWindowsAPIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSAPI_H__2C7C8432_9097_4BC9_96AD_3596A468D53A__INCLUDED_)
