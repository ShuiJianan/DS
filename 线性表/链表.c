#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct LNode{
    int data;
    struct LNode* Next;
}LNode;
typedef LNode* L;

int Length(L LNode);//求表长
L   FindKth(int index,L LNode);//按序号查找
L Find(int k,L LNode);//按值查找
L Insert(int index,int k,L LNode);//插入
L Delete(int index,L LNode);//删除

int main()
{
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


    // printf("%d\n",Length(one));
    // printf("%d\n",FindKth(5,one)->data);
    // printf("%d\n",Find(77,one)->data);

    L this=Insert(6,100,one);
    L that=Delete(2,this);
    //L that=Insert(2,200,this);

    while(that)
    {
        printf("%d\n",this->data);
        that=that->Next;
    }
    return 0;
}




int Length(L lnode)
{
    L test=lnode;
    int i=0;
    while(test)
    {
        test=test->Next;
        i++;
    }
    return i;
}

L FindKth(int index,L LNode)
{
    L test=LNode;
    int i=1;
    while(i<index&&test!=NULL)
    {
        test=test->Next;
        i++;
    }
    if(i==index)
    {
        return test;
    }
    else
    {
        return NULL;
    }
}

L Find(int k,L LNode)
{
    L test=LNode;
    while(test)
    {
        if(test->data==k)
        {
            return test;
        }
        test=test->Next;
    }
    return NULL;
}

L Insert(int index,int k,L LNode)
{
    L head=LNode;
    L test=LNode;
    L new=(L)malloc(sizeof(LNode));
    if(index==1)
    {
        new->data=k;
        new->Next=LNode;
        return new;
    }
    if(index<1||index>Length(LNode)+2)
    {
        return NULL;
    }
    while(index-2)
    {
        test=test->Next; 
        index--;   
    }
    new->Next=test->Next;
    new->data=k;
    test->Next=new;
    return head;
}

L Delete(int index,L LNode)
{
    L head=LNode;
    if(index==1)
    {
        head=head->Next;
        free(LNode);
        return head;
    }
    if(index<1||index>Length(LNode))
    {
        return NULL;
    }
    L current=FindKth(index-1,LNode);
    L deleted=current->Next;
    free(deleted);
    current->Next=deleted->Next;
    return head;
}