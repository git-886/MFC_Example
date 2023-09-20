// SnakeGame.h : main header file for the SNAKEGAME application
//

#if !defined(AFX_SNAKEGAME_H__5E729F21_D5A3_475E_9489_CF1FE107B625__INCLUDED_)
#define AFX_SNAKEGAME_H__5E729F21_D5A3_475E_9489_CF1FE107B625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameApp:
// See SnakeGame.cpp for the implementation of this class
//

class CSnakeGameApp : public CWinApp
{
public:
	CSnakeGameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSnakeGameApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEGAME_H__5E729F21_D5A3_475E_9489_CF1FE107B625__INCLUDED_)
