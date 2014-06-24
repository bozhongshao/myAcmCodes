/*
����ȷ�������㷨��ʹ�ò��鼯
Ȼ���������ܹؼ��ĵط�  
1���󼯺���ĳһ��������� ���ԴӴ���� ���ݵ������õ� 
2���ϲ��������ϵ�ʱ�� ����ֱ�ӹ�����ľ��� ���� �ڸ��Լ�������Դ����ľ���  ���� ���������ľ���
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct Question//�洢��������   ����յ�  ����ʱ��   
{int x , y , z , t , a;};
struct Information//�洢������Ϣ
{int x , y , z;char c;};
struct nodeC//�����洢�������
{int x , y;};

const int dx[4] = {1 , -1 , 0 , 0};//����
const int dy[4] = {0 , 0 , 1 , -1};

const int nx = 40010;
const int mx = 10010;

Information E[nx];//�洢��Ϣ
Question Q[mx];//�洢����
nodeC con[nx];
int fa[nx] , tmp[nx];
int n , m , L , len;

bool cmp_1(const Question &i , const Question &j)//��������ʱ�� ��������
{
	return (i.z < j.z);
}

bool cmp_2(const Question &i , const Question &j)//�������˳���������
{
	return (i.t < j.t);
}

void init()
{
	scanf("%d %d" , &n , &L);// ����ص���������Ϣ��
	for (int i = 1 ; i <= L ; ++i)//������Ϣ
		scanf("%d %d %d %c" , &E[i].x, &E[i].y , &E[i].z , &E[i].c);
	for (int i = 1 ; i <= n ; ++i)//��ʼ������Ϊ���� ����Ϊ 0 ��0
	{
		fa[i] =i;
		con[i].x = con[i].y = 0;
	}
	scanf("%d" , &m);//��������
	for (int i = 0 ; i < m ; ++i)//�������� ������
	{
		scanf("%d %d %d" , &Q[i].x , &Q[i].y , &Q[i].z);
		Q[i].t = i;
	}
	sort(Q , Q + m , cmp_1);//����������ƽ������� ���Դ�С�Ŀ�ʼ�� ����ͼ��ֻҪ��һ��
}

int find(int t)
{
	len = 0;
	while (fa[t] != t)//һֱ�����Դ�������㼯�ĵ�
	{
		tmp[len++] = t;
		t = fa[t];
	}
	for (int i = len - 2 ; i >= 0 ; --i)//����㼯�е������ ȫ��ֱ�Ӹ� t���������  ��t��Ϊ��׼�������� �����㽨�˹����ĵ�Ͳ�������
	{
		con[tmp[i]].x += con[tmp[i + 1]].x;
		con[tmp[i]].y += con[tmp[i + 1]].y;
		fa[tmp[i]] = t;
	}//�Ӵ�����ǰһ���㿪ʼ ������� �õ�Ѱ�ҵ������  //������������  0,0 ���Ծ������Ѿ�����������˵ĵ���� Ҳ��Ҫ��
	return t;
}

void work()
{
	int j = 0 , x , y , t;
	while (j < m && Q[j].z == 0)//����Ϊ0����Ϣ������ų��� ����ֵΪ-1 
	{
		Q[j++].a = -1;
	}

	for (int i = 1 ; i <= L ; ++i)//������Ϣ
	{
		x = find(E[i].x);//�Ѵ���x�����й����ĵ�Ľ�ϵ�һ���Ķ���  һ�����ϵ�һ�γ��ֵ��Ǹ�����Ǵ����
		y = find(E[i].y);//�Ѵ���y�����й����ĵ�Ľ�ϵ�һ���Ķ��� 
		fa[y] = x;//�����������Ϲ�����  ��Ϊ E[i].x �� E[i].y���й�ϵ��
		if (E[i].c == 'E') t = 0;//�����������Ӧ
		else if (E[i].c == 'W') t = 1;
		else if (E[i].c == 'N') t = 2;
		else if (E[i].c == 'S') t = 3;//con[E[i]].x-con[E[i].y].x ��E[i].x��ԭ���� ��ȥ y��ԭ���� �ټ��� �����������ʵ���� ���Եõ� y��xΪ��׼������
		con[y].x = -dx[t] * E[i].z - con[E[i].y].x + con[E[i].x].x;// ͨ��x�����y���������Ϊ�Ǵ�x��չ��y����x����   E[i].x��� E[i].y��ľ�������ԭ�� Ҳ������ľ��� ���� ����֮���ʵ�ʾ������  ���ܱ�ʾ���������֮��ľ��� 
		con[y].y = -dy[t] * E[i].z - con[E[i].y].y + con[E[i].x].y;
		while (j < m && Q[j].z == i)//��Ҫ�������ʱ�䵽��ʱ �Ϳ��Եõ�������Ĵ�
		{
			x = find(Q[j].x);//��x���ڼ��ϵĴ����
			y = find(Q[j].y); //���յ����ڵ㼯�Ĵ����
			if (x != y)//û�й�������
				Q[j].a = -1;
			else Q[j].a = abs(con[Q[j].x].x - con[Q[j].y].x) + abs(con[Q[j].x].y - con[Q[j].y].y);//�����
			++j;
		}
	}

	sort(Q , Q + m , cmp_2);// ��������Ⱥ�����

	for (int i = 0 ; i < m ; ++i)
		printf("%d\n" , Q[i].a);//������д�
}

int main()
{
	init();//��������
	work();//������
}


