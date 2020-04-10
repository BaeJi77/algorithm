#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N;
char map[10][10];

bool isPoss(int y, int x) {
    return 1 <= y && y <= 6 && 1 <= x && x <= 6; 
}

int goLeft(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goLeft(color, y, x - 1);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}
int goRight(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goRight(color, y, x + 1);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}
int goUp(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goUp(color, y - 1, x);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}
int goDown(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goDown(color, y + 1, x);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}

int goLeftUp(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goLeftUp(color, y - 1, x - 1);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}

int goLeftDown(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goLeftDown(color, y + 1, x - 1);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}
int goRightUp(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goRightUp(color, y - 1, x + 1);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}
int goRightDown(char color, int y, int x) {
    if(isPoss(y, x) == false) return 0;
    if(map[y][x] == '.') return 0;
    if(map[y][x] == color) return 1;

    int ret = goRightDown(color, y + 1, x + 1);
    if(ret == 1)
        map[y][x] = color;
    
    return ret;
}

void printingColor(char color, int y, int x) {
    goLeft(color, y, x - 1);
    goRight(color, y, x + 1);
    goUp(color, y - 1, x);
    goDown(color, y + 1, x);
    goLeftUp(color, y - 1, x - 1);
    goRightUp(color, y - 1, x + 1);
    goLeftDown(color, y + 1, x - 1);
    goRightDown(color, y + 1, x + 1);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    for(int i = 1 ; i <= 6 ; ++i)
        for(int j = 1 ; j <= 6 ; ++j)
            map[i][j] = '.';
    map[3][3] = 'W'; map[4][4] = 'W';
    map[3][4] = 'B'; map[4][3] = 'B';

    scanf("%d", &N);
    for(int i = 1 ; i <= N ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        // i가 홀수 일때 흑
        char color = i % 2 ? 'B' : 'W';
        map[a][b] = color;
        printingColor(color, a, b);
    }

    int bcnt = 0;
    int wcnt = 0;
    for(int i = 1 ; i <= 6 ; ++i) {
        for(int j = 1 ; j <= 6 ; ++j) {
            printf("%c", map[i][j]);
            if(map[i][j] == 'B') bcnt++;
            else if(map[i][j] == 'W') wcnt++;
        }
        puts("");
    }
    
    if(bcnt > wcnt) printf("Black");
    else printf("White");
}