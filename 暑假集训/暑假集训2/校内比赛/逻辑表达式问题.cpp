#include<iostream>
#include<string>
using namespace std;
string istr;//��洢���������
string str;//�洢���е���ĸ
int n;//��������ĸ��

bool b[15];//������ĸ��������״̬

bool weight(char a,char b)
{
	if (b=='(') return false;//��������
	if (a=='(') return false;//���������ȼ����
	if (a=='~') return true;//��ǰ���
	if (b=='~') return false;//�ں���ǰ��Ŀ϶����� Ҳ�Ǹ�
	if (a=='>'&&b!='>') return false;//���ȼ����
	if (b=='>') return true;//���ȼ���� ���Ժ��������ǰ��Ϳ�������
	if (a=='|' &&b!='>' && b!='|') return false;//���ȼ������ڶ�
	if (a=='&'&&b!='>' && b!='|'&&b!='&' ) return false;
	return true;
}

int find1(char ch)
{
	int i;
	for(i=0;i<n;++i)
	{
		if (ch==str[i]) return i;
	}
	return -1;
}

bool calc(bool a,char sign,bool b)
{
	switch(sign)
	{
	case '&': return (a&&b);
	case '|':return (a||b);
	case '>':return (!a||b);
	}
	return false;
}

bool judge()
{
	char sign[155];
	bool res[155];
	int stail,rtail,loc;
	stail=0;
	rtail=0;
	int i;
	for(i=0;i<int(istr.size());++i)
	{
		if (istr[i]=='-') continue;
		if (istr[i]=='(')
		{
			sign[stail++]='(';
		}
		else 
		{
			if (istr[i]==')')
			{
				while(sign[stail-1]!='(')
				{
					if (sign[stail-1]=='~')
					{
						res[rtail-1]=!res[rtail-1];
						stail--;
					}
					else 
					{
						res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
						rtail--;
						stail--;
					}
				}
				stail--;
				while(stail>0 && weight(sign[stail-2],sign[stail-1]))
				{
					if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;}
					else 
					{
						res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
						rtail--;
						stail--;
					}
				}
			}
			else 
			{
				if ((istr[i]>='a'&&istr[i]<='z')||(istr[i]>='A'&&istr[i]<='Z')) 
				{
					loc=find1(istr[i]);
					res[rtail++]=b[loc];
				}
				else 
				{
					if (stail>0 && weight(sign[stail-1],istr[i]))
					{
						if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;}
						else 
						{
							res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
							rtail--;
							stail--;
						}
						while(stail>0 && weight(sign[stail-2],sign[stail-1]))
						{
							if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;} //���ǵ�Ŀ����
							else 
							{
								res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
								rtail--;
								stail--;
							}
						}
						sign[stail++]=istr[i];
					}
					else
					{
						sign[stail++]=istr[i];
					}
				}
			}
		}
	}

	while(stail>0)
	{
		if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;}
		else 
		{
			res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
			rtail--;
			stail--;
		}
	}

	return res[0];
}

bool work(int num)
{
	if (num>=n)//������ĸ������״̬
	{
		if (judge()) return true;
		return false;
	}

	b[num]=true;
	if (work(num+1)) return true;
	b[num]=false;
	if (work(num+1)) return true;
	return false;
}


int main()
{
	int i;
	while(cin>>istr)
	{
		str="";
		for(i=0;i<int(istr.size());++i)
		{
			if (str.find(istr[i])==-1) str.insert(str.end(),istr[i]);
		}
		n=int(str.size());
		if (work(0)) puts("y");
		else puts("n");
	}
	return 0;
}