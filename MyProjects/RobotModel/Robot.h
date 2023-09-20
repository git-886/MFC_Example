// Robot1.h: interface for the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT1_H__47A3D124_7634_41B2_949D_38313B040FC5__INCLUDED_)
#define AFX_ROBOT1_H__47A3D124_7634_41B2_949D_38313B040FC5__INCLUDED_
#include "Ado.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef struct
{
	CString RobotName;
	float eyelr;
	float eyerr;
	float nosed;
	float mouthr;
	float headr;
	float neckl,neckw;
	float bodyl,bodyw;
	float armll,armlw;
	float armrl,armrw;
	float legll,leglw;
	float legrl,legrw;
	int ZX_x;
	int ZX_y;
}SRobot;
class CRobot  
{
public:
	void RobotWaveHand();
	void RobotWink();
	void RobotJump();
	void RobotMove();
	void RobotSaveToFile(CString FilePath);
	void InitCreateRobot();

	void RobotInit(CString m_CurRobotName);
	void DrawRobot();
	void Draw(CDC *p);
	void RobotSelect();
	void RobotUpdate();
	void RobotDelete(CString SelRobotName);
	void RobotCreate();

	CAdo m_Ado;
	CDC *pDC;

	//�����˲���
	int ZX_x;//��������
	int ZX_y;
	int m_flg;
	float m_t;
	int flag;
	float m_jd1;//��仯�Ƕ�
	float m_jd2;//�ԽǱ仯�Ƕ�
	float m_jd3;//���仯�Ƕ�
	CString RobotName;
	float eyelr;
	float eyerr;
	float nosed;
	float mouthr;
	float headr;
	float neckl,neckw;
	float bodyl,bodyw;
	float armll,armlw;
	float armrl,armrw;
	float legll,leglw;
	float legrl,legrw;
	
	float m_kx;//������
	float m_ky;
	
	

	CRobot();
	virtual ~CRobot();

};

#endif // !defined(AFX_ROBOT1_H__47A3D124_7634_41B2_949D_38313B040FC5__INCLUDED_)
