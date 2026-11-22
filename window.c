#include<stdio.h>
#include<SDL3/SDL.h>
#include<stdint.h>
#include<stdlib.h>

typedef uint8_t ui8;
typedef uint32_t ui32;
typedef uint64_t ui64;

#define WIDTH 320
#define HEIGHT 200
ui32 framebuffer[WIDTH *HEIGHT];
 
int main(void) {    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Event event;
    if (SDL_Init(SDL_INIT_VIDEO)){
		fprintf(stderr,"SDL Init failed %s",SDL_GetError());
		return EXIT_FAILURE;
	}
    
    
    window = SDL_CreateWindow("Test",
    WIDTH, 
    HEIGHT
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
     if (texture
     ==NULL){
		fprintf(stderr,"SDL create texture failed %s",SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;    
	}
    ui8 is_running = 1;
    while(is_running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				is_running = 0;
				} 
			 }
	SDL_UpdateTexture(
	texture,
	NULL,
	framebuffer,
	WIDTH*sizeof(ui32));
	
	
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}
SDL_DestroyTexture(texture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);

SDL_Quit();
}
    
    
     


