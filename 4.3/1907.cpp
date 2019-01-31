#include <cstdio>


int eat(int N)
{
    if(N == 1)
        return 1;
    else if(N == 2)
        return 2;
    return eat(N - 1) + eat(N - 2);
}


int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        printf("%d\n", eat(N));
    }
    return 0;
}

