#if !defined(AFX_DATAPROCESSANDDRAW_H__B6582453_235F_459E_967C_8C86B9C67C4C__INCLUDED_)
#define AFX_DATAPROCESSANDDRAW_H__B6582453_235F_459E_967C_8C86B9C67C4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataProcessAndDraw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataProcessAndDraw window

class CDataProcessAndDraw : public CWnd
{
// Construction
public:
	CDataProcessAndDraw();

// Attributes
public:

	CDC *pDC;
	float deg;//��

	float m_Xl[1000];//����������cosֵ
	float m_Yl[1000];//����������sinֵ

	int m_nXl;
	int m_nYl;

	float m_xl;//��¼ĳһʱ�̵�cosֵ��������m_Xl������
	float m_yl;//��¼ĳһʱ�̵�sinֵ��������m_Yl������

	



// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataProcessAndDraw)
	//}}AFX_VIRTUAL

// Implementation
public:
	void Move();
	void DrawZbzAndKd(float x0,float y0);
	void CosxDraw(float x0,float y0);
	void SinxDraw(float x0,float y0);
	void CircleDraw(float x0,float y0);
	void Draw(CDC *p);
	virtual ~CDataProcessAndDraw();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDataProcessAndDraw)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAPROCESSANDDRAW_H__B6582453_235F_459E_967C_8C86B9C67C4C__INCLUDED_)
