#include <cstdio>


int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", i, (a + b > c)?"true":"false");
    }
    return 0;
}

