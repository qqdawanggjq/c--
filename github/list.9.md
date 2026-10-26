# 函数
***
## 第 5 题

编写并测试一个函数 larger_of()，该函数把两个 double 类型变量的值替换为较大的值。例如，larger_of(x, y) 会把 x 和 y 中较大的值重新赋给两个变量。
### 答案
```c

#include<stdio.h>
void large_of(double* x,double* y)
{
    if(*x>=*y)
    {
        *y=*x;
    }
    else
    {
        *x=*y;
    }
}
int main()
{
    double a,b;
    scanf("%lf%lf",&a,&b);
    large_of(&a,&b);
    printf("%.2f %.2f",a,b);
    return 0;
}
```

## 第 7 题

编写一个函数，从标准输入中读取字符，直到遇到文件结尾。程序要报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位置。例如，c 和 C 在字母表中的位置都是 3。

合并一个函数，以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回 -1。
### 答案
```c
#include<stdio.h>
int judge(int ch)
{
    if(ch>='a'&&ch<='z')
    {
        return ch-'a'+1;
    }
    if(ch>='A'&&ch<='Z')
    {
        return ch-'A'+1;
    }
    return -1;
}
int main()
{
    int ch;
    while((ch=getchar())!=EOF)
    {
        int x=judge(ch);
        if(x!=-1)printf("是字母 %d\n",x);
        else printf("不是字母\n");
    }
    return 0;
}
```

## 第 8 题

第 6 章的程序清单 6.20 中，power() 函数返回一个 double 类型数的正整数次幂。

改进该函数，使其能正确计算负幂。另外，函数要处理 0 的任何次幂都为 0，任何数的 0 次幂都为 1（函数应报告 0 的 0 次幂未定义，因此把该值处理为 1）。

要使用一个循环，并在程序中测试该函数。
### 答案
```c
#include<stdio.h>
double power(double x,int exp)
{
    double pow=1;
    if(x==0&&exp==0)
    {
        printf("未定义\n");
        return 1;
    }
    if(exp>0)
    {
        for(int i=1;i<=exp;i++)
        {
            pow*=x;
        }
        return pow;
    }
    else if(exp<0)
    {
        for(int i=1;i<=-exp;i++)
        {
            pow*=x;
        }
        pow=1/pow;
        return pow;
    }
    else
    {
        return 1;
    }
}
int main()
{
    double x,xpow;
    int exp;
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while((scanf("%lf%d",&x,&exp))==2)
    {
        xpow=power(x,exp);
        printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}
```
### 改进
```c
#include<stdio.h>
double power(double n,int p)
{
    if(p==0)
    {
        if(n==0)
        {
            printf("未定义\n");
        }
        return 1;
    }
    double pow=1;
    int xp=p;
    if(p<0)xp=-p;
    for(int i=1;i<=xp;i++)
    {
        pow*=n;
    }
    if(p<0)
    {
        if(n==0)
        {
            printf("未定义\n");
            return 1;
        }
        pow=1.0/pow;
    }
    return pow;
}
int main()
{
    double x,xpow;
    int exp;
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while((scanf("%lf%d",&x,&exp))==2)
    {
        xpow=power(x,exp);
        printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}

```