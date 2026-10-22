
#include <stdio.h>
int main()
{
    int n,x,mid;
    int i,j,k,t;
    double p,q,l,v;
    double weight=0,value=0,value0=0,cha=0;//1.记得初始化
    int num[10];
    double pri[10],hei[10];//分别定义了编号、价值与重量的数组。
    printf("输入背包的容量:");
    scanf("%d",&x);//定义了容量上限
    printf("输入物品的数量:");
    scanf("%d",&n);//定义了物品数量
    //输入编号
    printf("输入%d个物品的编号:",n);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    //输入重量
    printf("输入%d个物品的重量:",n);
    for(k=0;k<n;k++)
        scanf("%lf",&hei[k]);
    //输入价值
    printf("输入%d个物品的价值:",n);
    for(j=0;j<n;j++)
        scanf("%lf",&pri[j]);
    //根据价格排序从高到低
    for(t=0;t<n-1;t++){
        for(j=0;j<n-1-t;j++){
            if(pri[j]>pri[j+1]){
                p=pri[j];pri[j]=pri[j+1];pri[j+1]=p;
                q=num[j];num[j]=num[j+1];num[j+1]=q;
                l=hei[j];hei[j]=hei[j+1];hei[j+1]=l;
            }            
        }
    }    
    //0-1背包问题的按价值贪心法求解
    printf("0-1背包问题的按价值贪心法求解:\n");
    for(i=n-1;i>=0;i--){
        if(weight+hei[i]<=x){
            weight+=hei[i];
            value+=pri[i];
        }
        else
            mid=i;
    }
    for(j=n-1;j>mid;j--){
        printf("%d号物品 重量:%lf 价值:%lf装入背包\n",num[j],hei[j],pri[j]);
    }
    printf("装入背包的物品总价值为:%lf\n",value);
    value=0;weight=0;
    //0-1背包问题的按单位价值贪心法求解
    printf("0-1背包问题的按单位价值贪心法求解:\n");
    //求均值
    double ave[n];
    for(i=0;i<n;i++){
        ave[i]=pri[i]/hei[i];
    }
    for(t=0;t<n-1;t++){
        for(j=0;j<n-1-t;j++){
            if(ave[j]>ave[j+1]){
                v=ave[j];ave[j]=ave[j+1];ave[j+1]=v;
                p=pri[j];pri[j]=pri[j+1];pri[j+1]=p;
                q=num[j];num[j]=num[j+1];num[j+1]=q;
                l=hei[j];hei[j]=hei[j+1];hei[j+1]=l;
            }            
        }
    }
   for(i=n-1;i>=0;i--){
        if(weight+hei[i]<=x){
            weight+=hei[i];
            value+=pri[i];
        }
        else
            mid=i;
    }
    for(j=n-1;j>mid;j--)
        printf("%d号物品 重量:%lf 价值:%lf,单位价值:%lf,装入背包\n",num[j],hei[j],pri[j],ave[j]);
    printf("装入背包的物品总价值为:%lf\n",value);
    value=0;weight=0;
    //部分背包问题的按单位价值贪心法求解
    for(i=n-1;i>=0;i--){
        weight+=hei[i];
        value+=pri[i];
        if(weight+hei[i]<=x){
        }
        else{
            weight=weight-hei[i];
            value=value-pri[i];
            cha=x-weight;
            value0=cha*pri[i]/hei[i];
            mid=i;
            break;
        }
    }
    for(j=n-1;j>mid;j--){
        printf("%d号物品 重量:%lf 价值:%lf,单位价值:%lf,装入背包\n",num[j],hei[j],pri[j],ave[j]);     
    }
    printf("%d号物品 重量:%.2f 价值:%.2f,单位价值:%.2f,其中%.2f重价值%.2f装入背包\n",num[j],hei[j],pri[j],ave[j],cha,value0);
    printf("装入背包的物品总价值为:%lf\n",value+value0);
    return 0;
}