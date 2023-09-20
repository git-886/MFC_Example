// DlgRobotParameter.cpp : implementation file
//

#include "stdafx.h"
#include "setrobot.h"
#include "DlgRobotParameter.h"
//#include "atlstr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRobotParameter dialog


CDlgRobotParameter::CDlgRobotParameter(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRobotParameter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRobotParameter)
	m_eyelr = 0.0f;
	m_eyerr = 0.0f;
	m_mouthr = 0.0f;
	m_RidSel = 0;
	m_ridUpdate = 0;
	m_mouthSel = 0.0f;
	m_eyelrSel = 0.0f;
	m_eyerrSel = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgRobotParameter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRobotParameter)
	DDX_Control(pDX, IDC_LISTALL, m_ListCtr);
	DDX_Text(pDX, IDC_eyelrUpdate, m_eyelr);
	DDX_Text(pDX, IDC_eyerUpdate, m_eyerr);
	DDX_Text(pDX, IDC_mouthrUpdate, m_mouthr);
	DDX_Text(pDX, IDC_RIDSelect, m_RidSel);
	DDX_Text(pDX, IDC_RIDUpdate, m_ridUpdate);
	DDX_Text(pDX, IDC_mouthrSel, m_mouthSel);
	DDX_Text(pDX, IDC_eyelrSel, m_eyelrSel);
	DDX_Text(pDX, IDC_eyerSel, m_eyerrSel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRobotParameter, CDialog)
	//{{AFX_MSG_MAP(CDlgRobotParameter)
	ON_LBN_SELCHANGE(IDC_LISTALL, OnSelchangeListall)
	ON_BN_CLICKED(IDC_BUTRefresh, OnBUTRefresh)
	ON_BN_CLICKED(IDC_BUTSelect, OnBUTSelect)
	ON_BN_CLICKED(IDC_BUTUpdate, OnBUTUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRobotParameter message handlers

void CDlgRobotParameter::OnSelchangeListall() 
{
	// TODO: Add your control notification handler code here
/*	int curSel = m_list.GetCurSel();
	_variant_t var,varIndex;

	CString m_RID,m_eyelr,m_eyerr,m_mouthr;
	//if(curSel < 0)
		return;
	try
	{
		m_Ado.m_pRecordset->MoveFirst();
		m_Ado.m_pRecordset->Move(long(curSel));

		var = m_Ado.m_pRecordset->GetCollect("RID");
		if(var.vt != VT_NULL)
			m_RID = (LPCSTR)_bstr_t(var);
		var = m_Ado.m_pRecordset->GetCollect("eyelr");
		if(var.vt != VT_NULL)
			m_eyelr = (LPCSTR)_bstr_t(var);

		var = m_Ado.m_pRecordset->GetCollect("eyerr");
		if(var.vt != VT_NULL)
			m_eyerr = (LPCSTR)_bstr_t(var);

		var = m_Ado.m_pRecordset->GetCollect("mouthr");
		if(var.vt != VT_NULL)
			m_mouthr = (LPCSTR)_bstr_t(var);
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	*/
}

void CDlgRobotParameter::ListData()
{
	int i;
	_variant_t var;
	CString RID,eyelr,eyerr,mouthr;
	 
	RID = eyelr = eyerr = mouthr ="";
	m_Ado.OnInitADOConn(".\\CAdo\\Robot1.mdb");
	CString sql;
	sql.Format("select * from robots");
	m_Ado.GetRecordSet(sql);
	try
	{
		if(!m_Ado.m_pRecordset->BOF)
		{
			m_Ado.m_pRecordset->MoveFirst();

		}
		else
		{
			AfxMessageBox("表内数据为空！");
			return;
		}
		while(!m_Ado.m_pRecordset->adoEOF)
		{
			var = m_Ado.m_pRecordset->GetCollect("RID");
			if(var.vt != VT_NULL)
				RID = (LPCSTR)_bstr_t(var);
			var = m_Ado.m_pRecordset->GetCollect("eyelr");
			if(var.vt != VT_NULL)
				eyelr = (LPCSTR)_bstr_t(var);

			var = m_Ado.m_pRecordset->GetCollect("eyerr");
			if(var.vt != VT_NULL)
				eyerr = (LPCSTR)_bstr_t(var);

			var = m_Ado.m_pRecordset->GetCollect("mouthr");
			if(var.vt != VT_NULL)
				mouthr = (LPCSTR)_bstr_t(var);

			m_ListCtr.InsertItem(i,RID);
			m_ListCtr.SetItemText(i,1,eyelr);
			m_ListCtr.SetItemText(i,2,eyerr);
			m_ListCtr.SetItemText(i,3,mouthr);

			m_Ado.m_pRecordset->MoveNext();

			i++;
		}
	}catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());

	}

}

void CDlgRobotParameter::OnBUTRefresh() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(false);
}

void CDlgRobotParameter::OnBUTSelect() 
{
	// TODO: Add your control notification handler code here
	
	//m_Ado.SelectData(1);

}

 void CDlgRobotParameter::OnBUTUpdate() 
 {
 	// TODO: Add your control notification handler code here
 	
 	//读出数据进行画刷新机器人
 	CString strText;
     GetDlgItemText(IDC_eyelrUpdate, strText);
 	//float eyelrValue = _wtof(strText);
 
 	
     GetDlgItemText(IDC_eyerUpdate, strText);
 	//float eyerrValue = _wtof(strText);
 
 	
     GetDlgItemText(IDC_mouthrUpdate, strText);
 	//float mouthrValue = _wtof(strText);
 
 	int idValue = GetDlgItemInt(IDC_RIDUpdate);
 
 	
 	//更新数据库数据
 }



BOOL CDlgRobotParameter::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle = m_ListCtr.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件 
	m_ListCtr.SetExtendedStyle(dwStyle); //设置扩展风格
	m_ListCtr.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	
	//为列表设置列数和列名从第0行开始
	int i = 0;
	m_ListCtr.InsertColumn(i++,"RID",LVCFMT_LEFT,125,0);
	m_ListCtr.InsertColumn(i++,"EYELR",LVCFMT_LEFT,125,1);
	m_ListCtr.InsertColumn(i++,"EYERR",LVCFMT_LEFT,125,1);
	m_ListCtr.InsertColumn(i++,"MOUTHR",LVCFMT_LEFT,132,1);
	//为列表添加数据，从第0行开始
	//ListData();







	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
