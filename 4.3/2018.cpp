#include <cstdio>


int fib[18] = {0};

void F()
{
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= 17; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return;
}


int main()
{
    int m;
    while(scanf("%d", &m) != EOF)
    {
        while(m--)
        {
            int n;
            scanf("%d", &n);
            F();
            for(int i = 0; i < n; i++)
            {
                for(int j = n - i - 1; j > 0; j--)
                {
                    printf("  ");
                }
                printf("0");
                for(int j = 0; j < 2 * i; j ++)
                {
                    printf(" %d", fib[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

