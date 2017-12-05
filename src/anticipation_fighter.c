/* anticipation_fighter.c */

#include "include.h"

int main(void)
{
    struct global *global = init_all();

    game(global);

    destroy_all(global);
    return 0;
}
