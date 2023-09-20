// DlgParameterSet.cpp : implementation file
//

#include "stdafx.h"
#include "SpringSport.h"
#include "DlgParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgParameterSet dialog


CDlgParameterSet::CDlgParameterSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgParameterSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgParameterSet)
	m_K = 0.0f;
	m_L = 0.0f;
	m_L0 = 0.0f;
	m_M = 0.0f;
	m_Z = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgParameterSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgParameterSet)
	DDX_Text(pDX, IDC_K, m_K);
	DDX_Text(pDX, IDC_L, m_L);
	DDX_Text(pDX, IDC_L0, m_L0);
	DDX_Text(pDX, IDC_M, m_M);
	DDX_Text(pDX, IDC_Z, m_Z);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgParameterSet, CDialog)
	//{{AFX_MSG_MAP(CDlgParameterSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgParameterSet message handlers
