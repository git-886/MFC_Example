//键盘输入一行字符，分别统计小写字母，大写字母，数字，空格，和其他字符的个数。
#include <stdio.h>
#include <string.h>
int main03()
{
	char arr[100];
	int z=0,Z=0,s=0,k=0,o=0;
	gets(arr);
	int count=strlen(arr);
	for(int i=0;i<count;i++)
	{
		if(arr[i]>='A'&&arr[i]<='z')
		{
			Z++;
		}else if(arr[i]>='a'&&arr[i]<='z')
		{
			z++;
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
	printf("大写字母个数为：%d\n",Z);
	printf("小写字母个数为：%d\n",z);
	printf("数字字符个数为：%d\n",s);
	printf("空格字符个数为：%d\n",k);
	printf("其他字符个数为：%d",o);
	return 0;
}  