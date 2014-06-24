#include <iostream>   
using namespace std;   
#define MAXN 205   
#define INF 2110000000   
#define MIN(x,y) (x<y?x:y)   
int map[MAXN][MAXN];   
  
int max_flow(int num,int map[][MAXN],int source,int sink)//�������壺������� ���� Դ�� ���   
{

    int my_queue[MAXN],queue_first,queue_end;//���������� ʵ��BFS����·��    
    int pre[MAXN],min_flow[MAXN];//��¼���ĸ��ڵ� ��ǰ·������С��һ�ε�ֵ��Ҳ������ֵ   
    int flow[MAXN][MAXN];//��¼��ǰ�����е���   
    int ans=0;//���ս��   
    memset(flow,0,sizeof(flow));   
    while(1)//һֱѭ����ֱ������������·��   
    {   
        queue_first=0;//��ʼ������   
        queue_end=0;   
        my_queue[queue_end++]=source;   
        memset(pre,-1,sizeof(pre));   
        min_flow[source]=INF;   
        pre[source]=-2;//Դ��ĸ��ڵ��������ʾ   
        while(queue_first<queue_end)//BFSѰ������·��   
        {   
            int temp=my_queue[queue_first++];//������   
            for(int i=0;i<num;i++)//�ɽ��temp������չ   
            {   
                if(pre[i]==-1&&flow[temp][i]<map[temp][i])//�����i��δ��̽���������һ��п�������   
                {      
                    my_queue[queue_end++]=i;//�������   
                    pre[i]=temp;//��ʾ���ڵ�   
                    min_flow[i]=MIN(min_flow[temp],(map[temp][i]-flow[temp][i]));//���min_flow   
                }   
            }   
            if(pre[sink]!=-1)//sink�ĸ��ڵ㲻Ϊ��ʼֵ��˵��BFS�Ѿ��ҵ���һ��·��   
            {   
                int k=sink;   
                while(pre[k]>=0)   
                {   
                    flow[pre[k]][k]+=min_flow[sink];//���µ���������flow   
                    flow[k][pre[k]]=-flow[pre[k]][k];   
                    k=pre[k];   
                }   
                break;   
            }   
        }   
        if(pre[sink]==-1) return ans;//����������·��������   
        else ans+=min_flow[sink];
    }      
} 


int main()   
{   
    int t,m,f;
	int ans;
	bool al[205];
	int i,j,k,num;
	scanf("%d",&t);
    while(t--)   
    { 
		scanf("%d%d",&m,&f);
        memset(map,0,sizeof(map));
        memset(al,false,sizeof(al));
        for(i=1;i<=f;i++)   
        {   
			scanf("%d",&k);
			for(j=1;j<=k;++j)
			{
            scanf("%d",&num);
			if (!al[num]) al[num]=true;
            map[i][num+f+1]=1;
			}
        }

		for(i=0;i<m;++i)
		{
			if (!al[i]) break;
		}
		if (i<m) {puts("impossible");continue;}

		for(i=0;i<m;++i)
		{
			map[i+f+1][m+f+1]=1;
		}
		for(i=1;i<=m;++i)
		{
			for(j=1;j<=f;++j)
			{
				map[0][j]=i;
			}

        ans=max_flow(m+f+2,map,0,m+f+1);
		if (ans==m) break;
		}
		printf("%d\n",i);
    }   
    return 0;   
}  

