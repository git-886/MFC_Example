/*
#include <stdio.h>
int main()
{
	int i = 1;
	printf("%d\n%d",++i,(i++)+(i++));
	char a,b,c;
    printf("���������ַ�\n");
	scanf("%c%c",&b,&c);
	printf("%c%c",b,c);
	printf("����a=?\n");
	scanf("a=%c",&a);
	printf("���������ַ�\n");
	scanf("%c%c",&b,&c);
	printf("%c%c%c",a,b,c);
	return 0;
}
*/
/*
//�ж�����һ�����Ƿ���ˮ�ɻ�����ˮ�ɻ�������λ���������͵����������λ������
#include <stdio.h>
int main()
{
	int x,a,b,c;
	printf("������Ҫ�жϵ�ˮ�ɻ�����\n");
	scanf("%d",&x);
	a=x/100;
	b=(x-a*100)/10;
	c=(x%10);
	if(x==a*a*a+b*b*b+c*c*c)
	{
		printf("%dΪˮ�ɻ���",x);
	}
	else
	{
    	printf("%d��Ϊˮ�ɻ���",x);
	}
}
*/
//С���������� С����100�״���ÿ������󷴵�Ϊԭ����һ����룬�ʷ���ʮ�κ���ܾ���͵�ʮ�η����ľ��롣
/*
#include <stdio.h>
int main()
{
	int i;
	printf("�������ܹ�����������\n");
	scanf("%d",&i);
	float h1=100,h2=0,sumpath=0;
	for(int j=0;j<i;j++)
	{
		sumpath+=(h1+h2);
		h1=h1/2;
		h2=h1;
	}
	printf("�ܹ�����Ϊ%.2f\n",sumpath);
	printf("��%d�η�������Ϊ%.2f",i,h1);
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
