#include<stdio.h>
int main()
{ 
int i,j,n,f[21][191];
//f[i][j]��ʾi����ʱ���Ƿ��ܲ���j����㣬�ܣ�����1�����ܣ�����0
for(i=0;i<21;i++)
for(j=0;j<191;j++)
   f[i][j]=(j==0);
//f[i][0]����1
for(n=2;n<21;n++)
   for(i=n-1;i>=1;i--)
    for(j=0;j<191;j++)
     if(f[n-i][j]==1)
      f[n][j+(n-i)*i]=1;
     //���f[n][x]==1
     //f[n][x+((n-i)*i)]=1
     while(scanf("%d",&n)!=EOF)
     {
      printf("0");
      for(j=1;j<=n*(n-1)/2;j++)
       if(f[n][j])
        printf(" %d",j);
       printf("\n");
     }
return 0;
}
