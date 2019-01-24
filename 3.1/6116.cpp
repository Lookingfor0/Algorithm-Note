#include <cstdio>

void regularize(int &a, int &b) {
    // make sure that a is always smaller than b
    if(a > b) {
        int t = a;
        a = b;
        b = t;
        return;
    }
}

int main() {
    int N, M;
    int d[100001] = {0};  // 应付后面的 i - 1
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        int t;
        scanf("%d", &t);
        d[i] += d[i - 1] + t;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        regularize(a, b);
        int res1, res2;
        res1 = d[b - 1] - d[a - 1];
        res2 = d[N] - res1;
        printf("%d\n", (res1 < res2)?res1:res2);
    }
    return 0;
}

