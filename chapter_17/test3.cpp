#include <stdio.h>
int main()
{
    double score[10], sum = 0, aver;
    int k = 0, i = 0;
    printf("请输入学生成绩:\n");
    for (i = 0; i < 10; i++)
    {
        scanf_s("%lf", &score[i]);
        sum += score[i];
    }
    aver = sum / 10;
    printf("%lf\n", aver);

    for (i = 0; i < 10; ++i)
        if(score[i] > aver) 
            k++;
    printf("%d\n", k);

    return 0;
}