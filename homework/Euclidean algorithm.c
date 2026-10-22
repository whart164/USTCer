//第十六题
#include<stdio.h>
int main()
{
    int m,n,temp;
    while(1)
    {
loof:   printf("请输入两个整数；\n");
        scanf("%d %d",&m,&n);
        if(m>0&&n>=0)
        {
            while(temp=m%n)
            {
                m=n;
                n=temp;
            }
            printf("最大公约数是%d\n",n);
            temp=0,m=0,n=0;
            rewind(stdin);
        }
        else
            goto loof;
        rewind(stdin);
    }
}