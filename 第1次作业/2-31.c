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

    printf("请构造字符类型的单循环链表，注意，要三种不同的字符(@结束)\n");
    int ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='@')
            break;
        push_back(ha,ch);
    }
    printf("构造完成的链表>>>");
    show(ha);

    Node *hb,*hc;
    initial(&hb);
    initial(&hc);
    function(ha,hb,hc);
    printf("分割过后的单循环链表\n");
    show(ha);
    show(hb);
    show(hc);

    return(1);
}

Node* _buynode(Elemtype ch)
{//本算法的功能是申请一个新的节点，节点的数据域赋值为x
    //最后返回这个节点的指针
    Node *s=(Node*)malloc(sizeof(Node));
    assert(s!=NULL);

    s->ch=ch;
    s->next=NULL;
    return(s);
}

void initial(Node **head)
{//本算法的功能是初始化单循环链表
    (*head)=(Node*)malloc(sizeof(Node));
    assert((*head)!=NULL);

    (*head)->next=*head;
    (*head)->ch=0;//表长为0
}
void push_back(Node *head,Elemtype ch)
{//本算法的前提是链表已经初始化
    //本算法的功能是在单循环链表的尾部插入一个新的节点
    //并把数据域赋值为ch
    Node *s=_buynode(ch);
    Node *p=head;
    while(p->next!=head)
        p=p->next;//p指向链表的尾部节点


    s->next=p->next;
    p->next=s;
    head->ch++;//表长加一
}

void show(Node *head)
{//本算法的前提是单循环链表至少有一个节点
    //本算法的功能是依次显示单循环链表中的数据元素
    if(head->ch==0)
        return;//表长合法性判断

    Node *p=head;
    while(p->next!=head)
    {
        printf("%c-->",p->next->ch);
        p=p->next;
    }
    printf("head.\n");
}

void function(Node *ha,Node *hb,Node *hc)
{//本算法的前提是三个链表已经初始化，并且a链表至少有三个不同的字符数据
    //本算法的功能是把链表a分割成三个链表a,b,c
    //a中存储其他字符，b,c中分别存储数字字符和字母字符

    Node *pa=ha;

    while(pa->next!=ha)
    {
        if(pa->next->ch<='9' && pa->next->ch>='0')
        {
            Node *q=pa->next;
            pa->next=q->next;//将数字字符的节点从a链表中摘下来
            Node *pb=hb->next;
            while(pb->next!=hb)
                pb=pb->next;//pb指向b链表中的尾节点
            q->next=pb->next;
            pb->next=q;//尾部插入
            hb->ch++;//表长加一
        }
        else if(pa->next->ch<='Z'&&pa->next->ch>='A' || pa->next->ch<='z'&&pa->next->ch>='a')
        {
            Node *q=pa->next;
            pa->next=q->next;//将字符字符从a链表中摘下来
            Node *pc=hc->next;
            while(pc->next!=hc)
                pc=pc->next;//pc指向c链表中的尾部节点
            q->next=pc->next;
            pc->next=q;
            hc->ch++;//表长加一
        }
        else
            pa=pa->next;//其他类型字符的，则pa向后移动一个节点
    }
}
