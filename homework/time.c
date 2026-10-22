//数组与文件
#include <stdio.h>
#include <time.h>//包含获取系统当前日期和时间的函数声明
int main()
{
    FILE *fpi,*fpo;//定义两个指针变量
    time_t seconds;//从1970年到现在的秒数
    char days_mons[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                            {31,29,31,30,31,30,31,31,30,31,30,31}};
    char leap=0;
    int year,month,day,hour,minute,second;
    int a[100];
    int n;
    int i,j,t;
    printf("有几个数(1~100):");
    scanf("%d",&n);//输入文件数组中有几个数
    fpi=fopen("data.txt","r");//使用只读的方式打开data.txt
    if(fpi==NULL)//打不开数据文件
    {
        fpi=fopen("data.txt","w+");//使用可读写的方式打开data.txt
        printf("输入%d个数:",n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            fprintf(fpi,"%d ",a[i]);
        }
        rewind(fpi);//调整到文件开头，以便后续从头开始读取
    } 
    fpo=fopen("result.txt","a");//使用可追加的方式打开result.txt
    for(i=0;i<n;i++)
        fscanf(fpi,"%d",&a[i]);//读取数据来源是是fpi，来自data.txt
    fclose(fpi);//关闭数据文件data.txt
    seconds=time(NULL)+8*60*60;//获取系统从1970年1月1日到现在的秒数，加上时区的秒数
    second=seconds%60;
    seconds/=60;
    minute=seconds%60;
    seconds/=60;
    hour=seconds%24;
    seconds/=24;
    year=1970;
    leap=((year%4==0&&year%100!=0)||(year%400==0));
    while((leap&&seconds>365)||(!leap&&seconds>364))
    {
        if(leap)//闰年
            seconds-=366;//减少一年366天
        else
            seconds-=365;
        year++;//年份加一
        leap=((year%4==0&&year%100!=0)||(year%400==0));
    }
    month=1;//计算月
    for(i=0;seconds>=days_mons[leap][i];i++,month++)//年内月份
        seconds-=days_mons[leap][i];//减少一个月
    day=seconds+1;//计算月内哪一天
    fprintf(fpo,"%d-%02d-%02d,%02d:%02d:%02d\n",year,month,day,hour,minute,second);
    for(i=0;i<n;i++)
        fprintf(fpo,"%d ",a[i]);//将数组中的数据写入文件
    fprintf(fpo,"\n");
    fclose(fpo);
    return 0;
}