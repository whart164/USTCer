//十六进制的学习
#include <stdio.h>
int main()
{
    char i;unsigned char f;long u;long long k;double v;

    i=0x7f;
    printf("char_max=%d\n",i);
    i=0x80;
    printf("char_min=%d\n",i);
    
    f=0xff;
    printf("unsigned char_max=%d\n",f);
    u=0x7fffffff;
    printf("long_max=%d\n",u);
    u=0x80000000;
    printf("long_min=%d\n",u);

    k=0xffefffffffffffff;
    v=*(double*)&k;
    printf("double_min=%e\n",v);

    k=0x8000000000000001;
    v=*(double*)&k;
    printf("double_0-=%e\n",v);

    k=0x0000000000000001;
    v=*(double*)&k;
    printf("double_0+=%e\n",v);

    k=0x7fefffffffffffff;
    v=*(double*)&k;
    printf("double_max=%e\n",v);
    return 0;
}