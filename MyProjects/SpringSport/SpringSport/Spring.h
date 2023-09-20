// Spring.h: interface for the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRING_H__4A701468_652F_4B9F_8296_E38396724B10__INCLUDED_)
#define AFX_SPRING_H__4A701468_652F_4B9F_8296_E38396724B10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpring  
{
public:
	void DrawFQuXian();
	void DrawAQuXian();
	void DrawVQuXian();
	void DrawYQuXian();
	void Move();
	void DrawCircle();
	void DrawSpring();
	void Draw(CDC *p);
	CSpring();
	virtual ~CSpring();

	CDC *pDC;

	//弹簧
	float m_initL;
	float m_phL;  //平衡长度
	float m_nowL; //实时长度
	CPoint m_LeftUp;  //弹簧左上角坐标
	float m_wSpring;  //弹簧宽度
	float m_kSpring;  //弹簧的弹性系数
	float m_znSpring; //弹簧的阻尼系数

	float m_Line;  //弹簧与小球之间的连线长度

	//小球
	float m_xCenter, m_yCenter; //小球中心坐标
	float m_rCir; //小球半径
	float m_mCir; //小球质量
	float m_initV; //小球速度

	float m_yCir[1000];  //小球运动轨迹
	float m_vCir[1000];  //小球运动速度
	float m_aCir[1000];  //小球加速度
	float m_fCir[1000];  //小球受力

	int m_nyCir, m_nvCir, m_naCir, m_nfCir;
};

#endif // !defined(AFX_SPRING_H__4A701468_652F_4B9F_8296_E38396724B10__INCLUDED_)
