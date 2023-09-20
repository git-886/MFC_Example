// Robots.h: interface for the CRobots class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTS_H__7D7E1B11_B230_42CE_A0DB_20922F7AE6A1__INCLUDED_)
#define AFX_ROBOTS_H__7D7E1B11_B230_42CE_A0DB_20922F7AE6A1__INCLUDED_
#include "Ado.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


typedef struct
{
	float eyelx,eyely,eyelr;
	float eyerx,eyery,eyerr;
	float nosex,nosey,noseb;
	float mouthx,mouthy,mouthr;
	float headx,heady,headr;
	float neckx,necky,neckl,neckw;
	float bodyx,bodyy,bodyl,bodyw;
	float armlx,armly,armll,armlw;
	float armrx,armry,armrl,armrw;
	float leglx,legly,legll,leglw;
	float legrx,legry,legrl,legrw;
	float footlx,footly,footll,footlw;
	float footrx,footry,footrl,footrw;
	float x;
	float y;
}SRobot;
class CRobots  
{
public:
	BOOL DeleteRobot();
	void InitRobot();
	void DrawRobot();
	void Draw(CDC *p);
	BOOL CreateRobot();
	CRobots();
	virtual ~CRobots();

	CAdo m_Ado;
	SRobot m_robot;
	SRobot m_Robots[100];//机器人数组
	int m_nRob;
	CDC *pDC;

	int m_YDX;
	int m_YDY;

	float m_kx;//x方向比例尺
	float m_ky;//y方向比例尺

};

#endif // !defined(AFX_ROBOTS_H__7D7E1B11_B230_42CE_A0DB_20922F7AE6A1__INCLUDED_)
