#include<iostream>
#include<set>
using namespace std;

struct wood//�洢ľ׮����Ϣ
{
	int A,B;//��A���ӽ�B����
};

int n;//ľ׮����Ŀ

wood w[1002];//�洢ľ׮��Ϣ������
set <int> ov;
set <int > v;



int main()
{
	int j,time1;
	set <int>::iterator i;
	while(cin>>n)
	{
	w[0].A=INT_MAX;
	w[n+1].A=INT_MAX;
	for(j=1;j<=n;++j)
	{
		cin>>w[j].A>>w[j].B;
   	}
	time1=0;
	v.insert(0);
	while(time1<=2520)
	{
		ov=v;
		v.clear();
		for(i=ov.begin();i!=ov.end();++i)
		{
			for(j=-5;j<=5;++j)
			{
				if (*i+j>=0&&*i+j<=n+1&&(time1+1)%(w[*i+j].A+w[*i+j].B)<=w[*i+j].A&&(time1+1)%(w[*i+j].A+w[*i+j].B)!=0) v.insert(*i+j);
			}
		}
		if (v.empty()) {puts("NO");return 0;}//��·����
        time1++;
		for(i=v.begin();i!=v.end();++i)
		{
			if (*i==n+1) break;//�ҵ���
		}
		if (i!=v.end()) break;
	}
	if (time1==2521) {puts("NO");}
	else cout<<time1<<endl;
	v.clear();
	}
	return 0;
}