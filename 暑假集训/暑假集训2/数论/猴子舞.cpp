/*
�㷨�������ֳ�n��Ȧ�� ��С����������  ��������   ���ɻ��ʵ�����ɵıض�������   ���ʵ��� �������������
���������Ķ�η�֮��Ҳ���ǻ��ʵ� ֻҪ���� 2 ��3  6 �����е��������ǻ��ʵ�   

*/
#include<iostream>
#include<cmath>
using namespace std;
long long max1;
int p[100];
int vis[100];
void getprime()//���һ����Χ�ڵ�����   ��һ����Ϊ6  ������
{
	int count1;
	int i,j;
	memset(p,0,sizeof(p));
	p[0]=6;
	p[1]=2;
    count1=2;
	for(i=3;i<300;++i)
	{
		for(j=2;j<=int(sqrt(double(i)));++j)
		{
			if (i%j==0) break;
		}
		if (j>int(sqrt(double(i)))) p[count1++]=i; 
	}
	p[count1]=INT_MAX;
}



void checkres(int num,int k)//���鵱ǰ״̬�ɴﵽ�Ĳ���  ��ʵ���Ǽ��㲽��
{
	int i,j;
	long long res;
	if (num==1) return;//����1 ����  
    res=1;
	for(i=1;i<=k;++i)//��������ʵ����ĳ˻� ����С������ 
	{
		if (vis[i]>0)
		{
			for(j=0;j<vis[i];++j)
			{
				res*=p[i];
			}
		}
	}

	//���⴦��2��3��������
	if (vis[0]==0)//��������ʱ�� 2 �� 3 ���ÿɲ���
	{
		
		if (vis[1]==0 &&(num==2 || num>3)) res*=2;//Ҫ�� 2 û���� ���� num������3  ���ұ�2 ��  ��ô������2
		if (vis[2]==0 && (num % 2==1)) res*=3;//Ҫ�� 3û���� ����num���ڻ��Ǵ���3 ������3 
	}
	else//������ʱ��  2��3 ����Ҫ��  ��1������� 5+1=6  5=2+3��
	{
		if (vis[1]==0) res*=2;//Ҫ��û���õ�2 ������� Ҳ����û���õ� 2�� ĳ�η�
		res*=3;//�ض���3   
	}

	if (res>max1)  //����ǰ�Ĳ�����max1 �Ƚ� Ҫ�Ǵ� �͸���
	{
		max1=res;
        /*�ڱ�������û���� �Ǹ������״̬��
		for(i=0;i<100;++i)
		{
			svis[i]=vis[i];
		}
		sk=k;
		*/
	}
}
//һ������
void work(int num,int k)
{
	int val;
	val=p[k];//ȷ��������Ϊ����
	vis[k]=0;//��ʼʱ0���� Ҳ���ǲ�ȡ
	if (val>num) //������ڵ�val�Ų��� �Ͷ�k-1���м��㲽��
	{
		checkres(num,k-1);
		return;
	}

    work(num,k+1);//��ȡ�õ�ǰ��������� 

	++(vis[k]);  //��ʾ��������val ���õ����������

    if (k<3)//2��3 �Ѿ���������⿼����   ������������ ����������  ֱ������ ��  4 �� 9
	{
		++(vis[k]);
		val=val*p[k];
	}

	while(val<num-1)//�Ե�ǰ������1-n   ��ǰ������n�η�  ���ڵ��� num-1   Ϊʲô��num-1 ��Ϊ ��������ʣ��1 �����û������
	{
		work(num-val,k+1);//ȡ�� ��ǰ������ĳ�η�  Ȼ�������������
		val=val*p[k];//����
		++(vis[k]);//����ݵ����鵱ȻҪ����
	}

	if (val==num) checkres(0,k);//����������õ��� num��ȻҪ������һ��
}

//����1Ԫ�ص�����
void findresult1(int num,int k)//ʣ�µ�����num��ǰ �������ǵ�k������
{
	int val;
	val=p[k];//ȷ������
	vis[k]=0;//��ʼʱ0���� Ҳ���ǲ�ȡ
	if (val>num)//ͬ��
	{
		if (num==2 || num==4) checkres(num,k-1);//���ֻ��ʣż�� ��Ȼ �Ǹ�1 �״�����
        return;
	}
	findresult1(num,k+1);//��ȡ�� ��ǰ����
	if (k==2) return;//��ʹ�� ��ǰ����������ĳ����  ��Ϊ ���Ҫ�õ�3 
	++(vis[k]);//����Ϊ1��
	if (k==1) //����2  ������2�� ��ȥ 1����������η�
	{
		++(vis[k]);
		val=val*p[k];
	}

	while(val<num-1)//����ͬ��
	{
		findresult1(num-val,k+1);
		val*=p[k];
		++(vis[k]);
	}
	if (val==num) checkres(0,k);
}

int main()
{
	int num;
	getprime();
	while(scanf("%d",&num),num!=0)//��������Ȧ�Ӹ���
	{
		memset(vis,0,sizeof(vis)); //�Ա�� ָ�������� ����ֵ
	    max1=0;//max1 ����ֵ
		work(num,1);//��ͨ����  ֻ��  6 �ſ��ܳ���1 ����� �� 2*3==6  6�����Ӧ����6 ����һȦ
		if (num>=6)//Ҫ�Ǵ���6  ���ܳ��� 1 �����
		{
			vis[0]=1;//�õ�6
			vis[1]=0;//����2
			vis[2]=0;//����3
			if (num>6) findresult1(num-6,1);//��1 ���������
			else checkres(0,0);//�������� �Ѿ�����
		}
		printf("%lld\n",max1);//������
	}
	return 0;
}