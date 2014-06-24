#include<iostream>
#include<queue>
using namespace std;

#define MAX 3700
bool vis1[MAX];
struct Node
{
	int la;
	struct Node *next;
};
int map[MAX][MAX];//�洢ͼ

Node edge[MAX];//���ӱ�


bool find_path(int n,int s,int t,int *pre )//���ù�ȱ��� Ѱ������·  �ܸ��� n��  ����Ҫ�����һ��
{
	Node *p;
	queue<int> q;
	bool vis[MAX];
	int top;//������ͷ��ֵ
	int i;// ѭ������
	for(i=0;i<=n;++i)
	{
		vis[i]=true;
	}
	q.push(s);
	while(!q.empty())//������� �ö���ʵ��
	{
		top=q.front();
		q.pop();
		p=edge[top].next;
		while(p)
		{
			if (top && !vis1[p->la]) {p=p->next;continue;} 
			if (vis[p->la] && map[top][p->la]>0) 
			{
				vis[p->la]=false;
				pre[p->la]=top;
				if (p->la==t) 
				{
                    return true;
					vis[t]=false;
				}
				q.push(p->la);
			}
			p=p->next;
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
			map[i][pre[i]]+=min1;
		}
		Flood+=min1;//����������
	}
	return Flood;
}

int main()
{
	Node *q;
	int i,j;//ѭ������
	int x,y;//����������
	int n,m,car;//ˮƽ�����ϵĹ�·�� ��ֱ�����ϵĹ�·��
	int Flood;//�����
	int casenum;
	casenum=0;
	while(cin>>n>>m>>car,n!=0||m!=0||car!=0)
	{
		for(i=0;i<=n*m+1;++i)
		{
			vis1[i]=true;
		}
		casenum++;
		for(i=0;i<=n*m+1;++i)//��ʼ���� ��ͼ
		{
			edge[i].next=NULL;
			for(j=0;j<=n*m+1;++j)
			{
				map[i][j]=1;
				map[j][i]=1;
			}
		}

		for(i=1;i<=car;++i)
		{
			cin>>y>>x;
			q=new Node;
			q->la=(x-1)*n+y;
			q->next=edge[0].next;
			edge[0].next=q;
			map[0][q->la]=1;
			vis1[q->la]=false;
		}
		for(i=1;i<=n*m;++i)
		{
			if (i-1>0&&(i-1)%n>0) 
			{
				q=new Node;
				q->la=i-1;
				q->next=edge[i].next;
				edge[i].next=q;
			}

			if (i+1<=n*m&&(i+1)%n!=1 )
			{
				q=new Node;
				q->la=i+1;
				q->next=edge[i].next;
				edge[i].next=q;
			}

			if (i+n<=n*m) 
			{
				q=new Node;
				q->la=i+n;
				q->next=edge[i].next;
				edge[i].next=q;
			}

			if (i-n>0) 
			{
				q=new Node;
				q->la=i-n;
				q->next=edge[i].next;
				edge[i].next=q;
			}
		}
		//�����߽�㽨������
        for(i=1;i<=n;++i)
		{
			q=new Node;
			q->la=n*m+1;
			q->next=edge[i].next;
			edge[i].next=q;
			
			q=new Node;
			q->la=i;
			q->next=edge[n*m+1].next;
			edge[n*m+1].next=q;
			map[i][n*m+1]=1;
		}

		for(i=1+n*(m-1);i<=n*m;++i)
		{
			q=new Node;
			q->la=n*m+1;
			q->next=edge[i].next;
			edge[i].next=q;

			q=new Node;
			q->la=i;
			q->next=edge[n*m+1].next;
			edge[n*m+1].next=q;
			map[i][n*m+1]=1;
		}

		for(i=1+n;i<1+n*(m-1);i+=n)
		{
			q=new Node;
			q->la=n*m+1;
			q->next=edge[i].next;
			edge[i].next=q;

			q=new Node;
			q->la=i;
			q->next=edge[n*m+1].next;
			edge[n*m+1].next=q;
			map[i][n*m+1]=1;
		}

		for(i=n*2;i<n*m;i+=n)
		{
			q=new Node;
			q->la=n*m+1;
			q->next=edge[i].next;
			edge[i].next=q;

			q=new Node;
			q->la=i;
			q->next=edge[n*m+1].next;
			edge[n*m+1].next=q;
			map[i][n*m+1]=1;
		}
		Flood=Ford_Fulkerson(n*m+2,0,n*m+1);
		printf("Scenario %d\n",casenum);
		if (Flood==car) puts("Solution exists");
		else puts("No solution available");
	}
	return 0;
}