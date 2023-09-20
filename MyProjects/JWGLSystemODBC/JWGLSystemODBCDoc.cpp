// JWGLSystemODBCDoc.cpp : implementation of the CJWGLSystemODBCDoc class
//

#include "stdafx.h"
#include "JWGLSystemODBC.h"

#include "JWGLSystemODBCSet.h"
#include "JWGLSystemODBCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCDoc

IMPLEMENT_DYNCREATE(CJWGLSystemODBCDoc, CDocument)

BEGIN_MESSAGE_MAP(CJWGLSystemODBCDoc, CDocument)
	//{{AFX_MSG_MAP(CJWGLSystemODBCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCDoc construction/destruction

CJWGLSystemODBCDoc::CJWGLSystemODBCDoc()
{
	// TODO: add one-time construction code here

}

CJWGLSystemODBCDoc::~CJWGLSystemODBCDoc()
{
}

BOOL CJWGLSystemODBCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCDoc diagnostics

#ifdef _DEBUG
void CJWGLSystemODBCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJWGLSystemODBCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJWGLSystemODBCDoc commands
