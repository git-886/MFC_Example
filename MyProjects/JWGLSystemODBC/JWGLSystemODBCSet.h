// JWGLSystemODBCSet.h : interface of the CJWGLSystemODBCSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JWGLSYSTEMODBCSET_H__A2D09A1A_BD41_4729_8F20_78318F253AB5__INCLUDED_)
#define AFX_JWGLSYSTEMODBCSET_H__A2D09A1A_BD41_4729_8F20_78318F253AB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CJWGLSystemODBCSet : public CRecordset
{
public:
	CJWGLSystemODBCSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CJWGLSystemODBCSet)

// Field/Param Data
	//{{AFX_FIELD(CJWGLSystemODBCSet, CRecordset)
	long	m_sid;
	long	m_sage;
	CString	m_snmae;
	CString	m_spro;
	CString	m_sclass;
	CString	m_ssex;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJWGLSystemODBCSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JWGLSYSTEMODBCSET_H__A2D09A1A_BD41_4729_8F20_78318F253AB5__INCLUDED_)

