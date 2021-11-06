#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct LNode{
    int data;
    struct LNode* Next;
}LNode;
typedef LNode* L;

//设计一个递归算法 删除所有值为x的结点
void DeletedX(L l,int x);

//有头指针，删除所有值为x的结点
void DeleteX(L l,int x);

//有头指针，从头到尾反向输出所有节点
void ReseverPrintf(L l);

//有头指针 删除最小节点
void DeletedMin(L l);

//将有头节点链表 原地逆置
void ReseverLink(L l);

//排序使一个链表递增有序
void LinkAdd(L l);

//链表无序 删除给定的两个值之间的结点
void DeleteStoT(L l,int s,int t);

//找两个链表的公共结点
L find(L l1,L l2);

//递增输出无序链表的值
void PrintfAdd(L l);

//将一个链表分为奇偶两个链表
L LinkDepart(L l);

//在递增有序的链表中删除重复的结点
void DeletedAA(L l);

//两个递增顺序的链表 合并成一个递减顺序的链表
L LinkADD(L l1,L l2);

int main(){
    L one=(L)malloc(sizeof(LNode));
    one->data=1;
    L two=(L)malloc(sizeof(LNode));
    one->Next=two;
    two->data=2;
    L three=(L)malloc(sizeof(LNode));
    two->Next=three;
    three->data=3;
    L four=(L)malloc(sizeof(LNode));
    three->Next=four;
    four->data=4;
    L five=(L)malloc(sizeof(LNode));
    four->Next=five;
    five->data=5;
    five->Next=NULL;

    ReseverPrintf(one);
   return 0;
}

void DeletedX(L l,int x)
{
    L current;
    if(l==NULL)
    {
        return;
    }
    if(l->data==x)
    {
        current=l;
        l=l->Next;
        free(l);    
        DeletedX(l,x);
    }
}

void DeleteX(L l,int x)
{
    L pre=l;
    L current=l->Next;
    while(l)
    {
        if(l->data==x)
        {
            current=l;
            l=l->Next;
            pre->Next=l;
            free(current);
        }
        else
        {
            pre=pre->Next;
            l=l->Next;
        }
    }
}

void ReseverPrintf(L l)
{
    if(l->Next!=NULL)
    {
        ReseverPrintf(l->Next);
    }
    printf("%d\n",l->data);   
}

void DeletedMin(L l)
{
    L pre=l;
    L current=l->Next;
    l=l->Next;
    int x=999;
    while (l)
    {
        if(l->data<x)
        {
            x=l->data;
            current=l;
        }
        pre=pre->Next;
        l=l->Next;
    }
    pre->Next=current->Next;
    free(current);
}

void ReseverLink(L l)
{
    L p,r;
    p=l->Next;
    l->Next=NULL;
    while(p)
    {
        r=p->Next;
        p->Next=l->Next;
        l->Next=p;
        p=r;
    }
    
}

void LinkAdd(L l)
{
    L p=l->Next,pre;
    L r=p->Next;
    p->Next=NULL;
    p=r;
    while(p)
    {
        r=p->Next;
        pre=l;
        while(pre->Next!=NULL&&pre->Next->data<p->data)
        {
            pre=pre->Next;
        }
        p->Next=pre->Next;
        pre->Next=p;
        p=r;
    }
}

void DeleteStoT(L l,int s,int t)
{
    L pre=l,current;
    l=l->Next;
    while(l)
    {
        if((s<l->data)&&(l->data<t))
        {
            current=l;
            pre->Next=current->Next;
            free(current);
            l=pre->Next;
        }
        else
        {
            pre=pre->Next;
            l=l->Next;
        }
        
    }
}

L find(L l1,L l2)
{
    int length1,length2;
    int dis;
    while(l1)
    {
        l1=l1->Next;
        length1++;
    }
     while(l2)
    {
        l2=l2->Next;
        length2++;
    }
    if(length1>length2)
    {
        dis=length1-length2;
        while(dis--)
        {
            l1=l1->Next;
        }
    }
    else
    {
        dis=length2-length1;
        while(dis--)
        {
            l2=l2->Next;
        }
    }
    while(l2!=l1)
    {
        l1=l1->Next;
        l2=l2->Next;
    }
    return l1;
}

void PrintfAdd(L l)
{
    L pre,p;
   
    while(l)
    {
        pre=l;
        p=pre->Next;
        int min=999;
        while(l)
        {
            if(l->data<min)
            {
                p=l;
                min=l->data;
            }
            pre=pre->Next;
            l=l->Next;
        }
        pre->Next=p->Next;
        free(p);
        printf("%d",min);
    }

}

L LinkDepart(L l)
{
    L l1;
    L l2=l;
    int add=1;
    while(l)
    {
        if(add%2!=0)
        {
           l2->Next=l;
           l2=l2->Next; 
        }
        else
        {
            l1->Next=l;
            l1=l1->Next;
        }
        l=l->Next;
    }
    l1->Next=NULL;
    l2->Next=NULL;
    return l1;
}

void DeletedAA(L l)
{
    L pre,p;
    pre=l->Next;
    p=pre->Next;
    int x=pre->data;
   while(pre->Next!=NULL)
   {
       if(p->data==x)
       {
           pre->Next=p->Next;
           free(p);
           p=pre->Next;
       }
       else
       {
           x=p->data;
           pre=pre->Next;
           p=p->Next;
       }
   }
}

L LinkADD(L l1,L l2)
{
    L pre1=l1->Next,pre2=l2->Next,work1;
    l1->Next=NULL;
    while(l1&&l2)
    {
        if(l1->data<l2->data)
        {
            work1=pre1->Next;
            pre1->Next=l1->Next;
            l1->Next=pre1;
            pre1=work1;
        }
        else
        {
            work1=pre2->Next;
            pre2->Next=l1->Next;
            l1->Next=pre2;
            pre2=work1;
        }
    }
    if(l1)
    {
        l2=l1;
    }
    while(work1)
    {
        work1=pre1->Next;
        pre1->Next=l1->Next;
        l1->Next=pre1;
        pre1=work1;
    }
    free(l2);
    return l1;
}