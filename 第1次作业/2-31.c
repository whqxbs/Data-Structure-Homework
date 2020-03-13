#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#define Elemtype char
typedef struct SCList
{
    Elemtype ch;
    struct SCList *next;
}Node;

Node* _buynode(Elemtype ch);
void initial(Node **head);
void push_back(Node *head,Elemtype ch);
void show(Node *head);
void function(Node *ha,Node *hb,Node *hc);

int main()
{
    Node *ha;
    initial(&ha);

    printf("�빹���ַ����͵ĵ�ѭ������ע�⣬Ҫ���ֲ�ͬ���ַ�(@����)\n");
    int ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='@')
            break;
        push_back(ha,ch);
    }
    printf("������ɵ�����>>>");
    show(ha);

    Node *hb,*hc;
    initial(&hb);
    initial(&hc);
    function(ha,hb,hc);
    printf("�ָ����ĵ�ѭ������\n");
    show(ha);
    show(hb);
    show(hc);

    return(1);
}

Node* _buynode(Elemtype ch)
{//���㷨�Ĺ���������һ���µĽڵ㣬�ڵ��������ֵΪx
    //��󷵻�����ڵ��ָ��
    Node *s=(Node*)malloc(sizeof(Node));
    assert(s!=NULL);

    s->ch=ch;
    s->next=NULL;
    return(s);
}

void initial(Node **head)
{//���㷨�Ĺ����ǳ�ʼ����ѭ������
    (*head)=(Node*)malloc(sizeof(Node));
    assert((*head)!=NULL);

    (*head)->next=*head;
    (*head)->ch=0;//��Ϊ0
}
void push_back(Node *head,Elemtype ch)
{//���㷨��ǰ���������Ѿ���ʼ��
    //���㷨�Ĺ������ڵ�ѭ�������β������һ���µĽڵ�
    //����������ֵΪch
    Node *s=_buynode(ch);
    Node *p=head;
    while(p->next!=head)
        p=p->next;//pָ�������β���ڵ�


    s->next=p->next;
    p->next=s;
    head->ch++;//����һ
}

void show(Node *head)
{//���㷨��ǰ���ǵ�ѭ������������һ���ڵ�
    //���㷨�Ĺ�����������ʾ��ѭ�������е�����Ԫ��
    if(head->ch==0)
        return;//���Ϸ����ж�

    Node *p=head;
    while(p->next!=head)
    {
        printf("%c-->",p->next->ch);
        p=p->next;
    }
    printf("head.\n");
}

void function(Node *ha,Node *hb,Node *hc)
{//���㷨��ǰ�������������Ѿ���ʼ��������a����������������ͬ���ַ�����
    //���㷨�Ĺ����ǰ�����a�ָ����������a,b,c
    //a�д洢�����ַ���b,c�зֱ�洢�����ַ�����ĸ�ַ�

    Node *pa=ha;

    while(pa->next!=ha)
    {
        if(pa->next->ch<='9' && pa->next->ch>='0')
        {
            Node *q=pa->next;
            pa->next=q->next;//�������ַ��Ľڵ��a������ժ����
            Node *pb=hb->next;
            while(pb->next!=hb)
                pb=pb->next;//pbָ��b�����е�β�ڵ�
            q->next=pb->next;
            pb->next=q;//β������
            hb->ch++;//����һ
        }
        else if(pa->next->ch<='Z'&&pa->next->ch>='A' || pa->next->ch<='z'&&pa->next->ch>='a')
        {
            Node *q=pa->next;
            pa->next=q->next;//���ַ��ַ���a������ժ����
            Node *pc=hc->next;
            while(pc->next!=hc)
                pc=pc->next;//pcָ��c�����е�β���ڵ�
            q->next=pc->next;
            pc->next=q;
            hc->ch++;//����һ
        }
        else
            pa=pa->next;//���������ַ��ģ���pa����ƶ�һ���ڵ�
    }
}
