#include<iostream>
using namespace std;

bool map[221][221];//��λ�����Ƿ��߹�
int direc[10000];// ��i���ķ���
int tot;//�ܹ���·������
int maxn;// ���߳�

bool judge(int step ,int x,int y)//�жϵ�ǰ�����޿��ܵ���
{
	int i;
	int sum;
	sum=0;
	for(i=step;i<=maxn;i+=2)//����ÿһ�� ���Ǹ�һ�εĶ���ͬһ�����ܴﵽͬһ��������ֵ
	{
		sum+=i;
	}
	if (x-110>sum || 110-x >sum || y-110>sum || 110-y>sum) 
	{
		sum=0;
		for(i=step+1;i<=maxn;i+=2)
		{
			sum+=i;
		}
		if (x-110>sum || 110-x >sum || y-110>sum || 110-y>sum) return false;
	};
	return true;
}
bool panduan(int x,int y,int step)//�ж��Ƿ������ƶ�������
{
	int i;
	if (direc[step]==direc[step-1]) return false;//�����ƶ�ͬ�����򷵻ؼ�
	switch(direc[step])
	{
	case 1:
		for(i=y+1;i<=y+step;++i)//�ж��Ƿ񾭹��Ѿ��߹��ĵ�
		{
			if (!map[x][i]) break;
		}
		if (i<=y+step) return false; 
		break;
	case 2:
		for(i=x+1;i<=x+step;++i)
		{
			if (!map[i][y]) break;
		}
		if (i<=x+step) return false; 
		break;
	case 3:for(i=y-1;i>=y-step;--i)
		   {
			   if (!map[x][i]) break;
		   }
		   if (i>=y-step) return false; 
		   break;
	case 4:
		for(i=x-1;i>=x-step;--i)
		{
			if (!map[i][y]) break;
		}
		if (i>=x-step) return false; 
		break;
	}

	return true;
}

void attach(int x,int y,int step)// ���߹��ĵ���б�Ǻͽ�����  ���ֿ�д������һЩ�жϿ����ٶȻ��һЩ��
{
	int i;
	switch(direc[step])
	{
	case 1:
		for(i=y+1;i<=y+step;++i)
		{
			if (map[x][i]) map[x][i]=false;
			else map[x][i]=true;
		}
		break;
	case 2:
		for(i=x+1;i<=x+step;++i)
		{
			if (map[i][y])		map[i][y]=false;
			else map[i][y]=true;
		}
		break;
	case 3:for(i=y-1;i>=y-step;--i)
		   {
			   if (map[x][i]) 	map[x][i]=false;
			   else map[x][i]=true;
		   }
		   break;
	case 4:
		for(i=x-1;i>=x-step;--i)
		{
			if (map[i][y])	map[i][y]=false;
			else map[i][y]=true;
		}
		break;
	}
}

void work(int x,int y,int step)
{
	int i;
	if (step>maxn+1) return;//���ܳ������߳�
	if (step!=1&&x==110&&y==110)
	{
		if (step<maxn+1) return;
		for(i=1;i<step;++i)
		{
			switch(direc[i])
			{
			case 1:putchar('n');break;
			case 2:putchar('e');break;
			case 3:putchar('s');break;
			case 4:putchar('w');break;
			}
		}
		putchar('\n');
		tot++;
		return;
	}

	if (!judge(step,x,y)) return;
	direc[step]=1;
	if (y<221-step&&panduan(x,y,step))     //n
	{   

		attach(x,y,step);
		work(x,y+step,step+1);
		attach(x,y,step);
	}

	direc[step]=3;
	if (y>=step&&panduan(x,y,step))     //s
	{
		attach(x,y,step);
		work(x,y-step,step+1);
		attach(x,y,step);
	}
	direc[step]=2;
	if (x<221-step&&panduan(x,y,step))     //e
	{
		attach(x,y,step);
		work(x+step,y,step+1);
		attach(x,y,step);
	}

	direc[step]=4;
	if (x>=step&&panduan(x,y,step))     //w
	{
		attach(x,y,step);//����߹��ı�
		work(x-step,y,step+1);
		attach(x,y,step);//������
	}


}

int main()
{

	int x,y,n;
	//while(cin>>maxn)
	cin>>maxn;
	{
		tot=0;
		memset(map,true,sizeof(map));
		cin>>n;
		while(n--)
		{
			cin>>x>>y;
			map[x+110][y+110]=false;
		}
		work(110,110,1);
		printf("Found %d golygon(s).\n",tot);
	}
	return 0;
}