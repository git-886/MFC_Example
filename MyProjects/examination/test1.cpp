/*
#include <stdio.h>
int main()
{
	int i = 1;
	printf("%d\n%d",++i,(i++)+(i++));
	char a,b,c;
    printf("输入两个字符\n");
	scanf("%c%c",&b,&c);
	printf("%c%c",b,c);
	printf("输入a=?\n");
	scanf("a=%c",&a);
	printf("输入两个字符\n");
	scanf("%c%c",&b,&c);
	printf("%c%c%c",a,b,c);
	return 0;
}
*/
/*
//判断输入一个数是否是水仙花数（水仙花数即各位数字立方和等于自身的三位整数）
#include <stdio.h>
int main()
{
	int x,a,b,c;
	printf("请输入要判断的水仙花数：\n");
	scanf("%d",&x);
	a=x/100;
	b=(x-a*100)/10;
	c=(x%10);
	if(x==a*a*a+b*b*b+c*c*c)
	{
		printf("%d为水仙花数",x);
	}
	else
	{
    	printf("%d不为水仙花数",x);
	}
}
*/
//小球下落问题 小球处于100米处，每次下落后反弹为原来的一半距离，问翻弹十次后的总距离和第十次反弹的距离。
/*
#include <stdio.h>
int main()
{
	int i;
	printf("请输入总共反弹次数：\n");
	scanf("%d",&i);
	float h1=100,h2=0,sumpath=0;
	for(int j=0;j<i;j++)
	{
		sumpath+=(h1+h2);
		h1=h1/2;
		h2=h1;
	}
	printf("总共距离为%.2f\n",sumpath);
	printf("第%d次反弹距离为%.2f",i,h1);
	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#define N 5
void sort(int a[],int n)
{
	int i,j,temp;
	for(i =1;i<n;i++)
	{
		for(j = 0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void main()
{
	int n,a[N],i,j;
	FILE *fp;
	printf("\nplease input N numbers:\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<N;j++)
	{
		printf("%d",a[j]);
	}
	sort(a,N);
	if((fp=fopen("C:\\fl.txt","w"))==NULL)
	{
		exit(0);
	}
	for(i = 0;i<N;i++)
	{
		fprintf(fp,"%3d",a[i]);
	}
	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(0);
	}
}
