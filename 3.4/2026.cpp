#include <cstdio>

const int month_days[12] =
{
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
};

struct Date
{
    int year;
    int month;
    int day;

    Date(int _y, int _m, int _d)
    {
        year = _y;
        month = _m;
        day = _d;
    }

    void next_day()
    {
        day++;
        if(day > month_days[month - 1])
        {
            day = day - month_days[month++ - 1];
        }
        if(month > 12)
        {
            year++;
            month -= 12;
        }
        printf("%4d-%02d-%02d\n", year, month, day);
    }
};


int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int y, m, d;
        scanf("%d%d%d", &y, &m, &d);
        Date today = Date(y, m, d);
        today.next_day();
    }
    return 0;
}
