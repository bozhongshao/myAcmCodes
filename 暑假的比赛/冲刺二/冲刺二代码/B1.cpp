# include <iostream>
using namespace std;

int w[2004];  //��Ʒ������
int v[2004];  //��Ʒ�ļ�ֵ
int c; //����������
int n; //��Ʒ������
int ** m; //����ֵ
int *x; //���Ž�����

int max(int a, int b); //��a, b�еĽϴ���
int min(int a, int b);
void fun(); // ��������ֵ
void Traceback(int *x); //�������Ž�


int main()
{
	int z,i,j,t,k,g;
	// freopen("0-1��������.in", "r", stdin);
	cin>>g;
	while(g--)
	{
		cin>>c;//kaishi****************
		cin>>z;
		j=0;
		for(i=1;i<=z;i++)
		{
			j++;
			scanf("%d%d%d",&w[j],&v[j],&t);
			for(k=2;k<=t;k++)
			{
				j++;
				w[j]=w[j-1];
				v[j]=v[j-1];
			}
		}
		//cin>>n;//beibaozhognlei
		n=j;
		m = new int *[n+1];
		for(i=1; i<=n; i++)
		{
			m[i] = new int [101];
		}
		for(i=1; i<=n; i++)
		{//��ʼ������ֵ��Ϊ0
			for(int j=1; j<=100; j++)
			{
				m[i][j] = 0;
			}
		}
		//x = new int [n+1];
		fun(); //�������ã���������ֵ
		//Traceback(x); //�������Ž�
	}
	return 0;
}


int max(int a, int b) //���庯������a, b�еĽϴ���
{
	if(a>=b)
		return a;
	else
		return b;
}

int min(int a, int b)  //��a, b�еĽ�С��
{
	if(a>=b)
		return b;
	else
		return a;
}
void fun()  //�Ե����ϼ�������ֵ
{
	int jMax = min(w[n]-1, c); //��֤jMax < w[n];
    for(int j=0; j<=jMax; j++) 
	{  //ֻ�е�n����Ʒ����������������
		m[n][j] = 0;
	}
	for(j=w[n]; j<=c; j++) 
	{  //ֻ�е�n����Ʒ���ұ��������㹻
		m[n][j] = v[n];
	}
	for(int i=n-1; i>1; i--)
	{
		jMax = min(w[i]-1, c); //ȷ��jMax < w[i];
		for(int j=0; j<=jMax; j++) 
		{ //����ѡ�����ƷΪi, i+1, ����, n, ������С��w[i]
			m[i][j] = m[i+1][j];
		}
		for(j=w[i]; j<=c; j++)   
		{	//����ѡ�����Ʒi, i+1, ����, n, ���������ڵ���w[i]
			m[i][j] = max(m[i+1][j], m[i+1][j-w[i]]+v[i]);
		}
	}
	m[1][c] = m[2][c];  //����û�����m[1][c]
	if(c >= w[1]) 
	{ //����ѡ�����Ʒ1��2��������n, �ұ����������ڵ���w[1]
		m[1][c] = max(m[1][c], m[2][c-w[1]]+v[1]);
	}
    //cout<<"������Ʒ������ֵΪ: ";
	cout<<m[1][c]<<endl;
}


void Traceback(int *x)  //��������ֵ�������Ž�
{
    for(int i=1; i<n; i++)
	{
		if(m[i][c] == m[i+1][c])
			x[i] = 0;
		else
		{
			x[i] = 1;
			c -= w[i]; 
		}
	}
	x[n] = (m[n][c])? 1:0;  //�ж�����ֵm[n][c]�Ƿ�Ϊ�棬����ǣ�x[n] = 1;��x[n] = 0;
	//	cout<<"���Ž���: "<<endl;
	/*for(i=1; i<=n; i++)
	{
	cout<<x[i]<<" ";
}*/
	cout<<endl;
}


