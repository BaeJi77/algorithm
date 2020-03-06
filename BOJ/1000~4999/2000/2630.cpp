#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int map[130][130];
int blue, white;

void cal(int xstart, int xend, int ystart, int yend) {
    int blueCnt = 0;
    int whiteCnt = 0;
    for(int i = ystart; i < yend ; i++) {
        for(int j = xstart ; j < xend ; j++) {
            if(map[i][j]) blueCnt++;
            else whiteCnt++;
        }
    }

    if(blueCnt == 0) white++;
    else if(whiteCnt == 0) blue++;
    else {
        int xmid = (xstart + xend) / 2;
        int ymid = (ystart + yend) / 2;
        cal(xstart, xmid, ystart, ymid);
        cal(xstart, xmid, ymid, yend);
        cal(xmid, xend, ystart, ymid);
        cal(xmid, xend, ymid, yend);
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    cal(0, N, 0, N);
    printf("%d\n%d", white, blue);
}