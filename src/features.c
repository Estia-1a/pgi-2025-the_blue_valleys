#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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

    read_image_data(filename, &data, &width, &height, &channel_count);
    printf("dimension: %d, %d\n", width, height);
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
    int somme = 0, max = -1;
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
    printf("max_pixel (%d, %d): %d, %d, %d\n", x_max, y_max, r_max, g_max, b_max);
}

void min_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    int i = 0;
    int somme = 0, min = 255 * 3;
    unsigned char r = 0, g = 0, b = 0, r_min = 0, g_min = 0 , b_min = 0;
    int x_min = 0, y_min = 0;
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
    int comp, comp_max = -1;
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
    printf("max_component %c (%d, %d): %d\n", component, x_max, y_max, comp_max);
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
    int comp_min=256;
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
    printf("min_component %c (%d, %d): %d", component, x_min, y_min, comp_min);
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

void rotate_acw(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int new_width=height;
    int new_height=width;
    unsigned char *rotated_data=malloc(new_width*new_height*3);
    int x, y;
    for (y=0; y<height; y++) {
        for (x=0; x<width; x++) {
            int pixel_index=(y*width+x)*3;
            int new_x=y;
            int new_y=width-1-x;
            int new_pixel_index=(new_y*new_width+new_x)*3;
            rotated_data[new_pixel_index+0]=data[pixel_index+0];
            rotated_data[new_pixel_index+1]=data[pixel_index+1];
            rotated_data[new_pixel_index+2]=data[pixel_index+2];
        }
    }
    write_image_data("image_out.bmp", rotated_data, new_width, new_height);
}

void color_invert(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i;
    int nb_pixels=width*height;
    for (i=0; i<nb_pixels ; i++) 
    {
        data[i*3+0]=255-data[i*3+0];
        data[i*3+1]=255-data[i*3+1];
        data[i*3+2]=255-data[i*3+2];
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_desaturate(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int i, r, g, b;
    int max, min;
    int nb_pixels=width*height;
    unsigned char new_val;
    for (i=0; i<nb_pixels ; i++) 
    {
        r = data[i*3+0];
        g = data[i*3+1];
        b = data[i*3+2];
        if (r > g && r > b){
            max=r;
            if (g > b){
                min=b;
            }
            else {
                min=g;
            }
        }
        else if (g > r && g > b){
            max=g;
            if (r > b){
                min=b;
            }
            else {
                min=r;
            }
        }
        else{
            max=b;
            if (r > g){
                min=g;
            }
            else {
                min=r;
            }
        }
        new_val = (min + max) / 2 ;
        data[i*3+0]=new_val;
        data[i*3+1]=new_val;
        data[i*3+2]=new_val;
    }
    write_image_data("image_out.bmp", data, width, height);
}


void mirror_horizontal(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x=0; x < width/2; x++) {
            int index_source = (y * width + x) * 3;
            unsigned char source_r = data[index_source];
            unsigned char source_g = data[index_source+1];
            unsigned char source_b = data[index_source+2];

            int x_destination = width - 1 - x;
            int index_destination = (y * width + x_destination) * 3;
            unsigned char destination_r = data[index_destination];
            unsigned char destination_g = data[index_destination+1];
            unsigned char destination_b = data[index_destination+2];

            data[index_destination] = source_r;
            data[index_destination+1] = source_g;
            data[index_destination+2] = source_b;

            data[index_source] = destination_r;
            data[index_source+1] = destination_g;
            data[index_source+2] = destination_b;

        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void rotate_cw(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int new_width=height;
    int new_height=width;
    unsigned char *rotated_data=malloc(new_width*new_height*3);
    int x, y;
    for (y=0; y<height; y++) {
        for (x=0; x<width; x++) {
            int pixel_index=(y*width+x)*3;
            int new_x=width-1-y;
            int new_y=x;
            int new_pixel_index=(new_y*new_width+new_x)*3;
            rotated_data[new_pixel_index+0]=data[pixel_index+0];
            rotated_data[new_pixel_index+1]=data[pixel_index+1];
            rotated_data[new_pixel_index+2]=data[pixel_index+2];
        }
    }
    write_image_data("image_out.bmp", rotated_data, new_width, new_height);
}

void mirror_vertical(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    for (int y = 0; y < height / 2; y++) {
        for (int x=0; x < width; x++) {
            int index_source = (y * width + x) * 3;
            unsigned char source_r = data[index_source];
            unsigned char source_g = data[index_source+1];
            unsigned char source_b = data[index_source+2];
 
            int y_destination = height - 1 - y;
            int index_destination = (y_destination * width + x) * 3;
            unsigned char destination_r = data[index_destination];
            unsigned char destination_g = data[index_destination+1];
            unsigned char destination_b = data[index_destination+2];
 
            data[index_destination] = source_r;
            data[index_destination+1] = source_g;
            data[index_destination+2] = source_b;
 
            data[index_source] = destination_r;
            data[index_source+1] = destination_g;
            data[index_source+2] = destination_b;
 
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void scale_crop(char *filename, int center_x, int center_y, int crop_width, int crop_height){
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int new_w=crop_width;
    int new_h=crop_height;
    unsigned char *cropped_data=malloc(new_w*new_h*3);
    int x, y;
    for (y = 0; y < new_h; y++) {
        for (x = 0; x < new_w; x++) {
            int src_x = center_x - new_w/2 + x;
            int src_y = center_y - new_h/2 + y;
            int new_index = (y * new_w + x) * 3;
            if (src_x < 0 || src_x >= width || src_y < 0 || src_y >= height) {
                cropped_data[new_index + 0] = 0;
                cropped_data[new_index + 1] = 0;
                cropped_data[new_index + 2] = 0;
            }
            else {
                int index = (src_y * width + src_x) * 3;
                cropped_data[new_index + 0] = data[index + 0];
                cropped_data[new_index + 1] = data[index + 1];
                cropped_data[new_index + 2] = data[index + 2];
            }
        }
    }
    write_image_data("image_out.bmp",cropped_data,new_w, new_h);
}

void mirror_total(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    mirror_vertical(filename);
    mirror_horizontal(filename);
    write_image_data("image_out.bmp", data, width, height);
}
