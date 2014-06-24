#include <iostream>
#include <math.h>
using namespace std;

#define  N 25+5
#define  inf  -999999999999999.0//xΪ����С
#define  eps   1e-11
double up[N][2],low[N][2];
int n;

int deq(double p)//����Ҫ��
{
 return fabs(p) < eps ? 0 : (p > 0 ? 1 :-1);
}

int Cross(double p1[],double p2[])//���
{
 double d = p1[0]* p2[1] - p2[0]* p1[1];
 return deq(d);
}

int Direction(double pi[],double pj[],double pk[])//�ж�pi-pk��pi-pj�ķ�λ��˳ʱ�뻹����ʱ�룩
{
 double p1[2],p2[2];
 p1[0] = pk[0]-pi[0],p1[1] = pk[1]-pi[1];
 p2[0] = pj[0]-pi[0],p2[1] = pj[1]-pi[1];
 return Cross(p1,p2);
}

bool Intersect(double p1[],double p2[],double p3[],double p4[])//�ж�p1��p2ֱ�ߺ�p3��p4�߶��Ƿ��ཻ
{
 int d3,d4;

 d3 = Direction(p1,p2,p3);
 d4 = Direction(p1,p2,p4);

 if(d3 *d4 <= 0)
  return true;
 

 return false;
}

double Xnum(double y1,double x1,double ys,double xs,double kq,double kp)//��xֵ
{
 return (y1-ys + kp * xs - kq * x1)/(kp- kq);
}
double Cpu(double p1[],double p2[])//��p1��p2��λֱ�ߵ����xֵ
{
 int k =0;
 while(k < n && Intersect(p1,p2,up[k],low[k]))//ö�ٴӵ�1���յ㿪ʼ
  k ++;

 if(k ==0)//�����1���յ�Ͳ�����
  return inf;

 if(k == n)//������һ���յ�����㣬˵���ᵽ����Զ��
  return up[n-1][0];
//��k-1���Ĺյ㵽k���Ĺյ��н���
 double kq = (p2[1]-p1[1])/(p2[0]-p1[0]);
 double d = inf;
 if(Intersect(p1,p2,up[k-1],up[k]))//������Ϲܵ��н���
 {
  double kp = (up[k][1]-up[k-1][1])/(up[k][0]-up[k-1][0]);

  d = max(d,  Xnum(p1[1],p1[0],up[k-1][1],up[k-1][0],kq,kp));

 }
//����Ϊʲô��if�����Լ�����...
 if(Intersect(p1,p2,low[k-1],low[k]))//������¹ܵ��н���
 {
  double kp = (low[k][1]-low[k-1][1])/(low[k][0]-low[k-1][0]);

  d = max(d, Xnum(p1[1],p1[0],low[k-1][1],low[k-1][0],kq,kp));
 }

 return d;
}
int main()
{
 //freopen("F://C++����//ACM2//read.txt","r",stdin);
 //freopen("F://C++����//ACM2//write.txt","w",stdout);

 while(scanf("%d",&n), n)
 {
  int i , j;

  for(i = 0; i <n;i++)
  {
   scanf("%lf %lf",&up[i][0],&up[i][1]);
   low[i][0] = up[i][0];
   low[i][1] = up[i][1] -1.0;
  }

  double d = inf;
  bool flag =true;
  for(i = 0; i <n && flag;i++)
  {
   for(j = i+1; j <n && flag;j++)
   {
    d = max(d, Cpu(up[i] ,up[j]));//ö�ٵ�1���յ���ϵ�͵�2���յ���µ�
    d = max(d, Cpu(up[i] ,low[j]));//...
    d = max(d, Cpu(low[i], up[j]));//...
    d = max(d, Cpu(low[i], low[j]));//...

    if(deq(d- up[n-1][0]) ==0)//���������Զ���˳�
    {
     flag =false;
     break;
    }
   }
  }

  if(!flag)
   printf("Through all the pipe.\n");
  else
   printf("%.2lf\n", d);
 }
 return 0;
}

