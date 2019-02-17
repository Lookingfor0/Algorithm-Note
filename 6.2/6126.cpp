#include <cstdio>
#include <set>

using namespace std;


int main()
{
	set<int> st[51];
	int N, M, K;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &M);
		for (int j = 0; j < M; j++)
		{
			int temp;
			scanf("%d", &temp);
			st[i].insert(temp);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		set<int> sum;
		int sa = st[a].size(), sb = st[b].size();
		for (set<int>::iterator j = st[a].begin(); j != st[a].end(); j++)
			sum.insert(*j);
		for (set<int>::iterator j = st[b].begin(); j != st[b].end(); j++)
			sum.insert(*j);
		int ss = double(sum.size());
		printf("%.1f%%\n", (sa + sb - ss) * 100.0 / ss);  // 注意：百分号要用 %% 
	}
	return 0;
}
