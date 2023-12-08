#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int rowe = 0; rowe < width; rowe += 1)
    {
        for (int clumen = 0; clumen < height; clumen += 1)
        {
            if (image[clumen][rowe].rgbtBlue == 0 && image[clumen][rowe].rgbtRed == 0 && image[clumen][rowe].rgbtGreen == 0)
            {
                image[clumen][rowe].rgbtBlue = 84;
                image[clumen][rowe].rgbtRed = 85;
                image[clumen][rowe].rgbtGreen = 69;
            }
        }
    }
}
