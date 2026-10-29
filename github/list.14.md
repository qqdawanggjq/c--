# 结构和其他形式输出
***

## 第4题：嵌套结构与结构传参
编写程序，定义一个包含两个成员的结构：第一个成员是社会保障号；第二个成员是姓名结构，姓名结构包含名、中间名和姓。
创建并初始化一个包含5个此类结构的数组。
编写函数输出各人的姓名和社会保障号，例如：
Dribble, Flossie M. -- 302039823
中间名只打印首字母及句点；没有中间名时不打印该部分。
(a) 将结构的地址传给输出函数。
(b) 修改程序，改为传递结构本身，而不是地址。
### 答案
```c
#include<stdio.h>
struct name
{
    char firstname[20];
    char midname[20];
    char lastname[20];
};
struct student
{
    char id[30];
    struct name name;
};
void pri1(struct student* people)
{
    printf("%s,",people->name.firstname);
    if(people->name.midname[0]!='\0')
    {
        printf("%c ",people->name.midname[0]);
    }
    printf("%s.--",people->name.lastname);
    printf("%s\n",people->id);
}
void pri2(struct student peoples)
{
    printf("%s,",peoples.name.firstname);
    if(peoples.name.midname[0]!='\0')
    {
        printf("%c ",peoples.name.midname[0]);
    }
    printf("%s.--",peoples.name.lastname);
    printf("%s\n",peoples.id);
}
int main()
{
    struct student arr[5];
    for(int i=0;i<5;i++)
    {
        scanf("%19s%19s%19s%29s",arr[i].name.firstname,
            arr[i].name.midname,arr[i].name.lastname,arr[i].id);
        pri1(&arr[i]);
        pri2(arr[i]);    
    }
    return 0;
}
```

## 第5题：学生成绩管理
(a) 定义name结构，包含名和姓两个字符串。
(b) 定义student结构，包含一个name结构、存放3个分数的grade数组，以及存放平均分的成员。
(c) 在main()中声明CSIZE=4个student结构的数组，并初始化姓名。使用函数完成后续任务。
(d) 获取4名学生的3个分数，保存到对应的grade数组。
(e) 计算每名学生的平均分，存入结构成员。
(f) 输出每名学生的全部信息。
(g) 输出班级所有分数列及学生平均分的平均值。
### 答案
```c
#include<stdio.h>
struct name
{
    char xing[30];
    char ming[30];
};
struct student
{
    struct name name;
    double grade[3];
    double aveage;
};
void entergrade(struct student s[])
{
    for(int i=0;i<4;i++)
    {
        scanf("%lf%lf%lf",&s[i].grade[0],
        &s[i].grade[1],&s[i].grade[2]);    
    }
}
void ave(struct student s[])
{
    for(int i=0;i<4;i++)
    {
        s[i].aveage=(s[i].grade[0]+s[i].grade[1]
            +s[i].grade[2])/3;
    }
}
void pri(struct student s[])
{
    for(int i=0;i<4;i++)
    {
        printf("%s %s %f %f %f %f\n",
        s[i].name.xing,s[i].name.ming,s[i].grade[0],
        s[i].grade[1],s[i].grade[2],s[i].aveage);
    }
    int aveave=(s[0].aveage+s[1].aveage+s[2].aveage+s[3].aveage)/4;
    printf("%f %f\n",aveave,aveave);
}
int main()
{
    struct student s[4]=
    {
        {{"Zhang","San"},{0},0},
        {{"Li","Si"},{0},0},
        {{"Wang","Wu"},{0},0},
        {{"Zhao","Liu"},{0},0}
    };
    entergrade(s);
    ave(s);
    pri(s);
    return 0;
}

```

## 第11题：使用函数指针处理数组
编写transform()函数，它接受4个参数：
1. double类型的源数组；
2. double类型的目标数组；
3. 表示数组元素个数的int参数；
4. 一个接收double参数、返回double结果的函数名（或函数指针）。
transform()将指定函数依次应用到源数组的每个元素，并把结果保存到目标数组。
例如：
transform(source, target, 100, sin);
表示对source的100个元素逐个调用sin()，把结果放到target。
编写测试程序，调用transform()四次，分别传入math.h中的两个函数，以及自己定义的两个适合的函数。
### 答案
```c
#include<stdio.h>
#include<math.h>
double square(double x)
{
    double aim=x*x;
    return aim;
}
void transform(double source[],double target[],int n,double (*hanshu)(double))
{
    for(int i=0;i<n;i++)
    {
        target[i]=hanshu(source[i]);
    }
}
int main()
{
    double source[5]={0,1,2,3,4};
    double target[5];
    transform(source,target,5,sin);
    for(int i=0;i<5;i++)
    {
        printf("%.3f ",target[i]);
    }
    printf("\n");
    transform(source,target,5,square);
    for(int i=0;i<5;i++)
    {
        printf("%.3f ",target[i]);
    }
    printf("\n");
    return 0;
}
```