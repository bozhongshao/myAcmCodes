#include <stdio.h> 
void main()   { 
	int p,e,i,d,n; 
	int num=1; 
	while(1) 
	{ 
		scanf("%d%d%d%d",&p,&e,&i,&d); 
		if(p!=-1) 
		{ 
			n=(5544*p+14421*e+1288*i-d+21252)%21252; 
			if(n==0) n=21252; 
			printf("Case %d: the next triple peak occurs in %d days.\n",num++,n); 
		} 
		else break; 
	} 

} 
