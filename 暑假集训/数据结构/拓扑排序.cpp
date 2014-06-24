#include<iostream>//�����ڽӾ���
using namespace std;

typedef struct node//���ڽӾ�����
{
	struct node *next;
	int loc;
}Tnode;

typedef struct //ͼ
{
	char ch[20];
	int num;
	Tnode *next;
}Graph;

void insert(Graph *G,int i,int j) //����������ĸ����
{
	Tnode *p=G[j].next,*q;
	q=new Tnode;
	q->loc=i;
	if (!p)
	{
		G[j].next=q;
		q->next=NULL;
		return;
	}
	while(p->next)
	{
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}

void topsort(Graph *G,int n)
{
	Tnode *p;
	int i=1,j,small=1;
	while(small<=n)
	{
		small=n+1;
		for(i=1;i<=n;i++)
		{
			if (G[i].num==0) 
			{
				 small=i; break;
			}
		}
		i++;
		for(;i<=n;i++)
		{
			if (G[i].num==0)
				if (strcmp(G[i].ch,G[small].ch)<0) 
				{
					small=i;
				}
		}
		if (small<=n)
		{
		 G[small].num--;
		 cout<<G[small].ch<<" ";
		}
		
		for(j=1;j<=n;j++)
		{
			if (G[j].num>0)
			{
				p=G[j].next;
				while(p)
				{
					if (p->loc==small) G[j].num--;
					p=p->next;
				}
			}
		}
	}
}
void print(Graph *G,int n)//���ͼ �ж�ͼ����ȷ��
{
	int i;
	Tnode *p;
	for(i=1;i<=n;i++)
	{
		cout<<G[i].ch<<":";
		p=G[i].next;
		while(p)
		{
			cout<<p->loc<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}

int main()
{
	Graph *G;
	int n,i,j,num;
	cin>>n;
	if (n)
	{
		getchar();
		G=new Graph[n+1];//��ͼ
		for(i=1;i<=n;i++)
		{
			cin>>G[i].ch;
			G[i].num=0;
			G[i].next=NULL;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>num;
				if (num)
				{
					G[j].num++;
					insert(G,i,j);
				}
			}
		}
		//print(G,n);
		topsort(G,n);
		cout<<endl;
	}
	return 0;
}