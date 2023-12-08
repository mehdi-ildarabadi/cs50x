#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get number
    int x;
    do
    {
        x = get_int("Please Enter Height : ");
    }
    while (x < 1 || x > 8);

    for (int b = 0; b < x; b += 1)
    {
        for (int s = x - b - 1; s > 0; s--)
        {
            printf(" ");
        }

        for (int z = 0; z <= b; z += 1)
        {
            // print#
            printf("#");
        }

        printf("  ");

        for (int l = 0; l <= b; l += 1)
        {
            // print#
            printf("#");
        }
        printf("\n");
    }
}
