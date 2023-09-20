// PIDParameterSet.cpp : implementation file
//

#include "stdafx.h"
#include "PIDAlgorithm.h"
#include "PIDParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPIDParameterSet dialog


CPIDParameterSet::CPIDParameterSet(CWnd* pParent /*=NULL*/)
	: CDialog(CPIDParameterSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPIDParameterSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPIDParameterSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPIDParameterSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPIDParameterSet, CDialog)
	//{{AFX_MSG_MAP(CPIDParameterSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPIDParameterSet message handlers
