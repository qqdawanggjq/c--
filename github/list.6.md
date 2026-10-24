# c控制语句：循环
***
## 第 18 题
Rabnud 博士加入了一个社交圈。他起初有 5 个朋友。他注意到他的朋友数量以下面的方式增长：第 1 周少了 1 个朋友，剩下的朋友数量翻倍；第 2 周少了 2 个朋友，剩下的朋友数量翻倍。一般而言，第 N 周少了 N 个朋友，剩下的朋友数量翻倍。编写一个程序，计算并显示 Rabnud 博士每周的朋友数量。该程序一直运行，直到超过邓巴数（Dunbar's number）。邓巴数是粗略估算一个人在社交圈中有稳定关系的成员的最大值，该值大约是 150。
### 答案
```c
#include<stdio.h>
int main()
{
    int fri=5;
    int week=1;
    while(fri<=150)
    {
        fri=(fri-week)*2;
        printf("Week: %d, friend number: %d\n",week,fri);
        week++;        
    }
    return 0;
}
```
## 第 14 题
编写一个程序，创建两个包含 8 个元素的 double 类型数组，使用循环提示用户为第一个数组输入 8 个值。第二个数组元素的值设置为第一个数组对应元素的累积之和。例如，第二个数组的第 4 个元素的值是第一个数组前 4 个元素之和，第二个数组的第 5 个元素的值是第一个数组前 5 个元素之和（用嵌套循环可以完成，但是利用第二个数组的第 5 个元素是第二个数组的第 4 个元素与第一个数组的第 5 个元素之和，只用一个循环就能完成任务，不需要使用嵌套循环）。最后，使用循环显示两个数组的内容，第一个数组显示在一行，第二个数组显示在第一个数组的下一行，而且每个元素都与第一个数组各元素相对应。
### 答案
```c
#include<stdio.h>
int main()
{
    double s1[10],s2[10];
    for(int i=0;i<8;i++)
    {
        printf("Please enter number:");
        scanf("%lf",&s1[i]);
        
    }
    double sum=0;
    for(int i=0;i<8;i++)
    {
        sum=sum+s1[i];
        s2[i]=sum;
    }
    for(int i=0;i<8;i++)
    {
        printf("%-10f ",s1[i]);
    }
    printf("\n");
    for(int i=0;i<8;i++)
    {
        printf("%-10f ",s2[i]);
    }
    return 0;
}
```
## 第 12 题
考虑下面两个无限序列：
```text
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
```
编写一个程序计算这两个无限序列的总和，直到到达某次数。提示：奇数个 -1 相乘得 -1，偶数个 -1 相乘得 1。让用户交互地输入指定的次数，当用户输入 0 或负值时结束输入。查看运行 100 项、1000 项、10000 项后的总和，是否发现每个序列都收敛于某值？
### 答案
```c
#include<stdio.h>
#include<math.h>
int main()
{
    int n=0;
    printf("Enter numer: ");
    while(scanf("%d",&n)==1&&n>0)
  {
    double sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        sum1=sum1+1.0/i;
        sum2=sum2+(pow(-1,i-1))*1.0/i;
    }
    printf("first: %f\nsecond: %f\n",sum1,sum2);
    printf("Enter numer: ");
  }
  return 0;
}
```
## 第 5 题
编写一个程序，提示用户输入大写字母。使用嵌套循环以下面金字塔型的格式打印字母：
```text
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
```
打印这样的图形，要根据用户输入的字母来决定。例如，上面的图形是在用户输入 E 后的打印结果。

提示：用外层循环处理行，每行使用 3 个内层循环，分别处理空格、以升序打印字母、以降序打印字母。如果系统不使用 ASCII 或其他以数字顺序编码的代码，请参照练习 3 的解决方案。
### 答案
```c
#include<stdio.h>
int main()
{
    char c;
    printf("请输入字母：");
    scanf("%c",&c);
    for(int i='A';i<=c;i++)
    {
        for(int j=1;j<=c-i;j++)
        {
            printf(" ");
        }
        for(int j=1;j<=i-'A'+1;j++)
        {
            printf("%c",'A'+j-1);
        }
        for(int j=i-'A';j>=1;j--)
        {
            printf("%c",'A'+j-1);
        }
        printf("\n");
    }
    return 0;
}
```