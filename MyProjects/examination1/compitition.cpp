//比赛
/*
#include <stdio.h>
int main()
{
  char J[3]={'A','B','C'};
  char Y[3]={'X','Y','Z'};
  for(int i=0;i<3;i++)
  {
      for(int j = 0;j<3;j++)
      {
          if(J[i]=='A'&&Y[j]=='X')
              continue;
          if(J[i]=='C'&&(Y[j]=='X'||Y[j]=='Z'))
          {
              continue;
          }
          printf("甲队:%c  VS  乙队：%c\n",J[i],Y[j]);
      }

  }
    return 0;
}
*/
//键盘输入一行字符，分别统计小写字母，大写字母，数字，空格，和其他字符的个数。
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[100];
	int t=0,z=0,s=0,k=0,o=0;
	gets(arr);
	int count=strlen(arr);
	for(int i=0;i<count;i++)
	{
		if(arr[i]>='A'&&arr[i]<='Z')
		{o
			z++;
		}else if(arr[i]>='a'&&arr[i]<='z')
		{
			t++;
		}else if(arr[i]>='0'&&arr[i]<='9')
		{
			s++;
		}else if(arr[i]==' ')
		{
			k++;
		}else
		{
			o++;
		}
	}
	printf("大写字母个数为：%d\n",z);
	printf("小写字母个数为：%d\n",t);
	printf("数字字符个数为：%d\n",s);
	printf("空格字符个数为：%d\n",k);
	printf("其他字符个数为：%d",o);
	return 0;
}  
*/
//某班期末考试由数学、英语、计算机，最多不超过30人参加，计算并输出每个学生的总分和平均分
//法一结构体
/*
#include <stdio.h>
struct studentscore
{
	float math;
	float english;
	float computer;
};
int main()
{
	struct studentscore st[30];
	int count;
	printf("请输入学生个数(不大于30)：\n");
	scanf("%d",&count);//输入学生个数
	for(int i = 0;i<count;i++)
	{
		printf("请输入学生%d数学成绩：\n",i+1);
		scanf("%f",&(st[count].math));
		printf("请输入学生%d英语成绩：\n",i+1);
		scanf("%f",&(st[count].english));
		printf("请输入学生%d计算机成绩：\n",i+1);
		scanf("%f",&(st[count].computer));
	}
	for(int j=0;j<count;j++)
	{
		float sum=(float)((st[j].math)+(st[j].english)+(st[j].computer));
		float level =(float)sum/3;
		printf("学生%d的总分为%f 平均分为：%f",j+1,sum,level);
	}
	return 0;
}
*/
//法二-数组-一维数组 数组-二维数组
/*
#include <stdio.h>
int main()
{
	int a[30],b[30],c[30],s[30],count;//a数学成绩 b英语成绩 d计算机成绩 s学生编号
	printf("数学个数（不大于30）：\n");
	scanf("%d",&count);
	for(int i=0;i<count;i++)
	{
		printf("数学成绩为:\n");
		scanf("%d",&a[i]);
		printf("英语成绩为:\n");
		scanf("%d",&b[i]);
		printf("计算机成绩为:\n");
		scanf("%d",&c[i]);
	}
	for(int j = 0;j<count;j++)
	{
		int sum = a[j]+b[j]+c[j];
		int level = sum/3;
		printf("学生%d\n数学成绩为：%3d英语成绩为：%3d计算机成绩为：%3d",j+1,a[j],b[j],c[j]);
		printf("\n");
		printf("总分为：%d 平均分为：%d",sum,level);
	}

}
*/
//输入三个数，按从小到大的顺序输出
/*
#include <stdio.h>
int main()
{
	float a,b,c,temp;
	printf("请输入三个数\n");
	scanf("%f%f%f",&a,&b,&c);
    printf("%-5f\n%-5f\n%-5f\n",a,b,c);
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c)
	{
		temp=a;
		a=c;
		c=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}
	printf("%-5.2f%-5.1f%-5.1f",a,b,c);
	return 0;
	
}
*/
//输入年份和月份，返回当月有多少天
/*
#include <stdio.h>
int main()
{
	int year,month,day;
	printf("请输入年份和月份：\n");
	scanf("%d%d",&year,&month);
	switch(month)
	{
	case 1:
    case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		 printf("sum of day:31");
		 break;
	case 4:
	case 6:
	case 9:
	case 11:
		 printf("sum of day:30");
		 break;
	case 2:
		 if((year%4==0)&&(year%100!=0)||year%400==0)
		 {
			 printf("sum of day:29");
		 }else
		 {
			 printf("sum of day:28");
		 }
		 break;
	default:
		printf("input is error!");
	}
}
*/
//打印十行杨辉三角
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int a[10][10];
	for(int i = 0;i<10;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for(int j=2;j<10;j++)
	{
		for(int k = 1;k<j;k++)
		{
			a[j][k]=a[j-1][k-1]+a[j-1][k];
		}
	}
	for(int m = 0;m<10;m++)
	{
		for(int n = 0;n<=m;n++)
		{
			printf("%5d",a[m][n]);
		}
		printf("\n");
	}
	return 0;
}
*/
//创建链表储存学生信息，并输入学生信息后打印到控制台
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
	char name[10];
	int no;
	int age;
	struct student *next;
}Stu;
Stu * insert(char name[],int no,int age)
{
	Stu *p = (Stu *)malloc(sizeof(Stu));
	if(p==NULL)
	{
		printf("申请空间失败！");
		return p;
	}
	strcpy(p->name,name);
	p->no=no;
	p->age=age;
	return p;

}
int main()
{
	Stu *head,*p;
	head = (Stu *)malloc(sizeof(Stu));
	if(head==NULL)
	{
		printf("申请头结点失败！");
		return 0;
	}
	p=head;
	int n;
	printf("请输入添加学生人数:");
	scanf("%d",&n);
	int i=n;
	while(i--)
	{
		char name[10];
		int no;
		int age;
		printf("请输入学生信息 姓名-学号-年龄\n");
		scanf("%s%d%d",name,&no,&age);
		Stu * s=insert(name,no,age);
		p->next=s;
		p=s;
		s->next=NULL;
	}
	Stu * q = head->next;
	while(q!=NULL)
	{
		printf("%s%d%d\n",q->name,q->no,q->age);
		q=q->next;
	}
	return 1;
}
*/

