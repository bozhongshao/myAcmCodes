//Program Car;
#include<iostream>
using namespace std;

int up,n1,m1,kills1,max1,m,n,r,c;// n��m�� r��Ԥ����λ c������r��Ԥ����λ��Ҫ�Ž��ĳ�����
int x[101],y[101],a[101];//x��y��ʾ�ų���λ��  a��ʾ�����ķ�ʽ



void solve(int wx,int wy)//�ź�ʣ��wx*wy��Ŀ�����
{
	int free,aa,bb,k,r0;
	free=n*m-wx*wy-r;//r��Ԥ��λ�õĳ���в�� ����û���ĵط�����Ŀ
	r0=c-free;//�����Ѿ��ܵ���в��λ��
	if (wx*wy<r0) return;//����ʣ�µ�λ�ò������㻹û�з���ĳ�����
    
	if (r0<=0)//���ʣ�µĳ������ ��c��Ԥ��λ���ϵĳ���в��λ��
	{
		k=wx*wy;
		if (k>max1) max1=k;
		return;
	}

	for (aa=1;aa<=wx;++aa) //���aa=[1-wx],bb=[1-wy],�󷽳����Ž� aa*wy+bb*wx-aa*bb>=r0 �����  �θ�������������
	{
		if (aa==wx)  bb=0 ;
		else
		{
			bb=(r0-aa*wy)/(wx-aa);//�ɹ�ʽ�ɵ�
			if (r0<aa*wy)  bb=0 ;//ռ aa�о��㹻��  ����bb����
			else  if ((r0-aa*wy)%(wx-aa)!=0)  ++bb;//���ռaa�в��� ���һ�Ҫ�ĳ�����r0-aa*wy���ܱ������Ѿ���aa��ռ�ݵķ��������ÿһ�еķ����������� ��ô����ռ������ Ҳ����bb���� ��Ϊbb���ɹ�ʽ����  ���ǹ�ʽ�������� �»���1
		}
		if (bb>=0)  
		{
			k=aa*wy+bb*wx-aa*bb;//aa bb ռ�ݵķ�����
			k=wx*wy-k;
			if (k>max1) max1=k;
		}
	}

}




void trys(int i,int wx,int wy)//��i��
{
	int j;
	if (i>r) //r��Ԥ����λ���ź���
	{
		solve(wx,wy);//���c�������복������
		return;
	}

	for (j=1;j<=i-1;++j) 
	{
		if ((x[j]==x[i])&&(a[j]==0))//��ֱ�ķ���ǰ��źõ�x��ȵ�
		{
			a[i]=0;
			trys(i+1,wx,wy);
			return;
		}

		if ((y[j]==y[i]) && (a[j]==1) )//��ķ�y��ȵ�
		{
			a[i]=1;
			trys(i+1,wx,wy);
			return;
		}
	}
	a[i]=0;//��ֱ�ķ�
	trys(i+1,wx-1,wy);
	a[i]=1;//��ķ�
	trys(i+1,wx,wy-1);
	a[i]=0;//�ָ�
}


int main()
{
	int i;
	cin>>n>>m>>r>>c;
	up=n*m-c-r;
	max1=-1;
	for (i=1;i<=r;++i) cin>>x[i]>>y[i];
	trys(1,n,m);
	cout<<max1<<endl;
}

