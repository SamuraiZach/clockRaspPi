#include "display.h"
#include <math.h>
#include <unistd.h>
#define WHITE 0xFFFF
#define BLUE 0x1F
#define GREEN 0x7E0
#define RED 0xF800
#define BLACK 0X0000

void clear_time(pi_framebuffer_t *);

void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *fb){

        int hs = hours;
        int ms = minutes;
        int se = seconds;
        display_colons(fb);
    printf("\ndisplaying hours\n");
        display_hours(hs, fb);
    printf("\ndisplaying minutes\n");
        display_minutes(ms, fb);
    printf("\ndisplaying seconds\n");
        display_seconds(se, fb);
        sleep(1);
    clear_time(fb);
}

void clear_time(pi_framebuffer_t *fb){
    sense_fb_bitmap_t *bm = fb->bitmap;
    bm->pixel[6][0] = BLACK;
    bm->pixel[6][1] = BLACK;
    bm->pixel[6][2] = BLACK;
    bm->pixel[6][3] = BLACK;
    bm->pixel[6][4] = BLACK;
    bm->pixel[6][5] = BLACK;
    bm->pixel[6][6] = BLACK;
    bm->pixel[6][7] = BLACK;

    bm->pixel[3][0] = BLACK;
    bm->pixel[3][1] = BLACK;
    bm->pixel[3][2] = BLACK;
    bm->pixel[3][3] = BLACK;
    bm->pixel[3][4] = BLACK;
    bm->pixel[3][5] = BLACK;
    bm->pixel[3][6] = BLACK;
    bm->pixel[3][7] = BLACK;

    bm->pixel[0][0] = BLACK;
    bm->pixel[0][1] = BLACK;
    bm->pixel[0][2] = BLACK;
    bm->pixel[0][3] = BLACK;
    bm->pixel[0][4] = BLACK;
    bm->pixel[0][5] = BLACK;
    bm->pixel[0][6] = BLACK;
    bm->pixel[0][7] = BLACK;
}

void display_colons(pi_framebuffer_t *fb){
        sense_fb_bitmap_t *bm=fb->bitmap;
        bm->pixel[1][2]=WHITE;
        bm->pixel[2][2]=WHITE;
        bm->pixel[4][2]=WHITE;
        bm->pixel[5][2]=WHITE;
        bm->pixel[1][3]=WHITE;
        bm->pixel[2][3]=WHITE;
        bm->pixel[4][3]=WHITE;
        bm->pixel[5][3]=WHITE;
        bm->pixel[1][5]=WHITE;
        bm->pixel[2][5]=WHITE;
        bm->pixel[4][5]=WHITE;
        bm->pixel[5][5]=WHITE;
        bm->pixel[1][6]=WHITE;
        bm->pixel[2][6]=WHITE;
        bm->pixel[4][6]=WHITE;
        bm->pixel[5][6]=WHITE;
}

void display_hours(int hours, pi_framebuffer_t *fb){
        sense_fb_bitmap_t *bm=fb->bitmap;
        int remainder = hours;
        if(hours%2 != 0 && hours >= 16){
                bm->pixel[6][3]=BLUE;
                remainder = remainder/2;
        }
        else if(hours%2 == 0 && hours >= 16){
                remainder = remainder/2;
        }



        if(remainder%2 != 0 && hours >= 8){
                bm->pixel[6][4]=BLUE;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && hours >= 8){
                remainder = remainder/2;
        }



        if(remainder%2 != 0 && hours >= 4){
                bm->pixel[6][5]=BLUE;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && hours >= 4){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && hours >= 2){
                bm->pixel[6][6]=BLUE;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && hours >= 2){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && hours >= 1){
                bm->pixel[6][7]=BLUE;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && hours >= 1){
                remainder = remainder/2;
        }
}

void display_minutes(int minutes, pi_framebuffer_t *fb){
        sense_fb_bitmap_t *bm=fb->bitmap;
        int remainder = minutes;
        if(minutes%2 != 0 && minutes >= 32){
                bm->pixel[3][2]=GREEN;
                remainder = remainder/2;
        }
        else if(minutes%2 == 0 && minutes >= 32){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && minutes >= 16){
                bm->pixel[3][3]=GREEN;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && minutes >= 16){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && minutes >= 8){
                bm->pixel[3][4]=GREEN;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && minutes >= 8){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && minutes >= 4){
                bm->pixel[3][5]=GREEN;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && minutes >= 4){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && minutes >= 2){
                bm->pixel[3][6]=GREEN;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && minutes >= 2){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && minutes >= 1){
                bm->pixel[3][7]=GREEN;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && minutes >= 1){
                remainder = remainder/2;
        }
}

void display_seconds(int seconds, pi_framebuffer_t *fb){
        sense_fb_bitmap_t *bm=fb->bitmap;
        int remainder = seconds;
        if(seconds%2 != 0 && seconds >= 32){
                bm->pixel[0][2]=RED;
                remainder = remainder/2;
        }
        else if(seconds%2 == 0 && seconds >= 32){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && seconds >= 16){
                bm->pixel[0][3]=RED;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && seconds >= 16){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && seconds >= 8){
                bm->pixel[0][4]=RED;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && seconds >= 8){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && seconds >= 4){
                bm->pixel[0][5]=RED;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && seconds >= 4){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && seconds >= 2){
                bm->pixel[0][6]=RED;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && seconds >= 2){
                remainder = remainder/2;
        }
        if(remainder%2 != 0 && seconds >= 1){
                bm->pixel[0][7]=RED;
                remainder = remainder/2;
        }
        else if(remainder%2 == 0 && seconds >= 1){
                remainder = remainder/2;
        }
}
