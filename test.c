#include<stdio.h>
int function1_1(int a,int b,int c)
{
    printf("%d %d %d",a,b,c);
    a=b;
    printf("%d %d %d",a,b,c);
    return(a);
}
int function2_1(int a,int b,int c)
{
    printf("%d %d %d",a,b,c);
    a=2+c;
    b=1;
    printf("%d %d %d",a,b,c);
    return(b);
}
int main_1()
{
    int a=1,b=2,c=3,d=4,e=5,f=6;;
    a=1,b=2,c=3,d=4,e=5,f=6;
    f=function1_1(c,b,d);
    printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);

    a=1,b=2,c=3,d=4,e=5,f=6;
    function2_1(d,b,e);
    printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);

     a=1,b=2,c=3,d=4,e=5,f=6;
    e=function1_1(f,a,d);
    printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);

    a=1,b=2,c=3,d=4,e=5,f=6;
    function2_1(f,e,a);
    printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
    return(0);   
}