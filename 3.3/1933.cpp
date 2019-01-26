#include <cstdio>


int main()
{
    int h;
    while(scanf("%d", &h) != EOF)  // 要考虑 EOF，这里真坑!
    {
        int b = 3 * h - 2;
        for(int i = 0; i < h; i++)
        {
            int t = b - 2 * i - h;
            for(int j = 0; j < b; j++)
            {
                if(j < t)
                    printf(" ");
                else
                    printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}

