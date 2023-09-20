// HuaCirTriRecView.cpp : implementation of the CHuaCirTriRecView class
//

#include "stdafx.h"
#include "HuaCirTriRec.h"

#include "HuaCirTriRecDoc.h"
#include "HuaCirTriRecView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecView

IMPLEMENT_DYNCREATE(CHuaCirTriRecView, CView)

BEGIN_MESSAGE_MAP(CHuaCirTriRecView, CView)
	//{{AFX_MSG_MAP(CHuaCirTriRecView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MENUITEMHuaY, OnMENUITEMHuaY)
	ON_COMMAND(ID_MENUITEMHuaJX, OnMENUITEMHuaJX)
	ON_COMMAND(ID_MENUITEMHuaSJX, OnMENUITEMHuaSJX)
	ON_COMMAND(ID_MENUITEMStart, OnMENUITEMStart)
	ON_COMMAND(ID_MENUITEMStop, OnMENUITEMStop)
	ON_COMMAND(ID_MENUITEMMove_BK, OnMENUITEMMoveBK)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_COMMAND(ID_MENUITEMChange_BK, OnMENUITEMChangeBK)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecView construction/destruction

CHuaCirTriRecView::CHuaCirTriRecView()
{
	// TODO: add construction code here
	m_nCir = 0;
	m_nRec = 0;
	m_nTri = 0;
	m_BJ_LBD = 0;
	PointD = NULL;
	PointU = NULL;
	PointTemp = NULL;
	m_nPic = 1;
	m_BK_x = 50;
	m_BK_y = 50;
	m_BK_w = 650;
	


}

CHuaCirTriRecView::~CHuaCirTriRecView()
{
}

BOOL CHuaCirTriRecView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecView drawing

void CHuaCirTriRecView::OnDraw(CDC* pDC)
{
	CHuaCirTriRecDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	

	    int i;
	    float x,y,r,w,h;
		float t,xd,yd,xu,yu;
		CPoint TriDraw[3];
		//画边框
		x = m_BK_x;
		y = m_BK_y;
		w = m_BK_w;
		pDC->Rectangle(x,y,x+w,y+w);
	    for(i = 0;i<m_nCir;i++)//画数组中所有的圆
		{
		   x = Cir[i].x + m_BK_x;
		   y = Cir[i].y + m_BK_y;
		   r = Cir[i].r;
		   pDC->Ellipse(x-r,y-r,x+r,y+r);
		
		}
		for(i = 0;i<m_nRec;i++)//画矩形
		{
			x = Rec[i].x + m_BK_x;
			y = Rec[i].y + m_BK_y;
			w = Rec[i].w;
			h = Rec[i].h;
			pDC->Rectangle(x,y,x+w,y+h);
		}
		for(i = 0;i<m_nTri;i++)//画三角形
		{
			int j;
			xd = Tri[i].xd;
			yd = Tri[i].yd;
			xu = Tri[i].xu;
			yu = Tri[i].yu;
			t = sqrt((xd-xu)*(xd-xu)+(yd-yu)*(yd-yu));
			TriDraw[0].x = xu;
			TriDraw[0].y = yu;
			TriDraw[1].x = xu-sqrt(3)*t;
			TriDraw[1].y = yu;
			TriDraw[2].x = xd;
			TriDraw[2].y = yd-t;
			pDC->MoveTo(TriDraw[2].x,TriDraw[2].y);
			for(j = 0;j < 3;j++)
			{
				pDC->LineTo(TriDraw[j].x,TriDraw[j].y);
			}
		}




	    

		CString strcir,strrec,strtri;
		strcir.Format("当前圆的个数：%d",m_nCir);
		strrec.Format("当前矩形个数：%d",m_nRec);
		strtri.Format("当前三角形个数：%d",m_nTri);
		pDC->TextOut(800,100,strcir);
		pDC->TextOut(800,115,strrec);
		pDC->TextOut(800,130,strtri);


		

     	
	
}

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecView printing

BOOL CHuaCirTriRecView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHuaCirTriRecView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHuaCirTriRecView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecView diagnostics

#ifdef _DEBUG
void CHuaCirTriRecView::AssertValid() const
{
	CView::AssertValid();
}

void CHuaCirTriRecView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHuaCirTriRecDoc* CHuaCirTriRecView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHuaCirTriRecDoc)));
	return (CHuaCirTriRecDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuaCirTriRecView message handlers



void CHuaCirTriRecView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_BJ_LBD = 1;
	PointD = point;
	PointTemp = point;
	CView::OnLButtonDown(nFlags, point);
}

void CHuaCirTriRecView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_BJ_LBD = 0;
	PointU = point;

	if(m_nPic == 1)//根据m_nPic来选择插入类型
	{
		InsertCircle();
	}else if(m_nPic == 2)
	{
		InsertRectangle();
	}else if(m_nPic == 3)
	{
		InsertRectangel();
	}
	Invalidate(true);
	
	CView::OnLButtonUp(nFlags, point);
}
void CHuaCirTriRecView::InsertCircle()//插入圆函数
{
	if((PointD.x != PointU.x)&&(PointU.y != PointD.y))
	{
		Cir[m_nCir].x = PointD.x - m_BK_x;
	    Cir[m_nCir].y = PointD.y - m_BK_y;
	    Cir[m_nCir].r = sqrt((PointD.x-PointU.x)*(PointD.x-PointU.x)+(PointD.y-PointU.y)*(PointD.y-PointU.y));
		Cir[m_nCir].vx = rand()%11+10;//10-20之间的随机数
		Cir[m_nCir].vy = rand()%11+10;
	    m_nCir++;
	}
	
}
void CHuaCirTriRecView::InsertRectangle()//插入矩形函数
{
	if((PointD.x != PointU.x)&&(PointU.y != PointD.y))
	{	
		Rec[m_nRec].x = PointD.x - m_BK_x;
	    Rec[m_nRec].y = PointD.y - m_BK_y;
	    Rec[m_nRec].h = abs(PointU.y - PointD.y);
	    Rec[m_nRec].w = abs(PointU.x - PointD.y);

		Rec[m_nRec].vx = rand()%11+10;
		Rec[m_nRec].vy = rand()%11+10;
	    m_nRec++;
	}


}

