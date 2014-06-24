#include<iostream>
#include<limits>

using namespace std;

const int MAXN = 501;
const int MAXE = 5201;
const int INF = numeric_limits<int>::max();

struct Edge
{
    int s;
    int e;
    int w;
};

int G[MAXN][MAXN];
Edge edges[MAXE];

bool BellmanFord(int n, int k)               //Bellman_Ford�㷨�ж��Ƿ���ڸ�Ȩ��·
{
    int d[MAXN];
    bool flag;
    
    /*for(int i=1; i<=n; i++)                  //���ӵ��������Ϊ0�ĳ���Դ��  ��ʵͼ���治���ڲ���ͨ������
    {
        d[i] = 0;
    }*/
	d[1]=0;

    for(int j=1; j<n; j++)
    {
        flag = false;
        for(int i=1; i<=k; i++)
        {
            if(d[edges[i].e] > d[edges[i].s] + edges[i].w)     //�ɳڲ���
            {
                d[edges[i].e] = d[edges[i].s] + edges[i].w;
                flag = true;
            }
        }
        if(!flag)
        {
            return true;
        }
    }

    for(int i=1; i<=k; i++)
    {
        if(d[edges[i].e] > d[edges[i].s] + edges[i].w)
        {
            return false;
       }
    }
    return true;
}    

int main()
{
    int F;
    int N,M,W;
    int s,e,t;
    int cntE;

    int i,j;

    cin>>F;
    while(F--)
    {
        cin>>N>>M>>W;

        for(i=1; i<=N; i++)
        {
            for(j=1; j<=N; j++)
            {
                G[i][j] = INF;
            }
        }

        for(i=0; i<M; i++)
        {
            cin>>s>>e>>t;
            if(G[s][e] > t)               //�����رߣ�����ֱ�Ӵ洢��
            {
                G[s][e] = t;
                G[e][s] = t;
            }
        }
        for(i=0; i<W; i++)
        {
            cin>>s>>e>>t;
            G[s][e] = -1 * t;
        }

        cntE = 0;
        for(i=1; i<=N; i++)             //���ڽӾ�������ȡ�ߣ�����߽��٣�����Ч����Bellman_Ford�ĸ��Ӷ�
        {
           for(j=1; j<=N; j++)
            {
                if(G[i][j] != INF)
                {
                    ++cntE;
                    edges[cntE].s = i;
                    edges[cntE].e = j;
                    edges[cntE].w = G[i][j];
                }
            }
        }

        if(BellmanFord(N,cntE))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    //system("Pause");
    return 0;
}