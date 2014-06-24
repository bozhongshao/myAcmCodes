/*
�㷨������֧�֣�minCircle(�ռ�)=�ռ��� A=a��  minCircle(A) Բ��Ϊa  �뾶Ϊ0   
��СԲ ���ɱ߽������3����ȷ�� �п�����������ȷ����
��Ȼ���� ���ڵ㼯B  ����minCircle(B)==minCircle(A) |B|<=3 ����a������B��  minCircle(A-a) ==minCircle(A) ����aû��ϵ
���� a����B�� minCircle(A-a)!=minCircle(A) ��û��a��СԲ�ͻᷢ���ı�  ��СԲ����B������  
*/
#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
#define MAX 1005 

typedef struct TPoint
{
	double x,y;
}TTriangle[3],TList[MAX];

struct TCircle
{
	double r;
	TPoint centre;
};

// typedef TTriangle TTriangle;

int casenum,n=0;//������ �͵�ĸ���

TList a;  //�������

TCircle c; //������



double distance1(TPoint p1,TPoint p2)//�����������
{
	return sqrt(double((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

double triangleArea(TTriangle t)//����Բ���ڽ����������
{
	return abs(t[0].x*t[1].y+t[1].x*t[2].y+t[2].x*t[0].y-t[1].x*t[0].y
		-t[2].x*t[1].y-t[0].x*t[2].y)/2;
}




TCircle circumcircleOfTriangle(TTriangle t)//�����Բ
{
	TCircle tmp;
	double a,b,c,c1,c2;
	double xA,yA,xB,yB,xC,yC;
	a=distance1(t[0],t[1]);
	b=distance1(t[1],t[2]);
	c=distance1(t[2],t[0]);
	tmp.r=a*b*c/triangleArea(t)/4;
	xA=t[0].x;yA=t[0].y;
	xB=t[1].x;yB=t[1].y;
	xC=t[2].x;yC=t[2].y;
	c1=(xA*xA+yA*yA-xB*xB-yB*yB)/2;
	c2=(xA*xA+yA*yA-xC*xC-yC*yC)/2;
	tmp.centre.x=(c1*(yA-yC)-c2*(yA-yB))/
		((xA-xB)*(yA-yC)-(yA-yC)*(xA-xB));
return tmp;
}



void init()//��������
{
	int i;
	cin>>n;
	for(i=0;i<MAX;i++)//��ʼ��a����
	{
		a[i].x=a[i].y=0;
	}
	for(i=1;i<=n;i++)//����������
		cin>>a[i].x>>a[i].y;
}




TCircle MinCircle2(int tce,TTriangle ce)
{
	TCircle tmp;
	tmp.centre.x=tmp.centre.y=0;//��ʱԲ��Բ�ĺͰ뾶��ʼ��Ϊ0
	tmp.r=0;
	switch(tce)
	{
	case 0:tmp.r=-2;break;//û�е����� ���뾶��Ϊ-2
	case 1:tmp.centre=ce[0];break;//һ�������ȷ��Բ��
	case 2://������ һ����������߶�Ϊֱ��
		tmp.r=distance1(ce[0],ce[1])/2;
		tmp.centre.x=(ce[0].x+ce[1].x)/2;
		tmp.centre.y=(ce[0].y+ce[1].y)/2;
		break;
	case 3://����������  �������ε����Բ
		tmp=circumcircleOfTriangle(ce);
	}
	return tmp;//����ȷ����Բ
}



void MinCircle(int t,int tce,TTriangle ce)//�����ݹ���̷�����  ÿһ��ȷ��һ����   Ȼ�󲻶ϵĸ���
{
	int i,j;
	TPoint tmp;
	c=MinCircle2(tce,ce);//������СԲ
	if(tce==3)  return ;//B���������������
	for(i=1;i<=t;i++)
	{
		if(distance1(a[i],c.centre)>c.r)//�����i���㲻����СԲ֮�� ˵��ǰ��ѡ���Ǹ��㲻�� ����ѡ ��һ��Ĳ���
		{
			ce[tce]=a[i];//����� �ŵ�tceλ���� tce�Ǵ�0��ʼ��  ���Լ����¼���������B������tce+1����
			MinCircle(i-1,tce+1,ce);//��a[i]����B�����е�ǰ ǰi��������СԲ
			// ��a[i]��a[1] ���н���  ���ǲ�����ʲôΪ�˱�̷���  ����һ�ּ�֦�Ĳ���  ͨ�������п���ѡΪ���Բ����ķ���ǰ����������Բ�Ĵ���
			tmp=a[i];
			for(j=i;j>=2;j--)
				a[j]=a[j-1];
			a[1]=tmp;
		}
	}
}






void run()
{
	TTriangle ce;//����ce���� �洢ȷ��Բ��������
	MinCircle(n,0,ce);//���ú�������СԲ
	//������
	printf("%.2lf ",c.centre.x);
	printf("%.2lf ",c.centre.y);
	printf("%.2lf\n",c.r);
}


int main()
{
	cin>>casenum;
	while(casenum--)
	{
		init();//��������
		run();
	}
	return 0;
}