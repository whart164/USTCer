#define N 7
#include <stdio.h>
int main()
{
    int value[N]={1,2,5,10,20,50,100};
    int a[N]={5,5,0,0,2,1,3};
    int money,i,num=0,c=0;
    printf("请输入需要支付的总额:");
    scanf("%d",&money);
    for(i=N-1;i>=0;i--){
        if(money/value[i]<=a[i])
            c=money/value[i];
        else
            c=a[i];
        money=money-c*value[i];
        num+=c;
    }
    if(money>0)
        num=-1;
    if(num!=1)
        printf("%d\n",num);
    else
        printf("无解！");
    return 0;
}