// PIDAlgorithmDoc.cpp : implementation of the CPIDAlgorithmDoc class
//

#include "stdafx.h"
#include "PIDAlgorithm.h"

#include "PIDAlgorithmDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmDoc

IMPLEMENT_DYNCREATE(CPIDAlgorithmDoc, CDocument)

BEGIN_MESSAGE_MAP(CPIDAlgorithmDoc, CDocument)
	//{{AFX_MSG_MAP(CPIDAlgorithmDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmDoc construction/destruction

CPIDAlgorithmDoc::CPIDAlgorithmDoc()
{
	// TODO: add one-time construction code here

}

CPIDAlgorithmDoc::~CPIDAlgorithmDoc()
{
}

BOOL CPIDAlgorithmDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmDoc serialization

void CPIDAlgorithmDoc::Serialize(CArchive& ar)
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
// CPIDAlgorithmDoc diagnostics

#ifdef _DEBUG
void CPIDAlgorithmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPIDAlgorithmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPIDAlgorithmDoc commands
