# c控制语句： 分支和跳转
***
## 第 7 题

编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。

做如下假设：

a. 基本工资 = 10.00 美元/小时

b. 加班（超过 40 小时） = 1.5 倍的时间

c. 税率：
- 前 300 美元为 15%
- 续 150 美元为 20%
- 余下的为 25%

用 #define 定义符号常量。

不用在意是否符合当前的税法。

### 答案
```c
#include<stdio.h>
#define pay 10.00
#define normal 40
#define overtime 1.5
#define shui1 0.15
#define shui2 0.20
#define shui3 0.25
int main()
{
    printf("请输入工作时间：");
    int hour;
    double all,shui,pour;
    scanf("%d",&hour);
    if(hour<=normal)
    {
        all=hour*pay;
    }
    else
    {
        all=(normal+(hour-normal)*overtime)*pay;
    }
        if(all<=300)
        {
            shui=shui1*all;
        }
        else if(all<=450)
        {
            shui=shui1*300+shui2*(all-300);
        }
        else
        {
            shui=shui1*300+shui2*150+shui3*(all-450);
        }
        pour=all-shui;
        printf("总工资：%.2f\n税金：%.2f\n净收入：%.2f",all,shui,pour);
        return 0;
}
```
## 第 10 题

1988 年的美国联邦税收计划是近代最简单的税收方案。

它分为 4 个类别，每个类别有两个等级。

下面是该税收计划的摘要（美元数为应征税的收入）：

| 类别 | 税金 |
|---|---|
| 单身 | 17850 美元按 15% 计，超出部分按 28% 计 |
| 户主 | 23900 美元按 15% 计，超出部分按 28% 计 |
| 已婚，共有 | 29750 美元按 15% 计，超出部分按 28% 计 |
| 已婚，离异 | 14875 美元按 15% 计，超出部分按 28% 计 |

例如，一位工资为 20000 美元的单身纳税人，应缴纳税费：

0.15 × 17850 + 0.28 × (20000 - 17850) 美元。

编写一个程序，让用户指定缴纳税金的种类和应纳税收入，然后计算税金。

程序应通过循环让用户可以多次输入。
### 答案
```c
#include <stdio.h>
int main()
{
    char type;
    double pay;
    printf("(单身--A, 户主--B, 已婚 共有--C, 已婚 离异--D)\n请输入缴纳税金的种类和应纳税收入: ");
    while (scanf(" %c%lf", &type, &pay)==2)
    {
        double shui;
        switch(type)
        {
            case 'A':
            {
               if(pay<=17850)
                {
                    shui=pay*0.15;
                }
                else
                {
                    shui=17850*0.15+(pay-17850)*0.28;
                }
                break;
            }
            case 'B':
            {
               if(pay<=23900)
                {
                    shui=pay*0.15;
                }
                else
                {
                    shui=23900*0.15+(pay-23900)*0.28;
                }
                break;
            }
            case 'C':
            {
               if(pay<=29750)
                {
                    shui=pay*0.15;
                }
                else
                {
                    shui=29750*0.15+(pay-29750)*0.28;
                }
                break;
            }
            case 'D':
            {
               if(pay<=14875)
                {
                    shui=pay*0.15;
                }
                else
                {
                    shui=14875*0.15+(pay-14875)*0.28;
                }
                break;
            }
            default:
            {
                printf("输入错误！请重新输入：");
                continue;
            }

        }
        printf("税金：%f\n",shui);
        printf("(单身--A, 户主--B, 已婚 共有--C, 已婚 离异--D)\n请输入缴纳税金的种类和应纳税收入: ");
    }
    return 0;
}

```
## 第 8 题

修改练习 7 的假设 a，让程序可以给出一个供选择的工资等级菜单。

使用 switch 完成工资等级选择。

运行程序后，显示的菜单应该类似这样：

```text
**************************************************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr                 2) $9.33/hr
3) $10.00/hr                4) $11.20/hr
5) quit
**************************************************************
```

如果选择 1～4 其中的一个数字，程序应该询问用户工作的小时数。

程序要通过循环运行，除非用户输入 5。

如果输入 1～5 以外的数字，程序应提醒用户输入正确的选项，然后再重复显示菜单提示用户输入。

使用 #define 创建符号常量表示各工资等级和税率。
### 答案
```c
#include<stdio.h>
#define pay1 8.75
#define pay2 9.33
#define pay3 10.00
#define pay4 11.20
#define normal 40
#define overtime 1.5
#define shui1 0.15
#define shui2 0.20
#define shui3 0.25
int main()
{
    while(1)
 {
    int hour;
    double all,shui,pour;
    double pay;
    printf("\n********************************\n");
        printf("请选择工资等级：\n");
        printf("1) $8.75/hr    2) $9.33/hr\n");
        printf("3) $10.00/hr   4) $11.20/hr\n");
        printf("5) quit\n");
        printf("********************************\n");

        printf("请输入选项：");
    int act=0;
    scanf("%d",&act);
    switch(act)
    {
        case 1:
        {
            pay=pay1;
            break;
        }
        case 2:
        {
            pay=pay2;
            break;
        }
        case 3:
        {
            pay=pay3;
            break;
        }
        case 4:
        {
            pay=pay4;
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            printf("请输入正确的选项：");
            continue;
        }
    }
    printf("请输入工作小时：");
    scanf("%d",&hour);
    if(hour<=normal)
    {
        all=hour*pay;
    }
    else
    {
        all=(normal+(hour-normal)*overtime)*pay;
    }
        if(all<=300)
        {
            shui=shui1*all;
        }
        else if(all<=450)
        {
            shui=shui1*300+shui2*(all-300);
        }
        else
        {
            shui=shui1*300+shui2*150+shui3*(all-450);
        }
        pour=all-shui;
        printf("总工资：%.2f\n税金：%.2f\n净收入：%.2f\n",all,shui,pour);
        return 0;
 }
}
```