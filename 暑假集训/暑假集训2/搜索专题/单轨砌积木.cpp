//program block;
//uses crt;
#include<iostream>
using namespace std;
#include<string>

int e[33],t[33];   //{�������м��}
int biao[33][33];   //{�����Ϊ�����ʽ������}
//s:array[-1..32,-1..32,0..1] of longint;   {����������}
int s[34][34][2];
int lmin,l,n,m;//n��ľ���� m����ߵĸ߶� lmin����С����  l�ǵ�ǰ�������ٶ�������
string fs;
char ch;
int total;

void  out()      //{���}
{
	int i,j;
	memset(biao,0,sizeof(biao));

	for(i=1;i<=32;++i)
	{
		e[i]=t[i];
	}

	++total;
	cout<<total<<endl;
	for (i=1;i<=l;++i)// {���ת��}
	{
		j=1;
		while (e[i]>0)
		{
			biao[j][i]=1;
			++j;
			--(e[i]);
		}
	}


	for (i=m;i>=1;--i)//{��ӡ}
	{
		for (j=1;j<=n;++j)
		{
		if (j!=n) printf("%d ",biao[i][j]);//�ÿո��������
		if (j==n) printf("%d",biao[i][j]);//�е���󲻲����ո�
		}
		if (l!=lmin || i!=1) putchar('\n');//��󲻲����س�
	}

}
//v��ʼʱ1   x��ʼ��n  z��ʼ��0
void work(int v,int x,int z)   //{��������}
{

	int i,j;
	if (v==l-v+1)                   //{�ж��Ƿ��ҵ���}��� l������ ��ôv�����м�һ��
	{
		if (x==0) return;
		if (x<=m)  { t[v]=x;out();}//ʣ��С�� m������������
		return;
	}

	if (v>l-v+1)//l��ż�� ��ȫ�����Ѿ����ź���
	{
		if (x==0)  out();//��Ӧ��ʣ��
		return;
	}


	//{�����}
	if (z==0)//�����Ҫ����
	{
		//{Ҫ��֤��>��ʱ}
		for (i=1;i<=m;++i)
		{
			for (j=i;j<=m;++j)
				if (x-i-j>=0)
				{
					t[v]=j;t[l-v+1]=i;//�ֱ�i��j����ԳƵ�����λ�� ��֤�������  ���Խ�i�������
					if (i==j)  work(v+1,x-i-j,0);//0��ʾ����������Ҫ�ж�T>T'
					else work(v+1,x-i-j,1);//1��ʾ����������Ҫ�ж���
				}
		}
	}


	if (z==1) //                      {���ñ�֤��>��ʱ}
	{
		for (i=1;i<=m;++i)
		{
			for (j=1;j<=m;++j)
			{
				if (x-i-j>=0)
				{
					t[v]=i;t[l-v+1]=j;//��Ϊ���ñ�֤�����������
					work(v+1,x-i-j,1); 
				}
			}
		}
	}


}

void suan()		//  {�������}ֱ������� total
{
	int x,y,i,j;
	int rr;
	//{���ݳ�ʼ��}
	memset(s,0,sizeof(s));
	s[1][0][0]=1;s[1][0][1]=1;
	s[1][1][0]=1;s[1][1][1]=1;
	for (x=1;x<=m;++x){ s[x+1][2][0]=1;s[x+1][2][1]=1;}
	//{-------------}
	for (x=2;x<=n;++x)
		for (y=2;y<=x;++y)           // {��s[x,y];}
		{
			//{-----�������-----}
			for (i=1;i<=m;++i)
				for (j=i;j<=m;++j)
					if (x-i-j>=0)
						if (i==j)
							s[x+1][y+1][0]=s[x+1][y+1][0]+s[x-i-j+1][y-2+1][0];
						else
							s[x+1][y+1][0]=s[x+1][y+1][0]+s[x-i-j+1][y-2+1][1];
			//{-----------------}
			for (i=1;i<=m;++i)
				for (j=1;j<=m;++j)
					if (x-i-j>=0)
						s[x+1][y+1][1]=s[x+1][y+1][1]+s[x-i-j+1][y-2+1][1];
		}
		rr=0;
		//{������}
		for (i=1;i<=n;++i)
			rr=rr+s[n+1][i+1][0];
		printf("Total=%d\n",rr);
}


int main()
{

	//{���ݳ�ʼ��}
	total=0;

	memset(t,0,sizeof(t));
	cin>>n;
	cin>>m;
	//{ѡ�������ʽ}
	//suan();
	lmin=int(double(n)/m+0.99);//�����С������
	//{����Ѱ��}
	printf("%d %d\n",n,m);
	for (l=n;l>=lmin;--l)//�������������С�������г���
	{
		work(1,n,0);
	}
	//printf("total=%d\n",total);
}
