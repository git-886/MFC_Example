//�ɼ�����������10��������������Ҳ��ż������Ҫ��������е�ÿ��ż�������������ż����ƽ����
/*
#include <stdio.h>
int main()
{
	int a[10];
	int sum=0;
	for(int i=0;i<10;i++)
	{
		printf("�������%d������\n",i+1);
		scanf("%d",&(a[i]));
	}
	for(int j = 0;j<10;j++)
	{
		if(a[j]%2==0)
		{
			printf("ż��Ϊ%5d",a[j]);
			sum+=a[j];
		}
	}
	printf("ż����Ϊ%d",sum/10);
	return 0;
}
*/
//������һ��3*4���󣬸þ����Ԫ���ɼ������뽫�þ���ֵ������Ԫ�ؼ������ڵ�λ�����
/*
#include <stdio.h>
int main()
{
	int a[3][4];
	for(int i=0;i<3;i++)
	{
		printf("�������%d��Ԫ�أ�3������\n",i+1);
		for(int j=0;j<4;j++)
		{
			scanf("%d",&(a[i][j]));
		}
		printf("\n");
	}
	printf("�þ�������Ϊ��\n");
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
	printf("���ֵΪ%d ���±�Ϊ����Ϊ%d,�к�Ϊ��%d",max,t+1,k+1);
	return 0;

}
*/
//�����������������Ӵ�С��˳�����
//δ���-���Ĺ��������������

#include <stdio.h>
int main()
{
	int a,b,c,temp;
	printf("����������������\n");
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
//�ж�2000-2500���е���Щ�������겢�������
//���꣺�ܱ�4���������ܱ�100����
//      �ܱ�100�������ܱ�400����
/*
#include <stdio.h>
int main()
{
	for(int i = 2000;i < 2501;i++)
	{
		if(((i%4==0)&&(i%100!=0))||((i%100==0)&&(i%400==0)))
		{
			printf("����Ϊ%d\n",i);
		}
	}
	return 0;
}
*/
//�����ж�-������n��Ϊ���ж����������2~n-1�����ܽ�n������nΪ����(��ʵֻ���ж�2~����n֮���ܲ��ܽ�n��������)
/*
#include <stdio.h>
int main()
{
	int n,flag=0;
	printf("�����뱻�ж�����\n");
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
		printf("%dΪ����",n);
	}else
	{
		printf("%d��������",n);
	}
	
}
*/
