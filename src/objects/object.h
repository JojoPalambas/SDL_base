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
};

enum hitbox_type
{
    MOVE1 = 1,      // Object can't move if hitbox touches wall
    MOVE2 = 2,      // Other objects can't move against hitbox
    DMG_TAKE = 4,   // Object looses HP if hitbox touches a DMG_DEAL hitbox
    DMG_DEAL = 8,   // Object deals dmg if hitbox touches a DMG_TAKE hitbox
    BULLET1 = 16,   // Hitbox blocks big projectiles (missiles, etc)
    BULLET2 = 32,   // Hitbox blocks small projectiles (bulets, etc)
    BULLET3 = 64    // Hitbox blocks non-material projectiles (micro-waves, etc)
};

/*=================================STRUCTURES=================================*/

struct hitbox
{
    int x1;                 // Left  bound of x (x min)
    int x2;                 // Right bound of x (x max)
    int y1;                 // Upper bound of y (y min)
    int y2;                 // Lower bound of y (y max)
    enum hitbox_type type;  // Type of hitbox (flags separated with '|')
}

struct frame
{
    SDL_Texture *texture;       // Texture of the frame
    int width;                  // Display width of the frame
    int height;                 // Display height of the frame
    int nb_hitboxes;            // Number of hitboxes of the frame
    struct hitbox **hitboxes;   // Hitboxes of the frame
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
    struct animation *cur_anim; // Current animation
    struct animation **anims;   // Animations managed by the animator
}

/*=================================FUNCTIONS==================================*/

/* obj_init.c */
struct hitbox *hitbox_init(int x1, int x2, int y1, int y2, int type);
struct frame *frame_init(const char *path,
                         struct hitbox **hitboxes, int nb_hitboxes);
struct animation *anim_init(const char *folder_path);
struct animator *animator_init(const char *folder_path);
struct animator *animator_cpy(struct animator *animator);
void animator_free(struct animator *animator);

#endif
