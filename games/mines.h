#ifndef MINES_H
#define MINES_H

#define WIDTH 320
#define HEIGHT 200
#define Grid_size 20
#define Mouse_d 15
enum {
    SIZE = 20,
    W_BOUND = 13,
    H_BOUND = 6,
    SIZE_LOC = 120 
};

typedef struct {
    int x;
    int y;
} Pos;
void removee(int a,int b, Pos arr[], int size);
int randint(int a, int b);
void num_counter(Pos arr[], int size, int flag[]);
void coords(Pos mine_pos[]);
int in_list_or_not(int a, int b, Pos mine_pos[], int size);
int num_of_mines(int a, int b, Pos mine_pos[],int size);
void put_pixel(int x, int y , int color , int arr[]);
void draw_mine(int x,int y, int arr[] );
void draw_one(float x,float y, int arr[] );
void draw_two(float x,float y, int arr[] );
void draw_three(float x,float y, int arr[] );
void draw_four(float x,float y, int arr[] );
void draw_five(float x,float y, int arr[] );
void draw_six(float x,float y, int arr[] );
void draw_seven(float x,float y, int arr[] );
void draw_eight(float x,float y, int arr[] );
void draw_one1(float x,float y, int arr[] );
void draw_two2(float x,float y, int arr[] );
void draw_three3(float x,float y, int arr[] );
void draw_four4(float x,float y, int arr[] );
void draw_five5(float x,float y, int arr[] );
void draw_six6(float x,float y, int arr[] );
void draw_seven7(float x,float y, int arr[] );
void draw_eight8(float x,float y, int arr[] );
void dig_at(int x,int y, int arr[], Pos mine[],int size);
void flag_at(int x,int y, int arr[]);
void score_board(int x,int y, int arr[],int flag[]);
void draw_zero0(float x, float y,int arr[]);
void draw_nine9(float x,float y, int arr[] );
void load_game(int arr[]);
#endif
