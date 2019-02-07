#include <cstdio>


const int maxn = 100010;
int a[maxn];

void myMerge(int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    int temp[maxn], index = 0;
    while(i <= r1 && j <= r2)
    {
        if(a[i] < a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    while(i <= r1) temp[index++] = a[i++];
    while(j <= r2) temp[index++] = a[j++];
    for(i = 0; i < index; i++)
        a[l1 + i] = temp[i];
}


void mergeSort(int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        myMerge(l, mid, mid + 1, r);
    }
}


int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
            scanf("%d", a + i);
        mergeSort(0, m - 1);
        for(int i = 0; i < m; i++)
            printf("%d\n", a[i]);
    }
    return 0;
}
