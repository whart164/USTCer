//交换数组的元素
#include <stdio.h>
int main()
{
    int a[100];
    int n;
    int i,j,t;
    printf("有几个数(1~100):");
    scanf("%d",&n);
    printf("输入%d个数:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n/2;i++)
    {
        t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
    printf("逆序储存后的数组元素依次为；\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    while(1)
    {
        printf("\n输入要交换的两个元素的位置(0~%d):",n-1);
        scanf("%d%d",&i,&j);
        if(i<0&&i>n-1||j<0&&j>n-1)
            break;
        else
        {x
            a[i]+=a[j];
            a[j]=a[i]-a[j];
            a[i]=a[i]-a[j];
        }
        for(i=0;i<n;i++)
            printf("%d",a[i]);
    }
    return 0;
}