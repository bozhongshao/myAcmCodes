#include "stdio.h"
/****** �����д���    ********/
void f_sum(int *x,int *y,int *z){
       int temp;
       *z=*x+*y;
/******    �����д���   *******/
       if(*x>*y)    {
              temp=*x;
              *x=*y;
              *y=temp;
       }
}
 
int main(){
       int n,i;
       int a,b,sum=0;
       scanf("%d",&n);
       for(i=1;i<=n;i++)    {
              scanf("%d %d",&a,&b);
/****** �����д���    ********/
              f_sum(&a,&b,&sum);
              printf("%d %d %d\n",a,b,sum);
       }
       return 1;
}
