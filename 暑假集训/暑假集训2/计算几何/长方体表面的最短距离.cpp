//program surface;

#include<iostream>
#include<cmath>
using namespace std;

const double pi=acos(-1.0);
// a[0]Ϊ������ߴ磬a[1],a[2]Ϊ���������
int a[3][4];
//�������̾���
double min1;

void init()//��������
{
	int i,j;
	for(i=0;i<=2;++i)
	{
		for(j=1;j<=3;++j)
		{
			cin>>a[i][j];
		}
	}
}

//���㹲������ 
void one_surface(int x1,int z1,int x2,int z2)// �����ʱ��ͳͳ����y����ȵ�
{
	double t;
	t=sqrt(double((x1-x2)*(x1-x2)+(z1-z2)*(z1-z2)));//����ƽ���������ľ���
	min1=t;
}

//�����������
void opposite_surface(int x1,int z1,int x2,int z2,int l,int h,int w)
{
	double t1,t2;
	int a,b;
	a=abs(x1-x2);//����ͼ��x����Ĳ�
	if ((z1+z2)<(h-z1)+(h-z2)) b=z1+z2+w;//չ����������ε�һ������x����ֱ
	else b=(h-z1)+(h-z2)+w;
    t1=sqrt(double(a*a+b*b));
	
	
	a=abs(z1-z2);//����ͼ��z����Ĳ�
	if (x1+x2<(l-x1)+(l-x2)) b=x1+x2+w;//չ����������ε�һ������z����ֱ
	else b=(l-x1)+(l-x2)+w;
    t2=sqrt(double(a*a+b*b));


	if (t1<t2) min1=t1;//ȡ��Сֵ
	else min1=t2;
}


//������������
void near_surface(int x1,int z1,int x2,int y2,int l,int h)
{
	//1�����꣨x1,0,z1�� 2������ (x2,y2,h);
	//����ͼ��1�� ��֪ x��z  yΪ
	double t;
	double g1,g2;
	int a,b;
	a=abs(x1-x2);
	b=(h-z1)+y2;
	min1=sqrt(double(a*a+b*b));

    //�������жϿɷ�ֱ��չ�����ڵ���������� ͨ��һ���м������չ��
	g1=atan(double(x1)/(h-z1));
	g2=atan(double(x2)/y2);
	if (g1+g2<=pi/2) //pi��Բ����
	{
		a=x1+y2;
		b=(h-z1)+x2;
		t=sqrt(double(a*a+b*b));
		if (t<min1) min1=t;
	}

	g1=atan(double(l-x1)/(h-z1));
	g2=atan(double(l-x2)/y2);
	if (g1+g2<=pi/2) 
	{
		a=(l-x1)+y2;
		b=(h-z1)+(l-x2);
		t=sqrt(double(a*a+b*b));
		if (t<min1) min1=t;
	}
}

