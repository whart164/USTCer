//在数组中查找数据
#include <stdio.h>
int main()
{
    int a[10];
    int flag=0;
    int i,Tofind;
    int low,high,mid;
    printf("请输入10个整数:");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("你输入的10个数是:0-无序，1-升序，2-降序？");
    scanf("%d",&flag);
    printf("输入你想要找的数据：");
    scanf("%d",&Tofind);
    if(flag==0)
    {
        for(i=0;i<10;i++)
        {
            if(a[i]==Tofind)
                printf("找到要找的数在数组位置；%d\n",i);
        }
    }
    else if(flag==1||flag==2)
    {
        low=0;high=9;
        while(low<high)
        {
            mid=(low+high)/2;
            if(a[mid]==Tofind)
                printf("找到要找的数在数组位置；%d\n",mid);
            if(flag==1)
            {
                if(a[mid]>Tofind)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else
            {
                if(a[mid]<Tofind)
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
    }
    else
        printf("无效操作\n");
    return 0;
}