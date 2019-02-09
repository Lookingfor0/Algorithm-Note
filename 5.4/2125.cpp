#include <cstdio>


const int maxn = 10000000;  // 2^15 ÊÇ¶à´óÄØ£¿
int prime[maxn / 2], num = 0;
bool p[maxn] = { 0 };

void Find_Prime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (!p[i])
		{
			prime[num++] = i;
			for (int j = i + i; j < maxn; j += i)
				p[j] = true;
		}
	}
}

int main()
{
	Find_Prime();
	int n;
	while (scanf("%d", &n), n)
	{
		int i = 0, j = num - 1, count = 0;
		while (i <= j)
		{
			if (prime[i] + prime[j] < n) i++;
			else if (prime[i] + prime[j] > n) j--;
			else
			{
				count++;
				i++;
				j--;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
