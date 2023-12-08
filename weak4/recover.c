#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *imgf = NULL;

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *drive = fopen(argv[1], "r");

    unsigned char *temp = malloc(512);

    char *filename = malloc(3 * sizeof(char));
    if (filename == 0)
    {
        return 1;
    }

    int image = 0;

    if (temp == NULL)
    {
        return 1;
    }

    while (fread(temp, sizeof(unsigned char), 512, drive))
    {
        if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && ((temp[3] & 0xf0) == 0xe0))
        {
            if (imgf != NULL)
            {
                fclose(imgf);
            }
            sprintf(filename, "%03i.jpg", image);
            imgf = fopen(filename, "w");
            fwrite(temp, 1, 512, imgf);
            image += 1;
        }
        else if (image != 0)
        {
            fwrite(temp, 1, 512, imgf);
        }
    }
    if (imgf != NULL)
    {
        fclose(imgf);
    }
    free(temp);
}
