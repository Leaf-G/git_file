//
// Created by gcc on 6/20/23.
//

#include<stdio.h>
int fun(int a)
{
    int b = 0;
    static int c = 3;
    b = b + 1;
    c = c + 1;
    return (a + b + c);
}
int main()
{
    int a = 2, i;
    for (i = 0; i < 3; i++)
        printf("%d\n", fun(a));
    return 0;
}
