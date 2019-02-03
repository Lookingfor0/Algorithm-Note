#include <cstdio>
#include <algorithm>

using namespace std;


bool cmp(int a, int b)
{
    return a >= b;
}


int main()
{
    int L, N;
    int ai[600];
    while(scanf("%d%d", &L, &N) != EOF)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", ai + i);
        }
        sort(ai, ai + N, cmp);
        int len = 0, i;
        for(i = 0; i < N && len < L; i++)
            len += ai[i];
        if(i == N && len < L)
            printf("impossible\n");
        else
            printf("%d\n", i);
    }
    return 0;
}
