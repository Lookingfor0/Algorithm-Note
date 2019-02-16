#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 26 * 26 * 26 * 10;  // 用hash识别学生名字
vector<int> stu[maxn];

int getid(char name[5])
{
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		num = num * 26 + name[i] - 'A';
	}
	num = num * 10 + name[3] - '0';
	return num;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int c, n;
		char name[5];
		scanf("%d %d", &c, &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%s", name);
			int id = getid(name);
			stu[id].push_back(c);
		}
	}
	for (int i = 0; i < N; i++)
	{
		char name[5];
		scanf("%s", name);
		int id = getid(name);
		sort(stu[id].begin(), stu[id].end());
		printf("%s %d", name, stu[id].size());
		for (int j = 0; j < stu[id].size(); j++)
		{
			printf(" %d", stu[id][j]);
		}
		printf("\n");
	}
	return 0;
}
