#include "helpers.h"
#include <math.h>

// Detect edges using Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) copy[i][j] = image[i][j];
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float gxR = 0, gxG = 0, gxB = 0, gyR = 0, gyG = 0, gyB = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (i+di >= 0 && i+di < height && j+dj >= 0 && j+dj < width) {
                        gxR += copy[i+di][j+dj].rgbtRed * Gx[di+1][dj+1];
                        gyR += copy[i+di][j+dj].rgbtRed * Gy[di+1][dj+1];
                        // Repeat for Green and Blue...
                    }
                }
            }
            int resR = round(sqrt(gxR*gxR + gyR*gyR));
            image[i][j].rgbtRed = (resR > 255) ? 255 : resR;
            // Apply same logic for Green and Blue
        }
    }
}
