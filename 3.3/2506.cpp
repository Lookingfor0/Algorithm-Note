#include <cstdio>
#include <cstring>


int main()
{
    int n;
    while(scanf("%d", &n) != EOF)  // 要考虑 EOF，这里真坑!
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
                printf(" ");
            for(int j = 0; j < n - i; j++)
                printf("* ");
            printf("\n");
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = n - i - 1; j > 0; j--)
                printf(" ");
            for(int j = i + 1; j > 0; j--)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
