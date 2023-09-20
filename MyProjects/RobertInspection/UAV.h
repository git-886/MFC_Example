// UAV.h: interface for the CUAV class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UAV_H__5EB5BD8A_D6AC_46F6_9379_6F756B0E7474__INCLUDED_)
#define AFX_UAV_H__5EB5BD8A_D6AC_46F6_9379_6F756B0E7474__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CarRobot.h"
typedef struct
{
	float x;
	float y;
}SPropeller;
class CUAV : public CCarRobot  
{
public:
	void PropellerRotate();
	void DrawCUAV();
	void DrawPropeller();
	void Draw(CDC *p);
	CUAV();
	virtual ~CUAV();
	CDC *pDC;
	float m_ProAngle;//ÂÝÐý½°½Ç¶È
	float m_wv;//ÂÝÐý½°Ðý×ª½ÇËÙ¶È

	SPropeller m_Prop[4];
	int m_nProp;



};

#endif // !defined(AFX_UAV_H__5EB5BD8A_D6AC_46F6_9379_6F756B0E7474__INCLUDED_)
