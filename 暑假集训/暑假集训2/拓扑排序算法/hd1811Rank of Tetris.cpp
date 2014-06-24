/*���ò��鼯����ȵ������������ͬ��������ǵ�root���棬����1 = 2,2 = 3,���鼯��ĸ���1����ô��1��2��3���������ֿ���һ������1,Ȼ���ٽ��ߣ�Ȼ��ͺ����Ե����������ˣ���ͬһʱ�̷�����more than one zero degree node��ʱ��˵����ȷ���ˣ��������������֮�󣬻���һЩ���degree��Ϊ0����˵����ͻ������OK�� */


#include<iostream>
using namespace std;


int num[10001];
int rnum[10001];
int n,m;
int count1;


struct Record
{
	int pre,next;
};

struct node
{
	int num;
	struct node *next;
};

struct Elem
{
	int num,degree;
	struct node *next;
};
    Elem t[10001];

int find1(int x)
{
	int i=x;
	while(num[x]!=x)
	{
		x=num[x];
	}

	while(num[i]!=i)
	{
		num[i]=x;
		i=num[i];
	}

	return x;
}

void topsort()
{
	int i,lable;
	int count2,count3;
	node *p;
	bool UNCERTAIN;
	UNCERTAIN=false;
	count3=0;
	while(1)
	{
		count2=0;
		for(i=0;i<count1;++i)
		{
			if (t[rnum[i]].degree==0) 
			{
				++count2;
				lable=i;
			}
		}
		if (count2==0) break;
		++count3;
		if (count2>1 && !UNCERTAIN) UNCERTAIN=true;
        --(t[rnum[lable]].degree);
		p=t[rnum[lable]].next;
		while(p)
		{
			--t[p->num].degree;
			p=p->next;
		}
	}

	if (count3<count1) puts("CONFLICT");
	else if (UNCERTAIN) puts("UNCERTAIN");
	else puts("OK");
}

int main()
{
	int pre,next;
	char ch,sign;
	node *q;
	Record r[20001];
	int i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			t[i].degree=0;
			t[i].next=NULL;
			num[i]=i;
		}
		count1=0;
		while(m--)
		{
			scanf("%d%c%c%c%d",&pre,&ch,&sign,&ch,&next);
			
			switch(sign)
			{
			case '=':
				{
					pre=find1(pre);
			        next=find1(next);
					if (pre!=next)
					{
					if (pre<next) num[next]=pre;
					else num[pre]=next;
					}
					break;
				}
			case '>':
				{
					r[count1].pre=pre;
					r[count1++].next=next;
					break;
				}
			case '<':
				{
					r[count1].pre=next;
					r[count1++].next=pre;
				}
			}

		}


		for(i=0;i<count1;++i)
		{
			if (find1(r[i].next)==r[i].pre || find1(r[i].pre)==r[i].next) break; 
			++t[find1(r[i].next)].degree;
			q=new node;
			q->num=find1(r[i].next);
			q->next=t[find1(r[i].pre)].next;
            t[find1(r[i].pre)].next=q;
		}
		if (i<count1) {puts("CONFLICT"); continue;}
        count1=0;
		for(i=0;i<n;++i)
		{
			if (find1(i)==i) rnum[count1++]=i;
		}
		topsort();
	}
	return 0;
}

