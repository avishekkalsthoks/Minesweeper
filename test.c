#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
        int x;
        int y;
}Pos;
const int size=25;
const int w_bound=10;
const int h_bound=10;
int randint(int a, int b){
return (rand() % (a-b+1) + a);
}
int main(){
srand(time(NULL));
Pos mine_pos[size];
int i = 0 ;
mine_pos[0].x = randint(1,w_bound);
mine_pos[0].y  = randint(1,h_bound);
while(i<size){
        mine_pos[i].x = randint(1,w_bound);
        mine_pos[i].y = randint(1,h_bound);
        for (int j=0;j<i;j++){
                if ((mine_pos[j].x == mine_pos[j+1].x) && (mine_pos[j+1].y == mine_pos[j].y)){
                        i--;
                        break;}} 
        i++;
}
for (int j = 0; j<10;j++){
        printf("[%d,%d]\t",mine_pos[j].x,mine_pos[j].y);
}
}


