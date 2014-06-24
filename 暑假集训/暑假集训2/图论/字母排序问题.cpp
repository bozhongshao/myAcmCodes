#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Node 
{
	int la;
	struct Node *next;
};

struct Map
{
	Node *next;
	int degree;
	char data;
};

Map  *m;
int A,K;
string l[50001];
bool vis[27][27];

void getchre(const string &a,const string &b,char *chmax,char *chmin)//�õ��Ⱥ������ַ����бȽϳ���С��������ĸ
{
	int alen,blen,i;
	alen=int(a.size());
	blen=int(b.size());
	for (i=0;i<alen&&i<blen;++i)
	{
		if (a[i]!=b[i]) {*chmax=a[i];*chmin=b[i];return;}
	}
}

int position(char ch)//������ĸ�������е��±�
{
	int i;
	for (i=0;i<K;++i)
	{
		if (m[i].data==ch) return i;
	}
	return -1;
}

string Topsort()//�������� 
{
	string res;
	Node *p;
	bool la;
	int i,count1,savei;
	res="";
	while (1)
	{
		la=false;
		count1=0;
		for (i=0;i<A;++i)
		{
			if (m[i].degree==0) 
			{
				savei=i;++count1;//������һ������   ֻ����һ��
			}
		}
		if (count1!=1) {break;}
		i=savei;
		res.insert(res.end(),m[i].data);
		m[i].degree=-1;
		p=m[i].next;
		while (p)
		{
			m[p->la].degree-=1;
			p=p->next;
		}
	}
	return res;
}


int main()
{
	string chorder;
	int maxla,minla;
	string str,sstr;
	char chmax,chmin;

	Node *q;
	int i,j;
	while(cin>>A>>K)
	{
		memset(vis,true,sizeof(vis));// ��ʼ�� ��� ָ���Ƿ��ظ������� Ϊȫ��û��
		for(i=0;i<K;++i)//�����ַ���
		{
			cin>>l[i];
		}
		cin>>str;//����Ҫ�ָ����ַ�
		m=new Map[A];//�����ڽӱ�
		for (i=0;i<A;++i)
		{
			m[i].data=str[i];
			m[i].next=NULL;
			m[i].degree=0;
		}

		for (i=0;i<K-1;++i)
		{
			for (j=i+1;j<K;++j)
			{
				chmax=0;chmin=0;
				getchre(l[i],l[j],&chmax,&chmin);
				if (chmax==0) continue;
				maxla=position(chmax);
				minla=position(chmin);
				if (vis[maxla][minla])
				{
					vis[maxla][minla]=false;
					++(m[minla].degree);
					q=new Node;
					q->la=minla;
					q->next=m[maxla].next;
					m[maxla].next=q;
				}
			}
		}

		/*for (i=0;i<A;++i)
		{
			cout<<m[i].data<<":";
			q=m[i].next;
			while (q)
			{
				cout<<m[q->la].data<<" ";
				q=q->next;
			}
			cout<<endl;
		}
		*/
		chorder=Topsort();
		if (int(chorder.size())<A) {puts("0");continue;}
		sstr=str;
		sort(str.begin(),str.end());//��Ҫ�ָ����ַ���������
		for (i=0;i<A;++i)
		{
			for (j=0;j<A;++j)
			{
				if (sstr[i]==str[j]) break;
			}
			putchar(chorder[j]);
		}
		putchar('\n');
	}
	return 0;
}