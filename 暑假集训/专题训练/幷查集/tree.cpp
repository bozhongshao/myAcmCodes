#include<iostream>
using namespace std;
struct Node
{
    int parent;
    int hight;
};
Node polong[100001];
bool visited[100001];//���ĳ����ֹ�
int find(int x) //���Ҹ�
{
	int st=x,q;
    while(x != polong[x].parent)
	{
		x = polong[x].parent;
	}
	 while(st != polong[st].parent)
	{
		q=polong[st].parent;
		polong[st].parent=x;
		st=q;
	}
    return x;
}

void merge(int a,int b)//�ϲ�
{
    if(polong[a].hight == polong[b].hight)
    {
        polong[a].parent = b;
        polong[b].hight += 1;
    }
    else if(polong[a].hight > polong[b].hight)
        polong[b].parent = a;
    else
        polong[a].parent = b;
}

int main()
{
    int maxn,minn,a,b,sign,i,test=0;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
		test++;
        if(a==-1 && b==-1)
            break;
        if(a==0 && b==0)
        {
            cout<<"Case "<<test<<" is a tree."<<endl;
            continue;
        }
        for(i=1;i<=100000;i++)//ע��ע��
        {
            polong[i].parent = i;
            polong[i].hight = 1;
            visited[i] = 0;
        }

        maxn = 0;
        minn = 100000;
        sign = 0;

        do{
            if(a > maxn)     maxn = a;
            if(b > maxn)    maxn = b;
            if(minn > a)    minn = a;
            if(minn > b)    minn = b;
            visited[a] = 1; 
            visited[b] = 1;
            a = find(a);
            b = find(b);
            if(a == b) //����ͬ��ʾ�л�·~
            {
                sign = -1;
                break;
            }
            else
                merge(a,b);

            scanf("%ld%ld",&a,&b);
            if(a==0 && b==0)
                break;                    
        }while(1);

        if(sign == -1) //��δ������
        {
            do{
                  scanf("%ld%ld",&a,&b);
                  if(a==0 && b==0)
                      break;
            }while(1);
        }

        if(sign == 0) //û�л�·���鿴�Ƿ���һ������
        {
            for(i=minn;i<=maxn;i++)
                if(visited[i] == 1 && polong[i].parent == i)
                    sign ++;
        }

        if(sign == 1)
            cout<<"Case "<<test<<" is a tree."<<endl;
        else
            cout<<"Case "<<test<<" is not a tree."<<endl;
    }
    return 0;
}