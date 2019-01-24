#include <cstdio>

int main() {
    int sum;
    char a[12], b[12];
    while(scanf("%s%s", &a, &b) != EOF) {
        sum = 0;
        for(int i = 0; a[i] != '\0'; i++) {
            for(int j = 0; b[j] != '\0'; j++) {
                sum += (a[i] - '0') * (b[j] - '0');
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}

