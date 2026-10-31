// #include<stdio.h>
// int main()
// {
//     printf("Please getput number kuatuo:");
//     double n;
//     scanf("%lf",&n);
//     double num=(950*n)/3.0e-23;
//     printf("%e",num);
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     printf("\a");
//     printf("plaintext\n\n");
//     printf("Startled by the sudden sound,Sally shouted,\n\"By the Great Pumpkin,what was that!\"");
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     printf("plaintext\n\nEnter a floating-point value:");
//     double n;
//     scanf("%lf",&n);
//     printf("fixed-point notation:%lf\n",n);
//     printf("exponential notation:%e\n",n);
//     printf("p notation:%a\n",n);
//     return 0;
// #include<stdio.h>
// #include<float.h>
// int main()
// {
//     double d=1.0/3.0;
//     float f=1.0f/3.0f;
//     printf("%.6f\n",f);
//     printf("%.12f\n",f);
//     printf("%.16f\n",f);
//     printf("%.6lf\n",d);
//     printf("%.12lf\n",d);
//     printf("%.16lf\n",d);
//     printf("%d\n",FLT_DIG);
//     printf("%d\n",DBL_DIG);
//     return 0;
// }
// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char first[20],last[20];
//     printf("enter your first name:");
//     scanf("%s",first);
//     printf("enter your last name:");
//     scanf("%s",last);
//     int len1=strlen(first);
//     int len2=strlen(last);
//     printf("plaintext\n\n%s %s\n",first,last);
//     printf("%*d %*d\n",len1,len1,len2,len2);
//     printf("plaintext\n\n%s %s\n",first,last);
//     printf("%-*d %-*d\n",len1,len1,len2,len2);
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     long long n;
//     scanf("%lld",&n);
//     long long str=n;
//     int max=1;
//     for(long long i=2;i*i<=n;i++)
//         {
//             int num=0;
//             long long t=n;
//             long long j=i;
//             while(t%j==0)
//                 {
//                     t=t/j;
//                     j++;
//                     num++;
//                     if(num>max)
//                     {
//                         max=num;
//                         str=i;
//                     }
//                 }
//         }
//     printf("%d\n",max);
//     for(long long i=0;i<max;i++)
//         {
//             printf("%lld",str+i);
//             if(i!=max-1)
//             {
//                 printf("*");
//             }
//         }
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     long long n;
//     scanf("%lld", &n);
//     long long str;
//     int max = 0; // 初始化为0，保证第一次找到因子就能更新

//     for (long long i = 2; i * i <= n; i++)
//     {
//         int num = 0;
//         long long t = n;
//         long long j = i;
//         while (t % j == 0)
//         {
//             t /= j;
//             j++;
//             num++;
//             if (num > max)
//             {
//                 max = num;
//                 str = i;
//             }
//         }
//     }

//     // 处理质数：循环没找到任何因子，最长序列就是自身
//     if (max == 0)
//     {
//         max = 1;
//         str = n;
//     }

//     // 输出
//     printf("%d\n", max);
//     for (long long i = 0; i < max; i++)
//     {
//         if (i == 0)
//             printf("%lld", str + i);
//         else
//             printf("*%lld", str + i);
//     }
//     printf("\n"); // 末尾补换行
// return 0;
// }
// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char s[50];
//     printf("enter your name:");
//     scanf("%s",s);
//     int len=strlen(s);
//     printf("\"%s\"\n",s);
//     printf("\"%20s\"\n",s);
//     printf("\"%-20s\"\n",s);
//     printf("\"%-*s\"\n",len+3,s);
//     return 0;
// }
// #include<stdio.h>
// void Temperatures(double tem)
// {
//     const double a=5.0/9.0;
//     const double b=32.0;
//     const double c=273.16;
//     double she=a*(tem-b);
//     double kai=she+c;
//     printf("%.2lf\n%.2lf\n%.2lf\n",tem,she,kai);
// }
// int main()
// {
//     double tem=0;
//     printf("请输入华氏温度：");
//     while((scanf("%lf",&tem))==1)
//     {
//         Temperatures(tem);
//         printf("请输入华氏温度：");
//     }
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     printf("This program computes moduli\n");
//     printf("Enter an integer to serve as the second operand: ");
//     int sec=0;
//     scanf("%d",&sec);
//     printf("\nNow enter the first operand: ");
//     int one=0;
//     scanf("%d",&one);
//     if(one<=0)
//     {
//         printf("Done\n");
//         return 0;
//     }
//     printf("%d %% %d is %d\n",one,sec,one%sec);
//     printf("Enter next number for first operand (<= 0 to quit): ");
//     while(scanf("%d",&one)==1&&one>0)
//     {
//         printf("%d %% %d is %d\n",one,sec,one%sec);
//         printf("Enter next number for first operand (<= 0 to quit): ");
//     }
//     printf("Done\n");
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int day=0;
//     printf("enter your days:");
//     while(scanf("%d",&day)==1&&day>0)
//     {
//         printf("%d days are %d weeks, %d days.\n",day,day/7,day%7);
//         printf("enter your days:");
//     }
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int fri=5;
//     int week=1;
//     while(fri<=150)
//     {
//         fri=(fri-week)*2;
//         printf("Week: %d, friend number: %d\n",week,fri);
//         week++;
//     }
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     double s1[10],s2[10];
//     for(int i=0;i<8;i++)
//     {
//         printf("Please enter number:");
//         scanf("%lf",&s1[i]);

