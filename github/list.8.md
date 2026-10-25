# 字符输入/输出和输入验证
***
## 第 1 题

设计一个程序，统计在读到文件结尾之前读取的字符数。
### 答案
```c
#include<stdio.h>
int main()
{
    int ch=0,num=0;
    while((ch=getchar())!=EOF)
    {
        num++;
    }
    printf("%d",num);
    return 0;
}
```

## 第 3 题

编写一个程序，在读到 EOF 之前，把输入作为字符流读取。

该程序要报告输入中的大写字母和小写字母的个数。

假设大小写字母数值是连续的。或者使用 ctype.h 库中合适的分类函数更方便。
### 答案
```c
#include<stdio.h>
int main()
{
    int ch=0,big=0,small=0;
    while((ch=getchar())!=EOF)
    {
        if(ch>='A'&&ch<='Z')big++;
        else if(ch>='a'&&ch<='z')small++;
    }
    printf("\n%d %d\n",big,small);
    return 0;
}
```
或
```c
#include<stdio.h>
#include<ctype.h>
int main()
{
    int ch=0,big=0,small=0;
    while((ch=getchar())!=EOF)
    {
        if(isupper(ch))big++;
        else if(islower(ch))small++;
    }
    printf("\n%d %d\n",big,small);
    return 0;
}
```

## 第 8 题

编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。

获得用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的操作。

该程序只接受菜单提供的选项。

程序使用 float 类型的变量存储用户输入的数字，如果用户输入失败，则允许再次输入。

进行除法运算时，如果用户输入 0 作为第 2 个数（除数），程序应提示用户重新输入一个新值。

该程序的一个运行示例如下：

```text
Enter the operation of your choice:
a. add           s. subtract
m. multiply      d. divide
q. quit
a
Enter first number: 22 .4
Enter second number: one
one is not a number.
Please enter a number, such as 2.5, -1.78E8, or 3: 1
22.4 + 1 = 23.4

Enter the operation of your choice:
a. add           s. subtract
m. multiply      d. divide
q. quit
d
Enter first number: 18.4
Enter second number: 0
Enter a number other than 0: 0.2
18.4 / 0.2 = 92

Enter the operation of your choice:
a. add           s. subtract
m. multiply      d. divide
q. quit
q
Bye.
```
### 答案
```c
#include<stdio.h>
int get_number(double* p)
{
    char wrong[100];
    int ok=0;
    while((ok=scanf("%lf",p))!=1)
    {
        if(ok==EOF)return 0;
        if(scanf("%99s",wrong)!=1)return 0;
        printf("%s is not a number.\n",wrong);
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
        int ch;
        while((ch=getchar())!='\n'&&ch!=EOF)
        {}
        if(ch==EOF)return 0;
    }
    return 1;
}
int main()
{
    while(1)
    {
        printf("\nEnter the operation of your choice: \n");
        printf("a. add        s. subtract\n");
        printf("m. multiply   d. divide\n");
        printf("q. quit\n");
        char c;
        if((scanf(" %c",&c))!=1)break;
        switch(c)
        {
            case 'a':
            {
                double one,two;
                printf("Enter first number: ");
                if((get_number(&one))==0)return 0;
                printf("Enter second number:");
                if((get_number(&two))==0)return 0;
                printf("%f + %f = %f\n",one,two,one+two);
                break;
            }
            case 's':
            {
                double one,two;
                printf("Enter first number: ");
                if((get_number(&one))==0)return 0;
                printf("Enter second number:");
                if((get_number(&two))==0)return 0;
                printf("%f - %f = %f\n",one,two,one-two);
                break;
            }
            case 'm':
            {
                double one,two;
                printf("Enter first number: ");
                if((get_number(&one))==0)return 0;
                printf("Enter second number:");
                if((get_number(&two))==0)return 0;
                printf("%f * %f = %f\n",one,two,one*two);
                break;
            }
            case 'd':
            {
                double one,two;
                printf("Enter first number: ");
                if((get_number(&one))==0)return 0;
                printf("Enter second number:");
                if((get_number(&two))==0)return 0;
                while(two==0)
                {
                    printf("Enter a number other than 0: ");
                    if((get_number(&two))==0)return 0;
                }
                printf("%f / %f = %f\n",one,two,one/two);
                break;
            }
            case 'q':
            {
                printf("Bye.\n");
                return 0;
            }
            default:
            {
                printf("Please enter a choice\n");
                continue;
            }
        }
    }
    return 0;
}
```