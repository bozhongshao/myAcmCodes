/*�㷨����;
1 ������������������ͨ����  
2 ��0��n-1 �����̽ÿ���������Ƿ��ǹؼ��ġ���ÿһ����㣬�ҳ����иý�����ͨ���������ý��ɾ���� ���»��ָ���ͨ���� Ҫ��ֻ�ܻ���һ�� ��˵�����ǹؼ������� 
�����µ���ͨ���������ܵ�  ��ͨ���������У��ڱ������� Ҳ���������У� ����ɾ��ԭ���� �����µ� ���Ұ��� ��С���������  ����
���������ǲ��ù�ȱ���̽����ͨ����
ͬʱ���Կ���ʹ����ȱ��� ��̽����ͨ���� ���Դ���ȼ��ٴ��볤��
*/
#include<iostream>
#include<set>
using namespace std;

#define MAX 100
struct Connect//Ϊ�洢��ͨ���������Ľṹ��
{
	set<int> Link;//������ͨ����
	struct Connect *next;
};

bool map[MAX][MAX];//�洢ͼ
bool vis[MAX];//��չʱ����Ƿ������
Connect Chead,*Ctail;//�洢������ͨ���������� �����һ����Ԫ��ָ��
int n;//������������
int minsubnet;//��С�İ�ȫ������

void findlink()//����ͨ����
{
	int i,j;
	Connect *p,*q;
	set<int> oex;//������set���ڹ����չ��ͨ����
	set<int> expand;//��ǰ��չ�ļ���
	set<int> ::iterator ex;//������
	for(i=0;i<n;++i)//���е㶼û�б�������
	{
		vis[i]=true;
	}
	p=&Chead;
	minsubnet=0;//��ʼ����С��ȫ������
	for(i=0;i<n;++i)
	{
		if (vis[i])
		{
			minsubnet+=1;//��С��ȫ��������1
			q=new Connect;
			q->Link.insert(i);
			oex.insert(i);
			vis[i]=false;
			while(1)
			{
				expand=oex;
				oex.clear();
				for(ex=expand.begin();ex!=expand.end();++ex)
				{
					for(j=0;j<n;++j)
					{
						if (vis[j] && map[*ex][j]) 
						{
							oex.insert(j);
							vis[j]=false;//��������
							q->Link.insert(j);
						}
					}
				}
				if (oex.empty()) break;
			}
			q->next=p->next;
			p->next=q;
			p=p->next;
		}
	}
	Ctail=p;
}

bool attemptdel(Connect *pre,int sn)//�����е�ǰ����һ����� Ϊɾ������  ����ɾ���ķ������ı�� �ú������ǳ���ɾ��ĳһ���� �����Ƿ�ؼ������� ���ҷ����Ƿ�����˸���
{

	Connect *p,*q,*next,temp;
	bool map1[MAX][MAX];
	set<int> oex;//������set���ڹ����չ��ͨ����
	set<int> expand;//��ǰ��չ�ļ���
	set<int> ::iterator ex,iset;//������
	int count1;
	int psn,qsn;//pָ��ָ�����ͨ��������С���������
	int i,j;//ѭ������
	for(i=0;i<n;++i)//���е㶼û�б�������
	{
		vis[i]=true;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			map1[i][j]=map[i][j];
		}
	}

	for(i=0;i<n;++i)
	{
		if (map1[sn][i]) 
		{
			map1[sn][i]=false;
			map1[i][sn]=false;
		}
	}
	temp.next=NULL;
	p=&temp;
	count1=0;
	for(iset=pre->next->Link.begin();iset!=pre->next->Link.end();++iset)
	{
		if (vis[*iset] && *iset!=sn)
		{
			count1+=1;
			q=new Connect;
			q->Link.insert(*iset);
			oex.insert(*iset);
			vis[*iset]=false;
			while(1)
			{
				expand=oex;
				oex.clear();
				for(ex=expand.begin();ex!=expand.end();++ex)
				{
					for(j=0;j<n;++j)
					{
						if (j!=sn &&pre->next->Link.find(j)!=pre->next->Link.end()&& vis[j] && map1[*ex][j] ) 
						{
							oex.insert(j);
							vis[j]=false;//��������
							q->Link.insert(j);
						}
					}
				}
				if (oex.empty()) break;
			}
			q->next=p->next;
			p->next=q;
			p=p->next;
		}
	}

	if (count1<=1) return false;
	minsubnet+=count1-1;
	pre->next=pre->next->next;
	p=pre;
	q=temp.next;
	while(q)
	{
		q->Link.insert(sn);
		next=q->next;//����q����һ�� ��Ϊq->next��ı�
		if (p->next) psn=*(p->next->Link.begin());//Ҫ����һ��Ϊ�վ�û��link 
		qsn=*(q->Link.begin());
		while(p->next && psn<qsn)
		{
			p=p->next;
			if (p->next) psn=*(p->next->Link.begin());//Ҫ����һ��Ϊ�վ�û��link
		}
		q->next=p->next;
		p->next=q;
		p=p->next;
		q=next;//q������
	}
	return true;
}

void printdata()
{
	Connect *p;
	set<int> ::iterator iset;//������
	cout<<minsubnet<<endl;
	p=Chead.next;
	while(p)
	{
		for(iset=p->Link.begin();iset!=p->Link.end();++iset)
		{
			cout<<*iset<<" ";
		}
		cout<<endl;
		p=p->next;
	}
}
int main()
{

	int i,j;//ѭ������
	int k,sn,lk;//�������ı��  һ���������������ķ������� ���ӵķ������ı��
	char ra;//��ȡ���õ�����
	Connect *p;
	set<int> ::iterator iset;//������
	bool  la;//��ǳ���ɾ���Ƿ������  ��ͨ����
	while(cin>>n)
	{
		//ͼ�Ľ���
		Chead.next=NULL;
		for(i=0;i<n;++i)//��ʼ��ͼ
		{
			for(j=0;j<n;++j)
			{
				map[i][j]=false;
			}
		}

		for(i=1;i<=n;++i)
		{
			cin>>k;
			cin>>ra;
			cin>>sn;
			cin>>ra;
			for(j=1;j<=sn;++j)
			{
				cin>>lk;
				map[k][lk]=true;//��һ����������һ���������������л���
			}
		}
		//���ҳ����е���ͨ�������洢��������
		findlink();
		//������ �ҵ���ͼ��ԭ�е���ͨ���� �������Ϳ�ʼ��ÿһ����ͨ���� ���Ƿ��йؼ�������
		p=&Chead;
		while(p->next)
		{
			for(iset=p->next->Link.begin();iset!=p->next->Link.end();++iset)
			{
				la=false;
				la=attemptdel(p,*iset);
				if (la) break;//Ҫ��ɾ���� ��Ӧ��������
			}
			if (!la) p=p->next;//Ҫ���Ѿ�ɾ���� �ͻ�Ҫ������������һ�����г���
		}
		printdata();//�������
	}
	return 0;
}