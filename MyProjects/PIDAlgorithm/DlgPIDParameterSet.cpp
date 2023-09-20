// DlgPIDParameterSet.cpp : implementation file
//

#include "stdafx.h"
#include "PIDAlgorithm.h"
#include "DlgPIDParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPIDParameterSet dialog


CDlgPIDParameterSet::CDlgPIDParameterSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPIDParameterSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPIDParameterSet)
	m_KPDis = 0.0f;
	m_KPSpe = 0.0f;
	m_KPAcc = 0.0f;
	m_KDDis = 0.0f;
	m_KDSpe = 0.0f;
	m_KDAcc = 0.0f;
	m_KIDis = 0.0f;
	m_KISpe = 0.0f;
	m_KIAcc = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgPIDParameterSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPIDParameterSet)
	DDX_Text(pDX, IDC_KP1, m_KPDis);
	DDX_Text(pDX, IDC_KP2, m_KPSpe);
	DDX_Text(pDX, IDC_KP3, m_KPAcc);
	DDX_Text(pDX, IDC_KD1, m_KDDis);
	DDX_Text(pDX, IDC_KD2, m_KDSpe);
	DDX_Text(pDX, IDC_KD3, m_KDAcc);
	DDX_Text(pDX, IDC_KI1, m_KIDis);
	DDX_Text(pDX, IDC_KI2, m_KISpe);
	DDX_Text(pDX, IDC_KI3, m_KIAcc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPIDParameterSet, CDialog)
	//{{AFX_MSG_MAP(CDlgPIDParameterSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPIDParameterSet message handlers
