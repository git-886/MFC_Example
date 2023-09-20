#if !defined(AFX_WZQGAME_H__9A3234D3_2716_4993_9028_42E730749D0D__INCLUDED_)
#define AFX_WZQGAME_H__9A3234D3_2716_4993_9028_42E730749D0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WZQGame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWZQGame window

class CWZQGame : public CWnd
{
// Construction
public:
	CWZQGame();

// Attributes
public:
	CDC *pDC;//
	int m_QiPan[19][19];//棋盘二维数组
	int m_row,m_colume;//标识当前下棋位置的棋盘行和列
	int m_Color;//标识画什么颜色的棋子
	int m_size;//棋盘单个区域规格
	int m_QP_x,m_QP_y;//棋盘左上角坐标
	CPoint point;//下棋位置



// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWZQGame)
	//}}AFX_VIRTUAL

// Implementation
public:
	int PanDuan();
	void XQ(CPoint p);
	void Hua(CDC *p);
	void HuaQZ();
	void DrawQP();
	void DrawXW();
	void DrawQPBackground();
	virtual ~CWZQGame();

	// Generated message map functions
protected:
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZQGAME_H__9A3234D3_2716_4993_9028_42E730749D0D__INCLUDED_)
