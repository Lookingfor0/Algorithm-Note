#include <cstdio>

const int maxn = 1000;


int main()
{
    int N;
    int s[maxn];
    while(scanf("%d", &N), N)
    {
        int c = 0;
        for(int i = 0; i < N; i++)
            scanf("%d", &s[i]);
        int target;
        scanf("%d", &target);
        for(int i = 0; i< N; i++)
        {
            if(target == s[i])
                c++;
        }
        printf("%d\n", c);
    }
    return 0;
}

