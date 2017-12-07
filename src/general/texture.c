/* texture.c */

#include "include.h"

SDL_Texture *texture_load(struct global *global, char *path)
{
    SDL_Surface *surface = IMG_Load(path);
    if (!surface)
        err(-1, "Cannot load %s", path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(global->renderer,
                                                        surface);
    SDL_FreeSurface(surface);
    return texture;
}

void texture_draw(struct global *global, SDL_Texture *texture,
                  int x, int y)
{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &(rectangle.w), &(rectangle.h));
    rectangle.w *= 2;
    rectangle.h *= 2;

    SDL_RenderCopy(global->renderer, texture, NULL, &rectangle);
}
