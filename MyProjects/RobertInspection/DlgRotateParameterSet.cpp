// DlgRotateParameterSet.cpp : implementation file
//

#include "stdafx.h"
#include "RobertInspection.h"
#include "DlgRotateParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRotateParameterSet dialog


CDlgRotateParameterSet::CDlgRotateParameterSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRotateParameterSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRotateParameterSet)
	m_r = 0.0f;
	m_direction = 0;
	m_w = 0.0f;
	m_SSZNSZ = 0;
	//}}AFX_DATA_INIT
}


void CDlgRotateParameterSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRotateParameterSet)
	DDX_Text(pDX, IDC_m_R, m_r);
	DDX_Text(pDX, IDC_Direction, m_direction);
	DDX_Text(pDX, IDC_M_W, m_w);
	DDX_Text(pDX, IDC_SSZOrNSZ, m_SSZNSZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRotateParameterSet, CDialog)
	//{{AFX_MSG_MAP(CDlgRotateParameterSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRotateParameterSet message handlers
