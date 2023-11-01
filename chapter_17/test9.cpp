#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    ch = getchar();

    if (islower(ch))
    {
        ch = toupper(ch);
        if (ch == 'Z')
            printf("ZA");
        else
            printf("%c%c", ch, ch + 1);
    }
    else if (isupper(ch))
    {
        printf("%d", ch);
    }

    return 0;
}