#if !defined(AFX_CARROBOT_H__86AAC162_CB42_4F79_9BF4_929B7DF5D646__INCLUDED_)
#define AFX_CARROBOT_H__86AAC162_CB42_4F79_9BF4_929B7DF5D646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarRobot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarRobot window
typedef struct
{
	float w;//���ٶ�
	float r;//Բ�뾶
	float angle;//
	float MaxND;
	float MinND;
	CPoint Max;
	CPoint Min;
	float x,y;//Բ������
	float ND;//С����ǰλ��Ũ��
}SRotateMethedCircle;

class CCarRobot : public CWnd
{
// Construction
public:
	CCarRobot();

// Attributes
public:
	CPoint m_YD;//����ԭ��
	float m_x,m_y;//��С��������ԭ��
	float m_w;//С����(m)
	float m_v;//С�������ƶ��ٶȣ�m/s��

	float m_r;//С����ת�˶��뾶-m
	float m_wv;//С����ת�˶����ٶȣ�rad/s��
	int m_Flag_SN;//С��ѡ���˶�˳ʱ��-1����ʱ��-2
	int m_dir;//С��ѡ���˶�����1~12
	float m_YXx;//С��ת����Բ������
	float m_YXy;

	SRotateMethedCircle RotCircle;

	int m_nd;//С��50m��Χ��Ũ��ֵ

	

	CPoint m_YSYDpoint;//�����ƶ�Ŀ������������

	CPoint m_PointGJ[100];//·��ָ����ʽ�ƶ�-�洢���̵�
	int m_nPointGJ;//���̵����
	int m_nCur;//�Ѿ��ﵽ��ĸ���

	float m_JD;//��ת��ʽ�µ�ǰ�Ƕ�

	float m_kx;
	float m_ky;//ת��ϵ��

	int m_flag_MoveWay;//���С���������ƶ���ʽ-ֱ���ƶ���ָ���㣨1��-�����ƶ���ָ���㣨2��-תȦ�ƶ���3��-ָ��·���ƶ���4��Ĭ��Ϊ1

	CDC *pDC;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarRobot)
	//}}AFX_VIRTUAL

// Implementation
public:
	void RotCircleInit(float nd,float m_x,float m_y);//��ʼ��תȦԲ����
	void RotateMethodFindLeakPoint(float n);
	void MoveToLeakPoint(int x);
	void DrawSpecifyPointPath();//��ָ��·��
	void InitSpecifyPoint(float x,float y);
	int MoveSpecifyPath();//����ָ��·���ƶ�
	void QuiYunaXin();
	void LBDProcess(CPoint point);
	int Move();
	void MoveRotate();
	void MoveBySpecifiedPoint(int x,int y);//����Ϊ��ͼĿ�����������
	int MoveByUniform();
	void DrawCar();
	void Draw(CDC *p);
	virtual ~CCarRobot();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCarRobot)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARROBOT_H__86AAC162_CB42_4F79_9BF4_929B7DF5D646__INCLUDED_)
