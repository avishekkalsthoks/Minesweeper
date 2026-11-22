#include <stdlib.h>
#include "mines.h"

int randint(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

void coords(Pos mine_pos[]) {
    int i = 0;
    while (i < SIZE) {
        int x = randint(0, W_BOUND);
        int y = randint(0, H_BOUND);

        int is_duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (mine_pos[j].x == x && mine_pos[j].y == y) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            mine_pos[i].x = x;
            mine_pos[i].y = y;
            i++;
        }
    }
}
