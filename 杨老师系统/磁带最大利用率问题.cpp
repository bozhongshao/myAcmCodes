#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b);

int main()
{
int num,*array,*max,leng,i,j,k,temp,tape;

printf("���������ݸ���\n");
scanf("%d",&num);
array = (int *)malloc(num * sizeof(int));
max = (int *)malloc(num * sizeof(int));

printf("�������������ݳ���\n");
for(i = 0; i < num; i++)
   scanf("%d",&array[i]);

qsort(array,num,sizeof(int),comp);//����

printf("������Ŵ�����");
scanf("%d",&tape);

for(temp = tape,leng = i = 0; i < num;i++)//��С����ѡȡ�����ֱ���ܺͳ����Ŵ���
{
   if(array[i] < temp)
   {
    max[leng++] = array[i];
    temp -= array[i];
   }
   else
    break;
}

for(j = leng - 1; j >= 0;j--)//ʹ�Ŵ����ÿռ価�����
{
   if(max[j] + temp < array[j + 1])
    break;
   for(k = j + 1; k < num; k++)
   {
    if(max[j] + temp < array[k])
     break;
    temp -= (array[k] - max[j]);
    max[j] = array[k];
   }
}

printf("\n���ÿռ䳤��%d,ִ�г������%d,�ֱ���\n",tape - temp,leng);
for(i = 0; i < leng; i++)
   printf("%d ",max[i]);
return 0;
}
int comp(const void *a, const void *b)
{
return(*(int *)a - *(int *)b);
}