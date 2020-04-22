#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  int ax,ay,bx,by,cx,cy,dx,dy;
  int A;
  scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
  dx=ax-bx+cx;
  dy=ay-by+cy;
  A=abs((ax*by-ay*bx)+(bx*cy-by*cx)+(cx*dy-dx*cy)+(dx*ay-dy*ax)) ;
  printf("Case %d: %d %d %d\n",i,dx,dy,A/2);
  }
  return 0;
    }