//将共n个的数字后m个移动到最前面
/*
#include<stdio.h>
int main()
{
	int n,m;
	int i,j;
	printf("请输入n：\n");
	scanf("%d",&n);
	printf("请输入m：\n");
	scanf("%d",&m);
	int a[20];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("移动前：\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	/*
	for(i=n-1;i>=0;i--)
	{
		a[i+m]=a[i];
	}
	for(i=0;i<m;i++)
	{
		a[m-i-1]=a[n+m-1-i];
	}
	*/
/*
	for(i=0;i<n-m;i++)
	{
		int temp;
		temp=a[0];
		for(j=0;j<n-1;j++)
		{
			a[j]=a[j+1];
		}
		a[n-1]=temp;
	}
	printf("\n");
	printf("排序后\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return ;
}
*/
//卖西瓜
/*
#include<stdio.h>
int main()
{
	int d,s=4;
	for(d=0;s>0;d++)
	{
		s=s/2-2;
	}
	printf("%d",d);
	return 1;
}
*/
//分解质因数eg:90=2*3*3*5
/*
#include<stdio.h>
int main()
{
	int n,count=0,i=2;
	printf("请输入待分解的数\n");
	scanf("%d",&n);
	int t=n;
	while(n!=1)
	{
		while(n % i == 0)
		{
			count++;
			n=n/i;
			if(count==1)
			{
				printf("%d=%d",t,i);
			}else{
				printf("*%d",i);
			}
		}
		i++;
	}
}
*/
//主串str1中子串str2的个数
/*
#include<stdio.h>
#include<string.h>
实现判断子串方法一
int substring(char *str1,char *str2)
	{
	int sum = 0;
	char *p1,*p2;
	p1=str1;
	p2=str2;
	while(*p1!='\0')
	{
		char *temp=p1;
		if(*p1==*p2)
		{
			while((*p1==*p2)&&(*p2!='\0'))
			{
				p1++;
				p2++;
			}
		}
		if(*p2=='\0')
		{
			sum++;
		}
		p1=temp+1;
		p2=str2;
	}
	return sum;
	}
	*/
