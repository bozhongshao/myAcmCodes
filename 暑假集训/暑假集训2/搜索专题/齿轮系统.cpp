//������õ�����ͼ����Ȧ�ķ�ʽ ʵ�����ǿ��Բ��� ������ת��ķ�ʽ ȥ��  �ٶȿ��ܻ��һ�� ������������ȷ������

#include<iostream>
#include<set>
using namespace std;

int min1;
int n,m,engine;//n������   m�����ڹ�ϵ�����ֵı��
int map[32][32];//�洢ת����ĵ�ͼ
char direct[32];//��¼�������ֵķ���

set <int> s;//��ǰ����
set <int> mind;//��СҪɾ����Ԫ�ؼ���
set <int> d;// ��ǰ���Ҫɾ����Ԫ��



void work(int x)//x�����Ѿ�ɾ���Ķ���ĸ���
{

	int k,l;
	int j;
	int lasti,lastj;
	int	 p[32]={0};//��¼�����������չ����
	bool la;
	set<int> od;//����û�н�û��������Ԫ����ӽ�d֮ǰ��d
	set <int> oex;//������չ�ĵ�
	set <int> expand;//������һ��Ҫ��չ�ĵ�
	set<int> ::iterator i;//���ϵĵ�����
	set <int> v;//�洢����������Ȧ��Ԫ��
	set <int> vis;//�Ѿ��������ĵ�ļ���
	if (x>min1) return;//Ҫ���Ѿ�������Сɾ���Ķ����� ��û��Ҫ��������
	expand.insert(engine);
	vis.insert(engine);
	la=false;

	while(1)//������������������Ȧ
	{
		oex=expand;
		expand.clear();
		for(i=oex.begin();i!=oex.end()&&!la;++i)//�����չ����Ҫ��չ��Ԫ��
		{
			//cout<<*i<<endl;
			for(j=1;j<=n&&!la;++j)//һ�������ܲ�����չ ����Ϊ�Ǿ����ʾ��ͼ��
			{
				if (map[*i][j]==1 && s.find(j)!=s.end() ) //�������չ ������չ����Ԫ�� ��s��
				{
					if (vis.find(j)==vis.end())//���û�б�������
					{
						map[*i][j]=2;
						map[j][*i]=2;
						vis.insert(j);
						expand.insert(j);
						p[j]=*i;
					}
					else //�������� Ҳ�����γ���Ȧ
					{
						lasti=*i;
						lastj=j;
						while(lasti!=lastj )
						{
							v.insert(lasti);
							v.insert(lastj);
							
							if (p[p[lasti]]==p[lastj]) //��ֹ�����ߵ�Ȧ��
							{
								v.insert(p[lasti]);
								lasti=lastj=p[lastj];
							}
							if (p[p[lastj]]==p[lasti]) 
							{
								v.insert(p[lastj]);
								lasti=lastj=p[lasti];
							}
							if (p[lasti]) {lasti=p[lasti];}
							if (p[lastj])lastj=p[lastj]; 
						}
						if (lasti==lastj) v.insert(lasti);

						if (v.size()%2==1) la=true;//�ж��ǲ�����Ȧ
						else {v.clear();map[*i][j]=2;map[j][*i]=2; p[j]=*i;expand.insert(j);}//������Ȧ�����
					}
				}
			}
		}
		if (expand.empty() || la ) break;
	}



	for(k=1;k<=n;++k)
	{
		for(l=1;l<=n;++l)
		{
			if (map[k][l]==2) map[k][l]=1;
		}
	}



	if (!la)
	{
		od=d;
		x=n-int(vis.size());
	    for(k=1;k<=n;++k)
		{
			if (vis.find(k)==vis.end()&&d.find(k)==d.end())
			{
				d.insert(k);
			}
		}
		
		//x+=int(d.size());
		if (min1>x)
		{
			min1=x;
			mind=d;
		}
		d=od;
		return;
	}




	for(i=v.begin();i!=v.end();++i)
	{
		if (*i!=engine)
		{
			s.erase(s.find(*i));
			d.insert(*i);
			work(x+1);
			d.erase(d.find(*i));
			s.insert(*i);
		}
	}


}


int main()
{
	char ch;
	int x,y,i,j,CC,OP,count;
	set<int>::iterator  k;
	set <int> oex;//������չ�ĵ�
	set <int> expand;//������һ��Ҫ��չ�ĵ�
	set <int> vis;
	while(cin>>n>>m)
	{
		d.clear();
		min1=INT_MAX;
		CC=0;
		OP=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				map[i][j]=0;
			}
		}

		for(i=1;i<=n;++i)
		{
			s.insert(i);
			direct[i]='N';
		}
		for(i=1;i<=m;++i)
		{
			cin>>x>>y;
			map[x][y]=true;
			map[y][x]=true;
		}
		cin>>engine;
		cin>>ch;
		if (ch=='O') OP++;
		else CC++;
		work(0);
		if (min1==0) puts("W");
		else puts("B");
		expand.insert(engine);
		vis.insert(engine);
		direct[engine]=ch;
		while(1)//��ȱ���ȷ�����ֵ�ת��
		{
			oex=expand;
			expand.clear();
			for(k=oex.begin();k!=oex.end();++k)
			{
				for(j=1;j<=n;++j)
				{
					if (map[*k][j]==1 && mind.find(j)==mind.end()&&vis.find(j)==vis.end()) 
					{
						map[*k][j]=2;
						map[j][*k]=2;
						if (direct[*k]=='C') {direct[j]='O';++OP;}
						else {direct[j]='C';++CC;}
						expand.insert(j);
						vis.insert(j);
					}
				}
			}
			if (expand.empty()) break;
		}
		if (!CC) cout<<"CC";//���˳ʱ��Ľ��
		else
		{
			cout<<"CC ";
			count=0;
			for(i=1;i<=n;++i)
			{
				if (direct[i]=='CC') 
				{
					++count;
					if (count<CC) {cout<<i<<" ";}
					else cout<<i<<endl;
				}
			}
		}

		if (!OP) cout<<"O"<<endl;//�����ʱ��Ľ��
		else
		{
			count=0;
			cout<<"O ";
			for(i=1;i<=n;++i)
			{
				if (direct[i]=='O') 
				{
					++count;
					if (count<OP) {cout<<i<<" ";}
					else cout<<i<<endl;
				}
			}
		}

		if (min1!=0)// ���Ҫɾ����Ԫ��
		{
			cout<<"R ";
			count=0;
			for(k=mind.begin();k!=mind.end();++k)
			{
				count++;
				if (count<int(mind.size())) cout<<*k<<" ";
				else cout<<*k<<endl;
			}
		}
		vis.clear();
		expand.clear();
		s.clear();
	}
	return 0;
}