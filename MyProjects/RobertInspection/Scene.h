#if !defined(AFX_SCENE_H__C05B21FE_EE8E_4BDC_BB83_66043048AA0C__INCLUDED_)
#define AFX_SCENE_H__C05B21FE_EE8E_4BDC_BB83_66043048AA0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Scene.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScene window

typedef struct
{
	int zb[4][2];//四点坐标
	int pos[2];//名字坐标
	char name[200];//名字数组
}Building;

typedef struct
{
	int zb[4][2];//四点坐标
}Road;
typedef struct
{
	float x;
	float y;
	float vx;//x方向速度
	float vy;//y方向速度
	float lifecycle;//生命周期
	int statue;//状态
}SParticle;

class CScene : public CWnd
{
// Construction
public:
	CScene();

// Attributes
public:

	CPoint m_YD;//原点

	CPoint m_Leak;//泄漏点

	float m_kx;//x方向比例尺
	float m_ky;//y方向比例尺

	int m_nd;//浓度---  50m范围内粒子个数
	


	Building building[200];
	Road road[200];
	SParticle m_Particle[10000000];
	int m_Nd[13];//存储指定点周围1~12点方向的浓度值




	int m_nBuilding;
	int m_nRoad;
	int m_nParticle;
	int m_nNd;

	FILE *fp;
	CDC *pDC;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScene)
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetMaxConcentrationDirection(float x,float y);
	int GetConcentration(float x,float y);
	void ParticleDraw();
	void ParticleDelete(int i);//参数i表示删除第i个粒子
	void ParticleMove();
	void ParticleCreate();
	void DrawRoad();
	int InitRoads();
	int InitBuildings();
	void DrawBuilding();
	void Draw(CDC *p);
	virtual ~CScene();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScene)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCENE_H__C05B21FE_EE8E_4BDC_BB83_66043048AA0C__INCLUDED_)
