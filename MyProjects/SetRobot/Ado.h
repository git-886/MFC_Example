// Ado.h: interface for the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADO_H__8DAB24E9_AC72_4B30_B752_AB688156AED3__INCLUDED_)
#define AFX_ADO_H__8DAB24E9_AC72_4B30_B752_AB688156AED3__INCLUDED_
#import "c:/program files/common files/system/ado/msado15.dll" rename_namespace("myADO") rename("EOF","adoEOF")
using namespace myADO;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdo  
{
public:
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void SelectData(int id);
	void UpdateData(int id,float eyelr,float eyerr,float mouthr);
	void OnInitADOConn(CString filename);
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	BOOL ExecuteSQL(CString strSQL);
	CString GetCollect(CString strField);
	void OnInitADOConnAccess();
	void OnInitADOConn();
	_RecordsetPtr& GetRecordSet(CString strSQL);

	_RecordsetPtr m_pRecordset;
	_ConnectionPtr m_pConnection;
	CString m_UserID;
	CString m_PassWord;
	CString m_DataSouce;



	void ExitConnect();
	CAdo();
	virtual ~CAdo();

};

#endif // !defined(AFX_ADO_H__8DAB24E9_AC72_4B30_B752_AB688156AED3__INCLUDED_)
