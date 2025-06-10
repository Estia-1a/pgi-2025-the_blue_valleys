#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}


void dimension(char* filename) {
    
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s\n", filename);
    } else {
        printf("dimension: %d, %d\n", width, height);
        free_image_data(data);
    }
}

void first_pixel(char *source_path){
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];
    printf("first_pixel: %d, %d, %d\n", r, g, b);
}

void tenth_pixel(char *source_path){
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char r = data[27];
    unsigned char g = data[28];
    unsigned char b = data[29];
    printf("tenth_pixel: %d, %d, %d\n", r, g, b);
}

void second_line(char *source_path){
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char r = data[3*width];
    unsigned char g = data[3*width+1];
    unsigned char b = data[3*width+2];
    printf("second_line: %d, %d, %d\n", r, g, b);
}

void max_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    int i = 0;
    int somme = 0, max = 0;
    unsigned char r, g, b, r_max, g_max, b_max;
    int x_max, y_max;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int nb_pixels = width * height;
    for (i=0; i<nb_pixels; i++) {
        r = data[i*3+0];
        g = data[i*3+1];
        b = data[i*3+2];
        somme = r + g + b;
        if (somme > max) {
            max=somme;
            r_max = r;
            g_max = g;
            b_max = b;
            x_max = i % width;
            y_max = i / width;
        }
    }
    printf("max pixel (%d,%d): %d, %d, %d", x_max, y_max, r_max, g_max, b_max);
}

void min_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    int i = 0;
    int somme = 0, min = 255 * 3;
    unsigned char r, g, b, r_min, g_min, b_min;
    int x_min, y_min;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int nb_pixels = width * height;
    for (i=0; i<nb_pixels; i++) {
        r = data[i*3+0];
        g = data[i*3+1];
        b = data[i*3+2];
        somme = r + g + b;
        if (somme < min) {
            min=somme;
            r_min = r;
            g_min = g;
            b_min = b;
            x_min = i % width;
            y_min = i / width;
        }
    }
    printf("min_pixel (%d,%d): %d, %d, %d", x_min, y_min, r_min, g_min, b_min);
}

