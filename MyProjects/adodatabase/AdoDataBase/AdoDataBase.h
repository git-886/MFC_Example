// AdoDataBase.h : main header file for the ADODATABASE application
//

#if !defined(AFX_ADODATABASE_H__CDA34030_DCD3_44A7_B5F0_5FC65E902F87__INCLUDED_)
#define AFX_ADODATABASE_H__CDA34030_DCD3_44A7_B5F0_5FC65E902F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdoDataBaseApp:
// See AdoDataBase.cpp for the implementation of this class
//

class CAdoDataBaseApp : public CWinApp
{
public:
	CAdoDataBaseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdoDataBaseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdoDataBaseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATABASE_H__CDA34030_DCD3_44A7_B5F0_5FC65E902F87__INCLUDED_)
