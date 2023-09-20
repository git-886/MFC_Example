// Robot1.cpp: implementation of the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robot.h"
#include "math.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define PI 3.1415926

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRobot::CRobot()
{
	m_kx = 100;
	m_ky = -m_kx;
	ZX_y = -ZX_y;
	m_t = 0;
	m_flg = 1;
	m_jd1 = PI;
	m_jd2 = PI/6.0;
	m_jd3 = 0;
	flag = 1;
	
}

CRobot::~CRobot()
{

}

void CRobot::RobotCreate()
{
	CString sql,temp;
	//CString RobotName,eyelr,eyerr,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,ZX_x,ZX_y;

	m_Ado.OnInitADOConn(".\\Ado\\robots.mdb");
	CString x,y,m_eyelr,m_eyerr,m_mouthr,m_neckl,m_neckw,m_bodyl,m_bodyw,m_armll,m_armlw,m_armrl,m_armrw,m_legll,m_leglw,m_legrl,m_legrw,m_nosed,m_headr;
	//将int转换为CString
	x.Format(_T("%d"),ZX_x);
	y.Format(_T("%d"),ZX_y);
	//将float转换为CString
	m_eyelr.Format(_T("%.4f"),eyelr);
	m_eyerr.Format(_T("%.4f"),eyerr);
	m_mouthr.Format(_T("%.4f"),mouthr);
	m_neckl.Format(_T("%.4f"),neckl);
	m_neckw.Format(_T("%.4f"),neckw);
	m_bodyl.Format(_T("%.4f"),bodyl);
	m_bodyw.Format(_T("%.4f"),bodyw);
	m_armll.Format(_T("%.4f"),armll);
	m_armlw.Format(_T("%.4f"),armlw);
	m_armrl.Format(_T("%.4f"),armrl);
	m_armrw.Format(_T("%.4f"),armrw);
	m_legll.Format(_T("%.4f"),legll);
	m_leglw.Format(_T("%.4f"),leglw);
	m_legrl.Format(_T("%.4f"),legrl);
	m_legrw.Format(_T("%.4f"),legrw);
	m_nosed.Format(_T("%.4f"),nosed);
	m_headr.Format(_T("%.4f"),headr);
	
	sql.Format("insert into robots (RobotName,eyelr,eyerr,nosed,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,ZX_x,ZX_y) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",RobotName,m_eyelr,m_eyerr,m_nosed,m_mouthr,m_headr,m_neckl,m_neckw,m_bodyl,m_bodyw,m_armll,m_armlw,m_armrl,m_armrw,m_legll,m_leglw,m_legrl,m_legrw,x,y);

	/*
	sql.Format("insert into robots (RobotName,eyelr,eyerr,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,ZX_x,ZX_y) values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')");
    temp.Format(",RobotName,eyelr,eyerr,mouthr,headr,neckl,neckw,bodyl,bodyw,armll,armlw,armrl,armrw,legll,leglw,legrl,legrw,ZX_x,ZX_y");
	sql += temp;
	*/
	//sql.Format("insert into robots (RobotName,eyelr,eyerr,mouthr) values('%s','%s','%s','%s')",RobotName,m_eyelr,m_eyerr,m_mouthr);

	m_Ado.ExecuteSQL(sql);

	m_Ado.ExitConnect();

	AfxMessageBox("OK!");
}

void CRobot::RobotDelete(CString SelRobotName)
{
	//获取连接
	m_Ado.OnInitADOConn(".\\Ado\\robots.mdb");
	CString sql;
	try
	{
		sql.Format("delete from robots where RobotName = '%s'",SelRobotName);
		m_Ado.ExecuteSQL(sql);
		AfxMessageBox("ok!");
	}
	catch(_com_error e)
	{
		e.Description();
		AfxMessageBox("Error!");
	}
	
	m_Ado.ExitConnect();
}

