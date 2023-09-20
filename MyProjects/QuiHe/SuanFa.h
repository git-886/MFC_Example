// SuanFa.h: interface for the CSuanFa class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUANFA_H__9DE86182_7A20_48FD_9093_3053B892B61E__INCLUDED_)
#define AFX_SUANFA_H__9DE86182_7A20_48FD_9093_3053B892B61E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSuanFa  
{
public:
	int QuiHe(int a,int b);
	int QuiHe(int a,int b,int c);
	CSuanFa();
	virtual ~CSuanFa();
	int PHF();
	int PF(int a[],int n);
	int a;
	int b;

};

#endif // !defined(AFX_SUANFA_H__9DE86182_7A20_48FD_9093_3053B892B61E__INCLUDED_)
