#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int h;
    do
    {
        h = get_int("Height: ");

    }
    while (1 > h || h > 8);

    for (int i = 0; i < h; i++)
    {
        for (int b = h - i; b > 1; b--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}