void CRobot::RobotUpdate()
{
	//获取连接
	m_Ado.OnInitADOConn(".\\Ado\\robots.mdb");
	CString sql;
	CString x,y,m_eyelr,m_eyerr,m_mouthr,m_neckl,m_neckw,m_bodyl,m_bodyw,m_armll,m_armlw,m_armrl,m_armrw,m_legll,m_leglw,m_legrl,m_legrw,m_nosed,m_headr;
	//将int转换为CString
	x.Format(_T("%d"),ZX_x);
	y.Format(_T("%d"),ZX_y);
	//将float转换为CString
	m_eyelr.Format(_T("%.4f"),eyelr);
	m_eyerr.Format(_T("%.4f"),eyerr);
	m_mouthr.Format(_T("%.4f"),mouthr);
	m_neckl.Format(_T("%.4f"),neckl);
	m_neckw.Format(_T("%.4f"),neckw);
	m_bodyl.Format(_T("%.4f"),bodyl);
	m_bodyw.Format(_T("%.4f"),bodyw);
	m_armll.Format(_T("%.4f"),armll);
	m_armlw.Format(_T("%.4f"),armlw);
	m_armrl.Format(_T("%.4f"),armrl);
	m_armrw.Format(_T("%.4f"),armrw);
	m_legll.Format(_T("%.4f"),legll);
	m_leglw.Format(_T("%.4f"),leglw);
	m_legrl.Format(_T("%.4f"),legrl);
	m_legrw.Format(_T("%.4f"),legrw);
	m_nosed.Format(_T("%.4f"),nosed);
	m_headr.Format(_T("%.4f"),headr);

	sql.Format("update robots set RobotName = '%s', eyelr = '%s', eyerr = '%s',nosed = '%s', mouthr = '%s', neckl = '%s', neckw = '%s', bodyl = '%s', bodyw = '%s', armll = '%s', armlw = '%s', armrl = '%s', armrw = '%s', legll = '%s', leglw = '%s', legrl = '%s', legrw = '%s', headr = '%s' where RobotName = '%s'",
		RobotName,m_eyelr,m_eyerr,m_nosed,m_mouthr,m_neckl,m_neckw,m_bodyl,m_bodyw,m_armll,m_armlw,m_armrl,m_armrw, m_legll,m_leglw,m_legrl,m_legrw,m_headr,RobotName);

	m_Ado.ExecuteSQL(sql);
	AfxMessageBox("Update Successed!");
	//关闭连接
	m_Ado.ExitConnect();

}

void CRobot::RobotSelect()
{

}

void CRobot::Draw(CDC *p)
{
	pDC = p;
	DrawRobot();
}

void CRobot::DrawRobot()
{
	float x,y,r,d;
	CPoint point[3];
	float a,b;//椭圆的长轴和短轴
	float w,l;//矩形的长和宽

	
	
	//画头
	x = ZX_x;
	y = ZX_y + (neckl + headr)* m_ky;
	r = headr * m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//画眼睛-左
	x = ZX_x - headr/2.0 * m_kx;
	y = ZX_y + (neckl + headr * 3.0/2.0) * m_ky;
	r = eyelr * m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//画眼睛-右
	x = ZX_x + headr/2.0 * m_kx;
	y = ZX_y + (neckl + headr * 3.0/2.0) * m_ky;
	r = eyerr * m_kx;
	if(m_flg == 1 || m_flg == 2)
	{
		pDC->Ellipse(x-r,y-r,x+r,y+r);
	}else if(m_flg == 0)
	{
		pDC->Ellipse(x-r,y-r/2.0,x+r,y+r/2.0);
		m_flg = 1;
	}
	//画鼻子
	point[0].x = ZX_x;
	point[0].y = ZX_y + (neckl + headr)* m_ky + nosed * m_ky;
	point[1].x = ZX_x + (nosed * cos(PI / 6.0))*m_kx;
	point[1].y = ZX_y + (neckl + headr)* m_ky -(nosed * sin(PI / 6.0))*m_ky;
	point[2].x = ZX_x - (nosed * cos(PI / 6.0))*m_kx;
	point[2].y = ZX_y + (neckl + headr)* m_ky -(nosed * sin(PI / 6.0))*m_ky;
	pDC->Polygon(point, 3);
	//画嘴巴
	x = ZX_x;
	y = ZX_y + (neckl + headr / 2.0) * m_ky;
	r = mouthr * m_kx;
	pDC->Ellipse(x-r,y-r/2.0,x+r,y+r/2.0);
	//画脖子
	x = ZX_x - neckw / 2.0 * m_kx ;
	y = ZX_y + neckl * m_ky;
	w = neckw * m_kx;
	l = neckl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//画身体
	x = ZX_x - bodyw * m_kx / 2.0;
	y = ZX_y;
	w = bodyw * m_kx;
	l = bodyl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//画胳膊-左边
	x = ZX_x - (bodyw/2.0 + armlw) * m_kx;
	y = ZX_y;
	w = armlw * m_kx;
	l = armll * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//画胳膊-右边
	
	x = ZX_x + (bodyw/2.0) * m_kx;
	y = ZX_y;
	w = armrw * m_kx;
	l = armrl * m_kx;
	d = sqrt(w * w + l * l);
	if(m_flg == 2)
	{
		pDC->MoveTo(x,y);
		x = ZX_x + (bodyw/2.0) * m_kx - w * cos(m_jd1);
		y = ZX_y + w * sin(m_jd1);
		pDC->LineTo(x,y);
		x = ZX_x + (bodyw/2.0) * m_kx + sqrt(w * w + l * l) * sin(m_jd2);
		y = ZX_y + sqrt(w * w + l * l) * cos(m_jd2);
		pDC->LineTo(x,y);
		x = ZX_x + (bodyw/2.0) * m_kx + l * sin(m_jd3);
		y = ZX_y + l * cos(m_jd3);
		pDC->LineTo(x,y);
		x = ZX_x + (bodyw/2.0) * m_kx;
		y = ZX_y;
		pDC->LineTo(x,y);
	}else
	{
		pDC->Rectangle(x,y,x+w,y+l);
	}
	
	//pDC->Rectangle(x,y,x+w,y+l);
	//画腿-左边
	x = ZX_x - bodyw/2.0 * m_kx;
	y = ZX_y -bodyl * m_ky;
	w = leglw * m_kx;
	l = legll * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
	//画腿-右边
	x = ZX_x + (bodyw/2.0 - armrw) * m_kx;
	y = ZX_y -bodyl * m_ky;
	w = legrw * m_kx;
	l = legrl * m_kx;
	pDC->Rectangle(x,y,x+w,y+l);
}

