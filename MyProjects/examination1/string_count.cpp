//��������һ���ַ����ֱ�ͳ��Сд��ĸ����д��ĸ�����֣��ո񣬺������ַ��ĸ�����
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
	printf("��д��ĸ����Ϊ��%d\n",Z);
	printf("Сд��ĸ����Ϊ��%d\n",z);
	printf("�����ַ�����Ϊ��%d\n",s);
	printf("�ո��ַ�����Ϊ��%d\n",k);
	printf("�����ַ�����Ϊ��%d",o);
	return 0;
}  