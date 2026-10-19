// #include<stdio.h>
// int main()
// {
//     printf(" hello world\nhttps://www.xiyoulinux.com/https://www.xiyoulinux.com/");
//     return 0;
// }
//  
#include<stdio.h>
#include<stdlib.h>
typedef struct result
{
    int* arr;
    int len;
}result;
void your_sort(int* arr1,int len1,int* arr2,int len2,result* res)
{
    res->len=len1+len2;
    res->arr=(int*)malloc(res->len*sizeof(int));
    for(int i=0;i<len1;i++)
    {
        res->arr[i]=arr1[i];
    }
    for(int i=0;i<len2;i++)
    {
        res->arr[len1+i]=arr2[i];
    }
    for(int i=0;i<res->len-1;i++)
    {
        for(int j=0;j<res->len-1-i;j++)
        {
            if(res->arr[j]>res->arr[j+1])
            {
                int t=res->arr[j+1];
                res->arr[j+1]=res->arr[j];
                res->arr[j]=t;
            }
        }
    }
    int slow=0;
    for(int fast=1;fast<res->len;fast++)
    {
        if(res->arr[fast]!=res->arr[slow])
        {
            slow++;
            res->arr[slow]=res->arr[fast];
        }
    }
    res->len=slow+1;
}
int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    result result;
    your_sort(arr1, len1, arr2, len2, &result);
    for (int i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    free(result.arr);
    return 0;
}