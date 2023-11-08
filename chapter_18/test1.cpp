#include <stdio.h>

int main()
{
    int n;
    int a, b, c, m;
    scanf("%d", &n);

    int total[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &m);
        int day[m];
        day[0] = a;
        day[1] = b;
        int j;
        for (j = 2; j < m; j++)
        {
            int pre_two_days = day[j - 1] + day[j - 2];
            if (pre_two_days - c < 1)
                day[j] = 1;
            else
                day[j] = pre_two_days - c;
        }

        total[i] = 0;
        for (j = 0; j < m; j++)
            total[i] += day[j];  
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", total[i]);
    
    return 0;
}