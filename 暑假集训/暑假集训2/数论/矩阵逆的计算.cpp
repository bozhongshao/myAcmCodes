#include<iostream>
#include<cmath>
using namespace std;

double map[150][150];
#define eps 1e-6

bool Solve(/*double map[][MAX],*/int n)//���ĺ��� map�洢���� 
{
	int s,i,j;
	for(s=0;s<n;++s)
	{
		for(i=s;i<n;++i)
		{
			if (fabs(map[i][s])>eps) break;
		}
		if (i==n) return false;
		if (i!=s) //����s��s��  ����0
		{
			for(j=0;j<2*n;++j)
			{
				double temp=map[s][j];
				map[s][j]=map[i][j];
				map[i][j]=temp;
			}
		}

		double a=map[s][s];//���Խ����ϻ�Ϊ1
		for(i=0;i<2*n;++i)
		{
			map[s][i]/=a;
		}

		for(i=0;i<n;++i)//��Ԫ Ҳ���ǽ����з��̵� s�б�Ϊ0  
		{
			if (i==s) continue;
			double b=map[i][s];
			for(j=s;j<2*n;++j)
			{
				map[i][j]-=map[s][j]*b;
			}
		}
	}
	return true;
}
int main()
{
	int casenum,t,n;
	int i,j;
	scanf("%d",&casenum);
	for(t=1;t<=casenum;++t)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				scanf("%lf",&map[i][j]);
			}
			for(j=n;j<2*n;++j)
			{
				if (i==j-n) {map[i][j]=1;continue;}
				map[i][j]=0;

			}
		}
		printf("Matrix %d :",t);
		if (Solve(n))
		{
			putchar('\n');
			for(i=0;i<n;++i)
			{
				for(j=n;j<2*n-1;++j)
				{
                    printf("%.6lf ",map[i][j]);
				}
				printf("%.6lf\n",map[i][j]);
			}
		}
		else 
		{
			puts(" NO.");
		}
	}
	return 0;
}