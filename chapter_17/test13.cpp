#include <stdio.h>

int main()
{
    int start_time;
    int minutes;
    scanf("%d %d", &start_time, &minutes);

    int total_minutes = (start_time / 100 * 60 + start_time % 100 + minutes);

    int min = total_minutes % 60;
    int hour = (total_minutes / 60) % 24;

    printf("%d%d", hour, min);

    return 0;
}