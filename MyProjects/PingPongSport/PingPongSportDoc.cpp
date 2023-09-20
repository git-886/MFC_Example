// PingPongSportDoc.cpp : implementation of the CPingPongSportDoc class
//

#include "stdafx.h"
#include "PingPongSport.h"

#include "PingPongSportDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportDoc

IMPLEMENT_DYNCREATE(CPingPongSportDoc, CDocument)

BEGIN_MESSAGE_MAP(CPingPongSportDoc, CDocument)
	//{{AFX_MSG_MAP(CPingPongSportDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportDoc construction/destruction

CPingPongSportDoc::CPingPongSportDoc()
{
	// TODO: add one-time construction code here

}

CPingPongSportDoc::~CPingPongSportDoc()
{
}

BOOL CPingPongSportDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPingPongSportDoc serialization

void CPingPongSportDoc::Serialize(CArchive& ar)
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
// CPingPongSportDoc diagnostics

#ifdef _DEBUG
void CPingPongSportDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPingPongSportDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPingPongSportDoc commands
