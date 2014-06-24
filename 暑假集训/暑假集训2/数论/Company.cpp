#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 205

struct Job
{
	string name;
	int value;
};
vector<Job> job;
double mat[MAX][MAX];
const double eps=1e-6;

bool cmp(const Job &a,const Job &b)
{
	return a.name<b.name;
}
bool Solve_X(/*double mat[][MAX],*/int n,int Xnum)//���ĺ��� mat�洢���� n��ʾ���̸��� Xnum��ʾδ֪���ĸ��� 
{
	int s,i,j;
	for(s=0;s<Xnum;++s)
	{
		for(i=s;i<n;++i)
		{
			if (fabs(mat[i][s])>eps) break;
		}
		if (i==n) return false;
		if (i!=s) //����s��s��  ����0
		{
			for(j=0;j<=Xnum;++j)
			{
				double temp=mat[s][j];
				mat[s][j]=mat[i][j];
				mat[i][j]=temp;
			}
		}

		double a=mat[s][s];//���Խ����ϻ�Ϊ1
		for(i=0;i<=Xnum;++i)
		{
			mat[s][i]/=a;
		}

		for(i=0;i<n;++i)//��Ԫ Ҳ���ǽ����з��̵ĳ� s�б�Ϊ0  ��ͬ�ش�Ҳһ������ ��Ȼ��ֻҪ��s+1��ʼ��
		{
			if (i==s) continue;
			double b=mat[i][s];
			for(j=s;j<=Xnum;++j)
			{
				mat[i][j]-=mat[s][j]*b;
			}
		}
	}
	return true;
}

int check_Ans(int n,int X_num)
{
	int i;
	for(i=X_num;i<n;++i)//����Ƿ��޽� �޽��򷵻�1
	{
		if (abs(mat[i][X_num])>eps) 
		{
			return 1;
		}
	}


	/*for(i=0;i<X_num;++i)//����Ƿ����� �����򷵻�2  ����� ֻ���ڳ������ж�
	{
	if (mat[i][i]==0) return 2;
	}*/

	for(i=0;i<X_num;++i)//����Ƿ�������  ���������򷵻�3
	{
		if ((fabs(mat[i][X_num]+eps-(int)(mat[i][X_num]+eps))>0.00001)) //����Ϊʲô�����-5�η�
		{
			return 3;
		}
	}

	for(i=0;i<X_num;++i)//����Ƿ񺬸�����  ���򷵻�4
	{
		if (mat[i][X_num]+eps<0) return 4;
	}

	return 0;//������������ ����0
}

int find1(const string &str)
{
	int i;
	for(i=0;i<int(job.size());++i)
	{
		if (job[i].name==str) return i;
	}
	return -1;
}
int main()
{

	double b[55];
	string str;
	int value;
	int X_num;
	int i,j;
	int loc;
	int n;
	int state;
	int equal;
	while(cin>>n)
	{
		X_num=0;
		equal=0;
		job.clear();

		for(i=0;i<MAX;++i)
		{
			for(j=0;j<MAX;++j)
			{
				mat[i][j]=0;
			}
		}
		for(i=0;i<n;++i)
		{
			cin>>str;
			if (str!=".")
			{
				cin>>value;
				loc=find1(str);
				if (loc==-1) 
				{
					++X_num;
					Job tmp;
					tmp.name=str;
					job.push_back(tmp);
					loc=int(job.size())-1;
				}
				mat[equal][loc]=value;
			}
			else 
			{
				cin>>value;
				b[equal++]=value;
			}
		}

		for(i=0;i<n;++i)
		{
			mat[i][X_num]=b[i];
		}
		//�������������
		if (!(Solve_X(equal,X_num))) {puts("Incomplete data");puts(".");continue;}//�ж϶������ڳ����н����ж�
		state=check_Ans(equal,X_num);
		if (state==1||state==3||state==4)
		{
			puts("Inconsistent data");puts(".");continue;
		}
		for(i=0;i<X_num;++i)
		{
			job[i].value=int(mat[i][X_num]+eps);
		}
		
		double min1,max1;
		min1=2100000000;
		max1=0;
		for(i=0;i<int(job.size());++i)
		{
			if (job[i].value<min1) min1=job[i].value;
			if (job[i].value>max1) max1=job[i].value;
		}
		if (max1/min1>=6) 
		{
			puts("Inconsistent data");puts(".");continue;
		}
		sort(job.begin(),job.end(),cmp);
		for(i=0;i<int(job.size());++i)
		{
			cout<<job[i].name<<" "<<job[i].value<<endl;
		}
		puts(".");
	}
	return 0;
}
