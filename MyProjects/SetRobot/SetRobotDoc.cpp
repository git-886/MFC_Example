// SetRobotDoc.cpp : implementation of the CSetRobotDoc class
//

#include "stdafx.h"
#include "SetRobot.h"

#include "SetRobotDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetRobotDoc

IMPLEMENT_DYNCREATE(CSetRobotDoc, CDocument)

BEGIN_MESSAGE_MAP(CSetRobotDoc, CDocument)
	//{{AFX_MSG_MAP(CSetRobotDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetRobotDoc construction/destruction

CSetRobotDoc::CSetRobotDoc()
{
	// TODO: add one-time construction code here

}

CSetRobotDoc::~CSetRobotDoc()
{
}

BOOL CSetRobotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSetRobotDoc serialization

void CSetRobotDoc::Serialize(CArchive& ar)
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
// CSetRobotDoc diagnostics

#ifdef _DEBUG
void CSetRobotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSetRobotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSetRobotDoc commands
