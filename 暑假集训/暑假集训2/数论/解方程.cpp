#include<iostream>
#include<cmath>
using namespace std;
#define MAX 205
double mat[MAX][MAX];



bool Solve_X(/*double mat[][MAX],*/int n,int Xnum)//���ĺ��� mat�洢���� n��ʾ���̸��� Xnum��ʾδ֪���ĸ��� ��������Ľ������mat��i����X_num��
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

		for(i=0;i<n;++i)//��Ԫ Ҳ���ǽ����з��̵ĳ� s�б�Ϊ0  
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

int main()
{

}