// DlgPingPongParameterSet.cpp : implementation file
//

#include "stdafx.h"
#include "PingPongSport.h"
#include "DlgPingPongParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPingPongParameterSet dialog


CDlgPingPongParameterSet::CDlgPingPongParameterSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPingPongParameterSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPingPongParameterSet)
	m_SdX = 0.0f;
	m_SdY = 0.0f;
	m_SdZ = 0.0f;
	m_ZbX = 0.0f;
	m_ZbY = 0.0f;
	m_ZbZ = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgPingPongParameterSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPingPongParameterSet)
	DDX_Text(pDX, IDC_SdX, m_SdX);
	DDX_Text(pDX, IDC_SdY, m_SdY);
	DDX_Text(pDX, IDC_SdZ, m_SdZ);
	DDX_Text(pDX, IDC_ZbX, m_ZbX);
	DDX_Text(pDX, IDC_Zby, m_ZbY);
	DDX_Text(pDX, IDC_ZbZ, m_ZbZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPingPongParameterSet, CDialog)
	//{{AFX_MSG_MAP(CDlgPingPongParameterSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPingPongParameterSet message handlers
