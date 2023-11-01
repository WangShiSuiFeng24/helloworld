#include <stdio.h>
int main()
{
    char op;
    int a, b, c;
    scanf("%d%c%d=%d", &a, &op, &b, &c);

    switch (op)
    {
        case '+':
            if(a+b==c)printf("Right!");else printf("Wrong!");
            break;
        case '-':
            if(a-b==c)printf("Right!");else printf("Wrong!");
            break;
        case '*':
            if(a*b==c)printf("Right!");else printf("Wrong!");
            break;
        case '/':
            if(a/b==c)printf("Right!");else printf("Wrong!");
            break;
    }
    return 0;
}