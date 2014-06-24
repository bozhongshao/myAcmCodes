/*
�㷨Ҫ�㣺
1�����ϱ�����
2��С�� ����֮����п�¥��    Ҳ����Ҫ��ȥ������������
3����ʵ����ÿ��̰���������һ�� ����һ��Ҫ���� ������ȥ ����µ�����  

������Ŀ���㷨��
��ͳ�Ƴ�ÿһ�� Ҫ���µĴ���   Ȼ���������  ѡ��Զ����������ɣ�������Ϊ���Բ������� 
��Ŀ��������Զ�Ĵ𰸾���Ψһ�� ����Ҫ�ǲ����ȵĻ�  �ͻ�����һ�ִ�

*/
//program deliver
#include<iostream>
using namespace std;

const int floors =10;// �ܵ�¥����

int uptable[floors+1];//��¥������
int downtable[floors+1];//��¥������
int Eup[floors+1];//
int Edown[floors+1];// 
int k,m;//k��ʾ�ж��ٸ�����
int package[51][3];//�洢������Ͷ������
int floor;//��ǰ�Ĳ���
void createtable()//��������ת����ͼ
{
	int i,j;
	memset(uptable,0,sizeof(uptable));//��ʼ����¥������
	memset(downtable,0,sizeof(downtable));//��ʼ����¥������
	for(i=1;i<=k;++i)
	{
		if (package[i][1]==package[i][2]) continue;//���ö�
		if (package[i][1]<package[i][2]) 
		{//���Ҫ��¥ ͳ��uptable�Ĵ���
			for(j=package[i][1];j<package[i][2];++j)
			{
				++(uptable[j]);
			}
		}
		else 
		{
			for (j=package[i][2];j<package[i][1];++j)//���Ҫ��¥ ͳ��downtable�Ĵ���
			{
				++(downtable[j]);
			}
		}
	}
    
	for(i=0;i<floors+1;++i)
	{
		Eup[i]=uptable[i];Edown[i]=downtable[i];
	}
	
	for(i=1;i<=floors;++i)//��¥����¥�Ĵ�����Ҫ��ͬ�����uptable[i]��downtable[i]����Ҫȡ���ܵ����ֵ ���˾�Ҫ�� ���˾�Ҫ��
    if (uptable[i]>downtable[i]) downtable[i]=uptable[i];
	else uptable[i]=downtable[i];
	
	for (i=floors-1;i>=1;--i) //  û�����»����������յش� �������ϻ�������
	{
		if (uptable[i]==0 && uptable[i+1]!=0) //�����û��¥���ǲ���Ҫ����������ȥ��
		{
			uptable[i]=1;downtable[i]=1;
		}
	}
	m=0;
	for (i=1;i<=floors;++i)
	{
		m+=uptable[i];//ͳ��һ��Ҫ�����ߵ��ܲ���
	}
	cout<<m<<endl;
}

void output(int x,int y,int z)
{
	printf("%d %d %d\n",x,y,z);//��� ��x�㵽y��    Я���������
}

bool upstair()//��һ��¥
{
	int i;
	bool bb;
	int p;
	if (uptable[floor]==0) return false;//����Ҫ������
	//�ж��Ƿ��ܹ���¥
	bb=true;
	p=0;
	for(i=1;i<=k;++i)//���������floor�����Ҫ���ϰ�Ļ���ҳ�Ŀ������ڵĲ����ߵĻ����Ϊ����p
		if (package[i][1]==floor && package[i][1]<package[i][2]) 
		{
			if (p==0) p=i;
			else if (package[p][2]<package[i][2]) p=i;
			bb=false;
		}

		if (bb) //���floor��û�л�����Ҫ���ϰᣬ��floor�����滹��û�л����������費��Ҫ������
		{
			if (Eup[floor]==uptable[floor]) return false;//��Ҫ����uptableû����Ϊ�Ϸ���������ı䣨�˵ش�Ϊ��մ�������� ����Ҳû�б���Ҫ��� �µ�����Ҫִ�� 
			else//�������������һ�� 
			{
				output(floor,floor+1,0);
			}
		}
		else 
		{
			++package[p][1];//���ﱻ������һ�㣬���������ڵĲ���
			output(floor,floor+1,p);//�����p������һ�� 
			Eup[floor]=Eup[floor]-1;//�����һ�����ϵ������һ������ Eup��ԭʼ������Ҫ�� ÿ��¥�������ƶ�����
		}
		uptable[floor]=uptable[floor]-1;//��Ҫ�����ߵĲ�����1
		floor+=1;
	return true;//�ɹ�������һ��
}

bool downstair()//��һ��¥
{
	int i;
	bool bb;
	int p;
	if (floor==1) return false;//�ж��Ƿ�����¥
	bb=true;
	p=0;
	//���������floor�����Ҫ���°�Ļ���ҳ�Ŀ������ڲ����͵Ļ����Ϊ����p
	for(i=1;i<=k;++i)
	{
		if (package[i][1]==floor && package[i][1]>package[i][2])
		{
			bb=false;
			if (p==0) p=i;
			else if (package[p][2]>package[i][2]) p=i;
		}
	}

	if (bb) //���floor��û����Ҫ���°�Ļ����floor�����滹��û�л����������費��Ҫ������
	{
		if (Edown[floor-1]==downtable[floor-1]) return false;
		else 
		{
			output(floor,floor-1,0);
		}
	}
	else 
	{
		Edown[floor-1]=Edown[floor-1]-1;
		package[p][1]=package[p][1]-1;//���ﱻ������һ����������ڵĲ���
		output(floor,floor-1,p);//�����p������һ��
	}

	downtable[floor-1]=downtable[floor-1]-1;//��Ҫ�����ߵĲ�����1 
	floor=floor-1;//���ڲ��1  ������һ��
	return true;
}



void process()
{
	floor=1;//�ӵ�һ�㿪ʼ
	do
	{
		if (!upstair()) //���Ͼ�����¥
			if (!downstair()) //�����Ͼ� ����¥����¥
				if (floor!=1)//�����ϲ����� ���ǲ��ڵ�һ�� ���ǳ����˴���
				{
					puts("Error!");
					return;
				}
				else break;//�ڵ�һ�� ˵�����е������Ѿ������
	}while(1);
}

int main()
{
	int i;
   cin>>k;
   for(i=1;i<=k;++i) cin>>package[i][1]>>package[i][2];
   createtable();//����ͼ
   process();//  ��Ҫ����
}