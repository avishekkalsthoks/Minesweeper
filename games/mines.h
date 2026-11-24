#ifndef MINES_H
#define MINES_H

#define WIDTH 320
#define HEIGHT 200
#define Grid_size 20
#define Mouse_d 15
enum {
    SIZE = 20,
    W_BOUND = 13,
    H_BOUND = 6 
};

typedef struct {
    int x;
    int y;
} Pos;

int randint(int a, int b);
void coords(Pos mine_pos[]);
int in_list_or_not(int a, int b, Pos mine_pos[]);
int num_of_mines(int a, int b, Pos mine_pos[]);
void put_pixel(int x, int y , int color , int arr[]);
void draw_mine(int x,int y, int arr[] );
void draw_one(int x,int y, int arr[] );
void draw_two(int x,int y, int arr[] );
void draw_three(int x,int y, int arr[] );
void draw_four(int x,int y, int arr[] );
void draw_five(int x,int y, int arr[] );
void draw_six(int x,int y, int arr[] );
void draw_seven(int x,int y, int arr[] );
void draw_eight(int x,int y, int arr[] );
void dig_at(int x,int y, int arr[], Pos mine[]);
void flag_at(int x,int y, int arr[], Pos mine[]);

#endif
