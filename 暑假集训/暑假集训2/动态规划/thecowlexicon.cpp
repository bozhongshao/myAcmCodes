#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int _dp[305];
char _str[305];
char _index[601][30];
int nen[601];

int main()
{
	int _W,n,i,j,k,l,_temp;
	scanf("%d%d",&_W,&n);
   //while (scanf("%d%d",&_W,&n)!=EOF)
   {
	   getchar();
	   gets(_str);
	   //scanf("%s",_str);
	   for (i=0;i<n;++i)
	   {
		   _dp[i]=i+1;//��ֵ
	   }
       for (i=0;i<_W;++i)
       {
		   gets(_index[i]);//����
		   //scanf("%s",_index[i]);
		   nen[i]=(int)strlen(_index[i]);//nenƥ���ϵĸ��� ��Ȼ���ǵ��ʵĳ���
	   }

	   for (i=0;i<n-1;++i)
	   {
		   for (j=0;j<_W;++j)
		   {
			   
			   if ((n-i+1)<nen[j]) continue;
			   for (k=i,l=0;k<n&&l<nen[j];++k,++l)//ƥ�����
			   {
                   if (_str[k]!=_index[j][l])  --l; 
			   }
			   if (l<nen[j]) continue;//ƥ�䵽���Ҳ���ܰ������ڽ���ƥ��ĵ���
			   if (i==0) _temp=k-nen[j];//����_temp�������һ��dp[k-1]��ֵ
			   else _temp=_dp[i-1]+k-i-nen[j];//������Ƕ�̬����
			   if (_dp[k-1]>_temp) _dp[k-1]=_temp;
		   }
		   if (_dp[i+1]>_dp[i]+1) _dp[i+1]=_dp[i]+1;//��һ��λ�ò�������ôֻ��+1 �õ�ֵ
	   }
	   printf("%d\n",_dp[n-1]);
   }
	return 0;
}
