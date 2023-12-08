#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Please Enter Start size : ");
    }
    while (start < 9);
    // TODO: Prompt for end size
    int End;
    do
    {
        End = get_int("Please Enter End size : ");
    }
    while (End < start);
    // TODO: Calculate number of years until we reach threshold
    int Years = 0;
    while (start < End)
    {
        start = start + (start / 3) - (start / 4);
        Years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", Years);
}
