#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLUR 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int idx = 0; idx < height; idx++)
    {
        for (int idy = 0; idy <= width; idy++)
        {
            RGBTRIPLE *triple = &image[idx][idy];
            //calculate the average
            int avg = round((float)(triple->rgbtBlue + triple->rgbtGreen + triple->rgbtRed) / 3);
            triple->rgbtBlue = avg;
            triple->rgbtGreen = avg;
            triple->rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int idx = 0; idx < height; idx++)
    {

        RGBTRIPLE temp = {0};
        int start = 0;
        int end = width - 1;
        //only iterate to approx. width/2 to reduce the runtime
        //reverse the sub array
        while (start < end)
        {
            temp = image[idx][start];
            image[idx][start] = image[idx][end];
            image[idx][end] = temp;
            start++;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    double average_blue, average_green, average_red;
    int stat;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_blue = average_green = average_red = stat = 0;
            // Box Blur
            for (int rows = i - ((BLUR - 1) / 2); rows <= i + ((BLUR - 1) / 2); rows++)
            {
                for (int cols = j - ((BLUR - 1) / 2); cols <= j + ((BLUR - 1) / 2); cols++)
                {
                    if ((rows >= 0 && rows < height) && (cols >= 0 && cols < width))
                    {
                        //adding all up to avg buffers
                        average_blue += image[rows][cols].rgbtBlue;
                        average_green += image[rows][cols].rgbtGreen;
                        average_red += image[rows][cols].rgbtRed;
                        stat++;
                    }
                }
            }
            //if we got something calculate the avg overall
            if (stat != 0)
            {
                average_blue =  round(average_blue / (double) stat);
                average_green = round(average_green / (double) stat);
                average_red = round(average_red / (double) stat);
                new_image[i][j].rgbtBlue = average_blue;
                new_image[i][j].rgbtGreen = average_green;
                new_image[i][j].rgbtRed = average_red;
            }
            else
            {
                return;
            }
        }
    }
    //set copy to image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}

//check and/or set cap of 255
int cap255(double n)
{
    int result = 0;

    if (n >= 255)
    {
        result = 255;
    }
    else if (n < 0)
    {
        result = 0;
    }
    else
    {
        result = (int) round(n);
    }
    return (result);
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rGx, gGx, bGx, rGy, gGy, bGy;
            rGx = gGx = bGx = rGy = gGy = bGy = 0;
            //checking for all possible fields, also calculating with gx or gy
            // Up
            if (i > 0)
            {
                rGy += -2 * image[i - 1][j].rgbtRed;
                gGy += -2 * image[i - 1][j].rgbtGreen;
                bGy += -2 * image[i - 1][j].rgbtBlue;
            }
            // Down
            if (i < height - 1)
            {

                rGy += 2 * image[i + 1][j].rgbtRed;
                gGy += 2 * image[i + 1][j].rgbtGreen;
                bGy += 2 * image[i + 1][j].rgbtBlue;
            }
            // Left
            if (j > 0)
            {
                rGx += -2 * image[i][j - 1].rgbtRed;
                gGx += -2 * image[i][j - 1].rgbtGreen;
                bGx += -2 * image[i][j - 1].rgbtBlue;

            }
            // Right
            if (j < height - 1)
            {
                rGx += 2 * image[i][j + 1].rgbtRed;
                gGx += 2 * image[i][j + 1].rgbtGreen;
                bGx += 2 * image[i][j + 1].rgbtBlue;

            }
            // Up left
            if (i >= 1 && j >= 1)
            {
                // Primeros tres valores, cambiando de signo muevo de lado el resultado
                rGx += -1 * image[i - 1][j - 1].rgbtRed;
                gGx += -1 * image[i - 1][j - 1].rgbtGreen;
                bGx += -1 * image[i - 1][j - 1].rgbtBlue;
                rGy += -1 * image[i - 1][j - 1].rgbtRed;
                gGy += -1 * image[i - 1][j - 1].rgbtGreen;
                bGy += -1 * image[i - 1][j - 1].rgbtBlue;
            }
            // Up right
            if (i > 0 && j < width - 1)
            {
                rGx += 1 * image[i - 1][j + 1].rgbtRed;
                gGx += 1 * image[i - 1][j + 1].rgbtGreen;
                bGx += 1 * image[i - 1][j + 1].rgbtBlue;
                rGy += -1 * image[i - 1][j + 1].rgbtRed;
                gGy += -1 * image[i - 1][j + 1].rgbtGreen;
                bGy += -1 * image[i - 1][j + 1].rgbtBlue;
            }
            // Bottom right
            if (i < height - 1  && j < width - 1)
            {
                rGx += 1 * image[i + 1][j + 1].rgbtRed;
                gGx += 1 * image[i + 1][j + 1].rgbtGreen;
                bGx += 1 * image[i + 1][j + 1].rgbtBlue;
                rGy += 1 * image[i + 1][j + 1].rgbtRed;
                gGy += 1 * image[i + 1][j + 1].rgbtGreen;
                bGy += 1 * image[i + 1][j + 1].rgbtBlue;
            }
            // Bottom left
            if (i < height - 1  && j > 0)
            {
                rGx += -1 * image[i + 1][j - 1].rgbtRed;
                gGx += -1 * image[i + 1][j - 1].rgbtGreen;
                bGx += -1 * image[i + 1][j - 1].rgbtBlue;
                rGy += 1 * image[i + 1][j - 1].rgbtRed;
                gGy += 1 * image[i + 1][j - 1].rgbtGreen;
                bGy += 1 * image[i + 1][j - 1].rgbtBlue;
            }

            // Compute result
            copy[i][j].rgbtRed = (int) cap255(sqrt((rGx * rGx) + (rGy * rGy)));
            copy[i][j].rgbtGreen = (int) cap255(sqrt((gGx * gGx) + (gGy * gGy)));
            copy[i][j].rgbtBlue = (int) cap255(sqrt((bGx * bGx) + (bGy * bGy)));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

