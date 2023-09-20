// CDlgpCurve.cpp : implementation file
//

#include "stdafx.h"
#include "HuaTu_InDialog.h"
#include "CDlgpCurve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDlgpCurve dialog


CCDlgpCurve::CCDlgpCurve(CWnd* pParent /*=NULL*/)
	: CDialog(CCDlgpCurve::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDlgpCurve)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCDlgpCurve::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDlgpCurve)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCDlgpCurve, CDialog)
	//{{AFX_MSG_MAP(CCDlgpCurve)
	ON_BN_CLICKED(IDC_COORD, OnPaint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDlgpCurve message handlers

void CCDlgpCurve::OnPaint() 
{
	// TODO: Add your control notification handler code here
	CString str;
	int i = 0;
	int max = 0;

	CPaintDC dc(this);

	CWnd *pWnd = GetDlgItem(IDC_COORD);

	CDC *pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	pDC->Rectangle(0,0,365,300);

	CPen *pPenRed = new CPen;
	
	pPenRed->CreatePen(PS_SOLID,1,RGB(255,0,0));

	CPen *pPenBlue = new CPen;

	pPenBlue->CreatePen(PS_SOLID,1,RGB(0,0,255));

	CGdiObject *pOldPen = pDC->SelectObject(pPenRed);
	pDC->MoveTo(35,10);
	pDC->LineTo(35,280);
	pDC->LineTo(340,280);
	WriteX(pDC);

}

void CCDlgpCurve::WriteX(CDC *pDC)//写x轴刻度并绘制
{
	double wholeT = 1.5;
	int i;
	CString str;
	str.Format("0");
	//写x刻度值
	pDC->TextOut(35,283,str);
	str.Format("%.1f",wholeT/5);
	pDC->TextOut(85,283,str);
	str.Format("%.1f",wholeT/5*2);
	pDC->TextOut(135,283,str);
	str.Format("%.1f",wholeT/5*3);
	pDC->TextOut(185,283,str);
	str.Format("%.1f",wholeT/5*4);
	pDC->TextOut(235,283,str);
	str.Format("%.1f s",wholeT);
	pDC->TextOut(285,283,str);

	//绘制刻度
	for(i = 0;i < 256;i+=5)
	{
		if((i&1) == 0)
		{
			pDC->MoveTo(i+35,280);
			pDC->LineTo(i+35,284);
		}
		else
		{
			pDC->MoveTo(i+35,280);
			pDC->LineTo(i+35,282);
		}
	}

	//绘制箭头
	pDC->MoveTo(335,275);
	pDC->LineTo(340,280);
	pDC->LineTo(335,285);

}

