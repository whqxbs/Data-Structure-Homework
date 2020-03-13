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

void Rk(sequenlist *L,int k){
	datatype x;
	int i,j;
	for(i=0;i<k;i++)
	{
		x=L->data[L->last];
		for(j=L->last-1;j>=0;j--){
			L->data[j+1]=L->data[j];
		}
		L->data[0]=x;
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
	int k;
	printf("Please input R k:\n");
	scanf("%d",&k);
	L=InitList();
	Rk(L,k);
	printf("Result:\n");
	Output(L);
	return 0; 
}

//Rk() ±º‰∏¥‘”∂»O(k*n) 
