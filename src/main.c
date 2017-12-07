/* main.c */

#include "include.h"

int main(void)
{
    struct global *global = init_all();

    logo(global);

    main_menu(global);

    game(global);

    destroy_all(global);
    return 0;
}
