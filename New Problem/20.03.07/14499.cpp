#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, K;
int map[30][30];
int dice[7]; // 1은 위쪽, 6은 아랫쪽
int nowY, nowX;

bool isPoss(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

void printDice() {
    for(int i = 1 ; i <= 6 ; i++)
        printf("%d ", dice[i]);
    puts("");
}

void changeDice(int dir) {
    // dir = 1: 동, 2: 서, 3:북, 4: 남
    if(dir == 1) {
        int temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    } else if (dir == 2) {
        int temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    } else if (dir == 3) {
        int temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    } else if (dir == 4) {
        int temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
}

int move(int dir) { // dir: 동 서 북 남
    if(dir == 1) {
        if(!isPoss(nowY, nowX + 1))
            return -1;
        nowX++;
    } else if (dir == 2) {
        if(!isPoss(nowY, nowX - 1))
            return -1;
        nowX--;
    } else if (dir == 3) {
        if(!isPoss(nowY - 1, nowX))
            return -1;
        nowY--;
    } else if(dir == 4) {
        if(!isPoss(nowY + 1, nowX))
            return -1;
        nowY++;
    }

    changeDice(dir);
    if(map[nowY][nowX] == 0) {
        map[nowY][nowX] = dice[6];
    } else {
        dice[6] = map[nowY][nowX];
        map[nowY][nowX] = 0;
    }

    return dice[1];
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d %d %d", &N, &M, &nowY, &nowX, &K);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i = 0 ; i < K ; i++) {
        int q;
        scanf("%d", &q);
        int ret = move(q);
        if(ret == -1) continue;
        else printf("%d\n", ret);
    }
}