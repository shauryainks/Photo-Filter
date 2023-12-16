#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int hh = 0; hh < height; hh++)
    {
        for (int ww = 0; ww < width; ww++)
        {
            float temp = image[hh][ww].rgbtRed + image[hh][ww].rgbtGreen + image[hh][ww].rgbtBlue;
            temp = temp / 3;
            temp = round(temp);
            image[hh][ww].rgbtRed = temp;
            image[hh][ww].rgbtBlue = temp;
            image[hh][ww].rgbtGreen = temp;
        }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int hh = 0; hh < height; hh++)
    {
        for (int ww = 0; ww < width; ww++)
        {
            float sepiared = .393 * image[hh][ww].rgbtRed + .769 * image[hh][ww].rgbtGreen + .189 * image[hh][ww].rgbtBlue;
            float sepiagreen = .349 * image[hh][ww].rgbtRed + .686 * image[hh][ww].rgbtGreen + .168 * image[hh][ww].rgbtBlue;
            float sepiablue = .272 * image[hh][ww].rgbtRed + .534 * image[hh][ww].rgbtGreen + .131 * image[hh][ww].rgbtBlue;

            if (sepiared > 255)
            {
                sepiared = 255;
            }
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }

            sepiablue = round(sepiablue);
            sepiagreen = round(sepiagreen);
            sepiared = round(sepiared);

            image[hh][ww].rgbtRed = sepiared;
            image[hh][ww].rgbtGreen = sepiagreen;
            image[hh][ww].rgbtBlue = sepiablue;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int hh = 0; hh < height; hh++)
    {
        int startwidth = 0;

        for (int endwidth = width - 1; endwidth > startwidth; endwidth--)
        {
            RGBTRIPLE temp;
            temp = image[hh][startwidth];
            image[hh][startwidth] = image[hh][endwidth];
            image[hh][endwidth] = temp;
            startwidth++;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float tempr = image[h][w].rgbtRed;
            float tempg = image[h][w].rgbtGreen;
            float tempb = image[h][w].rgbtBlue;
            float counter = 1;

            if (h - 1 >= 0 && w - 1 >= 0)
            {
                tempr += image[h - 1][w - 1].rgbtRed;
                tempg += image[h - 1][w - 1].rgbtGreen;
                tempb += image[h - 1][w - 1].rgbtBlue;
                counter++;
            }

            if (h - 1 >= 0)
            {
                tempr += image[h - 1][w].rgbtRed;
                tempg += image[h - 1][w].rgbtGreen;
                tempb += image[h - 1][w].rgbtBlue;
                counter++;
            }

            if (h - 1 >= 0 && w + 1 < width)
            {
                tempr += image[h - 1][w + 1].rgbtRed;
                tempg += image[h - 1][w + 1].rgbtGreen;
                tempb += image[h - 1][w + 1].rgbtBlue;
                counter++;
            }

            if (w - 1 >= 0)
            {
                tempr += image[h][w - 1].rgbtRed;
                tempg += image[h][w - 1].rgbtGreen;
                tempb += image[h][w - 1].rgbtBlue;
                counter++;
            }

            if (w + 1 < width)
            {
                tempr += image[h][w + 1].rgbtRed;
                tempg += image[h][w + 1].rgbtGreen;
                tempb += image[h][w + 1].rgbtBlue;
                counter++;
            }

            if (h + 1 < height && w - 1 >= 0)
            {
                tempr += image[h + 1][w - 1].rgbtRed;
                tempg += image[h + 1][w - 1].rgbtGreen;
                tempb += image[h + 1][w - 1].rgbtBlue;
                counter++;
            }

            if (h + 1 < height)
            {
                tempr += image[h + 1][w].rgbtRed;
                tempg += image[h + 1][w].rgbtGreen;
                tempb += image[h + 1][w].rgbtBlue;
                counter++;
            }

            if (h + 1 < height && w + 1 < width)
            {
                tempr += image[h + 1][w + 1].rgbtRed;
                tempg += image[h + 1][w + 1].rgbtGreen;
                tempb += image[h + 1][w + 1].rgbtBlue;
                counter++;
            }

            tempr = tempr / counter;
            tempg = tempg / counter;
            tempb = tempb / counter;

            tempr = round(tempr);
            tempg = round(tempg);
            tempb = round(tempb);

            tempimage[h][w].rgbtRed = tempr;
            tempimage[h][w].rgbtGreen = tempg;
            tempimage[h][w].rgbtBlue = tempb;
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            swap(&image[h][w], &tempimage[h][w]);
        }
    }

    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b
