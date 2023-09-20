#include <stdio.h>
int main01()
{
    for(int i =1;i<8;i=i+2)
    {
        int j=(7-i)/2;
        for(int m=0;m<j;m++)
        {
            printf(" ");
        }
        for(int n=0;n<i;n++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int t =5;t>0;t=t-2)
    {
        int j=(7-t)/2;
        for(int m=0;m<j;m++)
        {
            printf(" ");
        }
        for(int n=0;n<t;n++)
        {
            printf("*");
        }
        printf("\n");
    }
	return 0;
}