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
    float x;//λ�ò���
    float y;

    float vx;//�����ٶ�
    float vy;//�����ٶ�

    float fitness;//������Ӧ��
    float fitness1;//������Ӧ��
    float fitness2;//������Ӧ��

    float xbest;//������������λ��
    float ybest;//������������λ��
    float zbest;//������������λ��
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
	Partical m_p[5];//����Ⱥ��
    int m_np;//Ⱥ�����Ӹ���

    float m_fitness;//Ⱥ����Ӧ��
    float m_gbest_x;//Ⱥ�����Ž�x
    float m_gbest_y;//Ⱥ�����Ž�y

};

#endif // !defined(AFX_PSO_H__E019A4F4_76D9_4961_9925_A2E40CCFE3DD__INCLUDED_)
