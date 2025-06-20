#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension(char* filename);

void first_pixel(char *source_path);

void tenth_pixel (char *source_path);

void second_line(char *source_path);

void max_pixel(char *source_path);

void max_component(char *source_path, char component);

void min_pixel(char *source_path);

void color_red(char *filename);

void color_green(char *filename);

void color_blue(char *filename);

void color_gray(char *filename);

void color_gray_luminance(char *filename);

void min_component(char *source_path, char component);

void rotate_cw(char *filename);

void color_invert(char *filename);

void color_desaturate(char *filename);

void mirror_horizontal(char *filename);

void rotate_acw(char *filename);

void scale_crop(char *filename, int center_x, int center_y, int crop_width, int crop_height);

void mirror_vertical(char *filename);

void mirror_total(char *filename);


#endif
