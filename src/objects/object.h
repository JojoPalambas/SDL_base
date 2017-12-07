/* object.h */

#ifndef OBJECT_H
#define OBJECT_H

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

/*=================================ENUMS======================================*/

enum anim_index
{
    CREATE = 0,
    DESTROY,
    STAY_R,
    STAY_L,
    ATTK1,
    ATTK2,
    JUMP,
    MIDAIR
}

/*=================================STRUCTURES=================================*/

struct hitbox
{
    int x1; // Left  bound of x (x min)
    int x2; // Right bound of x (x max)
    int y1; // Upper bound of y (y min)
    int y2; // Lower bound of y (y max)
}

struct frame
{
    SDL_Texture *texture;       // Texture of the frame
    int width;                  // Display width of the frame
    int height;                 // Display height of the frame
    struct hitbox *phys_hitbox; // Hitbox for hitting obstacles and enemies
    struct hitbox *dmg_hitbox;  // Hitbox for taking damage
}

struct animation
{
    struct frame *frames;   // Frames of the animation
    struct frame cur_frame; // Current frame being displayed
    int nb_frames;          // Number of frames = length(frames)
    int frame_duration;     // Number of tics for each frame
    int min_frame_duration; // Minimum frame diration (if duration is random)
    int counter;            // if counter == 0 -> change frame
    int random_duration;    /* If the duration of a frame is
                               randint(min_frame_duration, frame_duration) */
    int random_order;       // If the next frame is randomly chosen
    int repeat;             // If a frame can repeat itself if randomly chosen
    int loop;               // If the animation loops
    struct animation *next; // Next animation if the animation doesn't loop
}

struct animator
{
    struct animation *cur_anim;
    struct animation **anims;
}

/*=================================FUNCTIONS==================================*/



#endif
