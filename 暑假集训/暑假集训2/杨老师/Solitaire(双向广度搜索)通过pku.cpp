#include<iostream>
#include<string>
#include<set>
#include<queue>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct State//һ����ʾ ��չ������״̬�Ľṹ��
{
	int a[4][2];
	string state;
	int step;
};

void reform(State *s)//���ĸ��������ת����һ�� 16λ���ַ���
{
	int i;
	s->state="0000000000000000000000000000000000000000000000000000000000000000";
	for(i=0;i<4;++i)
	{
		s->state[((s->a[i][0])-1)*8+s->a[i][1]]='1';
	}
}

int main()
{
	//bool vis1[65];//������������������ĵ�
	//bool vis2[65];//������������������ĵ�
	set<string> vis1;//������չ����ļ���
	set<string> vis2;//������չ����ļ���
	bool la,res;//����Ƿ��ҵ��� ���߸�������
	queue <State> q;//�������õĶ���
	queue <State> rq;//�������õĶ���
	State s,e;//��ʼ״̬��Ŀ��״̬ 
	State top,temp;//��ͷ �� ��ʱ����
	int i,j,k;
	while(cin>>s.a[0][0])
	{
		vis1.clear();
		vis2.clear();
		while(!q.empty())
		{
			q.pop();
		}
		while(!rq.empty())
		{
			rq.pop();
		}

		cin>>s.a[0][1];
		for(i=1;i<4;++i)
		{
			for(j=0;j<2;++j)
			{
				cin>>s.a[i][j];
			}
		}
		reform(&s);
		for(i=0;i<4;++i)
		{
			for(j=0;j<2;++j)
			{
				cin>>e.a[i][j];
			}
		}
		reform(&e);
		if (s.state==e.state) {puts("YES");continue;}//��ֱ�������

		s.step=0;
		e.step=0;
		q.push(s);
		la=false;
		res=false;
		vis1.insert(s.state);//��ʼ��չ
		while(!la&&!res&&!q.empty())
		{

			top=q.front();
			q.pop();
			for(i=0;!la&&!res&&i<4;++i)
			{
				for(j=0;!la&&!res&&j<4;++j)
				{
					if (top.a[i][0]+dir[j][0]>0&&top.a[i][0]+dir[j][0]<=8 && top.a[i][1]+dir[j][1]<=8&&top.a[i][1]+dir[j][1]>0) //û��Խ��
					{
						if (top.state[(top.a[i][0]+dir[j][0]-1)*8+top.a[i][1]+dir[j][1]]=='0')//Ҫ�ߵ��ĵ� û�б�ռ��
							//if(vis1[(top.a[i][0]+dir[j][0]-1)*8+(top.a[i][1]+dir[j][1])]) 
						{
							temp.step=top.step+1;//�����1 
							if (temp.step>4) {la=true;break;}//�����Ĳ�������
							for(k=0;k<4;++k)//���е� ֻҪ��һ�� �������հ�
							{
								temp.a[k][1]=top.a[k][1];
								temp.a[k][0]=top.a[k][0];
							}
							temp.a[i][0]=top.a[i][0]+dir[j][0];//Ҫ���µ� �͸���
							temp.a[i][1]=top.a[i][1]+dir[j][1];
							//vis1[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
							reform(&temp);//״̬ת�ַ���
							if (temp.state==e.state) {res=true;break;}//�ﵽĿ��״̬
							if (vis1.find(temp.state)==vis1.end()) {q.push(temp);vis1.insert(temp.state);}//û������״̬��  �Ϳ�����չ������״̬
						}

						else 
						{
							if (top.a[i][0]+2*dir[j][0]>0&&top.a[i][0]+2*dir[j][0]<=8 && top.a[i][1]+2*dir[j][1]<=8&&top.a[i][1]+2*dir[j][1]>0) 
							{
								if (top.state[(top.a[i][0]+2*dir[j][0]-1)*8+top.a[i][1]+2*dir[j][1]]=='0')
									//if(vis1[(top.a[i][0]+2*dir[j][0]-1)*8+(top.a[i][1]+2*dir[j][1])]) 
								{
									temp.step=top.step+1;
									if (temp.step>4) {la=true;break;}
									for(k=0;k<4;++k)
									{
										temp.a[k][1]=top.a[k][1];
										temp.a[k][0]=top.a[k][0];
									}
									temp.a[i][0]=top.a[i][0]+2*dir[j][0];
									temp.a[i][1]=top.a[i][1]+2*dir[j][1];
									//vis1[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
									reform(&temp);
									if (temp.state==e.state ) {res=true;break;}
									if (vis1.find(temp.state)==vis1.end()) {q.push(temp);vis1.insert(temp.state);}
								}
							}
						}
					}
				}
			}
		}


		if (res) {puts("YES");continue;}
		rq.push(e);
		vis2.insert(e.state);
		la=false;
		while(!la&&!res&&!rq.empty())
		{
			top=rq.front();
			rq.pop();
			for(i=0;!la&&!res&&i<4;++i)
			{
				for(j=0;!la&&!res&&j<4;++j)
				{
					if (top.a[i][0]+dir[j][0]>0&&top.a[i][0]+dir[j][0]<=8 && top.a[i][1]+dir[j][1]<=8&&top.a[i][1]+dir[j][1]>0) 
					{
						if (top.state[(top.a[i][0]+dir[j][0]-1)*8+top.a[i][1]+dir[j][1]]=='0')
							//if(vis2[(top.a[i][0]+dir[j][0]-1)*8+(top.a[i][1]+dir[j][1])]) 
						{
							temp.step=top.step+1;
							if (temp.step>4) {la=true;break;}
							for(k=0;k<4;++k)
							{
								temp.a[k][1]=top.a[k][1];
								temp.a[k][0]=top.a[k][0];
							}
							temp.a[i][0]=top.a[i][0]+dir[j][0];
							temp.a[i][1]=top.a[i][1]+dir[j][1];
							//vis2[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
							reform(&temp);
							if (temp.state==s.state ||vis1.find(temp.state)!=vis1.end()) {res=true;break;}//��������Ĳ����г��ֹ���
							if (vis2.find(temp.state)==vis2.end()) {rq.push(temp);vis2.insert(temp.state);}
						}

						else 
						{
							if (top.a[i][0]+2*dir[j][0]>0&&top.a[i][0]+2*dir[j][0]<=8 && top.a[i][1]+2*dir[j][1]<=8&&top.a[i][1]+2*dir[j][1]>0) 
							{
								if (top.state[(top.a[i][0]+2*dir[j][0]-1)*8+top.a[i][1]+2*dir[j][1]]=='0')
								//if(vis2[(top.a[i][0]+2*dir[j][0]-1)*8+(top.a[i][1]+2*dir[j][1])]) 
								{
									temp.step=top.step+1;
									if (temp.step>4) {la=true;break;}
									for(k=0;k<4;++k)
									{
										temp.a[k][1]=top.a[k][1];
										temp.a[k][0]=top.a[k][0];
									}
									temp.a[i][0]=top.a[i][0]+2*dir[j][0];
									temp.a[i][1]=top.a[i][1]+2*dir[j][1];
									//vis2[(temp.a[i][0]-1)*8+temp.a[i][1]]=false;
									reform(&temp);
									if (temp.state==s.state ||vis1.find(temp.state)!=vis1.end()) {res=true;break;}
									if (vis2.find(temp.state)==vis2.end()) {rq.push(temp);vis2.insert(temp.state);}
								}
							}
						}
					}
				}
			}
		}

		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}