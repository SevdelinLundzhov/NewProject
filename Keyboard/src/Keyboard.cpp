//============================================================================
// Name        : EasyMade5Keyboard.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

int main(int argc, char* argv[]) {

	SDL_Window *window = NULL;
	SDL_Surface *windowSurface = NULL;
	SDL_Surface *image1 = NULL;
	SDL_Surface *image2 = NULL;
	SDL_Surface *image3 = NULL;
	SDL_Surface *image4 = NULL;
	SDL_Surface *currentImage;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("na bate sevdi prozoreco ", SDL_WINDOWPOS_CENTERED,
				                          SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);

	image1 = SDL_LoadBMP("test1.bmp");
	image2 = SDL_LoadBMP("test2.bmp");
	image3 = SDL_LoadBMP("test3.bmp");
	image4 = SDL_LoadBMP("test4.bmp");
	currentImage = image1;

	bool isRuning = true;

	SDL_Event e;

	while(isRuning)
	{
		while(SDL_PollEvent( &e ) != 0)
		{
			if( e.type == SDL_QUIT)
			{
				isRuning = false;
			}
				else if(e.type == SDL_KEYDOWN)
				{
					switch(e.key.keysym.sym)
					{
					case SDLK_1:
					    currentImage = image1;
					  	  break;
					case SDLK_2:
						currentImage = image2;
						break;
					case SDLK_3:
						currentImage = image3;
						break;
					}
				}
				else if(e.type == SDL_MOUSEMOTION)
				{
					if(e.button.x < 200)
					{
						currentImage = image4;
					}
				}

		SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
		}
	}

	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image3);
	SDL_FreeSurface(image4);

	SDL_DestroyWindow(window);

	currentImage = image1 = image2 = image3 = image4 = NULL;
	window  = NULL;

	SDL_Quit();

	return 0;
}
