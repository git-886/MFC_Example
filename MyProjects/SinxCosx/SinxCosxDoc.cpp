// SinxCosxDoc.cpp : implementation of the CSinxCosxDoc class
//

#include "stdafx.h"
#include "SinxCosx.h"

#include "SinxCosxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxDoc

IMPLEMENT_DYNCREATE(CSinxCosxDoc, CDocument)

BEGIN_MESSAGE_MAP(CSinxCosxDoc, CDocument)
	//{{AFX_MSG_MAP(CSinxCosxDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxDoc construction/destruction

CSinxCosxDoc::CSinxCosxDoc()
{
	// TODO: add one-time construction code here

}

CSinxCosxDoc::~CSinxCosxDoc()
{
}

BOOL CSinxCosxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSinxCosxDoc serialization

void CSinxCosxDoc::Serialize(CArchive& ar)
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
// CSinxCosxDoc diagnostics

#ifdef _DEBUG
void CSinxCosxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSinxCosxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinxCosxDoc commands
