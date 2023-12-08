#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string text = get_string("Text: ");
    float a = 0;
    float f = 1;
    float h = 0;
    int b = strlen(text);
    for (int i = 0; i < b; i += 1)
    {
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 92))
        {
            a += 1;
        }
        if (text[i] == ' ')
        {
            f += 1;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            h += 1;
        }
    }

    {
        float L = 100 * (a / f);
        float S = 100 * (h / f);

        int index = round(0.0588 * L - 0.296 * S - 15.8);
        printf("%i\n", index);
        if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        else if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }
    }
}
