#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double mat[100][101];
//�÷����Ǹ�˹��Ԫ���ⷽ��
bool jiefangchen(int n,int x_num){//n��ʾ������Ŀ��x_num��ʾδ֪��������Ŀ��mat�ĵ�x_num+1�д洢����biֵ��
	int i,j,m;
	for(i=0;i<x_num;i++){//i��
		for(j=i;j<n;j++)if(fabs(mat[j][i])>0.000001)break;//�ҵ���i�е�i��Ϊ����
		if(j==n)return false;
		if(j!=i){
			for(int t=0;t<=x_num;t++){//��������
				double tmp=mat[i][t];
				mat[i][t]=mat[j][t];
				mat[j][t]=tmp;
			}			  
		}
		double a=mat[i][i];//�Խ���ϵ����Ϊ1
		for(m=i;m<=x_num;m++){
			mat[i][m]/=a;
		}
		//��Ԫ��
		for(m=0;m<n;m++){				
			if(m==i)continue;
			double b;				
			b=mat[m][i];
			for(int n=i;n<=x_num;n++){
				mat[m][n]-=b*mat[i][n];					
			}				
		}			
	}
	
	return true;
}

bool  checkIm(int n,int x_num){
	int type_num=x_num;
	int week=n;
	int i;
	for(i=type_num;i<week;i++){
		if(fabs(mat[i][type_num])>0.0000001)return true;//����޽�
	}
	for(i=0;i<type_num;i++){
		if(fabs(mat[i][type_num]+0.000001-(int)(mat[i][type_num]+0.000001))>0.00001)return true;//�����������
	}
	for(i=0;i<type_num;i++){
		if(mat[i][type_num]+0.000001 <0 )return true;//���Ϊ������
	}
	return false;
}

void main(){
	
	int x_num=9;
	int n=10;
	int i,j;
	int b[10]={30096,28880,32662,34217,36518,22426,23187,28934,27877,29942};

	char p[]="John Q. Crackjack ";
	for(i=0;i<5;i++){
		for(j=i;j<5+i;j++) mat[i][j]=p[j-i];
		mat[i][x_num]=b[i];

	}
	for(i=0;i<5;i++){
		for(j=i;j<5+i;j++)mat[i+5][j]=p[j-i+5];
		mat[i+5][x_num]=b[i+5];
	}
	printf("ԭ����Ϊ��\n");
	for(i=0;i<n;i++){
		for(j=0;j<x_num;j++)printf("%.0fx%d+",mat[i][j],j+1);
		printf("=%.2f\n",mat[i][x_num]);
	}
   jiefangchen(n,x_num);
   printf("ԭ���̻�Ϊ��\n");
   for(i=0;i<n;i++){
		for(j=0;j<x_num;j++)printf("%.0fx%d+",mat[i][j],j+1);
		printf("=%.2f\n",mat[i][x_num]);
	}

}
