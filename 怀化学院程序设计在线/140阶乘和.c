#include "stdio.h"
int main(){
/*****  �����д���    **********/
       int n,s=0,t=1;
       int k=1;
       scanf("%d",&n);
/*****  �����д���    **********/
       while(k<=n){
              t=t*k;
              s=s+t;
/*****  �����д���    **********/
              k=k+1;
       }
       printf("%d\n",s);
       return 1;
}
