#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef struct SString
{
    char data[MaxSize];
    int length;
}SString;
typedef SString* String;


String StrAssign(char* t,String s) //初始化串
{
    int i=0;
    while(t[i])
    {
        s->data[i]=t[i];
        i++;
        s->length++;
    }
    return s;
}

String StrCopy(String s,String t)//复制串
{
    for(int i=0;i<s->length;i++)
    {
        t->data[i]=s->data[i];
    }
    t->length=s->length;
    return t;
}

int StrEmpty(String s)//判断串是否为空
{
    if(s->data[0]=='\0')
    {
        return 1;
    }
    else{
        return -1;
    }
}

int indexs(String s,String t)
{
    int i=0,j=0;
    while(i<s->length&&j<t->length)
    {
        if(t->data[i]==s->data[i])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+2;
            j=1;
        }
    }
        if(j>=t->length)
        {
            return i-t->length;
        }else{
            return -1;
        }
}

int main()
{
    char* t = "lixianji";
    char* tt= "jil";
    String s=(String)malloc(sizeof(SString));
    String s1=(String)malloc(sizeof(SString));
    s=StrAssign(t,s);
    s1=StrAssign(tt,s1);

    printf("%d\n",indexs(s,s1));



    // s=StrAssign(t,s);
    // s1=StrCopy(s,s1);
    // for(int i=0;i<s1->length;i++)
    // {
    //     printf("%c",s1->data[i]);
    // }
    // printf("\n");
    return 0;
}