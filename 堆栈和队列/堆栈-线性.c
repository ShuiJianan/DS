#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct 
{
    int data[MaxSize];
    int top;
}Stack;
typedef Stack* S;


S InitStack();//初始化堆栈
void PushStack(S stack,int key);//入栈
int PopStack(S stack);//出栈

int main()
{
    S stack;
    stack=InitStack();
    PushStack(stack,1);
    PushStack(stack,2);
    PushStack(stack,3);
    PushStack(stack,4);
    PushStack(stack,5);
    PushStack(stack,6);
    printf(" key = %d\n",PopStack(stack));
    for(int i=0;i<stack->top;i++)
    {
        printf("%d\n",stack->data[i]);
    }
    printf("stack->top = %d\n",stack->top);
    return 0;
}


S InitStack()
{
    S stack=(S)malloc(sizeof(Stack));
    stack->top=0;
    return stack;
}

void PushStack(S stack,int key)
{
    if(stack->top==MaxSize)
    {
        return ;
    }
    stack->data[stack->top++]=key;
}

int PopStack(S stack)
{
    if(stack->top==0)
    {
        return -1;
    }
    int i=stack->data[--stack->top];
    return i;
}




