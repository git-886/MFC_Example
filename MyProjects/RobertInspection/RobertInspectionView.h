// RobertInspectionView.h : interface of the CRobertInspectionView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBERTINSPECTIONVIEW_H__77361E45_2B5D_4C4C_BCA4_FF24AC58C902__INCLUDED_)
#define AFX_ROBERTINSPECTIONVIEW_H__77361E45_2B5D_4C4C_BCA4_FF24AC58C902__INCLUDED_
#include "Scene.h"
#include "CarRobot.h"
#include "UAV.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobertInspectionView : public CView
{
protected: // create from serialization only
	CRobertInspectionView();
	DECLARE_DYNCREATE(CRobertInspectionView)

// Attributes
public:
	CRobertInspectionDoc* GetDocument();
	CScene m_scene;
	CCarRobot m_car;
	CUAV m_uav;//���˻�

	int m_xInit;//�����󽨰���ʱ�ĳ�ʼԭ��λ������
	int m_yInit;

	int m_xInitCar;//�����������ʱ�ĳ�ʼС��λ������
	int m_yInitCar;

	int m_xInitUAV;//�����������ʱ�ĳ�ʼС��λ������
	int m_yInitUAV;

	CPoint m_LBD;//�����󽨰���ʱ��ԭ��λ������
	CPoint m_LBDUniform;//��Ϊ�����ƶ���ʽʱ�������󽨰���ʱ��ԭ��λ������
	CPoint m_LBDNdTest;//���浱ǰ���λ�ã����ڲ���Ũ��,��ʼΪԭ��

	int m_flag_LBD;//��ǰ��£�Ϊ1���ͷſ���Ϊ0��

	int m_flag_Map;//����Ƿ�Ե�ͼ���зŴ���ƶ�-��1-��0��Ĭ��Ϊ0

	int m_flag_Test;//��ǲ������ͣ�1ΪŨ�Ȳ���,Ĭ��Ϊ1




// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobertInspectionView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobertInspectionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobertInspectionView)
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMENUITEMMoveUniform();
	afx_msg void OnMENUITEMMoveSpecifiedPoint();
	afx_msg void OnMENUITEMMoveRotate();
	afx_msg void OnMENUITEMMapControl();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMENUITEMStop();
	afx_msg void OnMENUITEMSpecifyPath();
	afx_msg void OnMENUITEMSpecifyPathStart();
	afx_msg void OnMENUITEMSpecifyPathStop();
	afx_msg void OnMENUITEMParticleStart();
	afx_msg void OnMENUITEMParticleStop();
	afx_msg void OnMENUITEMTestParticleConcentration();
	afx_msg void OnMENUITEMCheckStart();
	afx_msg void OnMENUITEMCheckStop();
	afx_msg void OnMENUITEMInitCarPos();
	afx_msg void OnMENUITEMUAVStartCheck();
	afx_msg void OnMENUITEMUAVStopCheck();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobertInspectionView.cpp
inline CRobertInspectionDoc* CRobertInspectionView::GetDocument()
   { return (CRobertInspectionDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBERTINSPECTIONVIEW_H__77361E45_2B5D_4C4C_BCA4_FF24AC58C902__INCLUDED_)
