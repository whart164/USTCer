//第十二题
#include<stdio.h>
int main()
{
    int data[3],i,j,k,max;
    printf("请在屏幕上输入3个数字:\n");
//输入三个整型数据//
    for(i=0;i<3;i++)
    {
        scanf("%d",&data[i]);
    }
//开始排序（选择排序，从大到小）//
    for(i=0;i<2;i++)
    {
        max=data[i];
        for(j=i+1;j<3;j++)
        {
            if(max>=data[j])
                max=data[i];
            else
            {
                max=data[j];
                data[j]=data[i];
                data[i]=max;
            }
        }
    }
//输出从大到小排序的数组//
    for(k=0;k<3;k++)
    {
        printf("%d ",data[k]);
    }
    return 0;
}