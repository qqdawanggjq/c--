# c语言概述
***
## 8. 
在 C 语言中，函数可以调用另一个函数。编写一个程序，调用一个名为  one_three()  的函数。该函数在一行打印单词“one”，再调用第 2 个函数  two() ，然后在另一行打印单词“three”。 two()  函数在一行显示单词“two”。 main()  函数在调用  one_three()  函数前要打印短语“starting now:”，并在调用完毕后显示短语“done!”。因此，该程序的输出应如下所示：
 
plaintext
  
starting now:
one
two
three
done!
### 答案
```c
#include<stdio.h>
void one_three()
{
    printf("one\n");
    two();
    printf("three\n");
}
void two()
{
    printf("two\n");
}
int main()
{
    printf("starting now:\n");
    one_three();
    printf("done!");
    return 0;
}
```
***
## 7. 
许多研究表明，微笑益处多多。编写一个程序，生成以下格式的输出：
 
plaintext
  
Smile!Smile!Smile!
Smile!Smile!
Smile!
 
 
该程序要定义一个函数，该函数被调用一次打印一次“Smile!”，根据程序的需要使用该函数。
### 答案
```c
#include<stdio.h>
void smile()
{
    printf("Smile!");
}
int main()
{
    printf("plaintext\n\n");
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=4-i;j++)
        {
            smile();
        }
        printf("\n");
    }
    return 0;
}
```
***
## 5. 
编写一个程序，生成以下输出：
 
plaintext
  
Brazil, Russia, India, China
India, China
Brazil, Russia
 
 
除了  main()  以外，该程序还要调用两个自定义函数：一个名为  br() ，调用一次打印一次“Brazil, Russia”；另一个名为  ic() ，调用一次打印一次“India, China”。其他内容在  main()  函数中完成。
```c
#include<stdio.h>
void br()
{
    printf("Brazil,Russia");
}
void ic()
{
    printf("India,China");
}
int main()
{
    printf("plaintext\n\n");
    br();
    printf(",");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    return 0;
}
```