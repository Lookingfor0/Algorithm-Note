#include <cstdio>


// 辗转相除法求最大公约数
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		printf("%d\n", gcd(m, n));
	}
	return 0;
}
