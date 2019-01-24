#include <cstdio>

int main() {
    int n;
    int odd, even;
    int t;
    while(scanf("%d", &n) != EOF) {
        odd = 0;
        even = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &t);
            if(t % 2 == 0)
                even++;
            else
                odd++;
        }
        printf("%s\n", (odd > even)?"YES":"NO");
    }
    return 0;
}

