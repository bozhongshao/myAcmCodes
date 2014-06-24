#include<iostream>
using namespace std;
#define  Max 6000
int n,m,w;
int a,b,t;
int d[502];
int ct;
struct edge
{
	int u,v,d;
}e[Max];
bool bellman_ford()
{
	for(int i=1;i<=n;i++)//��ʼ�����е�
		d[i]=999999;
	d[1]=0;
	for(int i=1;i<=n-1;i++)//����ѭ����ѭ���±�Ϊ��1��n��1
	{
		int ok=1; 
		//����;�����еı�
		for(int j=0;j<ct;j++)             //�������j��forѭ��û�С��ɳڡ����Ļ�
		{                                 //�Ͳ���Ҫ������һ��i��forѭ����   
			if(d[e[j].v]>d[e[j].u]+e[j].d)//��Ϊ�Ժ���Ҳ�����ɳ��ˣ�������ۿ��Եõ�֤��
			{
				d[e[j].v]=d[e[j].u]+e[j].d;
				ok=0;
			}
		}
		if(ok)
			break;                       
	}
	for(int i=0;i<ct;i++)// ���и���
	{
		if(d[e[i].v]>d[e[i].u]+e[i].d)
			return 1;
	}
	return 0;
}
int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		ct=0;
		cin>>n>>m>>w;
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b>>t;
			e[ct].u=a;
			e[ct].v=b;
			e[ct].d=t;
			ct++;
			e[ct].u=b;
			e[ct].v=a;
			e[ct].d=t;
			ct++;
		}
		for(int j=1;j<=w;j++)
		{
			cin>>a>>b>>t;
			e[ct].u=a;
			e[ct].v=b;
			e[ct].d=-t;
			ct++;
		}
		bool ans=bellman_ford();
		if(ans)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
