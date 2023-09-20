// RobertInspectionDoc.cpp : implementation of the CRobertInspectionDoc class
//

#include "stdafx.h"
#include "RobertInspection.h"

#include "RobertInspectionDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionDoc

IMPLEMENT_DYNCREATE(CRobertInspectionDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobertInspectionDoc, CDocument)
	//{{AFX_MSG_MAP(CRobertInspectionDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionDoc construction/destruction

CRobertInspectionDoc::CRobertInspectionDoc()
{
	// TODO: add one-time construction code here

}

CRobertInspectionDoc::~CRobertInspectionDoc()
{
}

BOOL CRobertInspectionDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionDoc serialization

void CRobertInspectionDoc::Serialize(CArchive& ar)
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
// CRobertInspectionDoc diagnostics

#ifdef _DEBUG
void CRobertInspectionDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobertInspectionDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobertInspectionDoc commands
