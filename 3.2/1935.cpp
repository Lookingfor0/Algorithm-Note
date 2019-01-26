#include <cstdio>
#include <cstring>

const int maxn = 1000;

struct student
{
    char id[10];
    char name[100];  // 这个大小有毒
    char gender[50];
    int age;
};

int main()
{
    int N, M;
    student s[maxn];
    while(scanf("%d", &N) != EOF)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%s %s %s %d", s[i].id, s[i].name, s[i].gender, &s[i].age);
        }
        scanf("%d", &M);
        while(M--)
        {
            char id[4];
            int k;
            scanf("%s", id);
            for(k = 0; k < N; k++)
            {
                if(!strcmp(s[k].id, id))
                {
                    printf("%s %s %s %d\n", s[k].id, s[k].name, s[k].gender, s[k].age);
                    break;
                }
            }
            if(k == N)
            {
                printf("No Answer!\n");
            }
        }
    }
    return 0;
}

