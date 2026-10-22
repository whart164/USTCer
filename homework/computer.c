//开发一个运算二元一次方程组的程序//
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,delta,answer,answerone,answertwo;
    printf("这是一个计算二元一次方程组的程序。请您输入ax2+bx+c=0中的a,b,c\n");
    scanf("%lf%lf%lf",&a,&b,&c);
    delta=b*b-4*a*c;
    if(delta<0)
        printf("此方程无解");
    else if(fabs(delta)<1e-6)
    {
        answer=-b/(2*a);
        printf("答案是:x=%.2lf",answer);
    }
    else
    {
        answerone=(-b-sqrt(delta))/(2*a);
        answertwo=(-b+sqrt(delta))/(2*a);
        printf("答案是:x1=%.2lf,x2=%.2lf",answerone,answertwo);
    }
    return 0;
}