// SnakeGameDoc.cpp : implementation of the CSnakeGameDoc class
//

#include "stdafx.h"
#include "SnakeGame.h"

#include "SnakeGameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDoc

IMPLEMENT_DYNCREATE(CSnakeGameDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnakeGameDoc, CDocument)
	//{{AFX_MSG_MAP(CSnakeGameDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDoc construction/destruction

CSnakeGameDoc::CSnakeGameDoc()
{
	// TODO: add one-time construction code here

}

CSnakeGameDoc::~CSnakeGameDoc()
{
}

BOOL CSnakeGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDoc serialization

void CSnakeGameDoc::Serialize(CArchive& ar)
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
// CSnakeGameDoc diagnostics

#ifdef _DEBUG
void CSnakeGameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnakeGameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDoc commands
