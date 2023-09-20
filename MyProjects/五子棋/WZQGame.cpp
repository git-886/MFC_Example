// WZQGame.cpp : implementation file
//

#include "stdafx.h"
#include "������.h"
#include "WZQGame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWZQGame

CWZQGame::CWZQGame()
{
	int i,j;
	m_size = 30;
	m_QP_x = 350;
	m_QP_y = 90;
	m_row = 0;
	m_colume = 0;
	m_Color = 1;//�Ȱ���
	for(i = 0; i < 19; i++)
	{
		for(j = 0; j < 19; j++)
		{
			m_QiPan[i][j] = 0;
		}
	}
	point = NULL;

}

CWZQGame::~CWZQGame()
{
}


BEGIN_MESSAGE_MAP(CWZQGame, CWnd)
	//{{AFX_MSG_MAP(CWZQGame)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWZQGame message handlers

void CWZQGame::DrawQPBackground()
{
	/*
	CBrush brush1,*bru1;
	brush1.CreateSolidBrush(RGB(255,0,0));
	bru1 = pDC->SelectObject(&brush1);
	pDC->Rectangle(0,0,1920,960);
	brush1.DeleteObject();
	pDC->SelectObject(bru1);
	*/
	int x,y,r;
	x = m_QP_x;
	y = m_QP_y;
	r = 18 * m_size;

	CBrush brush2,*bru2;
	brush2.CreateSolidBrush(RGB(244,164,96));
	bru2 = pDC->SelectObject(&brush2);
	pDC->Rectangle(x,y,x+r,y+r);
	brush2.DeleteObject();
	pDC->SelectObject(bru2);

}

void CWZQGame::DrawXW()
{
	int x,y,r;
	int i,j;
	for(i = 4 ; i <19 ; i+=5)
	{
		for(j = 4 ; j < 19 ; j+=5)
		{			
			x = m_QP_x + i * m_size;
			y = m_QP_y + j * m_size;
			r = m_size/6;
			CBrush brush,*bru;
			brush.CreateSolidBrush(RGB(0,0,0));
			bru = pDC->SelectObject(&brush);
			pDC->Ellipse(x - r,y - r,x + r,y + r);
			brush.DeleteObject();
			pDC->SelectObject(bru);
		}
	}
}

void CWZQGame::DrawQP()
{
	int x,y,i;
	for(i = 0; i < 19 ; i++)
	{
		x = m_QP_x;
		y = m_QP_y + i * m_size;
		pDC->MoveTo(x,y);

		x += 18 * m_size;
		pDC->LineTo(x,y);//����

		x = m_QP_x + i * m_size;
		y = m_QP_y;
		pDC->MoveTo(x,y);

		y += 18 * m_size;
		pDC->LineTo(x,y);//����

	}
}

void CWZQGame::HuaQZ()
{
	int i,j;
	int x,y;
	int r = m_size/3;
	for(i = 0 ; i < 19 ; i++)
	{
		for(j = 0 ; j < 19 ; j++)
		{
			if(m_QiPan[i][j] != 0)//Ϊ0˵��Ҫ������
			{
				if(m_QiPan[i][j] == -1)//˵���Ǻ�ɫ����
				{
					CBrush brush,*bru_Black;
					brush.CreateSolidBrush(RGB(0,0,0));
					bru_Black = pDC->SelectObject(&brush);
					x = m_QP_x + j * m_size;
					y = m_QP_y + i * m_size;
					pDC->Ellipse(x - r,y - r,x + r,y + r);
					brush.DeleteObject();
					pDC->SelectObject(bru_Black);
				}
				if(m_QiPan[i][j] == 1)//˵���ǰ�ɫ����
				{
					CBrush brush,*bru_White;
					brush.CreateSolidBrush(RGB(255,255,255));
					bru_White = pDC->SelectObject(&brush);
					x = m_QP_x + j * m_size;
					y = m_QP_y + i * m_size;
					pDC->Ellipse(x - r,y - r,x + r,y + r);
					brush.DeleteObject();
					pDC->SelectObject(bru_White);
				}
			}
		}
	}
}

void CWZQGame::Hua(CDC *p)
{
	pDC = p;
	DrawQPBackground();
	DrawQP();
	DrawXW();
	HuaQZ();
}

void CWZQGame::XQ(CPoint p)
{
	point = p;
	int r = m_size/3;//���Ӱ뾶
	int x = point.x;//�����x����
	int y = point.y;//�����y����
	int i,j;
	if(((x > m_QP_x) && (x < (m_QP_x +18 * m_size))) && (((y > m_QP_y) && (y < (m_QP_y +18 * m_size)))))
	{
		m_row = (y - m_QP_y)/m_size;//��ȡ����λ�õĵ�ǰ��
		m_colume = (x - m_QP_x)/m_size;//��ȡ����λ�õĵ�ǰ��
		i = m_row;
		j = m_colume;
	}
	if(m_QiPan[i][j] == 0 && m_Color == -1)
	{
		m_QiPan[i][j] = -1;//����Ϊ-1����ʾ������
		PanDuan();
		m_Color = 1;//��������
	}else if(m_QiPan[i][j] == 0 && m_Color == 1)
	{
		m_QiPan[i][j] = 1;//����Ϊ1,��ʾ������
		PanDuan();
		m_Color = -1;//��������
	}
}

int CWZQGame::PanDuan()
{
	int k;
	int i = m_row;
	int j = m_colume;
	/*************************************/
	int left = 0,right = 0;
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i][j - k] == -m_Color)//�����Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			right++;
		}
		else
			break;
	}
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i][j + k] == -m_Color)//�����Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			left++;
		}
		else
			break;
	}

	/**************************************/
	int up = 0,down = 0;
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i - k][j] == -m_Color)//�����Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			up++;
		}
		else
			break;
	}
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i + k][j] == -m_Color)//�����Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			down++;
		}
		else
			break;
	}

	/**************************************/

	int left_up = 0,right_down = 0;
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i - k][j - k] == -m_Color)//�������Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			left_up++;
		}
		else
			break;
	}
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i + k][j + k] == -m_Color)//�������Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			right_down++;
		}
		else
			break;
	}

	/**************************************/
	int right_up = 0,left_down = 0;
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i - k][j + k] == -m_Color)//�������Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			right_up++;
		}
		else
			break;
	}
	for(k = 1 ; k < 5 ; k++)
	{
		if(m_QiPan[i + k][j - k] == -m_Color)//�������Һ͵�ǰ�ո��µ�����һ������ɫ�����Ӹ���
		{
			left_down++;
		}
		else
			break;
	}
	//�����ж�
	if(left + right >=4 || up + down >=4 || left_up + right_down >=4 || left_down + right_up >=4)
	{
		if(m_Color == -1)
		{
			return -1;
		}
		if(m_Color == 1)
		{
			return 1;
		}
	}
	return 0;
}


