#include <stdio.h>

int main()
{
    // int number[] = {2, 2, 2, 3, 3, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10, 11, 11, 12, 13, 14, 14, 14, 14, 15, 16};
    int number[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10};
    int i, j, count = 0;
    int temp;

    int length = sizeof(number) / sizeof(number[0]);

    for (i = 0; i < length; i++)
    {
        temp = number[i];
        for (j = i + 1; j < length; j++)
        {
            if (number[j] != temp)
            {
                count++;
                number[count] = number[j];
                i = j - 1;
                break;
            }
        }
    }

    for (int i = 0; i <= count; i++)
        printf("%d ", number[i]);

    return 0;
}