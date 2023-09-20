// Ado.cpp: implementation of the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ado.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdo::CAdo()
{

}

CAdo::~CAdo()
{

}

void CAdo::OnInitADOConn()
{
	OnInitADOConnAccess();
//	OnInitADOConnOrcal();
//	OnInitADOConnSQLServer();
}

_RecordsetPtr& CAdo::GetRecordSet(_bstr_t bstrSQL)
{
  try
	{
		if(m_pConnection==NULL)
              OnInitADOConn();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(  m_pRecordset->State ==adStateOpen)
		{
			 AfxMessageBox("��¼����");
            m_pRecordset->Close();
			//m_pRecordset=NULL;
		}
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		//m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		 variant_t m_dirno;

	}
    catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	
	
	return m_pRecordset;
	
}

BOOL CAdo::ExecuteSQL(_bstr_t bstrSQL)
{
	_variant_t RecordsAffected;
	try
	{
        if(m_pConnection==NULL)
	     	OnInitADOConn();
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}

void CAdo::ExitConnect()
{
 try{
		if(m_pRecordset!=NULL)
		{
			if( m_pRecordset->State!=NULL)
			{
				m_pRecordset->Close();
				m_pRecordset=NULL;
			}
		}
		if( m_pConnection->State ==adStateOpen)
		{
			m_pConnection->Close();
			m_pConnection=NULL;
		}
		::CoUninitialize();
		
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CAdo::OnInitADOConn(CString filename)
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   char pBuf[MAX_PATH]; //���·���ı���
       CString appath,strConnect;
       GetModuleFileName(NULL, pBuf, MAX_PATH);//�˷���ȡ�ĺ�׼ȷ
       (_tcsrchr(pBuf, _T('\\')))[1] = 0; //ɾ���ļ�����ֻ���·��
	   
       appath=pBuf;
	   appath.TrimRight('\\');
	   strcpy(pBuf,appath);
      (_tcsrchr(pBuf, _T('\\')))[1] = 0; //ɾ���ļ�����ֻ���·��
	   appath=pBuf;
       appath+="attend.mdb";
	   appath=filename;
      strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Jet OLEDB:DataBase Password=ahut@123;Persist Security Info=False;Mode=Share Deny None",appath);
      m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	  
	   
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
	/*AfxOleInit();
	m_pConnection.CreateInstance(__uuidof(Connection));

	try                 
	{	
		// �򿪱���Access��Demo.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Image.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("���ݿ�����ʧ�ܣ�ȷ�����ݿ�Image.mdb�Ƿ��ڵ�ǰ·����!");	
	}     */ 
  
}

void CAdo::OnInitADOConnSQLServer()
{
    ::CoInitialize(NULL);
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		CString strConnect;

		strConnect.Format("Provider=SQLOLEDB;Data Sourse=Sql Server;Initial Catalog=master;User ID=sa;Password=abc123");
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);

		AfxMessageBox("Connected SQL Server!");
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConnSQLServer()");
		AfxMessageBox(e.Description());
	}
}

_RecordsetPtr& CAdo::GetRecordSet(CString strSQL)
{
	_bstr_t bstrSQL = (_bstr_t)strSQL;
	try
	{
		if(m_pConnection==NULL)
              OnInitADOConn();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(  m_pRecordset->State ==adStateOpen)
		{
			 AfxMessageBox("��¼����");
            m_pRecordset->Close();
			//m_pRecordset=NULL;
		}
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		//m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		 variant_t m_dirno;

	}
    catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	
	
	return m_pRecordset;
}

CString CAdo::GetCollect(CString strField)
{
	CString strValue;

	_variant_t variValue,variField;
	variField = (_variant_t)strField;

	variValue = m_pRecordset->GetCollect(variField);

	if( variValue.vt != VT_NULL)
    {
		strValue = (char *) _bstr_t  (variValue);
    }
	return strValue;
}

BOOL CAdo::ExecuteSQL(CString strSQL)
{
	_bstr_t bstrSQL;
	_variant_t RecordsAffected;

	bstrSQL = (_bstr_t)strSQL;

	try
	{
        if(m_pConnection==NULL)
	     	OnInitADOConn();
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}

void CAdo::OnInitADOConnAccess()
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //��õ�ǰӦ�ó���Ŀ¼���õ����ݿ�ľ���·��
       
       //DBpath = ex_AppPath + "\\db\\LianGang.mdb";
	   DBpath = ".\\CAdo\\student.mdb";

       strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None",DBpath);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
	/*AfxOleInit();
	m_pConnection.CreateInstance(__uuidof(Connection));

	try                 
	{	
		// �򿪱���Access��Demo.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Image.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("���ݿ�����ʧ�ܣ�ȷ�����ݿ�Image.mdb�Ƿ��ڵ�ǰ·����!");	
	}    
	*/
}

void CAdo::OnInitADOConnOrcal()
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //��õ�ǰӦ�ó���Ŀ¼���õ����ݿ�ľ���·��
       

  //     strConnect.Format("Provider=MSDAORA.1;User ID=%s;Password=%s;Data Source=%s;Persist Security Info=False",ex_pModel->m_DataBase.UserID,ex_pModel->m_DataBase.PassWord,ex_pModel->m_DataBase.DBName);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
}

void CAdo::OnInitADOConn(CString UserID, CString PassWord, CString DataSouce)
{
	OnInitADOConnOrcal(UserID,PassWord,DataSouce);
}

void CAdo::OnInitADOConnOrcal(CString UserID, CString PassWord, CString DataSouce)
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //��õ�ǰӦ�ó���Ŀ¼���õ����ݿ�ľ���·��
       

       strConnect.Format("Provider=MSDAORA.1;User ID=%s;Password=%s;Data Source=%s;Persist Security Info=False",UserID,PassWord,DataSouce);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
}