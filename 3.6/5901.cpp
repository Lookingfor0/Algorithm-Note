#include <cstdio>
#include <cstring>


int main()
{
    char str[256];
    while(scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        bool flag = true;
        for(int i = 0; i < len / 2; i++)
        {
            if(str[i] != str[len - i - 1])
            {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag?"YES":"NO");
    }
    return 0;
}

