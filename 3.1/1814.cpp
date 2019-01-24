#include <cstdio>
#include <cstring>


int main() {
    int L, M;
    int l, r, c;
    bool t[10001];
    while(scanf("%d%d", &L, &M) != EOF, L || M) {
        memset(t, 0, sizeof(t));
        c = 0;  // c 是被拿走的树的数目
        while(M--) {
            scanf("%d%d", &l, &r);
            for(int i = l; i <= r; i++)
                t[i] = true;
        }
        for(int i = 0; i <= L; i++)
            c += t[i];
        printf("%d\n", L + 1 - c);
    }

    return 0;
}

