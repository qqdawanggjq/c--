# c预处理和c库
***

### 第 3 题：直角坐标与极坐标转换

极坐标用向量的模（即向量的长度）和向量相对 x 轴逆时针旋转的角度来描述该向量。直角坐标用向量的 x 轴和 y 轴的坐标来描述该向量（见图 16.3）。编写一个程序，读取向量的模和角度（单位：度），然后显示 x 轴和 y 轴的坐标。相关方程如下：

x = r × cos A
y = r × sin A

需要一个函数完成转换，该函数接受一个包含极坐标的结构，并返回一个包含直角坐标的结构（或返回指向该结构的指针）。
#### 答案
```c
#include<stdio.h>
#include<math.h>
struct ji
{
    double mo;
    double jiao;
};
struct zhijiao
{
    double x;
    double y;
};
struct zhijiao trans(struct ji ori)
{
    struct zhijiao aim;
    double pi=acos(-1.0);
    aim.x=ori.mo*cos(ori.jiao*(pi/180));
    aim.y=ori.mo*sin(ori.jiao*(pi/180));
    return aim;
}
int main()
{
    struct ji ori;
    while(scanf("%lf%lf",&ori.mo,&ori.jiao)==2)
    {
        struct zhijiao aim=trans(ori);
        printf("%f %f\n",aim.x,aim.y);
    }
    return 0;
}
```

### 第 5 题：随机选择数组元素

编写一个函数接受这些参数：内含 int 类型元素的数组名、数组的大小和一个代表选取次数的值。该函数从数组中随机选择指定数量的元素，并打印它们。每个元素只能选择一次（模拟抽奖或挑选陪审团成员）。另外，如果你的实现有 time()（第 12 章讨论过）或类似的函数，可在 srand() 中使用这个函数的输出来初始化随机数生成器 rand()。编写一个简单的程序测试该函数。
#### 答案
```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void freedom(int arr[],int n,int select)
{
    for(int i=0;i<select;i++)
    {
        int j=rand()%(n-i);
        printf("%d ",arr[j]);
        int t=arr[j];
        arr[j]=arr[n-1-i];
        arr[n-1-i]=t;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    int arr[100];
    int i=0;
    while(i<100&&scanf("%d",&arr[i])==1)
    {
        i++;
    }
    printf("请输入选取次数：");
    int select;
    scanf("%d",&select);
    freeodm(arr,i,select);
    return 0;
}
```

### 第 7 题：动态分配 double 数组

下面是使用变参函数的一个程序段。使用较少的元素（在程序清单 16.17 后面的讨论中定义过），而不用变参函数的版本。用动态分配的数组初始化数组。

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main()
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}
```

new_d_array() 函数接受一个 int 类型的参数和 double 类型的参数。该函数返回一个指针，指向由 malloc() 分配的内存块。int 类型的参数指定了动态数组中的元素个数，double 类型的值用于初始化元素（第 1 个值赋给第 1 个元素，以此类推）。编写 show_array() 和 new_d_array() 函数的代码，完成这个程序。
#### 答案
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);
int main()
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}
double * new_d_array(int n, ...)
{
    double* p=(double*)malloc(sizeof(double)*n);
    va_list ap;
    va_start(ap,n);
    for(int i=0;i<n;i++)
    {
        p[i]=va_arg(ap,double);
    }
    va_end(ap);
    return p;
}
void show_array(const double ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%.2f",ar[i]);
    }
    printf("\n");
}
```