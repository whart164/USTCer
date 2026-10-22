#include <stdio.h>
#include <math.h>
int main()
{
    int R;
    scanf("%d", &R);
    int r_sq=R*R;   
    for (int i=0;i<=2*R;i++) 
    {
        for (int j=0; j<=4*R;j++) 
        {      
            double x=0.5*j-R;
            int y=i-R;
            double dist_sq=x*x+y*y;
            if (fabs(sqrt(x*x+y*y)-R)<=0.25)   
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
