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

int in_list_or_not(int a, int b, Pos mine_pos[],int size){
    int i = 0;
    while(i<size){
        if (mine_pos[i].x == a && mine_pos[i].y == b){
            return 1;
        }
        i++;
    }
    return 0;
}

int num_of_mines(int a, int b, Pos mine_pos[],int size){
    int n = 0;
    for (int i = -1; i<2;i++){
        for (int j = -1; j<2;j++){
            if (((i+a == a) && (j+b == b)) || (i+a < 0) || (j+b < 0) || (i+a > W_BOUND + 2) || (j+b>H_BOUND+2)){

            } else {
                if (in_list_or_not(i+a,j+b,mine_pos,size)){
                    n++;
                }
            }
        }
    }
    return n;
}


void put_pixel(int x, int y , int color , int arr[]){
    if (x<0 || x>=WIDTH || y < 0 || y >=HEIGHT ){
        return;
    } else{
        int z = WIDTH*y + x;
        arr[z]=color;}
}
void draw_mine(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+i,0xFF0000,arr);
        }
    for (int i = 3; i< Grid_size-2;i++){
            put_pixel((x+1)*Grid_size+i,(y+3)*Grid_size-i,0xFF0000,arr);
        }
    }

void draw_one(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =4; j< Grid_size-3;j++){
            if (i==12){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
        }
    }
}
void draw_two(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==5 || j==10 || j == 15){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if ((i==Grid_size-3 && j>=5 && j <=10) || (i == 3 && j>=10 && j<=15)){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x9200DB,arr);
            }
        }
    }
}
void draw_three(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==5 || j==10 || j == 15){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if ((i==Grid_size-3 && j>=5 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x9200DB,arr);
            }
        }
    }
}
void draw_four(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (i==12){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if (i==5 && j<=10){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if (j==10 && i<=12 && i>=5){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
        }
    }
}
void draw_five(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==5 || j==10 || j == 15){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if ((i==3 && j>=5 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x9200DB,arr);
            }
        }
    }
}
void draw_six(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==5 || j==10 || j == 15){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if ((i==3 && j>=5 && j <=10) || ((i == Grid_size-3||i==3) && j>=10 && j<=15)){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x9200DB,arr);
            }
        }
    }
}
void draw_seven(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j == 3){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }}
    }
    for (int i = 3; i< Grid_size-2;i++){
            put_pixel((x+1)*Grid_size+i,(y+3)*Grid_size-i,0x8000FF,arr);
            put_pixel((x+1)*Grid_size+i+1,(y+3)*Grid_size-i,0x8000FF,arr);
        }
    }
void draw_eight(int x,int y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==5 || j==10 || j == 15){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
            if ((i==3 && j>=5 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x9200DB,arr);
            }
            if ((i==Grid_size-3 && j>=5 && j <=10) || (i == 3 && j>=10 && j<=15)){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x9200DB,arr);
            }
        }
    }
}
void flag_at(int x,int y, int arr[] ){
    if (x>= 0 && y>=0 && x <= 20 && y <=20){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (i==8){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xFF0000,arr);
            }
            if (j==11 && i>=8){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xFF0000,arr);
            }
        }
    }
    for (int i = 8;i<Grid_size-2 ; i++){
        if (i>=8){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+i-6,0xFF0000,arr);
            }
    }
}

}
void dig_at(int i,int j, int arr[], Pos mine[],int size){
    if (i>= 0 && j>=0 && i <= 20 && j <=20){
        if (!in_list_or_not(i,j,mine,size)){
                switch (num_of_mines(i,j,mine,size))
                {
                case 0:
                    break;
                case 1:
                    draw_one(i,j,arr);
                    break;
                case 2:
                    draw_two(i,j,arr);
                    break;
                case 3: 
                    draw_three(i,j,arr);
                    break;
                case 4:
                draw_four(i,j,arr);
                    break;
                case 5:
                    draw_five(i,j,arr);
                    break;
                case 6:
                    draw_six(i,j,arr);
                    break;
                case 7:
                    draw_seven(i,j,arr);
                    break;
                case 8:
                    draw_eight(i,j,arr);
                default:
                    break;
                }
            }
    }
}
