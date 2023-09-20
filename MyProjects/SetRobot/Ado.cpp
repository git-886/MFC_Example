// Ado.cpp: implementation of the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SetRobot.h"
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

_RecordsetPtr& CAdo::GetRecordSet(CString strSQL)
{
	_bstr_t bstrSQL = (_bstr_t)strSQL;
	try
	{
		if(m_pConnection==NULL)
              //OnInitADOConnSQLServer();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(m_pRecordset->State==adStateOpen)
		{
			 AfxMessageBox("记录集打开");
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

void CAdo::OnInitADOConn()
{
	OnInitADOConnAccess();
}

void CAdo::OnInitADOConnAccess()
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //获得当前应用程序目录并得到数据库的绝对路径
       
       //DBpath = ex_AppPath + "\\db\\LianGang.mdb";
	   DBpath = ".\\CAdo\\Robot.mdb";

       strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None",DBpath);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}

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

void CAdo::OnInitADOConn(CString filename)
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   char pBuf[MAX_PATH]; //存放路径的变量
       CString appath,strConnect;
       GetModuleFileName(NULL, pBuf, MAX_PATH);//此方获取的很准确
       (_tcsrchr(pBuf, _T('\\')))[1] = 0; //删除文件名，只获得路径
	   
       appath=pBuf;
	   appath.TrimRight('\\');
	   strcpy(pBuf,appath);
      (_tcsrchr(pBuf, _T('\\')))[1] = 0; //删除文件名，只获得路径
	   appath=pBuf;
       appath+="attend.mdb";
	   appath=filename;
	   //Microsoft.ACE.OLEDB.12.0
	   //Microsoft.Jet.OLEDB.4.0
       //strConnect.Format("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=%s;Jet OLEDB:DataBase Password=abc123;Persist Security Info=False;Mode=Share Deny None",appath);
       //m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);

	   strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None",appath);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	  
	   
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
}

void CAdo::UpdateData(int id,float eyelr,float eyerr,float mouthr)
{
	
	OnInitADOConn(".\\CAdo\\Robot1.mdb");

	CString sql,value;

//	sql.Format("update s set sname ='王五' where sno = '9602' ");

	sql.Format("update robots set eyelr = %f,eyerr = %f,mouthr = %f where RID = %d",eyelr,eyerr,mouthr,id);
	GetRecordSet(sql);


	ExitConnect();

	AfxMessageBox("OK!");
}

void CAdo::SelectData(int id)
{
	OnInitADOConn(".\\CAdo\\Robot1.mdb");

	CString sql,value;;

	sql.Format("select * from robots where RID = %d ",id);
	GetRecordSet(sql);
	if(!m_pRecordset->adoEOF)
	{
		value=GetCollect("eyelr");
	}

	ExitConnect();

	AfxMessageBox(value);
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
			 AfxMessageBox("记录集打开");
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
