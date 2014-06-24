#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

const int INF = 0x3F3F3F3F; 
const int V = 305; 
const int E = 100005;
int pnt[E], cost[E], nxt[E]; 
int e, head[V],  dist[V]; 
bool vis[V]; 
int  cnt[V]; // ����д���
bool num[V];

int relax(int u, int v, int c){ 
	if( num[v] && dist[v] > dist[u] + c ) { 
		dist[v] = dist[u] + c; return 1; 
	} 
	return 0; 
} 
inline void addedge(int u, int v, int c){ 
	pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++; 
} 
int SPFA(int src, int n){// �˴��ö���ʵ�� 
	int  i; 
	memset(cnt, 0, sizeof(cnt)); // ��Ӵ��� 
	memset(vis, false, sizeof(vis)); 
	for( i=1; i <= n; ++i ) dist[i] = INF; 
	dist[src] = 0; 
	queue<int> Q; 
	Q.push(src); vis[src] = true; ++cnt[src]; 
	while( !Q.empty() ){ 
		int  u, v; 
		u = Q.front(); Q.pop(); vis[u] = false; 
		for( i=head[u]; i != -1; i=nxt[i] ){ 
			v = pnt[i]; 
			if( 1 == relax(u, v, cost[i]) && !vis[v] ) { 
				Q.push(v); vis[v] = true;  
				if( (++cnt[v]) > n ) return -1; // cnt[i]=Ϊ����д����������ж��Ƿ���ڸ�Ȩ��· 
			} 
		} 
	} 
	if( dist[n] == INF ) return -2; // src��n���ɴ��Щ��Ŀ��ʡ������ 
	return dist[n]; // ����src��n����̾��룬�������ⲻͬ���ı� 
} 


int main(void){ 
	int  n, m,q; 
	int x,y;
	int state;
	int ans,casenum;
	casenum=0;
	while( scanf("%d%d%d", &n, &m,&q),n!=0||m!=0||q!=0)
	{ 
		if (casenum) putchar('\n');
		++casenum;
		int  i, a, b, c; 
		e = 0; 
		memset(head, -1, sizeof(head));
		for(i=0;i<n;++i)
		{
			num[i]=false;
		}
		for( i=0; i < m; ++i ) 
		{
			// b-a <= c, �����(a, b):c ���ߵķ��򣡣��� 
			scanf("%d%d%d", &a, &b, &c); 
			addedge(a, b, c); 
		} 


		printf("Case %d:\n",casenum);
		for(i=0;i<q;++i)
		{
			scanf("%d",&state);
			switch(state)
			{
			case 0:
				{
					scanf("%d",&x);
					if (num[x]) printf("ERROR! At point %d\n",x);
					else num[x]=true;
					break;
				}
			case 1:
				{
					scanf("%d%d",&x,&y);
					if (!num[x] || !num[y]) 
					{
						printf("ERROR! At path %d to %d\n",x,y);
					}
					else 
					{
						if (x==y) puts("0");
						else 
						{
							ans=SPFA(x,y);
							if (ans==-2) puts("No such path");
							else printf("%d\n",ans);
						}
					}
				}
			}

		}
	} 
	return 0; 
} 
