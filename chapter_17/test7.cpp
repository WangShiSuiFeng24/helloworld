#include<stdio.h>

int main()
{
    int i;
    printf("Enter a positve integer: ");
    scanf("%d", &i);

    int array[i+1];
    array[0] = 0;
    array[1] = 1;
    for (int count = 2; count <= i; count++)
        array[count] = array[count - 1] + count;

    printf("The %d item is %d\n", i, array[i]);
}