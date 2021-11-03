#include<stdio.h>

//删除最小元素 删除的位置由最后一个元素填补
int DeleteMin(int num[],int length);

//将顺序表所有元素逆序 空间复杂度O(1)
void Resever(int num[],int length);

//删除所有值为x的元素 时间复杂度O(N) 空间复杂度O(1)
void DeleteX(int num[],int length,int key);

//在有序顺序表中删除从s到t的所有元素 若s和t不合理 或顺序表为空 报错
void DeleteStoT(int num[],int length,int s,int t);

//在顺序表中删除从s到t的所有元素 若s和t不合理 或顺序表为空 报错
void DeleteStoTs(int num[],int length,int s,int t);

//从有序顺序表中删除重复的元素
void DeleteAA(int num[],int length);

//两个有序顺序表合并成一个新的有序顺序表
int* NumAdd(int num1[],int length1,int length2,int num2[]);

//一个线性表中存放着两个线性表 将两个线性表的位置互换；
void Change(int num[],int m,int n);

//在一个递增有序的顺序表中找到一个元素 使其与后续元素交换 若找不到则插入
void FindX(int num[],int length,int x);

//将一个顺序表中的数据循环左移x位
void Movex(int num[],int length,int x);

//找两个升序序列的中位数 
int FindMid(int num1[],int num2[],int length1,int length2);

//找出一个元素 它的出现是 顺序表长度的一半多
int FindZ(int num[],int length);

//找出没找出的最小整数
int FindY(int num[],int length);

int main()
{
    int num1[8]={0,5,5,3,5,5,5,5};
    int num2[5]={1,2,3,4,20};
    // int* num3;
    // num3=NumAdd(num1,5,5,num2)；
    
    // printf("Deleted = %d\n",DeleteMin(num,10));
    // Resever(num,10);
    // DeleteX(num,10,66);
    //DeleteStoTs(num,10,4,6);
    //DeleteStoAA(num,10);
    // NumAdd(num1,5,5,num2);
    //Change(num1,6,4);
    //FindX(num1,9,5);
    //Movex(num1,10,9);
    //printf("key = %d\n",FindMid(num1,num2,5,5));
    //printf("key = %d\n",FindZ(num1,8));
    printf("min = %d\n",FindY(num2,5));
    for(int i=0;i<8;i++)
    {
        printf("%d\n",num1[i]);
    }
    return 0;
}

int DeleteMin(int num[],int length)
{
    int min=999,index;
    if(length==0)
    {
        return -1;
    }
    for(int i=0;i<length;i++)
    {
        if(num[i]<min)
        {
            min=num[i];
            index=i;
        }
    }
    num[index]=num[length-1];
    return min;
}

void Resever(int num[],int length)
{
    int rare=length-1;
    int key;
    for(int i=0;i<length/2;i++)
    {
        key=num[i];
        num[i]=num[rare];
        num[rare]=key;
        rare--;
    }
}

void DeleteX(int num[],int length,int key)
{
    for(int i=0;i<length;i++)
    {
        if(num[i]==key)
        {
            for(int j=i;j<length;j++)
            {
                num[j]=num[j+1];
            }
            length--;
        }
    }
    printf("length = %d\n",length);

}

void DeleteStoT(int num[],int length,int s,int t)
{
    int add=0,index;
    if((length==0)||(s>t))
    {
        return ;
    }
    for(int i=0;i<length;i++)
    {
       if((s<=num[i])&&(num[i]<=t))
       {
           add++;
           index=i;
       }
    }
    index+=1;
    //add+=1;
    for(;index<length;index++)
    {
        num[index-add]=num[index];
    }
    length-=add;
    printf("length = %d\n",length);
}

void DeleteStoTs(int num[],int length,int s,int t)
{
    int index=0;
    if((s>t)||length==0)
    {
        return ;
    }
    for(int i=0;i<length;i++)
    {
        if((s<=num[i])&&(num[i]<=t))
        {
            index++;
        }
        else
        {
            num[i-index]=num[i];
        }
    }
    length-=index;
    printf("length = %d\n",length);
}

void DeleteAA(int num[],int length)
{
    int k=num[0];
    int add=0;
    for(int i=1;i<length;i++)
    {
        if(num[i]==k)
        {
            add++;
        }
        else
        {
            num[i-add]=num[i];
            k=num[i];
        }
    }
    length-=add;
    printf("length = %d\n",length);
}

int* NumAdd(int num1[],int length1,int length2,int num2[])
{
    int*  list;
    int i,j,k;
    while((i<length1)&&(j<length2))
    {
        if(num1[i]<=num2[j])
        {
            list[k++]=num1[i++];
        }
        else
        {
            list[k++]=num2[j++];
        }
        while (i<length1)
        {
            list[k++]=num1[i++];
        }
        while (j<length2)
        {
            list[k++]=num2[j++];
        }
    }
    return list;
}

void Change(int num[],int m,int n)
{
    int k;
    while(m--)
    {
        k=num[m];
        for(int i=m;i<m+n;i++)
        {
            num[i]=num[i+1];
        }
        num[n+m]=k;
    }
}

void FindX(int num[],int length,int x)
{
    for(int i=0;i<length;i++)
    {
        if(num[i]==x)
        {
            num[i]=num[i+1];
            num[i+1]=x;
            return ;
        }
        if(num[i]>x)
        {
            for(int j=length;i<j;j--)
            {
                num[j]=num[j-1];
            }
            num[i]=x;
            return ;
        }
    }
    return ;
}

void Movex(int num[],int length,int x)
{
    int n=0;
    int k;
    while (n<x)
    {
        int k=num[0];
        for(int i=0;i<length;i++)
        {
            num[i]=num[i+1];
        }
        num[length-1]=k;
        n++;
    }
}

int FindMid(int num1[],int num2[],int length1,int length2)
{
    int add=length1;
    int i=0,j=0;
    int key;
    while(add)
    {
        if(num1[i]<num2[j])
        {
            key=num1[i++];
            add--;
        }
        else
        {
            key=num2[j++];
            add--;
        }
    }
    return key;
}

int FindZ(int num[],int length)
{
    int list[10]={0,0,0,0,0,0,0,0,0,0};
    int k=0;
    for(int i=0;i<length;i++)
    {
        list[num[i]]++;
    }
    for(int i=0;i<10;i++)
    {
        if(list[i]>k)
        {
            k=i;
        }
    }
    if(list[k]>length/2)
    {
        printf("%d\n",list[5]);
        return k;
    }
    return -1;
}

int FindY(int num[],int length)
{
    int list[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<length;i++)
    {
        list[num[i]]++;
    }
    for(int i=1;i<10;i++)
    {
        if(list[i]==0)
        {
            return i;
        }
    }
    return -1;
}