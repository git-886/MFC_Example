// HuaTu_InDialogDoc.cpp : implementation of the CHuaTu_InDialogDoc class
//

#include "stdafx.h"
#include "HuaTu_InDialog.h"

#include "HuaTu_InDialogDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogDoc

IMPLEMENT_DYNCREATE(CHuaTu_InDialogDoc, CDocument)

BEGIN_MESSAGE_MAP(CHuaTu_InDialogDoc, CDocument)
	//{{AFX_MSG_MAP(CHuaTu_InDialogDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogDoc construction/destruction

CHuaTu_InDialogDoc::CHuaTu_InDialogDoc()
{
	// TODO: add one-time construction code here

}

CHuaTu_InDialogDoc::~CHuaTu_InDialogDoc()
{
}

BOOL CHuaTu_InDialogDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogDoc serialization

void CHuaTu_InDialogDoc::Serialize(CArchive& ar)
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
// CHuaTu_InDialogDoc diagnostics

#ifdef _DEBUG
void CHuaTu_InDialogDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHuaTu_InDialogDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuaTu_InDialogDoc commands
