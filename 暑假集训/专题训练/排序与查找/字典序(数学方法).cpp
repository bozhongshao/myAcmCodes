#include <iostream> 
using namespace std; 
#include <string> 

int f[26][20]={0}; 
int g[20]={0}; 

int solve(string st) 
{ 
	string from,to; 
	to=st; 
	int index=0; 
	int len=to.length(); 
	if (len==1) 
		return to[0]-'a'+1; 
	for (int j=0;j <len;j++) 
		index+=g[j]; 
	for (int i=0;i <to[0]-'a';i++) 
		index+=f[i][len-1]; 
	int k=1; 
	while(k <len) 
	{ 
		if(to[k] <=to[k-1]) 
			return 0; 
		if (k+1==len) 
		{ 
			index++; 
		} 
		for (int p=to[k-1]-'a'+1;p <to[k]-'a';p++) 
			index+=f[p][to.length()-k-1]; 
		k++; 
	} 
	return index; 
} 
void record(int len) 
{ 
	g[0]=0; 
	g[1]=26; 
	for (int i=0;i<26;i++) 
	{ 
		f[i][0]=1; 
	} 
	for(int j=1;j <len;j++) 
	{ 
		for(int i=0;i <26;i++) 
		{ 
			for(int k=i+1;k <26;k++) 
				f[i][j]+=f[k][j-1]; 
		} 
		for(int i=0;i <26;i++) 
			g[j+1]+=f[i][j]; 
	} 
} 
int main() 
{ 
	int k; 
	string str; 
	cin>>k; 
	record(10); 
	while(k--) 
	{ 
		cin>>str; 
		cout <<solve(str) <<endl; 
	} 
}

/*����
���ʼǱ�
����һ������³��Ȳ�����k�������ַ�����
��һ��i���ַ���ͷ�ĳ��Ȳ�����k�������ַ�������Ϊf��i��k�������Ȳ�����k�������ַ����ܸ���Ϊg��k������g��k��=f��i��k����һ�ӵ�26��
*/
