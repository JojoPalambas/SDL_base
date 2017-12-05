#ifndef INCLUDE_H
#define INCLUDE_H

/*=================================INCLUDES===================================*/

#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <err.h>
#include <math.h>
#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>

/*=================================MACROS=====================================*/

#define NAME "Hardcore Bisounours"
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

/*=================================ENUMS======================================*/
enum program_status
{
    MENU,
    RUNNING,
    STOPPED,
    DEAD,
    VICTORY,
    END
};

/*=================================STRUCTURES=================================*/

struct inputs
{
    // 1 if pressed, else 0
    int up;
    int down;
    int left;
    int right;
    int space;
    int escape;
};

struct global
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    uint64_t last_frame;
    uint64_t game_counter;

    struct inputs inputs;
    enum program_status program_status;
};

/*=================================FUNCTIONS==================================*/

/* init.c */
struct global *init_all(void);
void destroy_all(struct global *global);

/* game.c */
void game(struct global *global);

#endif
