#include <cstdio>
#include <algorithm>


using namespace std;


struct show{
    int s;
    int e;
};

// 永远按照结束时间由小到大排序，若相等，则选择开始时间较大的。
bool cmp(show a, show b)
{
    if(a.e != b.e)
        return a.e < b.e;
    else
        return a.s >= b.s;
}

int main()
{
    int n;
    show shows[100];
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &shows[i].s, &shows[i].e);
        }
        sort(shows, shows + n, cmp);
        int count = 1, pres = 0;
        for(int i = 1; i < n; i++)
        {
            if(shows[i].s >= shows[pres].e)
                {
                    count++;
                    pres = i;
                }
        }
        printf("%d\n", count);
    }
    return 0;
}

