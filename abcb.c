
// C++ code to find the exponential notation
#include <stdio.h>
#include<math.h>
#include<string.h>
  
// function to calculate the exponential
// notation
typedef struct{
    double mantissa;
    int exponent;
}sciNotation;
void FindExponent(char s[], int n)
{
    char arr[10];
    int a=0;
    int i, j, b, c;
    for (i = 0; s[i] == '0' || s[i] == '.'; i++);
    for (j = n - 1; s[j] == '0' || s[j] == '.'; j--);
    int l;
    for(l=0;l<n;l++)
    {
        if(s[l]=='.')
        {
        c=l;
        break;
        }
    }
    if(l==n)
    c=n;
    printf("%d\n",c);
    putchar(s[i]);
    arr[a]=s[i];
    a++;
  
    if (i != j)
    {
        putchar('.');
        arr[a]='.';
        a++;
    }
  
    for (int k = i + 1; k <= j; k++)
        if (s[k] != '.')
        {
            putchar(s[k]);
            arr[a]=s[k];
            a++;
        }
    if (i < c)
        b = c - i - 1;
    else
        b = c - i;
    if (b)
        printf("E+%d\n\n", b);
    for(int l=0;l<a;l++)
        putchar(arr[l]);
    printf("\n%d",b);
    
}
  
// main function
int main()
{
    char s[] = "567432.1000";
    int n = strlen(s);
    double d;
    sscanf(s, "%lf\n", &d);
    printf("%lf\n", d);
    FindExponent(s, n);
}