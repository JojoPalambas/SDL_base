/* dead_menu.c */

#include "../include.h"

void dead_menu(struct global *global)
{
    printf("Dead menu\n");
    global->program_status = RUNNING;
    return;
}