//     }
//     double sum=0;
//     for(int i=0;i<8;i++)
//     {
//         sum=sum+s1[i];
//         s2[i]=sum;
//     }
//     for(int i=0;i<8;i++)
//     {
//         printf("%-10f ",s1[i]);
//     }
//     printf("\n");
//     for(int i=0;i<8;i++)
//     {
//         printf("%-10f ",s2[i]);
//     }
//     return 0;
// }
// #include<stdio.h>
// #include<math.h>
// int main()
// {
//     int n=0;
//     printf("Enter numer: ");
//     while(scanf("%d",&n)==1&&n>0)
//   {
//     double sum1=0,sum2=0;
//     for(int i=1;i<=n;i++)
//     {
//         sum1=sum1+1.0/i;
//         sum2=sum2+(pow(-1,i-1))*1.0/i;
//     }
//     printf("first: %f\nsecond: %f\n",sum1,sum2);
//     printf("Enter numer: ");
//   }
//   return 0;
// }
// #include<stdio.h>
// int main()
// {
//     char c;
//     printf("请输入字母：");
//     scanf("%c",&c);
//     for(int i='A';i<=c;i++)
//     {
//         for(int j=1;j<=c-i;j++)
//         {
//             printf(" ");
//         }
//         for(int j=1;j<=i-'A'+1;j++)
//         {
//             printf("%c",'A'+j-1);
//         }
//         for(int j=i-'A';j>=1;j--)
//         {
//             printf("%c",'A'+j-1);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// #include<stdio.h>
// #define pay 10.00
// #define normal 40
// #define overtime 1.5
// #define shui1 0.15
// #define shui2 0.20
// #define shui3 0.25
// int main()
// {
//     printf("请输入工作时间：");
//     int hour;
//     double all,shui,pour;
//     scanf("%d",&hour);
//     if(hour<=normal)
//     {
//         all=hour*pay;
//     }
//     else
//     {
//         all=(normal+(hour-normal)*overtime)*pay;
//     }
//         if(all<=300)
//         {
//             shui=shui1*all;
//         }
//         else if(all<=450)
//         {
//             shui=shui1*300+shui2*(all-300);
//         }
//         else
//         {
//             shui=shui1*300+shui2*150+shui3*(all-450);
//         }
//         pour=all-shui;
//         printf("总工资：%.2f\n税金：%.2f\n净收入：%.2f",all,shui,pour);
//         return 0;
// }
// #include <stdio.h>
// int main()
// {
//     char type;
//     double pay;
//     printf("(单身--A, 户主--B, 已婚 共有--C, 已婚 离异--D)\n请输入缴纳税金的种类和应纳税收入: ");
//     while (scanf(" %c%lf", &type, &pay)==2)
//     {
//         double shui;
//         switch(type)
//         {
//             case 'A':
//             {
//                if(pay<=17850)
//                 {
//                     shui=pay*0.15;
//                 }
//                 else
//                 {
//                     shui=17850*0.15+(pay-17850)*0.28;
//                 }
//                 break;
//             }
//             case 'B':
//             {
//                if(pay<=23900)
//                 {
//                     shui=pay*0.15;
//                 }
//                 else
//                 {
//                     shui=23900*0.15+(pay-23900)*0.28;
//                 }
//                 break;
//             }
//             case 'C':
//             {
//                if(pay<=29750)
//                 {
//                     shui=pay*0.15;
//                 }
//                 else
//                 {
//                     shui=29750*0.15+(pay-29750)*0.28;
//                 }
//                 break;
//             }
//             case 'D':
//             {
//                if(pay<=14875)
//                 {
//                     shui=pay*0.15;
//                 }
//                 else
//                 {
//                     shui=14875*0.15+(pay-14875)*0.28;
//                 }
//                 break;
//             }
//             default:
//             {
//                 printf("输入错误！请重新输入：");
//                 continue;
//             }

//         }
//         printf("税金：%f\n",shui);
//         printf("(单身--A, 户主--B, 已婚 共有--C, 已婚 离异--D)\n请输入缴纳税金的种类和应纳税收入: ");
//     }
//     return 0;
// }
