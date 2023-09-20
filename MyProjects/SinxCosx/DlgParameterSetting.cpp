// DlgParameterSetting.cpp : implementation file
//

#include "stdafx.h"
#include "SinxCosx.h"
#include "DlgParameterSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgParameterSetting dialog


CDlgParameterSetting::CDlgParameterSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgParameterSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgParameterSetting)
	m_W = 0.0f;
	m_XW = 0.0f;
	m_ZF = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgParameterSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgParameterSetting)
	DDX_Text(pDX, IDC_W, m_W);
	DDX_Text(pDX, IDC_XW, m_XW);
	DDX_Text(pDX, IDC_ZF, m_ZF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgParameterSetting, CDialog)
	//{{AFX_MSG_MAP(CDlgParameterSetting)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgParameterSetting message handlers
