#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;
int num[MAXN];

int partition(int l, int r)
{
	int p = rand() % (l - r + 1) + l;
	swap(num[l], num[p]);
	int temp = num[l];
	while (l < r)
	{
		while (l < r && num[r] > temp) r--;
		num[l] = num[r];
		while (l < r && num[l] <= temp) l++;
		num[r] = num[l];
	}
	num[l] = temp;
	return l;
}

int randomSelect(int l, int r, int k)
{
	if (l == r) return num[l];
	int p = partition(l, r);
	int m = r - p + 1;
	if (m == k) return num[p];
	else if (m < k)
		return randomSelect(l, p - 1, k - m);
	else
		return randomSelect(p + 1, r, k);
}

int main()
{
	srand((unsigned)time(NULL));  // 随机数种子
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", num + i);
	printf("%d\n", randomSelect(0, n - 1, k));
	return 0;
}

