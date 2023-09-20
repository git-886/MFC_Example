// DlgDeleteRobot.cpp : implementation file
//

#include "stdafx.h"
#include "robotmodel.h"
#include "DlgDeleteRobot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDeleteRobot dialog


CDlgDeleteRobot::CDlgDeleteRobot(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDeleteRobot::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDeleteRobot)
	m_DeletedRobotName = _T("");
	//}}AFX_DATA_INIT
}


void CDlgDeleteRobot::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDeleteRobot)
	DDX_Text(pDX, IDC_DeletedRobotName, m_DeletedRobotName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDeleteRobot, CDialog)
	//{{AFX_MSG_MAP(CDlgDeleteRobot)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDeleteRobot message handlers
