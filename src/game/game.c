/* game.c */

#include "include.h"

void run_game(struct global *global)
{
    game_init(global);

    while (global->program_status == RUNNING)
    {
        get_inputs(global);
        update(global);
        display(global);
        time(global);
    }

    game_destroy(global);
    return;
}
