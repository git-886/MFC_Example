#if !defined(AFX_PLANEWAR_H__386411AB_8978_4CB2_B668_E4BEA7040908__INCLUDED_)
#define AFX_PLANEWAR_H__386411AB_8978_4CB2_B668_E4BEA7040908__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlaneWar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlaneWar window
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
	float w;
	float h;
	float vy;
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
class CPlaneWar : public CWnd
{
// Construction
public:
	CPlaneWar();

// Attributes
public:
	int m_xBJ;
	int m_yBJ;
	int m_wBJ;
	int m_x;
	int m_y;
	int m_d;
	CDC *pDC;
	SBullet m_Bul[100];
	int m_nBul;
	SCircle m_Cir[100];
	int m_nCir;
	int m_Score;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneWar)
	//}}AFX_VIRTUAL

// Implementation
public:
	int CircleCollision();
	void CircleDelete(int n);
	void CircleHit();
	void CircleOut();
	void CircleDraw();
	void CircleMove();
	void CircleProduce();
	void ProduceTargets();
	void BulletOut();
	void BulletDelete(int n);
	void BulletMove();
	void BulletDraw();
	void BulletProduce();
	void PlaneMove(int nChar);
	void DrawBJ();
	void PlaneDraw();
	void Draw(CDC *p);
	virtual ~CPlaneWar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPlaneWar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEWAR_H__386411AB_8978_4CB2_B668_E4BEA7040908__INCLUDED_)
