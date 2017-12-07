/* logo.c */

#include "logo.h"

/* Displays the logo of the company */
void logo(struct global *global)
{
    printf("Affichege du logo\n");
    global->program_status = MAIN_MENU;
    return;
}
