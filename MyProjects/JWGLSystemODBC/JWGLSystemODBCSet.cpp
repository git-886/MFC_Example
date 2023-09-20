// JWGLSystemODBCSet.cpp : implementation of the CJWGLSystemODBCSet class
//

#include "stdafx.h"
#include "JWGLSystemODBC.h"
#include "JWGLSystemODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCSet implementation

IMPLEMENT_DYNAMIC(CJWGLSystemODBCSet, CRecordset)

CJWGLSystemODBCSet::CJWGLSystemODBCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CJWGLSystemODBCSet)
	m_sid = 0;
	m_sage = 0;
	m_snmae = _T("");
	m_spro = _T("");
	m_sclass = _T("");
	m_ssex = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CJWGLSystemODBCSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=JWGLSystem");
}

CString CJWGLSystemODBCSet::GetDefaultSQL()
{
	return _T("[dbo].[Student]");
}

void CJWGLSystemODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CJWGLSystemODBCSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[sid]"), m_sid);
	RFX_Long(pFX, _T("[sage]"), m_sage);
	RFX_Text(pFX, _T("[snmae]"), m_snmae);
	RFX_Text(pFX, _T("[spro]"), m_spro);
	RFX_Text(pFX, _T("[sclass]"), m_sclass);
	RFX_Text(pFX, _T("[ssex]"), m_ssex);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCSet diagnostics

#ifdef _DEBUG
void CJWGLSystemODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CJWGLSystemODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
