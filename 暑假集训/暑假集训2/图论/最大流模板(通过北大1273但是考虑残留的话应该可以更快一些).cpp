#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000

struct Node
{
	int la;
	struct Node *next;
};
int map[MAX][MAX];//�洢ͼ




bool find_path(int n,int s,int t,int *pre )//���ù�ȱ��� Ѱ������·  �ܸ��� n��  ����Ҫ�����һ��
{
	queue<int> q;
	bool vis[MAX];
	int top;//������ͷ��ֵ
	int i;// ѭ������
	for(i=1;i<=n;++i)
	{
		vis[i]=true;
	}
	q.push(s);
	vis[s]=false;
	while(!q.empty())//������� �ö���ʵ��
	{
		top=q.front();
		q.pop();
		for(i=1;i<=n;++i)//���ֻ�ܴ�1��ʼ��
		{
			if (vis[i] && map[top][i]>0) 
			{
				vis[i]=false;
				pre[i]=top;
				if (i==t) 
				{
					return true;
				}
				q.push(i);
			}
		}
	}
return false;
}




int Ford_Fulkerson(int n,int s,int t)
{
	int pre[MAX];//���ڼ�¼��Դ��s�����t������·
	int Flood;//��������ֵ
	int min1;//����·�Ŀ���������С���Ǹ�
	int i;//ѭ������
	Flood=0;//��ʼ�� �������Ϊ0
	while(find_path(n,s,t,pre))
	{
		min1=INT_MAX;
		for(i=t;i!=s;i=pre[i])//�ҵ�����������С���Ǹ�
		{
			if (map[pre[i]][i]<min1) 
			{
				min1=map[pre[i]][i];
			}
		}
		//����������ͬʱʹ������·��Ϊ�������� 
		for(i=t;i!=s;i=pre[i])
		{
			map[pre[i]][i]-=min1;
			map[i][pre[i]]+=min1;//�������
		}
		Flood+=min1;//����������
	}
	return Flood;
}

int main()
{
	int n,m;
	int num1,num2,flow;
	int i,j;
	int Flood;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(cin>>n>>m)
	{
		for(i=0;i<=m;++i)
		{
			for(j=0;j<=m;++j)
			{
				map[i][j]=0;
			}
		}

		for(i=1;i<=n;++i)
		{
			cin>>num1>>num2>>flow;
			map[num1][num2]+=flow;
		}

		Flood=Ford_Fulkerson(m,1,m);
		cout<<Flood<<endl;
	}
	return 0;
}