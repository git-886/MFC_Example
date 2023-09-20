#if !defined(AFX_TANKWAR_H__C2CCEB73_1A3E_4616_960A_19AE07B77DFA__INCLUDED_)
#define AFX_TANKWAR_H__C2CCEB73_1A3E_4616_960A_19AE07B77DFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TankWar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTankWar window

typedef struct
{
	float x;
	float y;
	float r;
	float vy;
	int fs;
}SCircle;

typedef struct
{
	float x;
	float y;
	float vy;
	float w,h;
	int fs;
}SRectangle;
typedef struct
{
	float x;
	float y;
	float d;
	float vy;
	int fs;
}STriangle;
typedef struct
{
	float x;
	float y;
	float vy;
	float r;
}SBullet;
class CTankWar : public CWnd
{
// Construction
public:
	CTankWar();


// Attributes
public:

// Operations
public:
	SCircle m_Cir[100];
	int m_nCir;
	SRectangle m_Rec[100];
	int m_nRec;
	STriangle m_Tri[100];
	int m_nTri;
	SBullet m_Bul[100];
	int m_nBul;
	CDC *pDC;
	int m_xBK;
	int m_yBK;
	int m_wBK;
	int m_x;
	int m_y;
	int m_r;

	long m_Score;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankWar)
	//}}AFX_VIRTUAL

// Implementation
public:
	int TriangleGameOver();
	void TriangleHit();
	void TriangleOut();
	void TriangleDelete(int n);
	void TriangleMove();
	void TriangleDraw();
	void TriangleProduce();
	int RectangleGameOver();
	void RectangleOut();
	void RectangleHit();
	void RectangleDelete(int n);
	void RectangleMove();
	void RectangleProduce();
	void RectangleDraw();
	int CircleGameOver();
	void BulleOut();
	void BulletDelete(int n);
	void BulletMove();
	void BulletDraw();
	void BulletProduce();
	void TankDraw();
	void CirOut();
	void DrawBK();
	void CircleHit();
	void TankMove(int nChar);
	void Produce();
	void Draw(CDC *p);
	void CircleDraw();
	void CircleProduce();
	void CircleDelete(int i);
	void CircleMove();
	virtual ~CTankWar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTankWar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKWAR_H__C2CCEB73_1A3E_4616_960A_19AE07B77DFA__INCLUDED_)
