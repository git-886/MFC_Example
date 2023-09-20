// DlgInitCarPosLeakPointCheck.cpp : implementation file
//

#include "stdafx.h"
#include "RobertInspection.h"
#include "DlgInitCarPosLeakPointCheck.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgInitCarPosLeakPointCheck dialog


CDlgInitCarPosLeakPointCheck::CDlgInitCarPosLeakPointCheck(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInitCarPosLeakPointCheck::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInitCarPosLeakPointCheck)
	m_X = 0.0f;
	m_Y = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgInitCarPosLeakPointCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInitCarPosLeakPointCheck)
	DDX_Text(pDX, IDC_m_X, m_X);
	DDX_Text(pDX, IDC_m_Y, m_Y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInitCarPosLeakPointCheck, CDialog)
	//{{AFX_MSG_MAP(CDlgInitCarPosLeakPointCheck)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInitCarPosLeakPointCheck message handlers
