#include <cstdio>


using namespace std;


int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        double cost;
        int a = n / 8;
        int b = n % 8;
        if(a == 0 && b > 0)
        {
            int t = b - 4;
            cost = 10.0 + ((t > 0)?(2 * t):0);  // 这里注意要加括号
        }
        else
        {
            if(b <= 5)
                cost = a * 18 + 2.4 * b;
            else
                cost = a * 18 + 2 * b + 2;
        }
        if(cost - (int)cost)
            printf("%.1f\n", cost);
        else
            printf("%d\n", (int)cost);
    }
    return 0;
}

