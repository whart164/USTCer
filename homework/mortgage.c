#include <stdio.h>
int main()
{
    char ctrl;
    float h_aera=0,h_price=0,h_cash=0,h_rate=0,h_year=0;
    unsigned int loan_month;
    float loan_sum,loan_mon_rate;
    float mon_pay,pay_sum=0;
    int h_type;
    float t;
    int i;
    while(1)
    {
        printf("\ns - 房贷计算\ne - 退出程序\n");
        ctrl=getchar();
        getchar();
        if(ctrl=='s')
        {
            printf("(1)输入购房面积\n");
            scanf("%f",&h_aera);
            printf("(2)输入购房单价\n");
            scanf("%f",&h_price);
            printf("(3)输入购房首付比例(x)%%\n");
            scanf("%f",&h_cash);
            printf("(4)输入贷款利率(x)%%\n");
            scanf("%f",&h_rate);
            printf("(5)输入贷款年限\n");
            scanf("%f",&h_year);
            printf("(6)输入贷款按揭方式: 0-等额本息, 1-等额本金\n");
            scanf("%d",&h_type);
            getchar(); 
            printf("%d",h_type);
            loan_mon_rate=h_rate/100./12;
            loan_month=h_year*12;
            loan_sum=h_aera*h_price*(1-h_cash/100);
            printf("贷款总额为:%.2f\n",loan_sum);
            pay_sum=0.0;
            if(h_type==0)
            {
                t=1.0;
                for(i=0;i<loan_month;i++)
                    t*=(1+loan_mon_rate);
                mon_pay=loan_sum*loan_mon_rate*t/(t-1);
                pay_sum=mon_pay*loan_month;
                printf("等额本息按揭方式每月还款金额为:%.2f\n",mon_pay);
                printf("等额本息按揭方式总还款金额为:%.2f\n",pay_sum);
            }
            else if(h_type==1) 
            {
                printf("等额本金按揭方式每月还款金额列表:\n");
                for(i=0;i<loan_month;i++)
                {
                    mon_pay = loan_sum / loan_month + (loan_sum - loan_sum / loan_month * i) * loan_mon_rate;
                    pay_sum+=mon_pay;
                    printf("第%d个月还款金额 ： %.2f\n",i+1,mon_pay);
                }
                printf("等额本金按揭方式总还款金额为:%.2f\n",pay_sum);
            }
        }
        else if(ctrl=='e')
            break;
    }
    return 0;
}
            
    
