#include <stdio.h>

int main()
{

    int k, m, a[200], b[200], n, con = 0;

    scanf("%d %d %d", &k, &m, &n);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        if ((a[i] == 0 && b[i] != 0) || (k / a[i] * b[i] >= n))
        {
            printf("%d", i);
            con++;
        }
        else if (b[i] == 0)
        {
            continue;
        }
        else
        {
            continue;
        }
    }
    if (con == 0)
    {

        printf("-1");
    }

    return 0;
}