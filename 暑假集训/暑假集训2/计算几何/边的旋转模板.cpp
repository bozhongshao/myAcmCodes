#include<iostream>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
struct point{double x,y;};

point rot(point a,point b,double ang)//��һ������ת��  ��һ�� ��ת�ĽǶ�  ������һ�������  ����Ҫע�ⷵ�صĵ��ֵ�����Ǹ�-0 Ҫ����
{
	point ret;
	double ve[2];
	double angle;
	double r;
	ve[0]=b.x-a.x;
	ve[1]=b.y-a.y;
	r=sqrt(ve[0]*ve[0]+ve[1]*ve[1]);
	angle=acos(ve[0]/r);
	if (ve[1]<0) angle=2*pi-angle;//yΪ��ֵ  Ҫ��������
	angle+=ang;
	ve[0]=r*cos(angle);
	ve[1]=r*sin(angle);
	ret.x=a.x+ve[0];
	ret.y=a.y+ve[1];
	return ret;
}

int main()
{

	return 0;
}

1.����
��������ת
���У�x1�� y1�����ǣ�x0�� y0����ת��B��õ��ĵ㣬Ҳ����λ������R���ָ��ĵ㡣
����Χ��Բ�����ʱ����ת��ʽ
x1 = x0 * cosB - y0 * sinB
y1 = x0 * sinB + y0 * cosB
˳ʱ����ת�ͰѽǶȱ�Ϊ��
x1 = x0 * cosB + y0 * sinB
y1 = -x0 * sinB + y0 * cosB
