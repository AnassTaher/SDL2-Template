#include <iostream>
#include "../SDL2/include/SDL2/SDL.h"

using namespace std;

int main(int argc, char* argv[]){

   SDL_Init(SDL_INIT_EVERYTHING);

   SDL_Window* window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

   SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

   SDL_RenderClear(renderer);

   SDL_RenderPresent(renderer);


   SDL_Delay(500);

   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(renderer);
   SDL_Quit();
    

    return 0;
}