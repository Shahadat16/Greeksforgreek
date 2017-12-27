#include<stdio.h>
#include<math.h>
int main()
{
    int l,b,p,ba,TC,r,pi,ar,rt,ai;
    scanf("%d",&TC);
    while(TC--)
    {
      pi=3.14;
      scanf("%d %d %d %d %d",&l,&b,&p,&ba,&r);
      ar=l*b;
      rt=0.5*p*ba;
      ai=pi*r*r;
      printf("%d %d %d\n",ar,rt,ai);
    }
    return 0;
}


