// DlgRobotParameterSet.cpp : implementation file
//

#include "stdafx.h"
#include "robotmodel.h"
#include "DlgRobotParameterSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRobotParameterSet dialog


CDlgRobotParameterSet::CDlgRobotParameterSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRobotParameterSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRobotParameterSet)
	m_armll = _T("");
	m_armlw = _T("");
	m_armrw = _T("");
	m_armrl = _T("");
	m_bodyl = _T("");
	m_bodyw = _T("");
	m_eyelr = _T("");
	m_eyerr = _T("");
	m_headr = _T("");
	m_legll = _T("");
	m_leglw = _T("");
	m_legrl = _T("");
	m_legrw = _T("");
	m_mouthr = _T("");
	m_neckl = _T("");
	m_neckw = _T("");
	m_nosed = _T("");
	m_RobotName = _T("");
	m_ZX_x = _T("");
	m_ZX_y = _T("");
	//}}AFX_DATA_INIT
}


void CDlgRobotParameterSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRobotParameterSet)
	DDX_Text(pDX, IDC_armll, m_armll);
	DDX_Text(pDX, IDC_armlw, m_armlw);
	DDX_Text(pDX, IDC_armrw, m_armrw);
	DDX_Text(pDX, IDC_armrl, m_armrl);
	DDX_Text(pDX, IDC_bodyl, m_bodyl);
	DDX_Text(pDX, IDC_bodyw, m_bodyw);
	DDX_Text(pDX, IDC_eyelr, m_eyelr);
	DDX_Text(pDX, IDC_eyerr, m_eyerr);
	DDX_Text(pDX, IDC_headr, m_headr);
	DDX_Text(pDX, IDC_legll, m_legll);
	DDX_Text(pDX, IDC_leglw, m_leglw);
	DDX_Text(pDX, IDC_legrl, m_legrl);
	DDX_Text(pDX, IDC_legrw, m_legrw);
	DDX_Text(pDX, IDC_mouthr, m_mouthr);
	DDX_Text(pDX, IDC_neckl, m_neckl);
	DDX_Text(pDX, IDC_neckw, m_neckw);
	DDX_Text(pDX, IDC_nosed, m_nosed);
	DDX_Text(pDX, IDC_RobotName, m_RobotName);
	DDX_Text(pDX, IDC_ZX_x, m_ZX_x);
	DDX_Text(pDX, IDC_ZX_y, m_ZX_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRobotParameterSet, CDialog)
	//{{AFX_MSG_MAP(CDlgRobotParameterSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRobotParameterSet message handlers
