#include <cstdio>


int main()
{
    char s1[10001];
    bool h[256] = {0};
    // scanf 遇到空格停止，gets 不允许使用，这里手动读入
    for(int i = 0; i < 10001; i++)
    {
        s1[i] = getchar();
        if(s1[i] == '\n')
        {
            s1[i] = '\0';
            break;
        }
    }
    char s2;
    while(true)
    {
        s2 = getchar();
        if(s2 == EOF || s2 == '\n')
            break;
        h[(int)s2] = true;
    }
    for(int i = 0; s1[i] != '\0'; i++)
    {
        // 含有 S2 中的字符
        if(h[int(s1[i])])
            continue;
        printf("%c", s1[i]);
    }
    printf("\n");
    return 0;
}
