#include <stdio.h>
int fractional(int n)
{
    if (n == 1)
        return 1;
    return n * fractional(n - 1);
}
int main()
{
    int n = 5;
    int m = fractional(n);
    printf("fractional(%d)=%d\n", n, m);
    return 0;
}