//������̾���
void run()
{
	int p[3][4];
	int q[8];//
	int pq;
	bool solve;
	int i,j,k;


	for(i=1;i<=2;++i)
	{
		for(j=1;j<=3;++j)
		{
			if (a[i][j]==0) p[i][j]=0;// i����j����������Ϊ0
			else
			{
				if (a[i][j]==a[0][j]) p[i][j]=2;//i����j����������߳����
				else p[i][j]=1;//i��j����Ĵ�С����
			}
		}
	}

	solve=false;
	for(j=1;j<=3;++j)
		//�ж��Ƿ���
		if (!solve) 
		{
			if (p[1][j]==p[2][j]&& p[1][j]!=1)//�ж�1���2����j����������ȵ����� ������
			{
				solve=true;// ������ҵ���Ӧ�����
				pq=0;//q���±�
				for(i=1;i<=3;++i)
					if (i!=j) //j�����ϵ�������Ϊ0  q[1] ,[2] ���� �� 1 ��j�����ϵ��������� q[3], [4] �����2 ��j�����ϵ���������
					{
						q[pq+1]=a[1][i];
						q[pq+3]=a[2][i];
						++pq;
					}
				one_surface(q[1],q[2],q[3],q[4]);
			}
		}


	for(j=1;j<=3;++j)
		//�ж��Ƿ����
		if (!solve)
		{
			if (abs(p[1][j]-p[2][j])==2) //��ĳһ��������һ��Ϊ0 һ������Ϊ�߳���������
			{
				solve=true;// ������ҵ���Ӧ�����
				pq=0;//q���±�
				for(i=1;i<=3;++i)
					if (i!=j)//��j������ ��������Ͷ�Ӧ�ı߳�  q[1],[2]�����1  q[3],[4]�����2 q[5],[6]�洢�����߳�
					{
						q[pq+1]=a[1][i];
						q[pq+3]=a[2][i];
						q[pq+5]=a[0][i];
						pq++;
					}
					q[7]=a[0][j];// j�����ϵı߳�   ����ͼ�е�w
					opposite_surface(q[1],q[2],q[3],q[4],q[5],q[6],q[7]);
			}
		}
		i=1;
		while(i<=3)
		{
			//�ж��Ƿ�����
			if ((p[1][i]==0 || p[1][i]==2) && !solve) //p[1][i]==0||p[1][i]==2 ��ʾ1��������  �����������������ʵ������Ҫ 
		    {
			 j=1;
			 while(j<=3)//����������������
			 {
				 if (i!=j && (p[2][j]==0 || p[2][j]==2)&&!solve)//�ж�2�� ��j������0  �����ǵ��ڱ߳� ����1 ���������һ��
				 {
					 solve=true;//����Ѿ��ҵ���Ӧ�����
                      
					 if (p[1][i]==p[2][j])//���������ͬ�ķ��� ͬʱ����ͬ��״̬  �����⡢ ����Ϊ0 ���� ����Ϊ�߳��� ��ı�j�����ϵ�״̬
					 {
						 a[1][j]=a[0][j]-a[1][j];//1����j�����ϵ�����= j�����ϵı߳���ȥ 1�������  
						 a[2][j]=a[0][j]-a[2][j];//2����j�����ϵ�����= j�����ϵı߳���ȥ 2�������
						 p[1][j]=2-p[1][j];// 1����j�����״̬��Ϊ ��Ե�  1->1  2->0  0->2
						 p[2][j]=2-p[2][j]; //2��Ҳһ��
					 }//����Ŀ���Ƿ� �����  2��j��������2  1��i��������0


					 if (p[1][i]==2) //���1����i����������Ϊ�߳���״̬Ϊ2  ����1���2�������
					 {
						// i j ����ֵ 
						 pq=i;
						 i=j;
						 j=pq;
                         //����1 2 ��ĵ������״̬
						 for(k=1;k<=3;++k)
						 {
							 pq=p[1][k];
							 p[1][k]=p[2][k];
							 p[2][k]=pq;
							 pq=a[1][k];
							 a[1][k]=a[2][k];
							 a[2][k]=pq;
						 }
					 }


					 k=1;
					 while(k==i || k==j) ++k; //k��ʾ����i��j����һ������
					 q[1]=a[1][k];
					 q[3]=a[2][k];
					 q[2]=a[1][j];
					 q[4]=a[2][i];
					 q[5]=a[0][k];
					 q[6]=a[0][j];

					// q[1],[2]  ��k j�����ʾ��1  i����Ϊ0  q[3]��[4]��k i�����ʾ��2 j������Ϊ�߳�   //���Բ���i�����ϵı߳�
					 near_surface(q[1],q[2],q[3],q[4],q[5],q[6]);
				 }
				 ++j;
			 }
		 }
			++i;
		}
}
//�����̾���
void done()
{
	printf("%.2lf\n",min1);
}


int main()
{
    init();
	run();
	done();
	return 0;
}