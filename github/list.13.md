# 文件输入/输出
***

## 第2题：文件复制
编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。尽量使用标准 I/O 和二进制模式。
### 答案
```c
#include<stdio.h>
#include<string.h>
int main(int argc,char*argv[])
{
    if(argc!=3)
    {
        printf("Usage: %s source target\n",argv[0]);
        return 1;
    }
    if(strcmp(argv[1],argv[2])==0)
    {
        printf("Source and target must be different\n");
        return 1;
    }
    FILE* fp1=fopen(argv[1],"rb");
    if(fp1==NULL)
    {
        printf("Cannot open source file\n");
        return 1;
    }
    FILE* fp2=fopen(argv[2],"wb");
    if(fp2==NULL)
    {
        printf("Cannot open target file\n");
        fclose(fp1);
        return 1;
    }
    int ch,ok=1;
    while((ch=fgetc(fp1))!=EOF)
    {
        if(fputc(ch,fp2)==EOF)
        {
            ok=0;
            break;
        }
    }
    if(ferror(fp1))ok=0;
    fclose(fp1);
    if(fclose(fp2)==EOF)ok=0;
    if(!ok)
    {
        printf("File copy failed\n");
        return 1;
    }
    printf("File copied successfully\n");
    return 0;
}
```

## 第10题：文件随机访问
编写一个程序打开一个文本文件，通过交互方式获得文件名。通过一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到下一个换行符之前的内容。用户输入负数或非数字字符可以结束输入循环。
### 答案
```c
#include<stdio.h>
int main()
{
    char filename[300];
    long pos;
    int ch;
    printf("Enter filename: ");
    scanf("%299s",filename);
    FILE* fp=fopen(filename,"rb");
    if(fp==NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }
    while(1)
    {
        printf("Enter position: ");
        if(scanf("%ld",&pos)!=1||pos<0)break;
        if(fseek(fp,pos,SEEK_SET)!=0)
        {
            printf("Cannot seek to position\n");
            continue;
        }
        while((ch=fgetc(fp))!=EOF&&ch!='\n')
        {
            putchar(ch);
        }
        putchar('\n');
        fclose(fp);
        return 0;
    }
}
```

## 第11题：文件字符串搜索
编写一个程序，接受两个命令行参数。第1个参数是一个字符串，第2个参数是一个文件名。然后该程序查找该文件，打印文件中包含该字符串的所有行。因为该任务是面向行而不是面向字符的，所以要使用 fgets() 而不是 getc()。使用标准 C 库函数 strstr()（11.5.7 节简要介绍过）在每一行中查找指定字符串。假设文件中的所有行都不超过255个字符。
### 答案
```c
#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("Usage:%s word filename\n",argv[0]);
        return 1;
    }
    FILE* fp=fopen(argv[2],"r");
    if(fp==NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }
    char line[257];
    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        if(strstr(line,argv[1])!=NULL)
        {
            printf("%s",line);
        }
    }
    fclose(fp);
    return 0;
}
```