// SpringSport.h : main header file for the SPRINGSPORT application
//

#if !defined(AFX_SPRINGSPORT_H__E830D85E_76FF_4AA4_8997_D09CEC9E568D__INCLUDED_)
#define AFX_SPRINGSPORT_H__E830D85E_76FF_4AA4_8997_D09CEC9E568D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpringSportApp:
// See SpringSport.cpp for the implementation of this class
//

class CSpringSportApp : public CWinApp
{
public:
	CSpringSportApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpringSportApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSpringSportApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPRINGSPORT_H__E830D85E_76FF_4AA4_8997_D09CEC9E568D__INCLUDED_)
