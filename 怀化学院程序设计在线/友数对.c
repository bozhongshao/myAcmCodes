#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int i;
	if (n<=1) return 0;
	for(i=2;i<=sqrt(n);i++)
		if (n%i==0) break;
	if (i>sqrt(n)) return 1;
	else return 0;
}
int main()
{
	int x,y,i,total=0;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y-1;i++)
     if (prime(i*(i+1)-1)) total++;
	printf("%d\n",total);
	return 0;
}