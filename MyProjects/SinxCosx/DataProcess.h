// DataProcess.h: interface for the CDataProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAPROCESS_H__DA4C0585_8B59_4803_BFD7_0969CD2DEB6A__INCLUDED_)
#define AFX_DATAPROCESS_H__DA4C0585_8B59_4803_BFD7_0969CD2DEB6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDataProcess  
{
public:
	void DrawAccelerationCurve(float x0,float y0);
	void DrawSpeedCurve(float x0,float y0);
	void DrawZBZ(float x0,float y0,char str[100]);
	void DrawZbzAndKd(float x0,float y0);
	void CosxDraw(float x0,float y0);
	void SinxDraw(float x0,float y0);
	void CircleDraw(float x0,float y0);
	void Draw(CDC *p);
	void Move();
	CDataProcess();
	virtual ~CDataProcess();

	

	int m_X;//圆心坐标
	int m_Y;
	float m_xGj[1000];
	float m_yGj[1000];

	float m_Vx[1000];//x方向速度
	float m_Vy[1000];//y方向速度

	float m_Ax[1000];//x方向加速度
	float m_Ay[1000];//y方向加速度

	int m_nVx;
	int m_nVy;
	int m_nAx;
	int m_nAy;

	float m_vx;
	float m_vy;
	float m_ax;
	float m_ay;



	int m_nxGj;
	int m_nyGj;

	float m_x;//位移单位m
	float m_y;

	float m_w;//角速度，单位rad/s

	float m_Initdeg;//相位，单位弧度
	float m_deg;

	float m_r;//振幅，单位m

	float m_k;//距离单位转换系数

	float m_Initx;
	float m_Inity;
	
	
	CDC *pDC;





};

#endif // !defined(AFX_DATAPROCESS_H__DA4C0585_8B59_4803_BFD7_0969CD2DEB6A__INCLUDED_)
