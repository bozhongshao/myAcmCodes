//������һ�����͵�ģ���� ֻҪ��1��T��������  �����еĿͻ����ӿ����еķ������а��մ����ٶȾ�����ٶ���������
//����ʱ�ı���Ƿ��������ɷ�����  
//��Ŀ����   ����n̨���� ����p2p��ԭ�� ֻҪ��ӵ������������ļ��ļ���������Գ�Ϊ������ û�и��ļ��Ŀͻ����Ϳ��Դ���̨���������� 
//��Ŀ ���� �������Ŀ ����ʱ��
// ÿ̨���ԵĿ���ʱ��� ����֮��Ĵ����ٶ�  ÿ̨�ͻ����Ŀ�ʼ����ʱ�� ����һ���ͻ�������������ļ� �����ϱ���˷����������������ͻ��Ҵ�������  
//Ҫ����ǣ���tʱ�� ÿ̨����ӵ������ļ��İٷֱ�

//����˼·  ģ�⼴��  
#include<iostream>
using namespace std;
struct Time1//�洢ÿ̨������Ŀ���ʱ���
{
	int on,off;
};


bool panduan(Time1 t[],int i)//�ж�һ̨������Ƿ��ڿ���ʱ���  �Ƿ���true
{
	int j;
	for(j=1;j<=t[0].on;++j)
	{ 
		if (t[j].on<i && t[j].off>=i) return true;
	}
	return false;
}

int main()
{
	int dd[25];//�洢 ÿ̨������Ŀ�ʼ����ʱ��
	int already[25];//�洢ÿ̨����� �Ѿ������˶��ٱ��ļ�������
	int map[25][25];// �洢 �������֮��Ĵ����ٶ�
	bool server[25];// ��ʶ �Ƿ������
	int change[25];//ÿһ���ӵ�����֮��  �洢Ҫ��ɷ������Ŀͻ����ı��
	Time1 tt[25][15];// �洢ÿ̨������Ŀ���ʱ���
	int casenum;//������Ŀ
	int count1;//�洢Ҫ���¿ͻ���Ϊ����������Ŀ
	int n,m,T;//��������������ز�������Ŀ��������ʱ��
	int k,s;//�ʼ�������������ļ��Ĵ�С
	int i,j,l,num,time2,sum;//����ѭ������   �������� �洢ʱ�� �����ÿ����Ҫ�ӵ����ݴ�С

	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%d%d",&n,&T);
		scanf("%d%d",&k,&s);
		memset(server,false,sizeof(server));
		memset(already,0,sizeof(already));
		while(k--)
		{
			scanf("%d",&num);
			server[num]=true;
			already[num]=s;
		}
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(j=1;j<=n;++j)
		{
			scanf("%d",&(tt[j][0].on));
			for(i=1;i<=tt[j][0].on;++i)
			{
				scanf("%d%d",&tt[j][i].on,&tt[j][i].off);
			}
		}


		for(i=0;i<=n;++i)
		{
			dd[i]=INT_MAX;
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&time2,&num);
			dd[num]=time2;
		}
	
	
		for(i=1;i<=T;++i)
		{
			count1=0;

			for(j=1;j<=n;++j)
			{

				if (server[j] || !panduan(tt[j],i)) continue;
				if (dd[j]<i) 
				{
					sum=0;
					for(l=1;l<=n;++l)
					{
						if (l==j) continue;
						if (server[l] && panduan(tt[l],i)) sum+=map[j][l];
					}
					already[j]+=sum;
					if (already[j]>=s) change[count1++]=j;
				}
			}

			for(j=0;j<count1;++j)
			{
				server[change[j]]=true;
			}

		}

		for(i=1;i<=n;++i)
		{
			if (server[i]) puts("100%");
			else 
			{
				printf("%d",(already[i]*100)/s);
				putchar('%');
				putchar('\n');
			}
		}
	}
	return 0;
}

//author shaobozhong