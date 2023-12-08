#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string massegas = get_string("Message: ");
    //  int a = strlen(massegas);
    for (int i = 0, a = strlen(massegas); i < a; i += 1)
    {
        int binar[] = {0, 0, 0, 0, 0, 0, 0, 0};

        int deci = massegas[i];

        int c = 0;
        while (deci > 0)
        {
            binar[c] = deci % 2;
            deci = deci / 2;
            c += 1;
        }
        for (int l = BITS_IN_BYTE - 1; l >= 0; l -= 1)
        {
            print_bulb(binar[l]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
