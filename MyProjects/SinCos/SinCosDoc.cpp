// SinCosDoc.cpp : implementation of the CSinCosDoc class
//

#include "stdafx.h"
#include "SinCos.h"

#include "SinCosDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinCosDoc

IMPLEMENT_DYNCREATE(CSinCosDoc, CDocument)

BEGIN_MESSAGE_MAP(CSinCosDoc, CDocument)
	//{{AFX_MSG_MAP(CSinCosDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinCosDoc construction/destruction

CSinCosDoc::CSinCosDoc()
{
	// TODO: add one-time construction code here

}

CSinCosDoc::~CSinCosDoc()
{
}

BOOL CSinCosDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSinCosDoc serialization

void CSinCosDoc::Serialize(CArchive& ar)
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
// CSinCosDoc diagnostics

#ifdef _DEBUG
void CSinCosDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSinCosDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinCosDoc commands
