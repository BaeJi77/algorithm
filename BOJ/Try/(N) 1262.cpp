#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, R1, C1, R2, C2;
char map[60][60];

/*
N = 5
....e....
...ede...
..edcde..
.edcbcde.
edcbabcde
.edcbcde.
..edcde..
...ede...
....e....
*/

// void printAlpha(int y, int sx, int ex) {
//     if(y > N) y = N - y % N;
//     for(int i = sx ; i <= ex ; i++) {
//         if(N - y)
//     }
// }

void init() {
    char main = 'a' + N - 1;
    for(int i = 1 ; i <= 2 * N - 1; i++) {
        for(int j = 1; j <= N; j++) {
            if(N - i - j < 0) {
                map[i][j] = main;
            }
            else map[i][j] = '.';
        }

        for(int j = N + 1; j <= 2 * N - 1; j++) {
            if(N - i + j < 0) {
                map[i][j] = main - N - i - j;
            }
            else map[i][j] - '.';
        }
    }

    for(int i = 1 ; i <= 2 * N - 1; i++) {
        for(int j = 1; j <= 2 * N - 1; j++) {
            printf("%c", map[i][j]);
        }
        puts("");
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d %d %d", &N, &R1, &C1, &R2, &C2);
    init();
}