#include "stdio.h"
int main(){
/*****  �����д���    **********/
       int n,s,t,m=1;
       int k=2;
       s=1;     //��һ�ֵ���ۼ���
/*****  �����д���    **********/
       scanf("%d",&n);
       while(k<=n){
/*****  �����д���    **********/
              m=m*k*(-1);
              s=s+m;
              k=k+1;
       }
       printf("%d\n",s);
       return 1;
}
