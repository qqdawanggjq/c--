# 字符串和字符串函数
## 第 1 题

设计并测试一个函数，从输入中获取 n 个字符（包括空白、制表符、换行符），把结果存储在一个数组里，它的地址被传递作为一个参数。
### 答案
```c
#include<stdio.h>
void enter(char s[],int n)
{
    for(int i=0;i<n;i++)
    {
        s[i]=getchar();
    }
}
int main()
{
    int n;
    printf("请输入n:\n");
    scanf("%d",&n);
    getchar();
    char s[1000]={0};
    enter(s,n);
    for(int i=0;i<n;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}
```

## 第 7 题

strncpy(s1, s2, n) 函数把 s2 中的 n 个字符拷贝至 s1 中，截断 s2，或者有必要的话在末尾添加空字符。

如果 s2 的长度是 n 或多于 n，目标字符串不能以空字符结尾。

该函数返回 s1。

自己编写一个这样的函数，名为 mystrncpy()。

在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
### 答案
```c
#include<stdio.h>
char* mystrncpy(char s1[],char s2[],int n)
{
    int i=0;
    for(;i<n&&s2[i]!='\0';i++)
    {
        s1[i]=s2[i];
    }
    for(;i<n;i++)
    {
        s1[i]='\0';
    }
    return s1;
}
int main()
{
    char s1[1000]={0};
    char s2[1000]={0};
    int n;
    scanf("%d",&n);
    int ch;
    while((ch=getchar())!='\n'&&ch!=EOF);
    fgets(s2,sizeof(s2),stdin);
    if(n<0||n>=1000)return 1;
    mystrncpy(s1,s2,n);
    printf("%s\n",s1);
    return 0;
}
```

## 第 9 题

编写一个函数，把字符串中的内容用其反序字符串代替。

在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
### 答案
```c
#include<stdio.h>
#include<string.h>
void fan(char s[])
{
    int left=0;
    int right=strlen(s)-1;
    while(left<right)
    {
        char p=s[left];
        s[left]=s[right];
        s[right]=p;
        left++;
        right--;
    }
    
}
int main()
{
    char s[1000];
    while(fgets(s,sizeof(s),stdin)!=NULL)
    {
        s[strcspn(s,"\n")]='\0';
        fan(s);
        printf("%s\n",s);
    }
    
    return 0;
}
```