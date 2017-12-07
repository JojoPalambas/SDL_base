/* init.c */

#include "include.h"

struct global *init_all(void)
{
    int ans = SDL_Init(SDL_INIT_VIDEO);
    if (ans)
        err(1, "Cannot initialize SDL");

    struct global *global = calloc(1, sizeof (struct global));
    if (!global)
        err(-1, "Cannot initialize global structure");

    global->window = SDL_CreateWindow(NAME,
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      SCREEN_WIDTH,
                                      SCREEN_HEIGHT,
                                      SDL_WINDOW_SHOWN);
    if (!global->window)
        err(-1, "Cannot initialize game window");

    global->renderer = SDL_CreateRenderer(global->window,
                                          -1,
                                          SDL_RENDERER_ACCELERATED);
    if (!global->renderer)
        err(-1, "Cannot initialize renderer");

    global->last_frame = SDL_GetTicks();

    global->program_status = RUNNING;

    return global;
}

static void free_global(struct global *global)
{
    free(global);
}

void destroy_all(struct global *global)
{
    SDL_DestroyRenderer(global->renderer);
    SDL_DestroyWindow(global->window);

    free_global(global);

    SDL_Quit();
}
