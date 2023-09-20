// DlgSaveRobotToFile.cpp : implementation file
//

#include "stdafx.h"
#include "robotmodel.h"
#include "DlgSaveRobotToFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSaveRobotToFile dialog


CDlgSaveRobotToFile::CDlgSaveRobotToFile(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSaveRobotToFile::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSaveRobotToFile)
	m_FilePath = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSaveRobotToFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSaveRobotToFile)
	DDX_Text(pDX, IDC_SaveFilePath, m_FilePath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSaveRobotToFile, CDialog)
	//{{AFX_MSG_MAP(CDlgSaveRobotToFile)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSaveRobotToFile message handlers
