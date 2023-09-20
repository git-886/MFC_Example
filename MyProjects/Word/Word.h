// Word.h : main header file for the WORD application
//

#if !defined(AFX_WORD_H__79CF7C33_925F_4F98_B1B2_97065F779049__INCLUDED_)
#define AFX_WORD_H__79CF7C33_925F_4F98_B1B2_97065F779049__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordApp:
// See Word.cpp for the implementation of this class
//

class CWordApp : public CWinApp
{
public:
	CWordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORD_H__79CF7C33_925F_4F98_B1B2_97065F779049__INCLUDED_)
