#include <iostream>
using namespace std;
int total;
   int n,m;
   long long per;
long long s[130000];
long long num[130000];
void totalnum(long x)
{	//����m������������
	int i;
	total=0;
	for(i=2;i*i<=x;i++){
		if(x%i==0)	{
			while(x%i==0)
				x=x/i;
			num[total]=i;
			total++;
		}
	}
	if(x!=1) {
		num[total]=x;
		total++;
	}		
}
long long por(long long x, long long y) {
	//����m��n�η���
	long long  i,k;
	k=x;
	for(i=1;i<y;i++)
		x=k*x;
	return x;
}

void get(int a, int b, int c) {
	//���������i+1�����ӵĸ���
	int i;
	if(b==c){
		long long t=m;
		for(i=0;i<c;i++){
			t=t/s[i];
		}
		per+=por(t,n);
	}
	else{
		for(i=a;i<total;i++)
		{
			s[b]=num[i];
			get(i+1,b+1,c);
		}
	}
}

int main()
{
	int k;
	long long res;
	int i;
	cin>>k;
	while(k>0) 
	{
		cin>>n>>m;
		totalnum(m);  //����m������������
		res=por(m,n);  //����m��n�η���
		for(i=0;i<total;i++){
			per=0;
			get(0,0,i+1);   //���������i+1�����ӵĸ���
			if(i%2==0){  res-=per; } 
			else{  res+=per; }
		}
		printf("%lld\n",res);
		k--;

	}
	return 0;
}

