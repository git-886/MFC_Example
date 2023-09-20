// PingPongSport.h : main header file for the PINGPONGSPORT application
//

#if !defined(AFX_PINGPONGSPORT_H__B57E5E38_FD38_43C4_87D5_A45470683298__INCLUDED_)
#define AFX_PINGPONGSPORT_H__B57E5E38_FD38_43C4_87D5_A45470683298__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportApp:
// See PingPongSport.cpp for the implementation of this class
//

class CPingPongSportApp : public CWinApp
{
public:
	CPingPongSportApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingPongSportApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPingPongSportApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGPONGSPORT_H__B57E5E38_FD38_43C4_87D5_A45470683298__INCLUDED_)
