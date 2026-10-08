#include <stdio.h>
int main()
{
    int i = 2;
    if (i % 15 == 0)
    {
        printf("love iu");
    }
    else if (i % 3 == 0)
    {
        printf("love");
    }
    else if (i % 5 == 0)
    {
        printf("iu");
    }
    else
    {
        printf("%d\n", i);
    }
    return 0;
}
