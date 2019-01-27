#include <cstdio>


int main()
{
    int a, b, m;
    unsigned int sum;
    while(scanf("%d", &m) != EOF && m)
    {
        scanf("%d%d", &a, &b);
        sum = a + b;
        int res[32] = {0};
        int i = 0;
        do
        {
            res[i++] = sum % m;
            sum = sum / m;
        }
        while(sum);
        while(i--)
        {
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}

