#include <stdio.h>
int main()
{
    int n;
    printf("Please enter a positive integer: ");
    while (!(scanf("%d", &n) && n > 0))
    {
        while (getchar() != '\n')
            continue;
        printf("Please enter a positive integer: ");
    }

    while (getchar() != '\n')
            continue;

    char array[n];
    printf("Enter %d characters: ", n);
    for (int i = 0; i < n; ++i)
        scanf("%c", &array[i]);

    printf("Your input characters is %s\n", array);
    return 0;
}