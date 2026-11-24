        #include<stdio.h>
#include<SDL3/SDL.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include "games/mines.h"
typedef uint8_t ui8;
typedef uint32_t ui32;
typedef uint64_t ui64;
const double target_frame = 1.0/60.0;

int framebuffer[WIDTH *HEIGHT];

void clear(ui32 color){
    for (int i = 0; i<WIDTH*HEIGHT;i++){
        framebuffer[i]= color;
    }
}
int main(void) {
    Pos locl[50];
    // Pos locr[60];
    Pos l = {100,100};
    Pos r = {100,100};
    int ol=0;
    int or =0;
    srand(time(NULL));
    Pos mines[SIZE];
    coords(mines);   
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Event event;
    if (!SDL_Init(SDL_INIT_VIDEO)){
		fprintf(stderr,"SDL Init failed %s",SDL_GetError());
		return EXIT_FAILURE;
	}
    
    
    window = SDL_CreateWindow("Test",
    WIDTH*3, 
    HEIGHT*3
    ,0);
    if (window==NULL){
		fprintf(stderr,"SDL create window failed %s",SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
    renderer = SDL_CreateRenderer(window,NULL);
     if (renderer==NULL){
		fprintf(stderr,"SDL create renderer failed %s",SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
	}
    texture = SDL_CreateTexture(renderer,
    SDL_PIXELFORMAT_XRGB8888,
    SDL_TEXTUREACCESS_STREAMING, 
    WIDTH,
    HEIGHT);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
     if (texture
     ==NULL){
		fprintf(stderr,"SDL create texture failed %s",SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;    
	}
    ui8 is_running = 1;
    ui32 frame = 0;
    while(is_running){
    ui64 start = SDL_GetPerformanceCounter();
    Pos l0 = l;
    Pos r0 = r;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				is_running = 0;
				} 
            else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN){
                if (event.button.button == SDL_BUTTON_LEFT){
                    l.x = (int)(event.button.x/60 -1);
                    l.y = (int)(event.button.y/60 -2);
                } 
                if (event.button.button == SDL_BUTTON_RIGHT){
                    r.x = (int)(event.button.x/1);
                    r.y = (int)(event.button.y/1);
                }
            }
			 }
    clear(0x00FFFF);
    // Below this all the graphics thing are done
    
    if (!(l0.x == l.x && l0.y == l.y)){
        locl[ol].x = l.x; 
        locl[ol].y= l.y;
        ol++;
    }
    if (r0.x != r.x && r0.y != r.y){
        // locr[or].x = r.x; 
        // locr[or].y= r.y;
        //flag_at(r.x,r.y,framebuffer,mines);
        or++;
    }
    // Borders setup
    for (int y = 0 ; y <HEIGHT;y++){
        for (int x = 0; x<WIDTH;x++){
            if (x<Grid_size || (x>(320-Grid_size)))
            {
                put_pixel(x,y,0xE8E8E8, framebuffer);
            }
            else if (y<Grid_size*2 || y>(200-Grid_size))
            {
                put_pixel(x,y,0xE8E8E8,framebuffer);
            }
            else if (x%Grid_size==0)
            {
                put_pixel(x,y,0x0000FF,framebuffer);
            }
            else if (y%Grid_size==0)
            {
                put_pixel(x,y,0x0000FF,framebuffer);
            }
        }
    }
    int i = 0;
    while (i!=ol+1){
        if (!in_list_or_not(locl[i].x,locl[i].y,mines)){
            dig_at(locl[i].x,locl[i].y,framebuffer,mines);}
        else {
            draw_mine(locl[i].x,locl[i].y,framebuffer);
        }
        i++;
    }
    // Above this all the graphics thing are done 
	SDL_UpdateTexture(
	texture,
	NULL,
	framebuffer,
	WIDTH*sizeof(ui32));
	

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    ui32 end = SDL_GetPerformanceCounter();
    double elapsed = (double)(end - start)/(double)(SDL_GetPerformanceFrequency());
    if (elapsed < target_frame){
        SDL_Delay((target_frame-elapsed)*1000.0);
    }
    frame++;
}

SDL_DestroyTexture(texture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);

SDL_Quit();
}
    
    
     


