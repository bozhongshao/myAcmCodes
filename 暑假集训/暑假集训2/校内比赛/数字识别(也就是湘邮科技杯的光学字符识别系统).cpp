/*��λ�Ķ�Ӧ��ϵ
�㷨������û��ʲô�㷨����Ҫ���Ƕ����� ��ʾ7��  Ȼ������ȥ����
����� ���벻�̿� 200���� ����һ��͹���  �����Ժ�

  1
  _ 
2|_|6      �м����һ����7
3|_|5 
4
*/
#include<iostream>
using namespace std;
int w[7]={64,32,16,8,4,2,1};//1-7��  ��Ӧ�Ķ�����ת����10����
int bin[10]={126,6,91,79,39,109,125,70,127,111};//�ö����Ʊ�ʾ0-9 10������

int a[9];//�洢9λ��λ�ϵ���Ϣ
int d[9];//�洢9λ��λ��10���Ʊ�ʾ����Ϣ
int res[9];//�洢Ψһ�Ľ��

void init()//���뺯��
{
	char ch[3];
	int i;
	for(i=0;i<9;++i)
	{
		a[i]=0;
	}

	cin>>ch[1]>>ch[2];
	if (ch[1]=='_') a[0]|=w[0];
	for(i=1;i<9;++i)
	{
		cin>>ch[0]>>ch[1]>>ch[2];
		if (ch[1]=='_') a[i]|=w[0];
	}//֮ǰ�ǵ�һ�е����� ����ֻ���ܶ�1λ�ò���Ӱ��  ֻ�������2λ�ÿ���Ϊ_

	for(i=0;i<9;++i)
	{
		cin>>ch[0]>>ch[1]>>ch[2];
		if (ch[0]=='|') a[i]|=w[1];
		if (ch[1]=='_') a[i]|=w[6];
		if (ch[2]=='|') a[i]|=w[5];
	}//���ڶ��� ���ݶ��ϵ�ͼ���ı�a��i����ֵ

	for(i=0;i<9;++i)
	{
		cin>>ch[0]>>ch[1]>>ch[2];
		if (ch[0]=='|') a[i]|=w[2];
		if (ch[1]=='_') a[i]|=w[3];
		if (ch[2]=='|') a[i]|=w[4];
	}//��������
}

int find1(int num)
{
	int i;
	for(i=0;i<10;++i)
	{
		if (num==bin[i]) return i;
	}
	return -1;
}

bool judge1(int *ar)
{
	int sum;
	int i;
	sum=0;
	for(i=8;i>=0;--i)
	{
		sum+=(9-i)*ar[i];
	}
	if (sum%11==0) return true;
	return false;
}

int judge2(int loc)
{
	int temp[9];
	int i,j;
	int num;
	int count1;
	count1=0;
	for(i=0;i<7;++i)
	{
		if ((a[loc]&w[i])==0) 
		{
			num=find1(a[loc]|w[i]);
			if (num==-1) continue;
			for(j=0;j<9;++j)
			{
				temp[j]=d[j];
			}
			temp[loc]=num;
			if (judge1(temp)) 
			{
				count1++;
				if(count1==1)
				{
					for(j=0;j<9;++j)
					{
						res[j]=temp[j];
					}
				}
				if (count1==2) break;
			}
		}
	}
	return count1;
}

int judge3()
{
	int i;
	int count1;
	count1=0;
	for(i=0;i<9;++i)
	{
		count1+=judge2(i);
		if (count1>=2) {count1=2;break;} 
	}
	return count1;
}

void work()
{
	int i;
	int count1;
	int loc;
	count1=0;
	for(i=0;i<9;++i)
	{
		d[i]=find1(a[i]);
		if (d[i]==-1) 
		{
			loc=i;
			++count1;
			if (count1==2) break;
		}
	}

	if (count1>=2)//�����������޷�������ʾ
	{
		puts("failure"); return;
	}
	else if (count1==0)
	{
		if (judge1(d))//�ж��ܷ�������ʽ
		{
			for(i=0;i<9;++i)
			{
				cout<<d[i];
			}
			cout<<endl;
		}
		else 
		{
			switch(judge3())//����Ҫ������λ�������ʱ���е��ж�
			{
			case 0:puts("failure"); return;
			case 1:
				{
					for(i=0;i<9;++i)
					{
						cout<<res[i];
					}
					cout<<endl;
					return;
				}
			case 2:puts("ambiguous");return;
			}
		}
	}
	else//��һ�����޷���ʾ���ֵ�
	{
		switch(judge2(loc))//��һλ�����е�����ж�
		{
		case 0:puts("failure"); return;
		case 1:
			{
				for(i=0;i<9;++i)
				{
					cout<<res[i];
				}
				cout<<endl;
				return;
			}
		case 2:puts("ambiguous");return;
		}
	}


}


int main()
{
	char ch;//����һ���ַ�  һ����. ���Կ��Բ���
	while(cin>>ch)
	{
		init();//����
		work();//�������
	}
	return 0;
}