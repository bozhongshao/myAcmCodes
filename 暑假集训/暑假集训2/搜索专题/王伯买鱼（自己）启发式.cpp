#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 33

bool map[maxn][maxn];//��¼ת��ͼ���ڽӾ���
bool p[maxn],pbest[maxn];//��¼ÿ��λ����ѡ��ѡ��״̬
int best,sumbest;//��ѵ����������ʽ�
int h[maxn];//�洢����ʽ�����Ľ��
int d[maxn];//�洢��������ĳ���
int fund,various;//�ʽ������
int v[maxn];//��ļ۸�

void init()//��ʼ��
{
	int i,j;
	best=0;
	sumbest=0;
	for(i=1;i<=various;++i)
	{
		for(j=1;j<=various;++j)
		{
			map[i][j]=false;
		}
	}
	for(i=1;i<=various;++i)
	{
		p[i]=false;
		pbest[i]=false;
	}
}

void datainput()
{
	int i,num,price;//ѭ����������š��۸�������ʾ��ͼ
	int num1,num2;//�бߵ���������ı��

	for(i=1;i<=various;++i)
	{
		cin>>num>>price;
		v[num]=price;
	}
	while(cin>>num1>>num2,num1!=0||num2!=0)
	{
		map[num1][num2]=true;
		map[num2][num1]=true;
	}
}

bool cmp(int a,int b)
{
	return a>b;
}

void h_found()//����ʽ����
{
	int c,t;
	int n,i,j,s;
	for(n=1;n<=various;++n)
	{
		for(i=1;i<=n;++i)//ͳ�Ƹ���ĳ���
		{
			d[i]=0;
			for(j=1;j<=n;++j)
			{
				if (map[i][j]) ++d[i];
			}
		}
		s=0;
		for(i=1;i<=n;++i) s+=d[i];//������ͼ�Ķ�֮��
        sort(d+1,d+n+1,cmp);//�Զȵ���������ɴ�С����
		c=0;
		t=0;
		while(c<s)//�����Ķȶ��㿪ʼȡ �����ֲ����ڶȵ��ܺ�
		{
			++t;
			c+=2*d[t];//�Ͽ�����������ı�
		}
		h[n]=n-t;
	}
}

bool judge(int choose,int sum,int i)
{
	int j;
	if (choose+h[i-1]<best) return false;
	if (sum>fund) return false;
	for(j=1;j<=various;++j)
	{
		if (p[j] && map[i][j]) return false;
	}
	return true;
}

void p_found(int choose,int sum,int i)//��ǰ��ѡ�����������ʽ�ͣ���ǰ���������ı��
{
	int j;
	if (i==0) 
	{
		if (choose>best||choose==best &&sum>sumbest)
		{
			best=choose;
			sumbest=sum;
			for(j=1;j<=various;++j)
			{
				pbest[j]=p[j];
			}
		}
		return;
	}
	if (choose+h[i-1]>=best)
	{
		p_found(choose,sum,i-1);
	}

	if (judge(choose+1,sum+v[i],i)) 
	{
		p[i]=true;
		p_found(choose+1,sum+v[i],i-1);
        p[i]=false;
	}

}


void dataoutput()
{
	int i;
	cout<<best<<" "<<sumbest<<endl;
	for(i=1;i<=various;++i)
	{
		if (pbest[i]) cout<<i<<endl;
	}
}
int main()
{
	cin>>fund>>various;
	init();
	datainput();
	h_found();
	p_found(0,0,various);
	dataoutput();
	return 0;
}