#include<iostream>
using namespace std;

int s[105][105],r[105][105],temp[105][105];
int min_1,m,n;
void index(int f)
{   
	int i,j,k,count,la,temp1;
	count=0;
	//�ָ���ʼ״̬
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			temp[i][j]=s[i][j];
		}
	}

	//������һ�к͵�f��
	if (f!=0)
	{
		for(i=0;i<m;i++)
		{
			temp1=temp[i][0];
			temp[i][0]=temp[i][f];
			temp[i][f]=temp1;
		}
		count++;
	}

	//ƥ���һ�� ����ƥ��ľͷ�
	for(i=0;i<m;i++)
	{
		if (temp[i][0]!=r[i][0])
		{
			for(j=0;j<n;j++)
			{
				if (temp[i][j]) temp[i][j]=0;
				else temp[i][j]=1;
			}
			count++;
		}
	}
	//�ӵڶ��п�ʼ����ƥ�� ��ƥ���ϵĲ������ܾ͵������� �Ҳ�����˵������������  �ҵ�ʱ�����ҵ���������Ҳ��Ҫ���е����
	for(j=1;j<n;j++)
	{
		la=1;
		for(i=0;i<m;i++)
		{
			if (temp[i][j]!=r[i][j]) break;
		}
		if (i>=m) continue;//ƥ�����˼���������
		la=0;
		for(k=j+1;k<n;k++)
		{
			for(i=0;i<m;i++)
			{
				if (temp[i][k]!=r[i][j]) break;
			}
			if (i<m) continue;
			//la=k;
			//break;
			if (!la) la=k;
			for(i=0;i<m;i++)//�Ƿ�Ҫ��������Ҳ��Ҫ����   ��Ҫ���ֿ���Ҳ�����ύ��ȷ �������ݵĲ�ȫ�� 
			{
				if (r[i][j]!=temp[i][k]) break;
			}
			if (i<m) continue;
			la=k;
			break;
		}

		if (la==0) break;
		for(i=0;i<m;i++)
		{
			temp1=temp[i][j];
			temp[i][j]=temp[i][k];
			temp[i][k]=temp1;
		}
		count++;
	}
	if (j<n) return;
	if (min_1>count) min_1=count;
}
int main()
{
	int t,i,j,f;
	scanf("%d",&t);
	while(t--)
	{
		min_1=INT_MAX;
		scanf("%d%d",&m,&n);
		if (m<=0||n<=0) {puts("0");continue;}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&s[i][j]);

			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&r[i][j]);
			}
		}
		for(f=0;f<n;f++)
		{
			index(f);//����f�����һ�н��н��� ���б任
		}

		if (min_1==INT_MAX) puts("-1");
		else printf("%d\n",min_1);
	}
	return 0;
}