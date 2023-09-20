//由键盘任意输入10个整数（有奇数也有偶数），要求输出其中的每个偶数，并输出所有偶数的平均数
/*
#include <stdio.h>
int main()
{
	int a[10];
	int sum=0;
	for(int i=0;i<10;i++)
	{
		printf("请输入第%d个整数\n",i+1);
		scanf("%d",&(a[i]));
	}
	for(int j = 0;j<10;j++)
	{
		if(a[j]%2==0)
		{
			printf("偶数为%5d",a[j]);
			sum+=a[j];
		}
	}
	printf("偶数和为%d",sum/10);
	return 0;
}
*/
//求任意一个3*4矩阵，该矩阵的元素由键盘输入将该矩阵值中最大的元素及其所在的位置输出
/*
#include <stdio.h>
int main()
{
	int a[3][4];
	for(int i=0;i<3;i++)
	{
		printf("请输入第%d行元素（3个）：\n",i+1);
		for(int j=0;j<4;j++)
		{
			scanf("%d",&(a[i][j]));
		}
		printf("\n");
	}
	printf("该矩阵数据为：\n");
	for(int m=0;m<3;m++)
	{
		for(int n=0;n<4;n++)
		{
			printf("%3d",a[m][n]);
		}
		printf("\n");
	}
	int max=0;
	int t,k;
	for(m=0;m<3;m++)
	{
		for(int n=0;n<4;n++)
		{
			if(max<a[m][n])
			{
				max=a[m][n];
				t=m;
				k=n;
			}
		}
	}
	printf("最大值为%d 其下标为行数为%d,列号为：%d",max,t+1,k+1);
	return 0;

}
*/
//输入三个整数，按从大到小的顺序输出
//未解决-查阅关于输入输出函数

#include <stdio.h>
int main()
{
	int a,b,c,temp;
	printf("请输入三个整数：\n");
	scanf("%d%d%d",a,b,c);
	if(a<b&&a<c)
	{
		if(b<c)
		{
			temp=a;
			a=c;
			c=temp;
		}else
		{
			temp=b;
			b=a;
			a=temp;
		}
		if(c>b)
		{
			temp=c;
			c=b;
			b=temp;
		}
		printf("%d>%d>%d",a,b,c);
	}
	return 0;
}
	/*
	
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a<c)
	{
		temp=a;
		a=c;
		c=temp;
	}
	if(b<c)
	{
		temp=b;
		b=c;
		c=temp;
	}
	printf("%d>%d>%d",a,b,c);
}
*/
//判定2000-2500年中的哪些年是闰年并将其输出
//闰年：能被4整除但不能被100整除
//      能被100整除且能被400整除
/*
#include <stdio.h>
int main()
{
	for(int i = 2000;i < 2501;i++)
	{
		if(((i%4==0)&&(i%100!=0))||((i%100==0)&&(i%400==0)))
		{
			printf("闰年为%d\n",i);
		}
	}
	return 0;
}
*/
//素数判断-方法将n作为被判断数，如果从2~n-1均不能将n整除即n为素数(其实只需判断2~根号n之间能不能将n整除即可)
/*
#include <stdio.h>
int main()
{
	int n,flag=0;
	printf("请输入被判断数：\n");
	scanf("%d",&n);
	for(int i = 2;i<n;i++)
	{
		if(n%i==0)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("%d为素数",n);
	}else
	{
		printf("%d不是素数",n);
	}
	
}
*/
