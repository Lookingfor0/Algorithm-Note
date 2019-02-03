#include <cstdio>
#include <algorithm>


using namespace std;


struct gasStation
{
    double p;
    double d;
};


bool cmp_price(gasStation a, gasStation b)
{
    if(a.d != b.d)
        return a.d < b.d;
    else
        return a.p < a.p;
}


int main()
{
    double C, D, Davg;
    int N;
    while(scanf("%lf%lf%lf%d", &C, &D, &Davg, &N) != EOF)
    {
        gasStation s[501];
        double disPerTime = C * Davg;  // 加满油能一次性走多远
        for(int i = 0; i < N; i++)
        {
            scanf("%lf%lf", &s[i].p, &s[i].d);
        }
        // 将终点看成一个价格为 0 的加油站
        s[N].p = 0, s[N].d = D, N++;
        // 将加油站按距离从小到大排序
        sort(s, s + N, cmp_price);
        // 判断能否到达终点
        bool can = true;
        double maxDis = 0;
        double total = 0;
        if(s[0].d > 0)
            can = false;
        else
        {
            int curSta = 0;
            double curTank = 0;
            while(s[curSta].d < D)
            {
                int nextSta;
                maxDis = s[curSta].d + disPerTime;
                double minPrice = 1e6;
                bool flag = false;  // 是否找得到加油站
                for(int i = curSta + 1; i < N && s[i].d <= maxDis; i++)
                {
                    // 在可达范围内找油价小的
                    flag = true;
                    if(s[i].p < minPrice)
                    {
                        nextSta = i;
                        minPrice = s[i].p;
                    }
                    if(s[i].p < s[curSta].p)
                    {
                        nextSta = i;
                        break;
                    }
                }
                if(!flag)
                {
                    can = false;
                    break;
                }
                double gas = (s[nextSta].d - s[curSta].d) / Davg;  // 到下一个加油站消耗的油
                if(minPrice < s[curSta].p)
                {
                    // 有比当前更便宜的加油站
                    total += (gas - curTank) * s[curSta].p;
                    curTank = 0.0;
                }
                else
                {
                    // 找不到更便宜的，把油加满，去下一个较便宜的加油站
                    total += (C - curTank) * s[curSta].p;
                    curTank = C - gas;
                }
                curSta = nextSta;
            }
        }
        if(can)
            printf("%.2f\n", total);
        else
            printf("The maximum travel distance = %.2f\n", maxDis);
    }
    return 0;
}

