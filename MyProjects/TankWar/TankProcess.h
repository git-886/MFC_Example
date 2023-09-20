#if !defined(AFX_TANKPROCESS_H__722C1B7A_3BF7_46CB_814F_9A120B9D4D24__INCLUDED_)
#define AFX_TANKPROCESS_H__722C1B7A_3BF7_46CB_814F_9A120B9D4D24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TankProcess.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTankProcess window
typedef struct
{
	int x;
	int y;
	int r;
}BulletNode;
class CTankProcess : public CWnd
{
// Construction
public:
	CTankProcess();

// Attributes
public:
	int m_tank_x;
	int m_tank_y;
	int m_tank_w;
	int m_pt_x;
	int m_pt_y;
	CDC *pDC;
	BulletNode m_bullet[50];//子弹数组
	int m_bullet_num;//子弹数目

	int m_direction;//坦克移动方向
	int m_score;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankProcess)
	//}}AFX_VIRTUAL

// Implementation
public:
	void MoveTankBoundaryDetermine();
	void BulletHitAndOut();
	void DrawBullet();
	void MoveBullet();
	void ProduceBullet();
	void MoveTank();
	void Draw(CDC *p);
	void DrawTank();
	virtual ~CTankProcess();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTankProcess)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKPROCESS_H__722C1B7A_3BF7_46CB_814F_9A120B9D4D24__INCLUDED_)
