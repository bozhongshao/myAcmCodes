
#include <iostream>
#include <string.h>
using namespace std;

void Delete(char *s,char *t)
{
	//ɾ������s�����а���t���Ӵ�
	char *subloc;  //�Ӵ�λ�õ�ָ��
	int i,k,len_t = strlen(t);
	subloc=strstr(s,t);  //��λ�Ӵ��������е���ָ��
	while(subloc)
	{
		for(i=0;i<len_t;i++)
			*(subloc+i)='0';  //����������Ӧλ��ȫ��Ϊ'0'
		subloc=strstr(s,t);
	}
	k=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='0')
		{
			cout<<s[i];
			k++;
		}
	}
	if(k==0)
		cout<<"NULL STRING";
	cout<<endl;
}

int main()
{
	int n;
	char s[81],t[81];
	cin>>n;  //��������
	while(n--)
	{
		cin>>s;
		cin>>t;
		Delete(s,t);
	}
	return 0;
}
