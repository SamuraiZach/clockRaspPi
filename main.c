#include "display.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#define BLACK 0X0000

int main(void){
   // pi_framebuffer_t *fb=getFrameBuffer();
    //int hrs, mms, secs;

   // char totalt[8];
    while(1){
        pi_framebuffer_t *fb=getFrameBuffer();
        printf("entering main");
            bool test = true;
            int hrs, mms, secs = 0;
            int grabbed = 0;
            //char totalt[8];
            //int result = scanf("%s",totalt);
        int result = scanf("%2d:%2d:%2d",&hrs,&mms,&secs);
        //printf("\ntotalt = %s\n",totalt);

        if(result != 0){
                //sscanf(totalt,"%d:%d:%d",&hrs,&mms,&secs);
            //printf("\ntotalt = %s\n",totalt);
            printf("\nhr = %d and min = %d sec = %d\n",hrs,mms,secs);
                grabbed = hrs + mms + secs;
                display_time(hrs,mms,secs,fb);
                //freeFrameBuffer(fb);
        }
        else{
            //clearFrameBuffer(fb,BLACK);
            //freeFrameBuffer(fb);
            return 0;
        }

    }

}
