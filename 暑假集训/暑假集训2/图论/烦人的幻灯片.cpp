#include<iostream>
using namespace std;


struct Powerpoint//������������õ�Ƭ �������ܶ�Ӧ������ 
{
	int x1,y1,x2,y2;//����ĶԶ�������
	struct Powerpoint *next;//������ܶ�Ӧ������ ����
	int count1;// ����
};


int main()
{

	int i,j,k,x,y;
	Powerpoint *p,*q;
	bool res;
	int n,count2;
	int ppt;
	res=true;
	cin>>n;
	p=new Powerpoint[n];
	for(i=0;i<n;++i)
	{
		cin>>p[i].x1>>p[i].x2>>p[i].y1>>p[i].y2;
		p[i].count1=0;
		p[i].next=NULL;
	}

	for(i=1;i<=n;++i)//�������ܵĶ�Ӧ��ϵ
	{
		cin>>x>>y;
		for(j=0;j<n;++j)
		{
			if (x>=p[j].x1&&x<=p[j].x2 && y>=p[j].y1&&y<=p[j].y2) 
			{
				q=new Powerpoint;
				q->count1=i;
				q->next=p[j].next;
				p[j].next=q;
				p[j].count1++;
			}
		}
	}

    //Ѱ��n-1�� �����ҵ��� n-1����ȷ���� ���ܹ�ȷ��
	for(i=1;i<=n-1;++i)
	{
		for(j=0;j<n;++j)
		{
			if (p[j].count1==0) {res=false;break;}//��û���ܶ�Ӧ��  ����
		}
		if (!res) break;

		for(j=0;j<n;++j)
		{
			if (p[j].count1==1) break;// Ψһ��Ӧ�ľ�ȷ������ ͬʱ��������������ɾ���������
		}
		if (j>=n) {res=false;break;}
		ppt=p[j].next->count1;
		
		for(k=0;k<n;++k)
		{
			if (k!=j)
			{
				count2=0;
				q=&p[k];
				while(q->next)
				{
					count2++;
					if (q->next->count1==ppt)
					{
						q->next=q->next->next;break;
					}
					q=q->next;
				}
				if (count2<p[k].count1) --p[k].count1;//�����ҵ���Ҫɾ������
			}
		}
	}


	if (!res) {puts("None");return 0;}

	for(i=0;i<n;++i)
	{
		printf("%c %d\n",i+65,p[i].next->count1);
	}

	return 0;
}