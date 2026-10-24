# 运算符,表达式和语句
***
### 第 9 题：温度转换

编写一个程序，要求用户输入一个华氏温度。

程序应读取 `double` 类型的值作为温度值，并把该值作为参数传递给一个用户自定义的函数 `Temperatures()`。

该函数计算摄氏温度和开氏温度，并以小数点后面两位数字的精度显示 3 种温度。

要使用不同的温标来表示这 3 个温度。

下面是华氏温度转换摄氏温度的公式：

**摄氏温度 = 5.0 / 9.0 × (华氏温度 - 32.0)**

开氏温标常用于科学研究，0 表示绝对零，代表最低的温度。

下面是摄氏温度转开氏温度的公式：

**开氏温度 = 摄氏温度 + 273.16**

`Temperatures()` 函数中用 `const` 创建温度转换中使用的变量。

在 `main()` 函数中使用一个循环让用户重复输入温度，当用户输入 `q` 或其他非数字时，循环结束。

`scanf()` 函数返回读取数据的数量，所以如果读取数字则返回 1，如果读取 `q` 则不返回 1。

可以使用 `==` 运算符将 `scanf()` 的返回值和 1 作比较，测试两值是否相等。
#### 答案
```c
#include<stdio.h>
void Temperatures(double tem)
{
    const double a=5.0/9.0;
    const double b=32.0;
    const double c=273.16;
    double she=a*(tem-b);
    double kai=she+c;
    printf("%.2lf\n%.2lf\n%.2lf\n",tem,she,kai);
}
int main()
{
    double tem=0;
    printf("请输入华氏温度：");
    while((scanf("%lf",&tem))==1)
    {
        Temperatures(tem);
        printf("请输入华氏温度：");
    }
    return 0;
}
```
### 第 8 题：求模运算

编写一个程序，显示求模运算的结果。

把用户输入的第 1 个整数作为求模运算的第 2 个运算对象，该数在运算过程中保持不变。

用户后面输入的数是第 1 个运算对象。

当用户输入一个非正值时，程序结束。

输出显示例如下：

```text
This program computes moduli.
Enter an integer to serve as the second operand: 256
Now enter the first operand: 438
438 % 256 is 182
Enter next number for first operand (<= 0 to quit): 1234567
1234567 % 256 is 135
Enter next number for first operand (<= 0 to quit): 0
Done
```
#### 答案
```c
#include<stdio.h>
int main()
{
    printf("This program computes moduli\n");
    printf("Enter an integer to serve as the second operand: ");
    int sec=0;
    scanf("%d",&sec);
    printf("\nNow enter the first operand: ");
    int one=0;
    scanf("%d",&one);
    if(one<=0)
    {
        printf("Done\n");
        return 0;
    }
    printf("%d %% %d is %d\n",one,sec,one%sec);
    printf("Enter next number for first operand (<= 0 to quit): ");
    while(scanf("%d",&one)==1&&one>0)
    {
        printf("%d %% %d is %d\n",one,sec,one%sec);
        printf("Enter next number for first operand (<= 0 to quit): ");
    }
    printf("Done\n");
    return 0;
}
```
### 第 3 题：天数转换

编写一个程序，提示用户输入天数，然后将其转换成周数和天数。

例如，用户输入 18，则转换成 2 周 4 天。

以下面的格式显示结果：

```text
18 days are 2 weeks, 4 days.
```

通过 `while` 循环让用户重复输入天数，当用户输入一个非正值时（如 0 或 -20），循环结束。
#### 答案
```c
#include<stdio.h>
int main()
{
    int day=0;
    printf("enter your days:");
    while(scanf("%d",&day)==1&&day>0)
    {
        printf("%d days are %d weeks, %d days.\n",day,day/7,day%7);
        printf("enter your days:");
    }
    return 0;
}
```