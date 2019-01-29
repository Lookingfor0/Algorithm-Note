#include <cstdio>


int main()
{
    int N, M;

    while(scanf("%d%d", &N, &M) != EOF)
    {
        int books[200] = {0};
        int reader[200] = {0};
        for(int i = 0; i < N; i++)
        {
            int book;
            scanf("%d", &book);
            reader[i] = book;
            books[book - 1]++;
        }
        for(int i = 0; i < N; i++)
        {
            int t = books[reader[i] - 1];
            if(t > 1)
                printf("%d\n", t - 1);
            else
                printf("BeiJu\n");
        }
    }
    return 0;
}

