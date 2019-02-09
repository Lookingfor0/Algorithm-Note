#include <cstdio>

// 最小公倍数只需 a*b / d（最大公约数），通过集合很好理解
// 为了防止溢出，我们使用 a / d * b

// 辗转相除法求最大公约数
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main()
{
	int N, m;
	scanf("%d", &N);
	while (N--)
	{
		int a, b;
		scanf("%d%d", &m, &a);
		for (int i = 1; i < m; i++)
		{
			scanf("%d", &b);
			a = b / gcd(a, b) * a;
		}
		printf("%d\n", a);
	}
	return 0;
}
