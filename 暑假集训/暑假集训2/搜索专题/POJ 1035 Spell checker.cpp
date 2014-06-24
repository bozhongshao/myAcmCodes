/*д��д������  ���ǲ��õ��� ��ٵķ�ʽ ƾ��set�ĺ�sort�ĳ�ɫ���� �ڱ�����Ac��  
���ǿ����˵�ʱ�� ���ڴ淢�ֲ��ܴ�   ��ʵ�����ɲ��ؽ������  ֻҪ��һƥ�� ��һ���ַ��ľ��ǿ��Ե�  
�����ó��ȿ���ɸ��һ��  �پ�û�취 ֻ��һ�����ַ���������
����Ҳ���гɾ͸�  ���Ҳ�ܳ�����������   
*/
#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

set<string> dictionary;
vector<string> dic;
vector<string> res;

int find1(const string &str)
{
	int i;
	for(i=0;i<int(dic.size());++i)
	{
		if (dic[i]==str) return i;
	}
	return false;
}

bool cmp(const string &a,const string &b)
{
	return find1(a)<find1(b);
}

int main()
{

	int i,j;
	char ch[2];
	string str;
	string nstr;
	//freopen("2.txt","w",stdout);
	ch[1]='\0';
	while(cin>>str,str!="#")
	{
		dictionary.insert(str);
		dic.push_back(str);
	}

	while(cin>>str,str!="#")
	{
		res.clear();
		if (dictionary.find(str)!=dictionary.end()) 
		{
			cout<<str<<" is correct"<<endl; 
			continue;
		}
		cout<<str<<":";
		for(i=0;i<int(str.size());++i)
		{
			nstr=str;
			nstr.erase(i,1);
			if (dictionary.find(nstr)!=dictionary.end())
			{
				res.push_back(nstr);
			}
		}

		for(i=0;i<int(str.size());++i)
		{
			ch[0]='a';
			for(j=0;j<26;++j)
			{
				ch[0]='a'+j;
				nstr=str;
				nstr[i]=ch[0];
				if (dictionary.find(nstr)!=dictionary.end())
				{
					res.push_back(nstr);
				}
			}
		}

		for(i=0;i<=int(str.size());++i)
		{
			ch[0]='a';
			for(j=0;j<26;++j)
			{
				ch[0]='a'+j;
				nstr=str;
				nstr.insert(i,ch);
				if (dictionary.find(nstr)!=dictionary.end())
				{
					res.push_back(nstr);
				}
			}
		}

		sort(res.begin(),res.end(),cmp);

		for(i=0;i<int(res.size());++i)
		{
			if (!i||res[i]!=res[i-1]) cout<<" "<<res[i];
		}	
		cout<<endl;
	}

	return 0;
}