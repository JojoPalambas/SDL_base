/* victory_menu.c */

#include "../include.h"

void victory_menu(struct global *global)
{
    printf("Victory menu\n");
    global->program_status = RUNNING;
    return;
}
