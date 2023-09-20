#include <stdio.h>
int main1()
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
          printf("¼×¶Ó:%c  VS  ÒÒ¶Ó£º%c\n",J[i],Y[j]);
      }

  }
    return 0;
}