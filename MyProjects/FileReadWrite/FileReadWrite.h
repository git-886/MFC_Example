// FileReadWrite.h : main header file for the FILEREADWRITE application
//

#if !defined(AFX_FILEREADWRITE_H__AA741B79_C54C_4EDD_BC96_38F7FF7B2A45__INCLUDED_)
#define AFX_FILEREADWRITE_H__AA741B79_C54C_4EDD_BC96_38F7FF7B2A45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileReadWriteApp:
// See FileReadWrite.cpp for the implementation of this class
//

class CFileReadWriteApp : public CWinApp
{
public:
	CFileReadWriteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileReadWriteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileReadWriteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEREADWRITE_H__AA741B79_C54C_4EDD_BC96_38F7FF7B2A45__INCLUDED_)
