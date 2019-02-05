#include <cstdio>
#include <algorithm>

using namespace std;


int a[100];

int binarySearch(int left, int right, int x)
{
    if(left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if(a[mid] == x)
        return mid;
    else if(a[mid] > x)
        return binarySearch(left, mid - 1, x);
    else
        return binarySearch(mid + 1, right, x);
}


int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int b;
            scanf("%d", &b);
            int res = binarySearch(0, n - 1, b);
            printf("%s\n", (res == -1)?"NO":"YES");
        }
    }
    return 0;
}

