#include <cstdio>
#include <cstdlib>


int hashTable[8] = {false};
int methods[92] = {0};
int P[8];
int count = 0;


void q(int index)
{
    if(index == 8)
    {
        for(int i = 0; i < 7; i++)
        {
            for(int j = i + 1; j < 8; j++)
            {
                if(abs(P[i] - P[j]) == abs(i - j))
                {
                    return;
                }
            }
        }
        for(int i = 0; i < 8; i++)
            methods[count] = methods[count] * 10 + P[i];
        count++;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        if(hashTable[i])
            continue;
        P[index] = i + 1;
        hashTable[i] = true;
        q(index + 1);
        hashTable[i] = false;
    }
    return;
}


int main()
{
    q(0);
    int n;
    while(scanf("%d", &n) != EOF)
    {
        while(n--)
        {
            int b;
            scanf("%d", &b);
            printf("%d\n", methods[b - 1]);
        }
    }
    return 0;
}
