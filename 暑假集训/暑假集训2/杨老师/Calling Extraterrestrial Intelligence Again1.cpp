#include<iostream>
using namespace std;
#define MAX 10001
bool p[MAX];
int ps[MAX];
int count1;

void Prime()
{
	int i,j;

	memset(p,true,sizeof(p));
	p[0]=false;
	p[1]=false;
	
	for(i=2;i*i<MAX;++i)
	{
		if (p[i])
		{
			for(j=i+i;j<MAX;j+=i)
			{
				p[j]=false;
			}
		}
	}
    count1=0;
	for(i=2;i<MAX;++i)
	{
		if (p[i]) {ps[count1++]=i;}
	}
}
int main()
{
	int m,a,b;
	double rate; 
	int p,q;//�Ƕ�Ӧ��Ŀ���������±�
	int resp,resq;
	int max1;
	Prime();
	while(cin>>m>>a>>b,m!=0||a!=0||b!=0)
	{	
		rate=double(a)/b;
		max1=0;
		for(p=count1-1;p>=0;--p)
		{
			for(q=p;q<count1;++q)//�ܷ��Ϊ�Ӵ�С  ���Ǵ�С ��Ȼ����ֱ�ӹ��˵��˻�С��max1��pֵ�����  �������жϲ���ֱ������ ����Ҫȫ���� 
			{
				if (ps[p]*ps[q]>m || (double)ps[p]/ps[q]<rate ) break;
				if (max1<ps[p]*ps[q])
				{
					max1=ps[p]*ps[q];
					resp=ps[p];
					resq=ps[q];
				}
			}
		}
		cout<<resp<<" "<<resq<<endl;
	}
	return 0;
}