#include<iostream>
using namespace std;

int modExp(int a,int b,int n)//���㷨  ʵ���˽�b����ŵ�һ������ ������  a^c=(a^b)^d b*d==c
{
	int t,y;
	t=1;
	y=a;
	while(b!=0)
	{
		if (b%2==1) t=(t*y)%n;
		y=(y*y)%n;
		b=b/2;
	}
	return t;
}

int main()
{
	int a,b,n;
	int k;
	cin>>k;
	while(k--)
	{
		cin>>a>>b>>n;
		cout<<modExp(a,b,n)<<endl;
	}
	return 0;
}

/*��֪��Ϊʲô�����Щ
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,k,i;
	cin>>a>>b>>c;
	for(i=k=1;i<=b;i++)//����
		k=k*a%c;
	cout<<k<<endl;
	return 0;
}
*/