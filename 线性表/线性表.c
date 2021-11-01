#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
}LNode;

typedef LNode* L;

L MakeEmpty();//初始化顺序表
int FindKth(int k,L list);//根据位置k 返回指定元素
int Find(int k,L list);//查找k
void Insert(int index,int k,L list);//插入一个元素在index位置
void Delete(int index,L list);//删除index上的元素
int Length(L list);//返回线性表的长度

int main()
{
    L list;
    list=MakeEmpty();
    list->data[0]=1;   
    list->data[1]=2;
    list->data[2]=3;
    list->data[3]=4;
    list->data[4]=5;
    list->data[5]=6;
    list->length=6;

    //printf("%d\n",Find(99,list));
    Insert(7,99,list);
    Insert(8,100,list);
  //  Delete(1,list);
    printf("-------------\n");
    for(int i=0;i<list->length;i++)
    {
        printf("%d\n",list->data[i]);
    } 
    printf("length = %d\n",Length(list));
    return 0;
}


L MakeEmpty()
{
    L list;
    list=(L)malloc(sizeof(LNode));
    list->length=0;
    return list;
}


int FindKth(int k,L list)
{
    return list->data[k-1];
}


int Find(int x,L list)
{
    for(int i=0;i<list->length;i++)
    {
        if(list->data[i]==x)
        {
            return i+1;
        }
    }
    return -1;
}




void Insert(int index,int k,L list)
{
    if(list->length==MaxSize)
    {
        return ;
    }
    if(index<1||index>list->length+2)
    {
        return ;
    }
    for(int i=list->length;i>=index-1;i--)
    {
        list->data[i+1]=list->data[i];
    }
    list->data[index-1]=k;
    list->length++;
    return ;
}

void Delete(int index,L list)
{
    if(index<1||index>list->length+1)
    {
        return ;
    }
    for(int i=index-1;i<list->length;i++)
    {
        list->data[i]=list->data[i+1];
    }
    list->length--;
}

int Length(L list)
{
    return list->length;
}