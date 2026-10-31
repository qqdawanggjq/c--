// #include<stdio.h>
// #define pay1 8.75
// #define pay2 9.33
// #define pay3 10.00
// #define pay4 11.20
// #define normal 40
// #define overtime 1.5
// #define shui1 0.15
// #define shui2 0.20
// #define shui3 0.25
// int main()
// {
//     while(1)
//  {
//     int hour;
//     double all,shui,pour;
//     double pay;
//     printf("\n********************************\n");
//         printf("请选择工资等级：\n");
//         printf("1) $8.75/hr    2) $9.33/hr\n");
//         printf("3) $10.00/hr   4) $11.20/hr\n");
//         printf("5) quit\n");
//         printf("********************************\n");

//         printf("请输入选项：");
//     int act=0;
//     scanf("%d",&act);
//     switch(act)
//     {
//         case 1:
//         {
//             pay=pay1;
//             break;
//         }
//         case 2:
//         {
//             pay=pay2;
//             break;
//         }
//         case 3:
//         {
//             pay=pay3;
//             break;
//         }
//         case 4:
//         {
//             pay=pay4;
//             break;
//         }
//         case 5:
//         {
//             return 0;
//         }
//         default:
//         {
//             printf("请输入正确的选项：");
//             continue;
//         }
//     }
//     printf("请输入工作小时：");
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
//         printf("总工资：%.2f\n税金：%.2f\n净收入：%.2f\n",all,shui,pour);
//         return 0;
//  }
// }
// #include<stdio.h>
// int main()
// {
//     int ch=0;
//     int num=0;
//     while(ch=getchar()!=EOF)
//     {
//         num++;
//     }
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int ch=0,num=0;
//     while((ch=getchar())!=EOF)
//     {
//         num++;
//     }
//     printf("%d",num);
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int ch=0,big=0,small=0;
//     while((ch=getchar())!=EOF)
//     {
//         if(ch>='A'&&ch<='Z')big++;
//         else if(ch>='a'&&ch<='z')small++;
//     }
//     printf("\n%d %d\n",big,small);
//     return 0;
// }
// #include<stdio.h>
// #include<ctype.h>
// int main()
// {
//     int ch=0,big=0,small=0;
//     while((ch=getchar())!=EOF)
//     {
//         if(isupper(ch))big++;
//         else if(islower(ch))small++;
//     }
//     printf("\n%d %d\n",big,small);
//     return 0;
// }
// 
// int ch;
// while((ch=getchar())!='\n'&&ch!=EOF){}
// float a;
// while((scanf("%f",&a))!=1)
// {
//     printf("cuo");
//     int ch;
//     while((ch=getchar())!='\n'&&ch!=EOF){}
//     printf("chongxin");

// }
// double a;
// int ok;
// while((ok=scanf("%f",&a))!=1)
// {
//     if(ok==EOF)return 0;
//     int ch;
//     while((ch=getchar())!='\n'&&ch!=EOF){}
//     if(ch==EOF)return 0;
// }
// int get_number(float* p)
// {
//     int ok=0;
//     if((ok=scanf("%f",x))==1)return 1;
//     if(ok==EOF)return 0;
//     return 0;
// }
// int main()
// {
//     float x;
//     if(get_number(&x)==1)
//     {
//         printf("%f",x);
//     }
// }
// int main()
// {
//     float a,b;
//     if(get_number(a)&&get_number(b))
//     {
//         printf("%f",a+b);
//     }
//     else
//     {
//         return 0;
//     }
//     return 0;
// }
// int main()
// {
//     while(1)
//     {
//         printf("hahaha");
//         char c;
//         if((scanf("%f",&c))!=1)break;
//         switch(c)
//         {
//             case a:
//             {
//                 break;
//             }
//             case q:
//             {
//                 return 0;
//             }
//             default:
//             {
//                 printf("cuo");
//                 continue;
//             }
//         }
//     }
// }
// while((scanf("%f",&a))==0)
// {
//     printf("chongxin");

