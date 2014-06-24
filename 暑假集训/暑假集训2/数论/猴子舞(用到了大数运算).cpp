/*
���ݷ�������֪������������ɿ��Եõ����ֵ   ���  ��
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 1000
int p[100];
char max1[MAX];
int vis[100];
int svis[100];

int sk;
/******************************************************************/
void reverse(char *from, char *to )
{
	int len=int(strlen(from));
	int i;
	for(i=0;i<len;i++)
		to[i]=from[len-i-1];
	to[len]='\0';
}
/******************************************************************/
void call_mult(char *first,char *sec,char *result)
{
	char F[MAX],S[MAX],temp[MAX];
	int f_len,s_len,f,s,r,t_len,hold,res;
	f_len=int(strlen(first));
	s_len=int(strlen(sec));
	reverse(first,F);
	reverse(sec,S);
	t_len=f_len+s_len;
	r=-1;
	for(f=0;f<=t_len;f++)
		temp[f]='0';
	temp[f]='\0';
	for(s=0;s<s_len;s++)
	{
		hold=0;
		for(f=0;f<f_len;f++)
		{
			res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
			temp[f+s]=res%10+'0';
			hold=res/10;
			if(f+s>r) r=f+s;
		}
		while(hold!=0)
		{
			res=hold+temp[f+s]-'0';
			hold=res/10;
			temp[f+s]=res%10+'0';
			if(r<f+s) r=f+s;
			f++;
		}
	}
	for(;r>0 && temp[r]=='0';r--);
	temp[r+1]='\0';
	reverse(temp,result);
}
/***************************************************************/
void getprime()//���һ����Χ�ڵ�����
{
	int count1;
	int i,j;
	memset(p,0,sizeof(p));
	p[0]=6;
	p[1]=2;
    count1=2;
	for(i=3;i<300;++i)
	{
		for(j=2;j<=int(sqrt(double(i)));++j)
		{
			if (i%j==0) break;
		}
		if (j>int(sqrt(double(i)))) p[count1++]=i; 
	}
	p[count1]=INT_MAX;
}


void itoa1(int num,char *res,int ra)
{
	char a[MAX];
	int i;
	int count1;
	count1=0;
	while(num)
	{
		a[count1++]=num%ra;
		num/=ra;
	}
	for(i=count1-1;i>=0;--i)
	{
		res[count1-1-i]=char(a[i]+48);
	}
	res[count1]='\0';
}

bool whomax(char *tempres)//�Ƚ��������ַ�������������������Ĵ�С
{
	int len1,len2;//��ʱ�����max1�ĳ���
	int i;
	len1=int(strlen(tempres));
	len2=int(strlen(max1));

	if (len1>len2) return true;
	if (len1<len2) return false;
	for(i=0;i<len1;++i)
	{
		if (tempres[i]>max1[i]) return true;
		if (max1[i]>tempres[i]) return false;
	}
	return false;
}

