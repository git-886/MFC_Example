// RobotModel.h : main header file for the ROBOTMODEL application
//

#if !defined(AFX_ROBOTMODEL_H__0AE7798C_F5E2_4317_B5F7_E9C7E04A5717__INCLUDED_)
#define AFX_ROBOTMODEL_H__0AE7798C_F5E2_4317_B5F7_E9C7E04A5717__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRobotModelApp:
// See RobotModel.cpp for the implementation of this class
//

class CRobotModelApp : public CWinApp
{
public:
	CRobotModelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotModelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRobotModelApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTMODEL_H__0AE7798C_F5E2_4317_B5F7_E9C7E04A5717__INCLUDED_)
