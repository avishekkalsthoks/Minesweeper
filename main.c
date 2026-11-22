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
#define WIDTH 320
#define HEIGHT 200
#define Grid_size 20
ui32 framebuffer[WIDTH *HEIGHT];
void put_pixel(int x, int y , ui32 color){
    if (x<0 || x>=WIDTH || y < 0 || y >=HEIGHT ){
        return;
    } else{
        int z = WIDTH*y + x;
        framebuffer[z]=color;}
}
void clear(ui32 color){
    for (int i = 0; i<WIDTH*HEIGHT;i++){
        framebuffer[i]= color;
    }
}
int main(void) { 
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
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				is_running = 0;
				} 
			 }
    
    clear(0x00FFFF);
    // Below this all the graphics thing are done

    
    
    // Borders setup
    for (int y = 0 ; y <HEIGHT;y++){
        for (int x = 0; x<WIDTH;x++){
            if (x<Grid_size || (x>(320-Grid_size)))
            {
                put_pixel(x,y,0xE8E8E8);
            }
            else if (y<Grid_size*2 || y>(200-Grid_size))
            {
                put_pixel(x,y,0xE8E8E8);
            }
            else if (x%Grid_size==0)
            {
                put_pixel(x,y,0x0000FF);
            }
            else if (y%Grid_size==0)
            {
                put_pixel(x,y,0x0000FF);
            }
        }
    }
    for (int i = 0; i<SIZE;i++)
    {
        put_pixel((mines[i].x+1)*Grid_size,(mines[i].y +2)*Grid_size,0xFF0000);
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
    
    
     