void checkres(int num,int k)//���鵱ǰ״̬�ɴﵽ�Ĳ���
{
	int i,j;
	char temp[MAX];
	char res[MAX];
	if (num==1) return;//���ʣ��1 ����
	strcpy(res,"1");//����ǰ���� ����ֵ1 
	for(i=1;i<=k;++i)//�������ֽ�������� ��� �ý��
	{
		if (vis[i]>0)
		{
			for(j=0;j<vis[i];++j)
			{
				itoa1(p[i],temp,10);
				call_mult(res,temp,res);
			}
		}
	}

	//���⴦��2��3��������
	if (vis[0]==0)//Ҫ��û���õ�6  
	{
		//�ֱ��ж� 2 �� 3 �Ƿ��ܷŽ�ȥ  ����ʣ�µ�Ҫ�� 3 ����3  ���������2 ���������� ����3
		if (vis[1]==0 &&(num==2 || num>3)) call_mult(res,"2",res);//���2û�� ���ң�ʣ��2 ���� ʣ�µ�������3 �� ��ô���ҳ˽�ȥ Ҳ�������ȥ
		if (vis[2]==0 && (num % 2==1)) call_mult(res,"3",res);//���3û���ù� ���� ʣ�µ�num������ ��Ȼ��������1���� ������5 2 �� 3 ͬ��
	}
	else //Ҫ���õ���6  Ҳ���� ��Ժ�1Ԫ�����������
	{
		if (vis[1]==0) call_mult(res,"2",res);//2û�ù� ����2 
		call_mult(res,"3",res);//һ����3  �������� 2 �� 3 ������6  ������ �ú���6 
	}

	if (whomax(res))  //����ǰ�Ĳ�����max1 �Ƚ� Ҫ�Ǵ� �͸���
	{
		strcpy(max1,res);
        /*�ڱ�������û���� �Ǹ������״̬��
		for(i=0;i<100;++i)
		{
			svis[i]=vis[i];
		}
		sk=k;
		*/
	}
}
//һ������
void work(int num,int k)//�����Ķ�η�֮�� ���ǻ��ʵ� ��Ϊ �������� ����1�ͱ��� ֻ�и�����
{
	int val;
	val=p[k];
	vis[k]=0;
	if (val>num) //���ǵ�ǰ�������Ѿ����� num
	{
		checkres(num,k-1);
		return;
	}

    work(num,k+1);//��ȡ�õ�ǰ���������

	++(vis[k]);//ʹ�����±�Ϊk�������ļ��������1  �����õ��� ��ǰ������1�η�  

    if (k<3)//�����ǰ��kС��3  Ҳ���� ������2 ���� 3    ��Ϊ2 �� 3 �����⴦��
	{
		++(vis[k]);//��ǰ����ʹ�ô���  ��1  ����Ҫ�õ� ��������ƽ��
		val=val*p[k];// val���Ե�ǰ����  Ҳ���ǵ�ǰ������ ƽ��
	}

	while(val<num-1)
	{
		work(num-val,k+1);//��ʹ�� ��ǰ������ĳ�η� �������� 
		val=val*p[k];//����
		++(vis[k]);//��Ǽ�1  ���������������
	}

	if (val==num) checkres(0,k);//������ǵ���num ��ʹ�ø�����   �������
}

//����1Ԫ�ص�����
void findresult1(int num,int k)
{
	int val;
	val=p[k];// ��������1�η�
	vis[k]=0;//��ʼ�� ����Ϊ0  Ҳ����
	if (val>num)//�������num�� �ͽ��м���
	{
		if (num==2 || num==4) checkres(num,k-1);//numʣ�µı���Ҫ��2 ����4  
        return;
	}
	findresult1(num,k+1);//��ȡ��ǰ������
	if (k==2) return;//������� 3 �ͷ���  Ҳ���ǲ�ʹ��3 ��3��ĳ����  �Ͳ������6��6�ı���
	++(vis[k]);//���1 ����
	if (k==1) //Ҫ����ʹ��2  ��ֱ������һ�� ����
	{
		++(vis[k]);//��Ǽ�1
		val=val*p[k];//����
	}

	while(val<num-1)//���� ͬʱ��������
	{
		findresult1(num-val,k+1);//������ǰ���ݵĿ��з���
		val*=p[k];
		++(vis[k]);
	}
	if (val==num) checkres(0,k);//������� num�� �ͽ��м���  ������������
}

int main()
{
	int num;
	getprime();
	while(cin>>num,num!=0)
	{
		memset(vis,0,sizeof(vis));//��������鸳��ֵ  
		strcpy(max1,"0");// ���ֵ ��ֵ ��Ϊ��
		work(num,1);//������2 ��ʼ����
		if (num>=6)
		{
			vis[0]=1;//����ʹ���� 6��1�η�
			vis[1]=0;
			vis[2]=0;
			if (num>6) findresult1(num-6,1);//����������� �ֽ�����һ��ȦΪ6
			else checkres(0,0);//6�Ĵ��� ������ ֱ��������ʾ
		}
		cout<<max1<<endl;
	}
	return 0;
}