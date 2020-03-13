#include<stdio.h>
typedef int datatype;
typedef struct node{
	datatype data;
	struct node *next;
}Linklist;
Linklist *CREATLISTF()//头插法建表 
{
	char ch; //逐个输入字符，'$'位结束符 
	Linklist *head,*s;
	head=NULL;//初始链表为空 
	ch=getchar();
	while(ch!='$'){
		s=(struct node*)malloc(sizeof(Linklist));
		s->data=ch;
		s->next=head;
		head=s;
		ch=getchar();
	}
	return head;
}

void invert(Linklist *head)
{

	Linklist *s,*p,*m;
	int i=0,k=0,j=0;
	char ch;
	s=head;
	p=head;
	m=head;
	while(s->next!=NULL)//查找尾节点
	{
		s=s->next;
		j++;
	}
	for(i=1;i<=j/2;i++)
	{
		p=p->next;
		m=head;
		for(k=1;k<=j-i+1;k++)
		{
			m=m->next;
		}
		ch=p->data;
		p->data=m->data;
		m->data=ch;
	}

}

void Output(Linklist *head) {
	Linklist *h = head;
	if (h == NULL) {//判空
		printf("The Link is null");
		return;
	}
	while (h != NULL) {
		printf("%c", h->data);
		h = h->next;
	}
}

int main(void)
{
	Linklist *L;
	L=CREATLISTF();
	printf("Begin:\n");
	Output(L);
	invert(L);
	printf("Result:\n");
	Output(L);
	return 0; 
}
