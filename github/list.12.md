# 存储类别、链接和内存管理
***


## 第5题：随机数排序

编写一个程序，生成100个1～10范围内的随机数，并以降序排列（可以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排序）。
### 答案
```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int arr[100];
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        arr[i]=rand()%10+1;
    }
    for(int i=0;i<99;i++)
    {
        for(int j=i+1;j<100;j++)
        {
            if(arr[j]>arr[i])
            {
                int t=arr[j];
                arr[j]=arr[i];
                arr[i]=t;
            }
        }
    }
    for(int i=0;i<100;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
```

## 第8题：动态数组

下面是程序的一部分：

```c
#include <stdio.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");

    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);

        pa = make_array(size, value);

        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }

        printf("Enter the number of elements (<1 to quit): ");
    }

    printf("Done.\n");
    return 0;
}
```

提供 make_array() 和 show_array() 函数的定义，完成该程序。

make_array() 函数接受两个参数，第1个参数是int类型数组的元素个数，第2个参数是要赋给每个元素的值。该函数调用malloc()创建一个大小合适的数组，将其每个元素设置为指定的值，并返回一个指向该数组的指针。

show_array() 函数显示数组的内容，一行显示8个数。
### 答案
```c
#include<stdio.h>
#include<stdlib.h>
int* make_array(int elem,int val)
{
    int* p=(int*)malloc(elem*sizeof(int));
    if(p==NULL)return NULL;
    for(int i=0;i<elem;i++)
    {
        p[i]=val;
    }
    return p;
}
void show_array(const int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",ar[i]);
        if((i+1)%8==0)printf("\n");
    }
    if(n%8!=0)printf("\n");
}
int main(void)
{
    int* pa;
    int size;
    int value;
    printf("Enter the number of element: ");
    while(scanf("%d",&size)==1&&size>0)
    {
        printf("Enter the initialization value: ");
        scanf("%d",&value);
        pa=make_array(size,value);
        if(pa)
        {
            show_array(pa,size);
            free(pa);
            pa=NULL;
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}
```

## 第9题：动态字符串数组

编写一个符合以下描述的函数。

首先，询问用户需要输入多少个单词。然后，接收用户输入的单词，并显示出来。

使用 malloc() 和回答第1个问题（即要输入多少个单词），创建一个动态数组，该数组包含相应的指向char的指针。

注意，由于数组的每个元素都是指向char的指针，所以用于存储malloc()返回值的指针应该是一个指向char的指针的指针。

在读取字符串时，该程序应该把单词读入一个临时的char数组，使用malloc()分配足够的空间来存储单词，并把地址存入该指针数组（该数组中每个元素都是指向char的指针）。

然后，从临时数组中把单词复制到动态分配的存储空间中。

因此，有一个字符指针数组，每个指针都指向一个对象，该对象的大小正好足够容纳被存储的特定单词。

下面是该程序的一个运行示例：

How many words do you wish to enter? 5
Enter 5 words now:
I enjoyed doing this exercise

Here are your words:
I
enjoyed
doing
this
exercise
### 答案
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    printf("How many words do you wish to enter? ");
    int num;
    scanf("%d",&num);
    printf("Enter %d words now:\n",num);
    char s[1000];
    char** p=malloc(num*sizeof(char*));
    if(p==NULL)return 1;
    for(int i=0;i<num;i++)
    {
        scanf("%999s",s);
        p[i]=malloc(strlen(s)+1);
        if(p[i]==NULL)
        {
            for(int j=0;j<i;j++)
            {
                free(p[j]);
            }
            free(p);
            return 1;
        }
        strcpy(p[i],s);
    }
    printf("Here are you words:\n");
    for(int i=0;i<num;i++)
    {
        printf("%s\n",p[i]);
    }
    for(int i=0;i<num;i++)
    {
        free(p[i]);
    }
    free(p);
    return 0;
}
```