
#include<iostream>
#include <math.h> 
using namespace std;


const double pi=acos((double)-1); 
//����Բ�Ľ�lat��ʾγ��,-90<=w<=90,lng��ʾ����  lat��ʾγ�� ��Χ��-90--+90  ��Ϊ�� ��Ϊ�� ����Ϊ���ڵ��� 0 С��360��
//�����������ڴ�Բ�ӻ���ӦԲ�Ľ�,0<=angle<=pi 
double angle(double lng1,double lat1,double lng2,double lat2)
{ 
	double dlng=fabs(lng1-lng2)*pi/180; 
	while (dlng>=pi+pi) dlng-=pi+pi; 
	if (dlng>pi) dlng=pi+pi-dlng;
	lat1*=pi/180,lat2*=pi/180;
	return acos(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2));
}

//�����������,rΪ��뾶
inline double sphere_dist(double r,double lng1,double lat1,double lng2,double lat2)
{ 
	return r*angle(lng1,lat1,lng2,lat2); 
}

int main()
{
    double la1,la2,m,ing1,ing2;
	double r,result;
	char dir;
	r=6370;
	while(cin>>la1)
	{
		cin>>m>>dir;
		la1+=m/60;
		if (dir=='S') la1*=-1;
		cin>>ing1>>m>>dir;
        ing1+=m/60;
		if (dir=='W') ing1=360-ing1;
        cin>>la2>>m>>dir;
        la2+=m/60;
		if (dir=='S') la2*=-1;
		cin>>ing2>>m>>dir;
        ing2+=m/60;
		if (dir=='W') ing2=360-ing2;
		result=sphere_dist(r,ing1,la1,ing2,la2);
		printf("%.3f\n",result);
	}
	return 0;
}