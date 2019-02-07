#include <cstdio>


const int maxn = 5000;
int a[maxn];


int Partition(int l, int r)
{
    int t = a[l];
    while(l < r)
    {
        while(l < r && a[r] > t) r--;
        a[l] = a[r];
        while(l < r && a[l] <= t) l++;
        a[r] = a[l];
    }
    a[l] = t;
    return l;
}


void quickSort(int l, int r)
{
    if(l < r)
    {
        int p = Partition(l, r);
        quickSort(l, p - 1);
        quickSort(p + 1, r);
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    quickSort(0, n - 1);
    for(int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

