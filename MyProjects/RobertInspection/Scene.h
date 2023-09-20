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
	int zb[4][2];//�ĵ�����
	int pos[2];//��������
	char name[200];//��������
}Building;

typedef struct
{
	int zb[4][2];//�ĵ�����
}Road;
typedef struct
{
	float x;
	float y;
	float vx;//x�����ٶ�
	float vy;//y�����ٶ�
	float lifecycle;//��������
	int statue;//״̬
}SParticle;

class CScene : public CWnd
{
// Construction
public:
	CScene();

// Attributes
public:

	CPoint m_YD;//ԭ��

	CPoint m_Leak;//й©��

	float m_kx;//x���������
	float m_ky;//y���������

	int m_nd;//Ũ��---  50m��Χ�����Ӹ���
	


	Building building[200];
	Road road[200];
	SParticle m_Particle[10000000];
	int m_Nd[13];//�洢ָ������Χ1~12�㷽���Ũ��ֵ




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
	void ParticleDelete(int i);//����i��ʾɾ����i������
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
