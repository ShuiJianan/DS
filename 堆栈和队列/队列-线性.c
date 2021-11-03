#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10


typedef struct 
{
    int data[MaxSize];
    int rare;
}Queue;

typedef Queue* Q;


Q InitQueue();//初始化队列
void PushQueue(Q queue,int key);//入队
int PopQueue(Q queue);//出队

int main()
{
    Q queue=InitQueue();
    PushQueue(queue,1);
    PushQueue(queue,2);
    PushQueue(queue,3);
    PushQueue(queue,4);
    PushQueue(queue,5);
    printf("Pop key = %d\n",PopQueue(queue));
    PushQueue(queue,6);
    for(int i=0;i<queue->rare;i++)
    {
        printf("%d\n",queue->data[i]);
    }
    printf("queue->rare = %d\n",queue->rare);
    return 0;
}

Q InitQueue()
{
    Q queue=(Q)malloc(sizeof(Queue));
    queue->rare=0;
    return queue;
}

void PushQueue(Q queue,int key)
{
    if(queue->rare==MaxSize)
    {
        return ;
    }
    queue->data[queue->rare++]=key;
}

int PopQueue(Q queue)
{
    int key=queue->data[0];
    if(queue->rare==0)
    {
        return -1;
    }
    for(int i=0;i<queue->rare-1;i++)
    {
        queue->data[i]=queue->data[i+1];
    }
    queue->rare--;
    return key;
}