# 字符串和格式化输入/输出
***
## 7. 
编写一个程序，将一个double类型的变量设置为1.0/3.0，一个float类型的变量设置为1.0/3.0。分别显示两次计算的结果各3次：一次显示小数点后面6位数字；一次显示小数点后面12位数字；一次显示小数点后面16位数字。程序中要包含float.h头文件，并显示FLT_DIG和DBL_DIG的值。1.0/3.0的值与这些值一致吗？
### 答案
```c
#include<stdio.h>
#include<float.h>
int main()
{
    double d=1.0/3.0;
    float f=1.0f/3.0f;
    printf("%.6f\n",f);
    printf("%.12f\n",f);
    printf("%.16f\n",f);
    printf("%.6lf\n",d);
    printf("%.12lf\n",d);
    printf("%.16lf\n",d);
    printf("%d\n",FLT_DIG);
    printf("%d\n",DBL_DIG);
    return 0;
}
```
***
##  6. 
编写一个程序，先提示用户输入名，然后提示用户输入姓。在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。字母数要与相应名和姓的结尾对齐，如下所示：
plaintext
  
Melissa Honeybee
      7         8
 
 
接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，如下所示：
plaintext
  
Melissa Honeybee
7       8
### 答案
```c
#include<stdio.h>
#include<string.h>
int main()
{
    char first[20],last[20];
    printf("enter your first name:");
    scanf("%s",first);
    printf("enter your last name:");
    scanf("%s",last);
    int len1=strlen(first);
    int len2=strlen(last);
    printf("plaintext\n\n%s %s\n",first,last);
    printf("%*d %*d\n",len1,len1,len2,len2);
    printf("plaintext\n\n%s %s\n",first,last);
    printf("%-*d %-*d\n",len1,len1,len2,len2);
    return 0;
}
```
***
## 2. 
编写一个程序，提示用户输入名字，并执行以下操作：
a. 打印名字，包括双引号；
b. 在宽度为20的字段右端打印名字，包括双引号；
c. 在宽度为20的字段左端打印名字，包括双引号；
d. 在比姓名宽度宽3的字段中打印名字。
### 答案
```c
#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    printf("enter your name:");
    scanf("%s",s);
    int len=strlen(s);
    printf("\"%s\"\n",s);
    printf("\"%20s\"\n",s);
    printf("\"%-20s\"\n",s);
    printf("\"%-*s\"\n",len+3,s);
    return 0;
}
```