// Circle.h : main header file for the CIRCLE application
//

#if !defined(AFX_CIRCLE_H__38289F3F_0208_411A_96A4_A01B0A9F0652__INCLUDED_)
#define AFX_CIRCLE_H__38289F3F_0208_411A_96A4_A01B0A9F0652__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCircleApp:
// See Circle.cpp for the implementation of this class
//

class CCircleApp : public CWinApp
{
public:
	CCircleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCircleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLE_H__38289F3F_0208_411A_96A4_A01B0A9F0652__INCLUDED_)
