//  https://www.acmicpc.net/problem/2931
//  2931_가스관.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int N,M,sx,sy,ex,ey;
int nx,ny,px,py,ans;
int pointX,pointY;
char map[30][30];
int visited[30][30];
bool flag;
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int dx[8] = {1,0,-1,1,-1,1,0,-1};
char changeLetter[7] = {'|','-','+','1','2','3','4'};


bool isposs(int y,int x){
    return y>=0&&x>=0&&y<N&&x<M;
}

//'|'인 경우
void case1(int preX,int preY, int nowX, int nowY){
    if(preY+1 == nowY){
        nx = nowX;
        ny = nowY+1;
    }else if(preY-1 == nowY){
        nx = nowX;
        ny = nowY-1;
    }
}

//'-'인 경우
void case2(int preX,int preY, int nowX, int nowY){
    if(preX+1 == nowX){
        nx = nowX+1;
        ny = nowY;
    }else if(preX-1 == nowX){
        nx = nowX-1;
        ny = nowY;
    }
    
}

//'+'인 경우
void case3(int preX,int preY, int nowX, int nowY){
    if(preX+1 == nowX){
        nx = nowX+1;
        ny = nowY;
    }else if(preX-1 == nowX){
        nx = nowX-1;
        ny = nowY;
    }else if(preY+1 == nowY){
        nx = nowX;
        ny = nowY+1;
    }else if(preY-1 == nowY){
        nx = nowX;
        ny = nowY-1;
    }
}

//'1'
void case4(int preX,int preY, int nowX, int nowY){
    if(preY+1 == nowY){
        nx = nowX+1;
        ny = nowY;
    }else if(preX-1 == nowX){
        nx = nowX;
        ny = nowY-1;
    }
}

//'2'
void case5(int preX,int preY, int nowX, int nowY){
    if(preY-1 == nowY){
        nx = nowX+1;
        ny = nowY;
    }else if(preX-1 == nowX){
        nx = nowX;
        ny = nowY+1;
    }
}

//'3'
void case6(int preX,int preY, int nowX, int nowY){
    if(preY-1 == nowY){
        nx = nowX-1;
        ny = nowY;
    }else if(preX+1 == nowX){
        nx = nowX;
        ny = nowY+1;
    }
}

//'4'
void case7(int preX,int preY, int nowX, int nowY){
    if(preY+1 == nowY){
        nx = nowX-1;
        ny = nowY;
    }else if(preX+1 == nowX){
        nx = nowX;
        ny = nowY-1;
    }
}

void copyVisit(int a[][30], int b[][30]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}


void findFirst(int y,int x){
    for (int i = 0; i < 8; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(isposs(yy, xx) && map[yy][xx] != '.'){
            ny = yy;
            nx = xx;
            return;
        }
    }
}

bool findNumber(){
    int check[30][30];
    copyVisit(check , visited);
    findFirst(sy, sx);
    px = sx;
    py = sy;
    
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            printf("%d " , check[i][j]);
//        }
//        puts("");
//    }
//    puts("");
    
    while (1) {
        if(ny == ey && nx == ex)
            return true;

        printf("%d %d %d %d\n" , px,py,nx,ny);
        
        char letter = map[ny][nx];
        if(letter == '.' && flag == false){
            flag = true;
            pointX = nx;
            pointY = ny;
            return false;
        }
        
        check[ny][nx]--;
        if(check[ny][nx] < 0)
            return false;
        
        int preXX = nx;
        int preYY = ny;
        
        if(letter == '|')
            case1(px, py, nx, ny);
        else if(letter == '-')
            case2(px, py, nx, ny);
        else if(letter == '+')
            case3(px, py, nx, ny);
        else if(letter == '1')
            case4(px, py, nx, ny);
        else if(letter == '2')
            case5(px, py, nx, ny);
        else if(letter == '3')
            case6(px, py, nx, ny);
        else if(letter == '4')
            case7(px, py, nx, ny);
        
        px = preXX;
        py = preYY;
    }
}


int main(){
    scanf("%d %d" , &N,&M);
    for (int i = 0 ; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++) {
            scanf("%c" , &map[i][j]);
            if(map[i][j] == 'M'){
                sy = i;
                sx = j;
                visited[i][j] = 1;
            }else if(map[i][j] == 'Z'){
                ey = i;
                ex = j;
                visited[i][j] = 1;
            }else if(map[i][j] == '.'){
                visited[i][j] = -1;
            }else if(map[i][j] == '+'){
                visited[i][j] = 2;
            }else{
                visited[i][j] = 1;
            }
        }
    }
    
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c" , map[i][j]);
        }
        puts("");
    }
    puts("");
    
    
    findNumber();
//    for (int i = 0; i < 7; i++) {
//        map[pointY][pointX] = changeLetter[i];
//        if(changeLetter[i] == '+')
//            visited[pointY][pointX] = 2;
//        else
//            visited[pointY][pointX] = 1;
//
//        if(findNumber() == true){
//            ans = i;
//            break;
//        }
//    }
//
//    printf("%d %d %c" ,pointX , pointY , changeLetter[ans]);
}
