#include <stdio.h>
#include "util.h"



int main()
{
    int a = 123;
    int b = 456;

    int add_result = add(a, b);
    int sub_result = sub(a, b);
    printf("%d, %d\n", add_result, sub_result);
    return 0;
}