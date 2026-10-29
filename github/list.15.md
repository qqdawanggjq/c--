# 位操作
***
## 第1题：二进制字符串转换为整数

编写一个函数，把二进制字符串转换为一个数值。
例如，有下面的语句：

char *pbin = "01001001";

那么把 pbin 作为参数传递给该函数后，
它应该返回一个 int 类型的值 73。
### 答案
```c
#include<stdio.h>
int trans(char *s)
{
    int num=0;
    while(*s!='\0')
    {
        num=(num<<1)+(*s-'0');
        s++;
    }
    return num;
}
int main()
{
    char s[1000];
    while(scanf("%s",s)!=EOF)
    {
    int num=trans(s);
    printf("%d",num);
    }
    return 0;
}
```

## 第3题：统计二进制中打开的位数

编写一个函数，接受一个 int 类型的参数，
并返回该参数中打开位的数量。
在一个程序中测试该函数。
### 答案
```c
#include<stdio.h>
int count(int x)
{
    unsigned int n=(unsigned int)x;
    int num=0;
    while(n!=0)
    {
        if(n&1)num++;
        n=n>>1;
    }
    return num;
}
int main()
{
    int x;
    scanf("%d",&x);
    int n=count(x);
    printf("%d\n",n);
    return 0;
}
```

## 第5题：循环左移位

编写一个函数，把一个 unsigned int 类型值中
的所有位向左旋转指定数量的位。

例如，rotate_l(x, 4) 把 x 中所有位向左移动
4 个位置，而且从最左端移出的位会重新出现在右端。

也就是说，把高阶位移出的位放入低阶位。
在一个程序中测试该函数。
### 答案
```c
#include<stdio.h>
#include<limits.h>
unsigned int rotate(unsigned int n,int move)
{
    int len=sizeof(unsigned int)*CHAR_BIT;
    move=move%len;
    if(move==0)return n;
    unsigned int ns=((n<<move)|(n>>(len-move)));
    return ns;
}
int main()
{
    unsigned int n;
    int move;
    scanf("%u%d",&n,&move);
    if(move<0)return 1;
    unsigned int x=rotate(n,move);
    printf("%u",x);
    return 0;
}
```