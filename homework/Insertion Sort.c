//排序练习
#define N 8
#include <stdio.h>
int main(){
    //插入排序，从小到大
    int i,j,k,n;int a[N];
    for(i=0;i<N;i++){
        printf("print:") ; scanf("%d",&n);
        for(j=i;j>0;j--){
            if(a[j-1]>n)
                a[j]=a[j-1];
            else break;
        }
        a[j]=n;
    }
    for(k=0;k<N;k++)
        printf("%d ",a[k]);   
}