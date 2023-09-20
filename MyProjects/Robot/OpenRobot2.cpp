// OpenRobot2.cpp : implementation file
//

#include "stdafx.h"
#include "robot.h"
#include "OpenRobot2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenRobot dialog


COpenRobot::COpenRobot(CWnd* pParent /*=NULL*/)
	: CDialog(COpenRobot::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpenRobot)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COpenRobot::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenRobot)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpenRobot, CDialog)
	//{{AFX_MSG_MAP(COpenRobot)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenRobot message handlers
