#include <cstdio>


int main() {
    int N;
    while(scanf("%d", &N) != EOF){
        int A[5] = {0};
        int n3 = 0;
        int flag = 1;
        bool exist[5] = {0};  // judge if An exists
        for(int i = 0; i < N; i++) {
            int t;
            scanf("%d", &t);
            switch(t % 5) {
                case 0:
                    if(t % 2 == 0) {
                        exist[0] = true;
                        A[0] += t;
                    }
                    break;
                case 1:
                    exist[1] = true;
                    A[1] += flag * t;
                    flag = -flag;
                    break;
                case 2:
                    exist[2] = true;
                    A[2]++;
                    break;
                case 3:
                    exist[3] = true;
                    A[3] += t;
                    n3++;
                    break;
                case 4:
                    exist[4] = true;
                    A[4] = (t > A[4])?t:A[4];
                    break;
            }
        }

        for(int i = 0; i < 5; i++) {
            if(!exist[i]) {
                printf("N ");
            } else if(i == 3) {
                printf("%.1f ", (double)A[3] / n3);
            } else if(i == 4) {
                printf("%d\n", A[4]);
            } else {
                printf("%d ", A[i]);
            }
        }
    }
    return 0;
}