/*实现方式二
int substring(char *str1,char *str2)
{
	int count=0,i,j;
	for(i=0;i<strlen(str1);i++)
	{
		for(j=0;j<strlen(str2);j++)
		{
			if(str1[i+j]!=str2[j])
			{
				break;
			}
		}
		if(j==strlen(str2))
			{
				count++;
			}
	}
	return count;

}
*/
/*
int main()
{
	char str1[30],str2[30];
	gets(str1);
	gets(str2);
	printf("字串个数为%d",substring(str1,str2));
	return 1;
}*/
//输入十个数对其进行排序从小到大，并将排序前后的结果打印到控制台，将排序后的结果写入到C:\\file.txt文件中
/*
#include<stdio.h>
#include<stdlib.h>
void sort(int num[],int n)
{
	int i,j,temp,k;
    //冒泡排序
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}

	/*简单选择排序
	for(i=0;i<n-1;i++)
	{
		k = i;
		for(j=i+1;j<n;j++)
		{
			if(num[k]>num[j])
			{
				k=j;
			}
		}
		if(k!=i)
			{
				temp=num[k];
				num[k]=num[i];
				num[i]=temp;
			}
	}
	
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
}
int main()
{
	int num[10]={10,1,56,8,5,101,103,1,2,4};
    int i;
	/*for(i=0;i<10;i++)
	{
		printf("请输入第%d个数\n",i+1);
		scanf("%d",&num[i]);
	}
	print(num,10);
	sort(num,10);
	print(num,10);
	FILE *fp;
	if((fp=fopen("C:\\file.txt","w"))==NULL)
	{
		printf("open file defeat!!");
		exit(0);
	}
	int k = 0;
	while(k!=10)
	{
		fprintf(fp,"%5d",num[k++]);
	}
	fclose(fp);
	return 1;

}
*/
//验证scanf()输入函数
/*
#include<stdio.h>
int main()
{
	char a,b,c;
	int d,e,f;
	scanf("%c %c %c",&a,&b,&c);
	printf("a=%c,b=%c,c=%c",a,b,c);
	printf("\n");
	scanf("%d%d%d",&d,&e,&f);
	printf("d=%d,e=%d,f=%d",d,e,f);

	return 1;
}
*/
//求两个数的最小公倍数
/*#include<stdio.h>
int main()
{
	int x,y,i,temp;
	printf("请输入x:");
	scanf("%d",&x);
	printf("请输入y:");
	scanf("%d",&y);
	if(x<y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	for(i=x;;i++)
	{
		if((i%x==0)&&(i%y==0))
		{
			printf("最小公倍数为:%d\n",i);
			break;
		}
	}
	return 1;
}
*/
//求两个数的最大公倍数与最小公约数
/*
#include<stdio.h>
int main()
{
	int x,y,a,b,i,temp;
	printf("请输入x:");
	scanf("%d",&x);
	printf("请输入y:");
	scanf("%d",&y);
	a=x;
	b=y;
	if(x<y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	i = x%y;
	while(i)
	{
		x=y;
		y=i;
		i=x%y;
	}
	printf("最大公倍数为:%d,最小公约数为:%d\n",y,(a*b)/y);
}
*/
//验证
/*#include<stdio.h>
#include<string.h>
int main()
{
	char a[20]="ab",b[20]="LMNP";
	int i =0;
	strcat(a,b);
	puts(a);
	while(a[i++]!='\0')b[i]=a[i];
	puts(b);
	return 1;
}
*/
//结果
/*注意i++了
abLMNP
LbLMNP
*/
//验证
#include<stdio.h>
int main()
{
	char a1[5],a2[5],a3[5],a4[5];
	scanf("%s%s",a1,a2);
	gets(a3);
	gets(a4);
	puts(a1);
	printf("a1 is over");
	puts(a2);
	printf("a2 is over");
	puts(a3);
	printf("a3 is over");
	puts(a4);
	printf("a4 is over");
	return 1;
}

