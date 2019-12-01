#include <pthread.h>

#include "Game.h"
#include "Tui.h"

int main()
{
    pthread_t tui_thrd;
    pthread_create(&tui_thrd, NULL, &tui_run, NULL);
    game_start();

    while (!game_at_exit())
    {
        game_user_input();
    }

    tui_end();
    pthread_join(tui_thrd, NULL);
    return 0;
}
