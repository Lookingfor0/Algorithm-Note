#include <cstdio>


int getv(int a, int da) {
    int t = a % 10;
    int v = 0;
    while(a) {
        if(t == da) {
            v = v * 10 + da;
        }
        a = a / 10;
        t = a % 10;
    }
    return v;
}

int main() {
    int a, da, b, db;
    while(scanf("%d%d%d%d", &a, &da, &b, &db) != EOF) {
        printf("%d\n", getv(a, da) + getv(b, db));
    }
    return 0;
}
