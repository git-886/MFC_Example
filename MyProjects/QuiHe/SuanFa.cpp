// SuanFa.cpp: implementation of the CSuanFa class.
//
//////////////////////////////////////////////////////////////////////

#include "SuanFa.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSuanFa::CSuanFa()
{

}

CSuanFa::~CSuanFa()
{

}

int CSuanFa::QuiHe(int a,int b)
{
    return a+b;
}
int CSuanFa::QuiHe(int a,int b,int c)
{
	return a+b+c;
}
int CSuanFa::PHF()
{
	return a*a+b*b;
}
int CSuanFa::PF(int a[],int n) //求数组平方函数
{
	int sum = 0;
	int i;
	for(i=0;i<n;i++)
	{
		sum+=a[i]*a[i];
	}
	return sum;
}




/*1.3
int main()
{
	CSuanFa sf;
	int a[20];
	int n,i;
	printf("请输入共多少数：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个数：\n",i+1);
		scanf("%d",&a[i]);
	}
	printf("%d",sf.PF(a,n));
	return 1;
}
*/
/*
//多态
int main()
{
	int h2,h3;
	CSuanFa sf;
	h2 = sf.QuiHe(2,3);
	h3 = sf.QuiHe(2,3,4);
	printf("%d,%d\n",h2,h3);
}
*/
class student
{
public:
	int Sno;
	int Age;
	int ChengJi[3];
public:
	float PingJunChengJi()
	{
		return (ChengJi[0]+ChengJi[1]+ChengJi[2])/3.0;
	}
};
class YanJinSheng:public student
{
public :
	char YanJiuFangXiang[20];
};
void main()
{
	YanJinSheng jj;
	jj.ChengJi[0] = 80;
	jj.ChengJi[1] = 90;
	jj.ChengJi[2] = 100;
	printf("%f\n",jj.PingJunChengJi());
}
