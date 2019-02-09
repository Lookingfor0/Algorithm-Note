#include <cstdio>

// ��С������ֻ�� a*b / d�����Լ������ͨ�����Ϻܺ����
// Ϊ�˷�ֹ���������ʹ�� a / d * b

// շת����������Լ��
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
