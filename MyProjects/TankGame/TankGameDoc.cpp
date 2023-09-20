// TankGameDoc.cpp : implementation of the CTankGameDoc class
//

#include "stdafx.h"
#include "TankGame.h"

#include "TankGameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankGameDoc

IMPLEMENT_DYNCREATE(CTankGameDoc, CDocument)

BEGIN_MESSAGE_MAP(CTankGameDoc, CDocument)
	//{{AFX_MSG_MAP(CTankGameDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankGameDoc construction/destruction

CTankGameDoc::CTankGameDoc()
{
	// TODO: add one-time construction code here

}

CTankGameDoc::~CTankGameDoc()
{
}

BOOL CTankGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTankGameDoc serialization

void CTankGameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTankGameDoc diagnostics

#ifdef _DEBUG
void CTankGameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTankGameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankGameDoc commands