void CRobot::RobotInit(CString m_CurRobotName)
{
	m_Ado.OnInitADOConn(".\\Ado\\robots.mdb");
	CString sql,value;
	sql.Format("select * from robots where RobotName = '%s'",m_CurRobotName);
	
	//获取记录集
	m_Ado.GetRecordSet(sql);
	if(!m_Ado.m_pRecordset->adoEOF)
	{//m_Ado.m_pRecordset->MoveNext();//移动到下一条记录
		
		
		RobotName = m_Ado.GetCollect("RobotName");
		
		value = m_Ado.GetCollect("eyelr");
		eyelr = atof(value);
		value = m_Ado.GetCollect("eyerr");
		eyerr = atof(value);
		value = m_Ado.GetCollect("nosed");
		nosed = atof(value);
		value = m_Ado.GetCollect("mouthr");
		mouthr = atof(value);
		value = m_Ado.GetCollect("headr");
		headr = atof(value);
		value = m_Ado.GetCollect("neckl");
		neckl = atof(value);
		value = m_Ado.GetCollect("neckw");
		neckw = atof(value);
		value = m_Ado.GetCollect("bodyw");
		bodyw = atof(value);
		value = m_Ado.GetCollect("bodyl");
		bodyl = atof(value);
		value = m_Ado.GetCollect("armll");
		armll = atof(value);
		value = m_Ado.GetCollect("armlw");
		armlw = atof(value);
		value = m_Ado.GetCollect("armrl");
		armrl = atof(value);
		value = m_Ado.GetCollect("armrw");
		armrw = atof(value);
		value = m_Ado.GetCollect("legll");
		legll = atof(value);
		value = m_Ado.GetCollect("leglw");
		leglw = atof(value);
		value = m_Ado.GetCollect("legrl");
		legrl = atof(value);
		value = m_Ado.GetCollect("legrw");
		legrw = atof(value);
	
		value = m_Ado.GetCollect("ZX_x");
		ZX_x = atoi(value);
		value = m_Ado.GetCollect("ZX_y");
		ZX_y = atoi(value);
	}


	m_Ado.ExitConnect();

}

void CRobot::InitCreateRobot()
{
	RobotName = "robot?";
	eyelr = 0.08;
	eyerr = 0.08;
	nosed = 0.1;
	mouthr = 0.1;
	headr = 0.4;
	neckl  = 0.2;
	neckw = 0.1;
	bodyl = 0.4;
	bodyw = 0.4;
	armll = 0.3;
	armlw = 0.2;
	armrl = 0.3;
	armrw = 0.2;
	legll = 0.4;
	leglw = 0.2;
	legrl = 0.4;
	legrw = 0.2;
	ZX_x = 300;
	ZX_y = 500;
}

void CRobot::RobotSaveToFile(CString FilePath)
{

	FILE * fp;
	if((fp = fopen(FilePath,"w")) != NULL)
	{
		fprintf(fp,"%s,%f,%f,%f",RobotName,eyelr,eyerr,mouthr);		
		fclose(fp);
	}
	else
	{
		AfxMessageBox("打开文件失败！");
	}
	
}

void CRobot::RobotMove()
{
	ZX_x = 300 * sin(m_t) + 300;
	m_t += 0.05;
	
}

void CRobot::RobotJump()
{
	ZX_y = 300 * sin(m_t) + 500;
	m_t += 0.05;
}

void CRobot::RobotWink()
{
	m_flg = 0;
}

void CRobot::RobotWaveHand()
{
	//挥挥右手
	m_flg = 2;
	
	if(m_jd1 >= PI  && flag == 0)
	{
		m_jd1 -=0.05;
		m_jd2 -=0.05;
		m_jd3 -=0.05;	
	}
	if(m_jd1 <= PI * 3/2.0 && flag == 1)
	{
		m_jd1 +=0.05;
		m_jd2 +=0.05;
		m_jd3 +=0.05;
	}
	if(m_jd1 > PI * 3/2.0)
	{
		flag = 0;
	}
	else if(m_jd1 < PI)
	{
		flag = 1;
	}
}
