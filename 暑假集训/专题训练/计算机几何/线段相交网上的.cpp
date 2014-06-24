#include <cmath>
#include <iostream>
using namespace std;

#define PRECISION 1e-8

struct Point
{
	double x, y;
};//ƽ���ϵĵ�

bool isEqual(Point a, Point b)
{
	return (a.x == b.x) && (a.y == b.y);
}

int dbcmp(double d)
{
	if (fabs(d) < PRECISION)
		return 0;
	return d > 0 ? 1 : -1;
}//����ں���,���⾫�����

double length(double x, double y)
{
	return sqrt(x*x + y*y);
}//������ģ

double dotdet(double x1, double y1, double x2, double y2)
{
	return x1*x2 + y1*y2;
}//�������

double det(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}//�������

int cross(Point a, Point c, Point d)
{
	return dbcmp( det(a.x-c.x, a.y-c.y, d.x-c.x, d.y-c.y) );
}//������������,a��cd�Ҳ෵��1,��෵��-1,���߷���0

bool between(Point a, Point c, Point d)
{
	return dbcmp( dotdet(c.x-a.x, c.y-a.y, d.x-a.x, d.y-a.y) ) != 1;
}//��cross(a, c, d)==0��ǰ����,��a���߶�cd�ڲ�����true

int segIntersect(Point a, Point b, Point c, Point d)
{
	int a_cd = cross(a, c, d);
	if (a_cd == 0 && between(a, c, d))
		return 2;
	
	int b_cd = cross(b, c, d);
	if (b_cd == 0 && between(b, c, d))
		return 2;
	
	int c_ab = cross(c, a, b);
	if (c_ab == 0 && between(c, a, b))
		return 2;
	
	int d_ab = cross(d, a, b);
	if (d_ab == 0 && between(d, a, b))
		return 2;

	if ((a_cd ^ b_cd) == -2 && (c_ab ^ d_ab) == -2)
		return 1;
	
	return 0;
}//���߶��ཻ���,0--���ཻ,1--�淶�ཻ,2--���淶�ཻ(���ڶ˵���غ�)

void intersectPoint(Point a, Point b, Point c, Point d, Point &e)
{
	double sc, sd;
	
	sc = fabs( det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) );
	sd = fabs( det(b.x-a.x, b.y-a.y, d.x-a.x, d.y-a.y) );
	e.x = (sc * d.x + sd * c.x) / (sc + sd);
	e.y = (sc * d.y + sd * c.y) / (sc + sd);
}//���߶ι淶�ཻʱ,�õ�e���ؽ���

bool GetPoint(Point a, Point b, Point c, Point d, Point e)
{
	bool flag = true;

	if (isEqual(a, c) || isEqual(a, d))
	{
		e.x = a.x;
		e.y = a.y;
	}
	else if (isEqual(b, c) || isEqual(b, d))
	{
		e.x = b.x;
		e.y = b.y;
	}
	else if (isEqual(c, a) || isEqual(c, b))
	{
		e.x = c.x;
		e.x = c.y;
	}
	else if (isEqual(d, a) || isEqual(d, b))
	{
		e.x = d.x;
		e.y = d.y;
	}
	else if (between(a, c, d) && cross(b, c, d) != 0)
	{
		e.x = a.x;
		e.y = a.y;
	}
	else if (between(b, c, d) && cross(a, c, d) != 0)
	{
		e.x = b.x;
		e.y = b.y;
	}
	else if (between())
	return flag;
}

int main()
{
	Point a, b, c, d, e;
	int n, t;
	bool flag;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;
		cin >> d.x >> d.y;
		t = segIntersect(a, b, c, d);
		if (t == 0)
			cout << "NO" << endl;
		else if (t == 1)	//�淶�ཻʱ�󽻵�
		{
			intersectPoint(a, b, c, d, e);
			printf("(%.2lf,%.2lf)\n", e.x, e.y);
		}
		else	//���淶�ཻ�Ҳ��غ�ʱ�󽻵�
		{
			flag = GetPoint(a, b, c, d, e);
			if (!flag)
				cout << "NO" << endl;
			else
				printf("(%.2lf,%.2lf)\n", e.x, e.y);
		}
	}
	
	return 0;
}