void CAdoDBDlg::OnButton1() 
{
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

	AfxOleInit();///初始化COM库
	m_pConnection.CreateInstance("ADODB.Connection");
	m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=test.mdb","","",adModeUnknown);///连接数据库

	m_pRecordset.CreateInstance("ADODB.Recordset");
	m_pRecordset->Open("SELECT * FROM  users",
_variant_t((IDispatch*)m_pConnection,true),adOpenStatic,adLockOptimistic,adCmdText);

	_variant_t vUsername;
	vUsername = m_pRecordset->GetCollect("username");
	
	CString str;
	str = (char *) _bstr_t  (vUsername);
	AfxMessageBox(str);
}
