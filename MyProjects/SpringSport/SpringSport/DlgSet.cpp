// DlgSet.cpp : implementation file
//

#include "stdafx.h"
#include "SpringSport.h"
#include "DlgSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSet dialog


CDlgSet::CDlgSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSet)
	m_nowL = 0.0f;
	m_mCir = 0.0f;
	m_kSpring = 0.0f;
	m_znSpring = 0.0f;
	m_initV = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSet)
	DDX_Text(pDX, IDC_EDIT1, m_nowL);
	DDX_Text(pDX, IDC_EDIT2, m_mCir);
	DDX_Text(pDX, IDC_EDIT3, m_kSpring);
	DDX_Text(pDX, IDC_EDIT4, m_znSpring);
	DDX_Text(pDX, IDC_EDIT5, m_initV);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSet, CDialog)
	//{{AFX_MSG_MAP(CDlgSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSet message handlers
