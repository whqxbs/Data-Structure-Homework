#include<stdio.h>
typedef int datatype;
#define maxsize 1024
typedef struct{
	datatype data[maxsize];
	int last;
}sequenlist;
sequenlist *InitList(){
	int num,i;
	sequenlist *L;
	printf("Please input num:\n");
	scanf("%d",&num);
	if(num>maxsize)
	{
		printf("input error\n");
		return -1;
	}
	L=(sequenlist*)malloc(sizeof(sequenlist));
	if(L==NULL)
	{
		printf("malloc memory error");
		return -1;
	}
	printf("Please input L (%d elements):\n",num);
	for(i=0;i<num;i++)
	scanf("%d",&L->data[i]);
	L->last=i-1;
	return L;
}

void InverseList(sequenlist *L){
	int i,j;
	datatype temp;
	j=(L->last-1)/2;
	for(i=0;i<=j;i++)
	{
		temp=L->data[i];
		L->data[i]=L->data[L->last-i];
		L->data[L->last-i]=temp;
	}
}
void Output(sequenlist *L)
{
	int i;
	for(i=0;i<=L->last;i++){
		printf("%d\n",L->data[i]);
	}
}
int main(void)
{
	sequenlist *L;
	L=InitList();
	InverseList(L);
	printf("Result:\n");
	Output(L);
	return 0; 
}
