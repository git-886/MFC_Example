// PSO.h: interface for the PSO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSO_H__E019A4F4_76D9_4961_9925_A2E40CCFE3DD__INCLUDED_)
#define AFX_PSO_H__E019A4F4_76D9_4961_9925_A2E40CCFE3DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct Partical
{
    float x;//位置参数
    float y;

    float vx;//粒子速度
    float vy;//粒子速度

    float fitness;//粒子适应度
    float fitness1;//粒子适应度
    float fitness2;//粒子适应度

    float xbest;//个体粒子最优位置
    float ybest;//个体粒子最优位置
    float zbest;//个体粒子最优位置
};

class PSO  
{
public:
	PSO();
	virtual ~PSO();
public:
	void Draw(CDC *p);
	void Run(int IterationsNum);
	float GetRandom(float min,float max);
	float calculateFitness(float x,float y);
	void ParticalUpdate();
	void ParticalInit();
	Partical m_p[5];//粒子群体
    int m_np;//群体粒子个数

    float m_fitness;//群体适应度
    float m_gbest_x;//群体最优解x
    float m_gbest_y;//群体最优解y

};

#endif // !defined(AFX_PSO_H__E019A4F4_76D9_4961_9925_A2E40CCFE3DD__INCLUDED_)
