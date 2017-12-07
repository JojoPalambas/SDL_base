/* main_menu.c */

#include "../include.h"

void main_menu(struct global *global)
{
    printf("Main menu\n");
    global->program_status = RUNNING;
    return;
}
