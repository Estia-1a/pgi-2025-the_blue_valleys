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

void print_pixel(char *filename, int x, int y){
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int pixel_index = (y*width+x)*channel_count;
    unsigned char r = data[pixel_index];
    unsigned char g = data[pixel_index+1];
    unsigned char b = data[pixel_index+2];
    if(data==NULL){
        printf("NULL");
    }
    if(x < 0 || x >= width || y < 0 || y >= height) {
        printf("NULL");
    }
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, r, g, b);
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

void max_component(char *source_path, char component) {
    if (component != 'R' && component != 'G' && component != 'B') {
        printf("Le parametre de la fonction doit etre R, G ou B.");
        return;
    }
    unsigned char *data;
    int width, height, channel_count;
    int i = 0;
    unsigned char comp, comp_max;
    int x_max, y_max;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int nb_pixels = width * height;
    for (i=0; i<nb_pixels; i++) {

        if (component == 'R') {
            comp = data[i*3+0];
            if (comp>comp_max) {
                comp_max=comp;
                x_max = i % width;
                y_max = i / width;
            }
        }

        else if (component == 'G') {
            comp = data[i*3+1];
            if (comp>comp_max) {
                comp_max=comp;
                x_max = i % width;
                y_max = i / width;
            }
        }
        else {
            comp = data[i*3+2];
            if (comp>comp_max) {
                comp_max=comp;
                x_max = i % width;
                y_max = i / width;
            }
        }  
    }
    printf("max component %c (%d, %d): %d", component, x_max, y_max, comp_max);
}

void color_red(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i;
    int nb_pixels=width*height;
    for (i=0; i<nb_pixels ; i++) {
        data[i*3+1]=0;
        data[i*3+2]=0;
    }
    write_image_data("image_out.bmp", data, width, height);

}

void color_green(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i;
    int nb_pixels=width*height;
    for (i=0; i<nb_pixels ; i++) {
        data[i*3+0]=0;
        data[i*3+2]=0;
    }
    write_image_data("image_out.bmp", data, width, height);

}

void color_blue(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i;
    int nb_pixels=width*height;
    for (i=0; i<nb_pixels ; i++) {
        data[i*3+0]=0;
        data[i*3+1]=0;
    }
    write_image_data("image_out.bmp", data, width, height);
}

void min_component(char *source_path, char component) {
    if (component != 'R' && component != 'G' && component != 'B') {
        printf("Le parametre de la fonction doit etre R, G ou B.");
        return;
    }
    unsigned char *data;
    int width, height, channel_count;
    int i = 0;
    unsigned char comp;
    int comp_min=255*3+1;
    int x_min, y_min;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int nb_pixels = width * height;
    for (i=0; i<nb_pixels; i++) {

        if (component == 'R') {
            comp = data[i*3+0];
            if (comp<comp_min) {
                comp_min=comp;
                x_min = i % width;
                y_min = i / width;
            }
        }

        else if (component == 'G') {
            comp = data[i*3+1];
            if (comp<comp_min) {
                comp_min=comp;
                x_min = i % width;
                y_min = i / width;
            }
        }
        else {
            comp = data[i*3+2];
            if (comp<comp_min) {
                comp_min=comp;
                x_min = i % width;
                y_min = i / width;
            }
        }  
    }
    printf("min component %c (%d, %d): %d", component, x_min, y_min, comp_min);
}

void color_gray(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i;
    int nb_pixels=width*height;
    int moy;
    for (i=0; i<nb_pixels ; i++) 
    {
        moy = (data[i*3+0] + data[i*3+1] + data[i*3+2]) / 3;
        data[i*3+0]=moy;
        data[i*3+1]=moy;
        data[i*3+2]=moy;
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_gray_luminance(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i;
    int nb_pixels=width*height;
    unsigned char moy;
    for (i=0; i<nb_pixels ; i++) 
    {
        moy = data[i*3+0]*0.21 + data[i*3+1]*0.72 + data[i*3+2]*0.07;
        data[i*3+0]=moy;
        data[i*3+1]=moy;
        data[i*3+2]=moy;
    }
    write_image_data("image_out.bmp", data, width, height);
}

