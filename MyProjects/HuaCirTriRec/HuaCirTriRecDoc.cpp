// HuaCirTriRecDoc.cpp : implementation of the CHuaCirTriRecDoc class
//

#include "stdafx.h"
#include "HuaCirTriRec.h"

#include "HuaCirTriRecDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecDoc

IMPLEMENT_DYNCREATE(CHuaCirTriRecDoc, CDocument)

BEGIN_MESSAGE_MAP(CHuaCirTriRecDoc, CDocument)
	//{{AFX_MSG_MAP(CHuaCirTriRecDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecDoc construction/destruction

CHuaCirTriRecDoc::CHuaCirTriRecDoc()
{
	// TODO: add one-time construction code here

}

CHuaCirTriRecDoc::~CHuaCirTriRecDoc()
{
}

BOOL CHuaCirTriRecDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecDoc serialization

void CHuaCirTriRecDoc::Serialize(CArchive& ar)
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
// CHuaCirTriRecDoc diagnostics

#ifdef _DEBUG
void CHuaCirTriRecDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHuaCirTriRecDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecDoc commands
