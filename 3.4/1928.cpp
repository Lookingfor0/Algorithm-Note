#include <cstdio>
// 较为直接的方法是把较小的日期一天一天的增加，直到两个日期相等。

const int unLeapYearDays = 365;
const int leapYearDays = 366;
// 各个月份的天数
const int month_days[12][2] =
{
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
};

bool isLeap(int year)
{
    return (!(year % 4) && (year % 100)) || !(year % 400);
}


int main()
{
    int t1, t2;
    int y1, m1, d1, y2, m2, d2;
    int delta;
    // 将较小的日期一次加一天，直到与另一个日期相等，这样就可以求出差值。
    while(scanf("%d%d", &t1, &t2) != EOF)
    {
        // 小的如日期放到 t1
        if(t1 > t2)
        {
            int temp = t1;
            t1 = t2;
            t2 = temp;
        }
        y1 = t1 / 10000, m1 = t1 / 100 % 100, d1 = t1 % 100;
        y2 = t2 / 10000, m2 = t2 / 100 % 100, d2 = t2 % 100;
        delta = 0;
        bool leap_2 = isLeap(y2);
        // 若不在同一年份
        if(y1 < y2)
        {
            // 把 t1 年份加到与 t2 相差 1
            while(y1 < y2 - 1)
            {
                delta += isLeap(y1)?leapYearDays:unLeapYearDays;
                y1++;
            }
            // t1 年份剩余的天数
            bool leap_1 = isLeap(y1);
            for(m1 = m1 - 1; m1 < 12; m1++)
            {
                delta += month_days[m1][leap_1];
            }
            delta -= d1;
            // t2 年份已经过去的天数
            for(m2 = m2 - 2; m2 >= 0; m2--)
            {
                delta += month_days[m2][leap_2];
            }
            delta += d2;
        }
        else
        {
            // 年份相同
            if(m1 < m2) {
                // 把月份加到相差1
                for(m1 = m1 - 1; m1 < m2 - 2; m1++){
                    delta += month_days[m1][leap_2];
                    m1++;
                }
                // m1 月剩余的天数和 m2 月经过的天数
                delta = delta + month_days[m1][leap_2] -d1 + d2;
            }
            else
            {
                delta = d2 - d1;
            }
        }
        delta += 1;
        printf("%d\n", delta);
    }
    return 0;
}