// }
// #include<stdio.h>
// int get_number(double* p)
// {
//     char wrong[100];
//     int ok=0;
//     while((ok=scanf("%lf",p))!=1)
//     {
//         if(ok==EOF)return 0;
//         if(scanf("%99s",wrong)!=1)return 0;
//         printf("%s is not a number.\n",wrong);
//         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
//         int ch;
//         while((ch=getchar())!='\n'&&ch!=EOF)
//         {}
//         if(ch==EOF)return 0;
//     }
//     return 1;
// }
// int main()
// {
//     while(1)
//     {
//         printf("\nEnter the operation of your choice: \n");
//         printf("a. add        s. subtract\n");
//         printf("m. multiply   d. divide\n");
//         printf("q. quit\n");
//         char c;
//         if((scanf(" %c",&c))!=1)break;
//         switch(c)
//         {
//             case 'a':
//             {
//                 double one,two;
//                 printf("Enter first number: ");
//                 if((get_number(&one))==0)return 0;
//                 printf("Enter second number:");
//                 if((get_number(&two))==0)return 0;
//                 printf("%f + %f = %f\n",one,two,one+two);
//                 break;
//             }
//             case 's':
//             {
//                 double one,two;
//                 printf("Enter first number: ");
//                 if((get_number(&one))==0)return 0;
//                 printf("Enter second number:");
//                 if((get_number(&two))==0)return 0;
//                 printf("%f - %f = %f\n",one,two,one-two);
//                 break;
//             }
//             case 'm':
//             {
//                 double one,two;
//                 printf("Enter first number: ");
//                 if((get_number(&one))==0)return 0;
//                 printf("Enter second number:");
//                 if((get_number(&two))==0)return 0;
//                 printf("%f * %f = %f\n",one,two,one*two);
//                 break;
//             }
//             case 'd':
//             {
//                 double one,two;
//                 printf("Enter first number: ");
//                 if((get_number(&one))==0)return 0;
//                 printf("Enter second number:");
//                 if((get_number(&two))==0)return 0;
//                 while(two==0)
//                 {
//                     printf("Enter a number other than 0: ");
//                     if((get_number(&two))==0)return 0;
//                 }
//                 printf("%f / %f = %f\n",one,two,one/two);
//                 break;
//             }
//             case 'q':
//             {
//                 printf("Bye.\n");
//                 return 0;
//             }
//             default:
//             {
//                 printf("Please enter a choice\n");
//                 continue;
//             }
//         }
//     }
//     return 0;
// }
// #include<stdio.h>
// void large_of(double* x,double* y)
// {
//     if(*x>=*y)
//     {
//         *y=*x;
//     }
//     else
//     {
//         *x=*y;
//     }
// }
// int main()
// {
//     double a,b;
//     scanf("%lf%lf",&a,&b);
//     large_of(&a,&b);
//     printf("%.2f %.2f",a,b);
//     return 0;
// }
// #include<stdio.h>
// double power(double n,int p)
// {
//     if(p==0)
//     {
//         if(n==0)
//         {
//             printf("未定义\n");
//         }
//         return 1;
//     }
//     double pow=1;
//     int xp=p;
//     if(p<0)xp=-p;
//     for(int i=1;i<=xp;i++)
//     {
//         pow*=n;
//     }
//     if(p<0)
//     {
//         if(n==0)
//         {
//             printf("未定义\n");
//             return 1;
//         }
//         pow=1.0/pow;
//     }
//     return pow;
// }
// int main()
// {
//     double x,xpow;
//     int exp;
//     printf("Enter a number and the positive integer power");
//     printf(" to which\nthe number will be raised. Enter q");
//     printf(" to quit.\n");
//     while((scanf("%lf%d",&x,&exp))==2)
//     {
//         xpow=power(x,exp);
//         printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
//         printf("Enter next pair of numbers or q to quit.\n");
//     }
//     printf("Hope you enjoyed this power trip -- bye!\n");
//     return 0;
// }
// #include<stdio.h>
// int judge(int ch)
// {
//     if(ch>='a'&&ch<='z')
//     {
//         return ch-'a'+1;
//     }
//     if(ch>='A'&&ch<='Z')
//     {
//         return ch-'A'+1;
//     }
//     return -1;
// }
// int main()
// {
//     int ch;
//     while((ch=getchar())!=EOF)
//     {
//         int x=judge(ch);
//         if(x!=-1)printf("是字母 %d\n",x);
//         else printf("不是字母\n");
//     }
//     return 0;
// }
// #include<stdio.h>
// void copy_arr(double aim[],double pri[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         aim[i]=pri[i];
//     }
// }
// void copy_ptr(double aim[],double pri[],int n)
// {
//     double* p=pri;
//     for(int i=0;i<n;i++)
//     {
//         aim[i] = *p;
//         p++;
//     }
// }
// void copy_ptrs(double aim[],double pri[],double* p)
// {
//     for(int i=4;i>=0;i--)
//     {
//         aim[i] = *p;
//         p--;
//     }
// }
// int main()
// {
//     double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
//     double target1[5];
//     double target2[5];
//     double target3[5];
//     copy_arr(target1, source, 5);
//     copy_ptr(target2, source, 5);
//     copy_ptrs(target3, source, source + 5);
//     for(int i=0;i<5;i++)
//     {
//         printf("%f %f %f %f\n",source,target1,target2,target3);
//     }
//     return 0;
// }