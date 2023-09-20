// HuaTu_InDialog.h : main header file for the HUATU_INDIALOG application
//

#if !defined(AFX_HUATU_INDIALOG_H__894D609E_2E48_4374_9465_85618C84E7CF__INCLUDED_)
#define AFX_HUATU_INDIALOG_H__894D609E_2E48_4374_9465_85618C84E7CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogApp:
// See HuaTu_InDialog.cpp for the implementation of this class
//

class CHuaTu_InDialogApp : public CWinApp
{
public:
	CHuaTu_InDialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaTu_InDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHuaTu_InDialogApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUATU_INDIALOG_H__894D609E_2E48_4374_9465_85618C84E7CF__INCLUDED_)
