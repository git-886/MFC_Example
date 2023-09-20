/*
//°¸ÀýÒ»
#include<stdio.h>
class CSuanFa
{
public:
	int a,b;
	int QuiHe()
	{
		return a+b;
	}
	int PFH()
	{
		return a*a+b*b;
	}
};
void main()
{
	int he,pfh;
	CSuanFa sf1,sf2;
	sf1.a=10;
	sf1.b=20;

	sf2.a=50;
	sf2.a=60;
	he = sf1.QuiHe();
	sf1.a=30;
	sf1.b=40;

	pfh = sf1.PFH();
	he = sf1.QuiHe();
	printf("%d %d\n",he,pfh);
}
*/