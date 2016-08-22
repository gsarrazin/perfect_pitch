#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <QMediaPlayer>
 
int main(int argc, char *argv[])
{
#if 0
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    //SDL_Window *screen = SDL_CreateWindow("My Game Window",
    //                          SDL_WINDOWPOS_UNDEFINED,
    //                          SDL_WINDOWPOS_UNDEFINED,
    //                          640, 480,
    //                          SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_DOUBLEBUF);

    //SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    
    // Create an SDL window
	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	
	// if failed to create a window
	if(!window)
	{
		// we'll print an error message and exit
		std::cerr << "Error failed to create window!\n";
		return 1;
	}
	
	// Create an OpenGL context (so we can use OpenGL functions)
	SDL_GLContext context = SDL_GL_CreateContext(window);
	
	// if we failed to create a context
	if(!context)
	{
		// we'll print out an error message and exit
		std::cerr << "Error failed to create a context\n!";
		return 2;
	}
	
	SDL_Event event;	 // used to store any events from the OS
	bool running = true; // used to determine if we're running the game
	
	glClearColor(1, 0, 0, 1);
	while(running)
	{
		// poll for events from SDL
		while(SDL_PollEvent(&event))
		{
			// determine if the user still wants to have the window open
			// (this basically checks if the user has pressed 'X')
			running = event.type != SDL_QUIT;
		}
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Swap OpenGL buffers
		SDL_GL_SwapWindow(window);
	}
	
	
	// Destroy the context
	SDL_GL_DeleteContext(context);
	
	// Destroy the window
	SDL_DestroyWindow(window);
	
 

    SDL_Quit();
#else
player = new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("/home/gsarrazin/Projects/perfect_pitch/Notes_Piano-01.wav"));
player->setVolume(50);
player->play();
delete player;
#endif
    return 0;
}
