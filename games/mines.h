#ifndef MINES_H
#define MINES_H

enum {
    SIZE = 25,
    W_BOUND = 10,
    H_BOUND = 6 
};

typedef struct {
    int x;
    int y;
} Pos;

int randint(int a, int b);
void coords(Pos mine_pos[]);

#endif
