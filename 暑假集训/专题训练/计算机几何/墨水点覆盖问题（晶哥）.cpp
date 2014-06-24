/*
����

Maxwell��һ����Ƥ���к��� 
һ�죬�����ְ��ָɾ���ǽ��īˮŪ���ˣ���ʱ��������ܿ��Ҫ�����ˡ�Maxwell����һ���ɫ��͹�����ȥ��ס��Щīˮ�㡣���ܸ������������С�����͹���������ס��Щīˮ���� 
���ڣ�������Щīˮ������꣬����ش���ܸ�ס����īˮ���͹�����ʹ�����С�� 

����

����ĵ�һ����һ��ȷ����������T��T�ǲ��������������� 
ÿ�����������ĵ�һ����һ��������N��1��N��105����N��īˮ�ĵ����������N�У���i�а���������Xi��Yi(0��Xi,Yi<20000)��ʾ��i��īˮ������ꡣ����֮���ÿո�ֿ���

���

����ÿ�����������������һ����ɣ���ÿ�����������С���������һʵ��������С�����һλ��

��������

2
4
0 0
1 0
0 1
1 1
2
0 0
0 1

�������

1.0
0.0

��Ŀ����

CN(CN:���� EN:Ӣ�� JP:����)
*/
#include <iostream>   //cout, cin
#include <algorithm>  //copy sort
#include <iterator>   //ostream_iterator
#include <vector>     //vector
#include <queue>      //queue
#include <stdlib.h>   //srand rand
#include <time.h>     //time
#include <limits>     //numeric_limits
#include <math.h>     //sqrt
#include <assert.h>   //assert

class Point
{
public:
	Point( double x=0, double y=0 ) : m_x(x), m_y(y) {}
public:
	double m_x;
	double m_y;
};

double area;

std::istream& operator>> (std::istream& in, Point& p)
{
	return (in>>p.m_x>>p.m_y);
}

std::ostream& operator<< (std::ostream& out, const Point& p)
{
	return (out<<"x="<<p.m_x<<" y="<<p.m_y);
}

class CmpXY
{
public:
	bool operator() (const Point& l, const Point& r)
	{
		bool ret;
		if ( l.m_x<r.m_x )
		{
			ret=true;
		}
		else if ( l.m_x==r.m_x )
		{
			if ( l.m_y<r.m_y )
			{
				ret=true;
			}
			else
			{
				ret=false;
			}
		}
		else
		{
			ret=false;
		}
		return ret;
	}
};

void findup(std::vector<Point>& in, const Point& p1, const Point& p2, std::vector<Point>& out)
{
	std::vector<Point> up;  //���ϰ���
	Point upp; //����
	double uph=0; //����
	double h;
	std::vector<Point>::iterator iter=in.begin();
	while ( iter!=in.end() )
	{
		h=p1.m_x*p2.m_y+iter->m_x*p1.m_y+p2.m_x*iter->m_y-iter->m_x*p2.m_y-p2.m_x*p1.m_y-p1.m_x*iter->m_y;
		if ( h>0 )  //p3��ֱ��p1p2��� ���ϰ���
		{
			up.push_back(*iter);
			if ( h>uph )
			{
				uph=h;
				upp=*iter;
			}
		}
		++iter;
	}
	if ( uph>0 )
	{
		area+=uph;
		out.push_back(upp);
	}
	//�ݹ鹹�����ϰ�
	if ( !up.empty() )
	{
		findup(up, p1, upp, out);
		findup(up, upp, p2, out);
	}
}

void finddown(std::vector<Point>& in, const Point& p1, const Point& p2, std::vector<Point>& out)
{
	std::vector<Point> down; //���°���
	Point downp;  //����
	double downh=0;  //���� 
	double h;
	std::vector<Point>::iterator iter=in.begin();
	while ( iter!=in.end() )
	{
		h=p1.m_x*p2.m_y+iter->m_x*p1.m_y+p2.m_x*iter->m_y-iter->m_x*p2.m_y-p2.m_x*p1.m_y-p1.m_x*iter->m_y;
		if ( h<0 ) //p3��ֱ��p1p2�ұ� ���°���
		{
			down.push_back(*iter);
			if ( h<downh )
			{
				downh=h;
				downp=*iter;
			}
		}
		++iter;
	}
	if ( downh<0 )
	{
		area+=-downh;
		out.push_back(downp);
	}
	//�ݹ鹹�����°�
	if ( !down.empty() )
	{
		finddown(down, p1, downp, out);
		finddown(down, downp, p2, out);
	}
}

void FindPoint(std::vector<Point>& in, std::vector<Point>& out)
{
	//����
	std::sort(in.begin(), in.end(), CmpXY());
	Point p1=in.front(); //͹��һ��
	Point p2=in.back();  //͹��һ��
	out.push_back(p1);
	out.push_back(p2);
	//��������
	std::vector<Point>::iterator iter=in.begin()+1;
	std::vector<Point> up; //��͹���� 
	std::vector<Point> down; //��͹����
	Point upp, downp;  //͹������
	double uph=0, downh=0;    //��������߸߶�
	double h;
	while ( iter!=in.end()-1 )
	{
		h=p1.m_x*p2.m_y+iter->m_x*p1.m_y+p2.m_x*iter->m_y-iter->m_x*p2.m_y-p2.m_x*p1.m_y-p1.m_x*iter->m_y;
		if ( h>0 ) //p3��ֱ��p1p2��� ���ϰ���
		{
			up.push_back(*iter);
			if ( h>uph )
			{
				uph=h;
				upp=*iter;
			}
		}
		if ( h<0 ) //p3��ֱ��p1p2�ұ� ���°���
		{
			down.push_back(*iter);
			if ( h<downh )
			{
				downh=h;
				downp=*iter;
			}
		}
		++iter;
	}
	if ( uph>0 )
	{
		area+=uph;
		out.push_back(upp);
	}
	if ( downh<0 )
	{
		area+=-downh;
		out.push_back(downp);
	}
	//�����ϰ�
	if ( !up.empty() )
	{
		findup(up, p1, upp, out);
		findup(up, upp, p2, out);
	}
	//�����°�
	if ( !down.empty() )
	{
		finddown(down, p1, downp, out);
		finddown(down, downp, p2, out);
	}
}

std::vector<Point> in;
std::vector<Point> out;

int main(int argc, char* argv[])
{
	int t;
	std::cin>>t;
	int n;
	Point p;
	while (t--)
	{
		std::cin>>n;
		if (n!=1)
		{	
			in.clear();
			out.clear();
			area=0;
			for (int i=0; i<n; ++i)
			{
				std::cin>>p.m_x>>p.m_y;
				in.push_back(p);
			}
			FindPoint(in, out);
		}
		else
		{
			std::cin>>p.m_x>>p.m_y;
			area=0;
		}
		printf("%.1f\n", area/2);
	}
	return 0;
}