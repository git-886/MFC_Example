// JWGLSystemODBC.h : main header file for the JWGLSYSTEMODBC application
//

#if !defined(AFX_JWGLSYSTEMODBC_H__1A28771C_A934_4491_927A_0806737251BF__INCLUDED_)
#define AFX_JWGLSYSTEMODBC_H__1A28771C_A934_4491_927A_0806737251BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCApp:
// See JWGLSystemODBC.cpp for the implementation of this class
//

class CJWGLSystemODBCApp : public CWinApp
{
public:
	CJWGLSystemODBCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJWGLSystemODBCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJWGLSystemODBCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JWGLSYSTEMODBC_H__1A28771C_A934_4491_927A_0806737251BF__INCLUDED_)
