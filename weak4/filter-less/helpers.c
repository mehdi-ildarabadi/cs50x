#include "helpers.h"
#include<math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int redmai, greenmai, bluemai;
    float graout;

    for (int a = 0; a < height; a +=1)
    {
        for (int b = 0; b < width; b +=1)
        {
            redmai = image[a][b].rgbtRed;
            greenmai = image[a][b].rgbtGreen;
            bluemai = image[a][b].rgbtBlue;

            graout = round ((redmai + greenmai + bluemai) / 3.0);

            image[a][b].rgbtRed = graout;
            image[a][b].rgbtGreen = graout;
            image[a][b].rgbtBlue = graout;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int redmai, greenmai, bluemai;
    int redmain, greenmain, bluemain;
    for (int a = 0; a < height; a +=1)
    {
        for (int b = 0; b < width; b +=1)
        {
            redmai = image[a][b].rgbtRed;
            greenmai = image[a][b].rgbtGreen;
            bluemai = image[a][b].rgbtBlue;

            redmain = .393 * redmai + .769 * greenmai + .189 * bluemai;
            if (redmain > 255)
            {
                redmain = 255;
            }
            greenmain = .349 * redmai + .686 * greenmai + .168 * bluemai;
            if (greenmain > 255)
            {
                greenmain = 255;
            }
            bluemain = .272 * redmai + .534 * greenmai + .131 * bluemai;
            if (bluemain > 255)
            {
                bluemain = 255;
            }
            image[a][b].rgbtRed = redmain;
            image[a][b].rgbtGreen = greenmain;
            image[a][b].rgbtBlue = bluemain;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rowplace[width];
    for (int y = 0; y < height; y +=1)
    {
        for (int a = 0; a < width; a +=1)
        {
            rowplace[a] = image[a][y];
        }
        for (int a = 0; a < width; a +=1)
        {
            image[a][y].rgbtRed = rowplace[width - a - 1].rgbtRed;
            image[a][y].rgbtGreen = rowplace[width - a - 1].rgbtGreen;
            image[a][y].rgbtBlue = rowplace[width - a - 1].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyy[width][width];

    for (int y = 0; y < height; y +=1)
    {
        for (int a = 0; a < width; a +=1)
        {
            copyy[a][y] = image[a][y];
        }
    }
     for (int d = 0; d < height; d +=1)
    {
        for (int i = 0; i < width; i +=1)
        {
            int coun = 0;
            float redsum = 0;
            float blusum = 0;
            float gresum = 0;

            for (int c = -1; c < 2; c +=1)
            {
                for (int m = -1; m < 2; m +=1)
                {
                    if (!(d=c < 0 || d+c >= height || i+m < 0 || i+m >= width))
                    {
                       redsum += copyy[d + c][i + m].rgbtRed;
                       blusum += copyy[d + c][i + m].rgbtBlue;
                       gresum += copyy[d + c][i + m].rgbtGreen;
                       coun +=1;

                    }
                    else
                    {
                        continue;
                    }
                }
            }
            image[d][i].rgbtRed = (int)round(redsum / coun);
            image[d][i].rgbtGreen = (int)round(gresum / coun);
            image[d][i].rgbtBlue = (int)round(blusum / coun);
        }
    }

}
