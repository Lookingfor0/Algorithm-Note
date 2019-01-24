#include <cstdio>


struct P {
    int wt;
    int dt;
    int cc;  // 不同手势的获胜次数
    int jj;
    int bb;

    P() {
        wt = 0;
        dt = 0;
        cc = 0;
        jj = 0;
        bb = 0;
    }

    void static battle(P &a, P &b, char g1, char g2) {
        if(g1 == g2) {
            a.dt++;
            b.dt++;
        } else {
            switch(g1) {
            case 'C':
                if(g2 == 'J') {
                    a.wt++;
                    a.cc++;
                } else {
                    b.wt++;
                    b.bb++;
                }
                break;
            case 'J':
                if(g2 == 'B') {
                    a.wt++;
                    a.jj++;
                } else {
                    b.wt++;
                    b.cc++;
                }
                break;
            case 'B':
                if(g2 == 'C') {
                    a.wt++;
                    a.bb++;
                } else {
                    b.wt++;
                    b.jj++;
                }
                break;
            }
        }
    }

    char maxTimesG() {
        int maxT = (cc > jj)?cc:jj;
        maxT = (maxT > bb)?maxT:bb;
        // 注意这里是按字母顺序
        if(bb == maxT)
            return 'B';
        else if(cc == maxT)
            return 'C';
        else
            return 'J';
    }
};

int main() {
    int N;
    P p1, p2;
    char g1, g2;
    scanf("%d", &N);
    while(N--) {
        getchar();  // 吃掉换行符
        scanf("%c %c", &g1, &g2);
        p1.battle(p1, p2, g1, g2);
    }
    printf("%d %d %d\n", p1.wt, p1.dt, p2.wt);
    printf("%d %d %d\n", p2.wt, p2.dt, p1.wt);
    printf("%c %c\n", p1.maxTimesG(), p2.maxTimesG());
    return 0;
}

