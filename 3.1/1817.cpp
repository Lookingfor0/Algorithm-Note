#include <cstdio>

int resolve(char chr[13]) {
    int flag = 1;
    int num = 0;
    for(int i = 0; chr[i] != '\0'; i++) {
        if(chr[i] == '-')
            flag = -1;
        else if(chr[i] == ',')
            continue;
        else
            num = num * 10 + chr[i] - '0';
    }
    return flag * num;
}

int main() {
    int n1, n2;
    char a[13], b[13];
    while(scanf("%s%s", &a, &b) != EOF) {
        n1 = resolve(a);
        n2 = resolve(b);
        printf("%d\n", n1 + n2);
    }
    return 0;
}

