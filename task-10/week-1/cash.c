
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 0;
    float c;

    do
    {
        c = get_float("Cents Owed: ");

    }
    while (0 > c);
    // int ce = round(o * 100);


    while (25 <= c)
    {
        c = c - 25;
        count++;
    }

    while (10 <= c)
    {
        c = c - 10;
        count++;
    }

    while (5 <= c)
    {
        c = c - 5;
        count++;
    }

    while (1 <= c)
    {
        c = c - 1;
        count++;
    }

    printf("%i\n", count);
}