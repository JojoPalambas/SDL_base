/* main.c */

#include "include.h"

int main(void)
{
    struct global *global = init_all();

    logo(global);

    while (global->program_status != END)
    {
        if (global->program_status == LOGO)
            logo(global);
        else if (global->program_status == MAIN_MENU)
            main_menu(global);
        else if (global->program_status == RUNNING)
            game_run(global);
        else if (global->program_status == DEAD_MENU)
            dead_menu(global);
        else if (global->program_status == VICTORY_MENU)
            victory_menu(global);
    }

    destroy_all(global);
    return 0;
}
