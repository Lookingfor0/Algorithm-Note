#include <cstdio>

const int maxn = 210;


int main()
{
    int N;
    int x[maxn];
    int X;
    int k;
    while(scanf("%d", &N) != EOF)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &x[i]);
        }
        scanf("%d", &X);
        for(k = 0; k < N; k++)
        {
            if(X == x[k])
            {
                printf("%d\n", k);
                break;;
            }
        }
        if(k == N)
            printf("%d\n", -1);
    }
    return 0;
}
