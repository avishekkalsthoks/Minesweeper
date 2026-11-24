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
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
    for (int i = 3; i< Grid_size-2;i++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+i,0xFF0000,arr);
        }
    for (int i = 3; i< Grid_size-2;i++){
            put_pixel((x+1)*Grid_size+i,(y+3)*Grid_size-i,0xFF0000,arr);
        }
    }

void draw_one(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }
    }
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =4; j< Grid_size-3;j++){
            if (i==12){
                put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0x8000FF,arr);
            }
        }
    }
}
void draw_two(float x,float y, int arr[] ){
     for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
void draw_three(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
void draw_four(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
void draw_five(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
void draw_six(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
void draw_seven(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
void draw_eight(float x,float y, int arr[] ){
    for (int i = 1; i< Grid_size;i++){
        for (int j =1; j< Grid_size;j++){
            put_pixel((x+1)*Grid_size+i,(y+2)*Grid_size+j,0xCBCBCB,arr);
        }}
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
    if (x>= 0 && y>=0 && x <= 13 && y <=6){
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
    for (int i = 8;i<Grid_size-1;i++){
        for (int j = i-5;j<11;j++){
            put_pixel((x+1)*Grid_size+i+1,(y+2)*Grid_size+j,0xFF0000,arr);
        }
    }
    }
}

void dig_at(int i,int j, int arr[], Pos mine[],int size){
    if (i>= 0 && j>=0 && i <= 13 && j <=6){
        if (!in_list_or_not(i,j,mine,size)){
                switch (num_of_mines(i,j,mine,size))
                {
                case 0:
                    for (int x = 1; x< Grid_size;x++){
                        for (int y = 1; y<Grid_size;y++){
                           put_pixel((i+1)*Grid_size+x,(j+2)*Grid_size+y,0xCBCBCB,arr); 
                        }
                    }
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
void score_board(int x,int y,int arr[],int flag[]){
    for (int i =x;i<=x+80;i++){
        for(int j = y;j<=y+25;j++){
            put_pixel(i,j,0x00000,arr);
        }
    }
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (i==8){
                put_pixel(x+i,y+j,0xFF0000,arr);
            }
            if (j==11 && i>=8){
                put_pixel(x+i,y+j,0xFF0000,arr);
            }
            
        }
    }
    for (int i = 8;i<Grid_size-1;i++){
        for (int j = i-5;j<11;j++){
            put_pixel(x+i+1,y+j,0xFF0000,arr);
        }
    }
    switch (flag[1])
                {
                case 0:
                draw_zero0(x+20,10,arr);
                    break;
                case 1:
                    draw_one1(x+20,10,arr);
                    break;
                case 2:
                    draw_two2(x+20,10,arr);
                    break;
                case 3: 
                    draw_three3(x+20,10,arr);
                    break;
                case 4:
                draw_four4(x+20,10,arr);
                    break;
                case 5:
                    draw_five5(x+20,10,arr);
                    break;
                case 6:
                    draw_six6(x+20,10,arr);
                    break;
                case 7:
                    draw_seven7(x+20,10,arr);
                    break;
                case 8:
                    draw_eight8(x+20,10,arr);
                    break;
                case 9:
                    draw_nine9(x+20,10,arr);
                    break;
                }
         switch (flag[0])
                {
                case 0:
                    draw_zero0(x+40,10,arr);
                    break;
                case 1:
                    draw_one1(x+40,10,arr);
                    break;
                case 2:
                    draw_two2(x+40,10,arr);
                    break;
                case 3: 
                    draw_three3(x+40,10,arr);
                    break;
                case 4:
                draw_four4(x+40,10,arr);
                    break;
                case 5:
                    draw_five5(x+40,10,arr);
                    break;
                case 6:
                    draw_six6(x+40,10,arr);
                    break;
                case 7:
                    draw_seven7(x+40,10,arr);
                    break;
                case 8:
                    draw_eight8(x+40,10,arr);
                    break;
                case 9:
                    draw_nine9(x+40,10,arr);
                    break;
                }
}
void removee(int a, int b, Pos arr[],int size){
    for (int i=0;i<size;i++){
        if (arr[i].x == a && arr[i].y == b){
            arr[i].x = -1;
            arr[i].y = -1;
        }
    }
}
void num_counter(Pos arr[],int size,int flag[]){
    int n =0;
    for (int i = 0; i<size;i++){
        if (arr[i].x>=0 && arr[i].y>=0){
            n++;
        }
    }
    flag[0]=n%10;
    flag[1]= (int)(n/10);
}
void draw_one1(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =4; j< Grid_size-3;j++){
            if (i==12){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_two2(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j==10 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==Grid_size-3 && j>=4 && j <=10) || (i == 3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_three3(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j==10 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==Grid_size-3 && j>=4 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_four4(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =4; j< Grid_size-2;j++){
            if (i==12){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if (i==5 && j<=10){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if (j==10 && i<=12 && i>=5){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_five5(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j==10 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==3 && j>=4 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_six6(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j==10 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==3 && j>=4 && j <=10) || ((i == Grid_size-3||i==3) && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_seven7(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j == 4){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }}
    }
    for (int i = 3; i< Grid_size-3;i++){
            put_pixel(x+i,y-i+Grid_size,0xFFFFFF,arr);
            put_pixel(x+i+1,y-i+Grid_size,0xFFFFFF,arr);
        }
    }
void draw_eight8(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j==10 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==3 && j>=4 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==Grid_size-3 && j>=4 && j <=10) || (i == 3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_zero0(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==3 && j>=5 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==Grid_size-3 && j>=5 && j <=10) || (i == 3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}
void draw_nine9(float x,float y, int arr[] ){
    for (int i = 3; i< Grid_size-2;i++){
        for (int j =3; j< Grid_size-2;j++){
            if (j==4 || j==10 || j == 15){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==3 && j>=4 && j <=10) || (i == Grid_size-3 && j>=10 && j<=15)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
            if ((i==Grid_size-3 && j>=5 && j <=10)){
                put_pixel(x+i,y+j,0xFFFFFF,arr);
            }
        }
    }
}