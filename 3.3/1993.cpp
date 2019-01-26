#include <cstdio>
#include <cstring>


int main()
{
    char w[81];
    while(scanf("%s", w) != EOF)  // 要考虑 EOF，这里真坑!
    {
        int s = strlen(w);
        // 这里的 n1 与题目中的定义稍有不同
        int n1 = (s - 1) / 3;
        int n2 = s - n1 * 2;
        int i;
        for(i = 0; i < n1; i++)
        {
            printf("%c", w[i]);
            for(int j = 0; j < n2 - 2; j++)
                printf(" ");
            printf("%c\n", w[s - i - 1]);
        }
        for(; i < n1 + n2; i++)
        {
            printf("%c", w[i]);
        }
        printf("\n");
    }
    return 0;
}

