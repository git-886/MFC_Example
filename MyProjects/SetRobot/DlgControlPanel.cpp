// DlgControlPanel.cpp : implementation file
//

#include "stdafx.h"
#include "SetRobot.h"
#include "DlgControlPanel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgControlPanel dialog


CDlgControlPanel::CDlgControlPanel(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgControlPanel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgControlPanel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgControlPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgControlPanel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgControlPanel, CDialog)
	//{{AFX_MSG_MAP(CDlgControlPanel)
	ON_BN_CLICKED(IDC_BUTConDatabase, OnBUTConDatabase)
	ON_BN_CLICKED(IDC_BUTDisConDatabase, OnBUTDisConDatabase)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgControlPanel message handlers

void CDlgControlPanel::OnBUTConDatabase() 
{
	// TODO: Add your control notification handler code here
	//m_ado.OnInitADOConnSQLServer();
}

void CDlgControlPanel::OnBUTDisConDatabase() 
{
	// TODO: Add your control notification handler code here
	m_ado.ExitConnect();
}
