#include <cstdio>


int n;  // 物品总数
int methods = 0;
int volumns[20];
bool hashTable[20] = {false};  // 是否已经装进袋子


void contain(int v, int start)
{
    if(v > 40)
        return;
    if(v == 40)
        methods++;
    for(int i = start; i < n; i++)
    {
        if(hashTable[i])
            continue;
        hashTable[i] = true;
        contain(v + volumns[i], i + 1);
        hashTable[i] = false;
    }
}


int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", volumns + i);
        }
        methods = 0;  // 归零
        contain(0, 0);
        printf("%d\n", methods);
    }
    return 0;
}

