#include <cs50.h>
#include <stdio.h>

void row(int i);

int main(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num > 8 || num < 1);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }

        row(i);
        printf("  ");
        row(i);
        printf("\n");
    }
}

void row(int i)
{
    for (int z = 0; z <= i; z++)
    {
        printf("#");
    }
}
