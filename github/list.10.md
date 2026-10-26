# 数组和指针
***
## 第 2 题：数组复制

编写一个程序，初始化一个 double 类型的数组，然后把该数组的内容拷贝至 3 个其他数组中（在 main() 中声明这 4 个数组）。使用带数组表示法的函数进行第 1 份拷贝。使用带指针表示法和指针递增的函数进行第 2 份拷贝。把目标数组名、源数组名和待拷贝项的元素个数作为前两个函数的参数。第 3 个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针作为参数。也就是说，给定以下声明，则函数调用如下所示：

double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];

copy_arr(target1, source, 5);
copy_ptr(target2, source, 5);
copy_ptrs(target3, source, source + 5);
### 答案
```c
#include<stdio.h>
void copy_arr(double aim[],double pri[],int n)
{
    for(int i=0;i<n;i++)
    {
        aim[i]=pri[i];
    }
}
void copy_ptr(double aim[],double pri[],int n)
{
    double* p=pri;
    for(int i=0;i<n;i++)
    {
        aim[i] = *p;
        p++;
    }
}
void copy_ptrs(double aim[],double pri[],double* p)
{
    for(int i=0;pri+i<p;i++)
    {
        aim[i]=pri[i];
    }
}
int main()
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    for(int i=0;i<5;i++)
    {
        printf("%f %f %f %f\n",source[i],target1[i],target2[i],target3[i]);
    }
    return 0;
}
```

## 第 6 题：数组逆序

编写一个函数，把 double 类型数组中的数据倒序排列，并在一个简单的程序中测试该函数。
### 答案
```c
#include<stdio.h>
void fan(double pri[],double copy[],int n)
{
    for(int i=0;i<n;i++)
    {
        copy[i]=pri[i];
    }
    for(int i=0;i<n;i++)
    {
        pri[n-1-i]=copy[i];
    }
}
int main()
{
    double pri[100];
    double copy[100];
    int n=0;
    while(n<100&&(scanf("%lf",&pri[n]))==1)
    {
        n++;
    }
    fan(pri,copy，n);
    printf("逆函数\n");
    for(int i=0;i<n;i++)
    {
        printf("%f",pri[i]);
    }
    return 0;
}
```

## 第 9 题：二维数组复制

编写一个程序，初始化一个 double 类型的 3×5 二维数组，使用一个处理变长数组的函数将其拷贝至另一个二维数组中。还要编写一个以变长数组为形参的函数以显示两个数组的内容。这两个函数应该能够处理任意 N×M 数组（如果编译器不支持变长数组，就使用传统 C 函数处理 N×5 的数组）。
### 答案
```c
#include<stdio.h>
void cop(int hang,int lian,double pri[hang][lian],double copy[hang][lian])
{
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<lian;j++)
        {
            copy[i][j]=pri[i][j];
        }
    }
}
void prin(int hang,int lian,double pri[hang][lian],double copy[hang][lian])
{
    printf("原数组\n");
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<lian;j++)
        {
            printf("%f ",pri[i][j]);
        }
        printf("\n");
    }
    printf("拷贝数组\n");
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<lian;j++)
        {
            printf("%f ",copy[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    double pri[3][5],copy[3][5];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%lf",&pri[i][j]);
        }
    }
    cop(3,5,pri,copy);
    prin(3,5,pri,copy);
    return 0;
}
```