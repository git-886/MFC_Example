// TankGame.h : main header file for the TANKGAME application
//

#if !defined(AFX_TANKGAME_H__DF9B5F14_808F_4C2A_8C37_3427276D746E__INCLUDED_)
#define AFX_TANKGAME_H__DF9B5F14_808F_4C2A_8C37_3427276D746E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTankGameApp:
// See TankGame.cpp for the implementation of this class
//

class CTankGameApp : public CWinApp
{
public:
	CTankGameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTankGameApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKGAME_H__DF9B5F14_808F_4C2A_8C37_3427276D746E__INCLUDED_)