void CHuaCirTriRecView::InsertRectangel()//插入三角形函数
{
	if((PointD.x != PointU.x)&&(PointU.y != PointD.y))
	{
		Tri[m_nTri].xd = PointD.x;
	    Tri[m_nTri].yd = PointD.y;
	    Tri[m_nTri].xu = PointU.x;
	    Tri[m_nTri].yu = PointU.y;

		Tri[m_nTri].vx = rand()%11+10;
		Tri[m_nTri].vy = rand()%11+10;


	    m_nTri++;
	}

}

void CHuaCirTriRecView::OnMENUITEMHuaY() 
{
	// TODO: Add your command handler code here
	m_nPic = 1;//表识画圆
	
}

void CHuaCirTriRecView::OnMENUITEMHuaJX() 
{
	// TODO: Add your command handler code here
	m_nPic = 2;//标识画矩形
	
}

void CHuaCirTriRecView::OnMENUITEMHuaSJX() 
{
	// TODO: Add your command handler code here
	m_nPic = 3;//标识画三角形
	
}


void CHuaCirTriRecView::OnMENUITEMStart() //图形移动函数-开始
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);	
}

void CHuaCirTriRecView::OnMENUITEMStop() //图形停止函数-结束
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CHuaCirTriRecView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Move();
	CView::OnTimer(nIDEvent);
}

void CHuaCirTriRecView::Move()
{
	int i;
	float t = 0.1;
	for(i = 0; i <m_nCir; i++)//移动圆
	{
		Cir[i].x += Cir[i].vx*t;
		Cir[i].y += Cir[i].vy*t;
	
		if(Cir[i].x+Cir[i].r+m_BK_x > m_BK_w+m_BK_x)//撞到右边框
		{
			Cir[i].vx = -Cir[i].vx;
		}
		if(Cir[i].x-Cir[i].r+m_BK_x < m_BK_x)//撞到左边框
		{
			Cir[i].vx = -Cir[i].vx;
		}
		if(Cir[i].y+Cir[i].r+m_BK_y > m_BK_w+m_BK_y)//撞到下边框
		{
			Cir[i].vy = -Cir[i].vy;
		}
		if(Cir[i].y-Cir[i].r+m_BK_y < m_BK_y)//撞到上边框
		{
			Cir[i].vy = -Cir[i].vy;
		}
	}
	for(i = 0;i < m_nRec;i++)//移动矩形
	{
		Rec[i].x +=Rec[i].vx*t;
		Rec[i].y +=Rec[i].vy*t;
		if(Rec[i].x + Rec[i].w + m_BK_x > m_BK_w+m_BK_x)
		{
			Rec[i].vx = -Rec[i].vx;
		}
		if(Rec[i].x + m_BK_x < m_BK_x)
		{
			Rec[i].vx = -Rec[i].vx;
		}
		if(Rec[i].y + Rec[i].h + m_BK_y > m_BK_w+m_BK_y)
		{
			Rec[i].vy = -Rec[i].vy;
		}
		if(Rec[i].y + m_BK_y< m_BK_y)
		{
			Rec[i].vy = -Rec[i].vy;
		}
	}
	for(i = 0;i < m_nTri;i++)//移动三角形
	{
		
		Tri[i].xd +=Tri[i].vx*t;
		Tri[i].xu +=Tri[i].vx*t;
		Tri[i].yd +=Tri[i].vy*t;
		Tri[i].yu +=Tri[i].vy*t;

		if(Tri[i].xd > m_BK_w+m_BK_x)
		{
			Tri[i].vx =-Tri[i].vx;//反弹至反方向
		    Tri[i].vy =-Tri[i].vy;
		}
		if(Tri[i].xd < m_BK_x)
		{
			Tri[i].vx =-Tri[i].vx;
		    Tri[i].vy =-Tri[i].vy;
		}
		if(Tri[i].yd > m_BK_y+m_BK_w)
		{
			Tri[i].vx =-Tri[i].vx;
		    Tri[i].vy =-Tri[i].vy;
		}
		if(Tri[i].yd < m_BK_y)
		{
			Tri[i].vx =-Tri[i].vx;
		    Tri[i].vy =-Tri[i].vy;
		}
	}
	Invalidate(true);
}

void CHuaCirTriRecView::OnMENUITEMMoveBK() //边框移动函数
{
	// TODO: Add your command handler code here
	m_nPic = 0;
	
	
}

void CHuaCirTriRecView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if((m_nPic == 0)&&(m_BJ_LBD == 1))
	{
		 m_BK_x = PointTemp.x + point.x - PointD.x;
		 m_BK_y = PointTemp.y + point.y - PointD.y;

		 Invalidate(true);
	}
	
	CView::OnMouseMove(nFlags, point);
}

BOOL CHuaCirTriRecView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_nPic == 0)
	{
		if(zDelta > 0)
			m_BK_w += 0.1*m_BK_w;
		if(zDelta < 0)
			m_BK_w -= 0.1*m_BK_w;
	}
	Invalidate(true);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CHuaCirTriRecView::OnMENUITEMChangeBK() 
{
	m_nPic = 0;
	// TODO: Add your command handler code here
	
}
