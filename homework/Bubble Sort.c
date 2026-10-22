//冒泡排序
#define N 5
#include <stdio.h>
int main()
{
    int i,j,t,temp,n,k;
    int a[N];
    for(i=0;i<N;i++){
        printf("print:") ; scanf("%d",&a[i]);
    }
    for(t=0;t<N;t++){
        for(j=0;j<N-t;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1] ; a[j+1]=a[j] ; a[j]=temp;
            }
        }
    }
    for(k=0;k<N;k++)
        printf("%d ",a[k]); 
}