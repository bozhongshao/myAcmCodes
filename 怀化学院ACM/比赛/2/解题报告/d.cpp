#include <stdio.h>
#include <string.h>
int que[1000001][2];
int v[200001];
int n,k;
int e,h,t;
int bfs()
{
	if(k==n) return 0;
	e=h=0; //hΪ��ͷ  eΪ��β
	memset(v,0,sizeof(v)); //v���鱣�沽��
	que[++e][0]=n;v[n]=1;
	que[e][1]=0;
	while(e-h)
	{
		h++; //����
		t=que[h][0]+1;//ǰ��һ��
		if(t<=200000 && !v[t])//��չ�ڵ�
		{
			v[(que[++e][0]=t)]=que[h][1]+1;
			que[e][1]=que[h][1]+1;
		}
		t=que[h][0]-1;//����һ��
		if(t>=0 && !v[t])//��չ�ڵ�
		{
			que[++e][0]=t;
			que[e][1]=v[t]=que[h][1]+1;
		}
		t=2*que[h][0];//��Ծ
		if(t<=200000 &&!v[t])//��չ�ڵ�
		{
			que[++e][0]=t;
			que[e][1]=v[t]=que[h][1]+1;
		}
		if(v[k]) return v[k];
	}
	return -1;
}
int main()
{
	while(scanf("%d%d",&n,&k)+1)
	{
		printf("%d\n",bfs());
	}
	return 0;
}