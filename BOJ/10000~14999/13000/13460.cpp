#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int N, M;
int fry, frx, fby, fbx;
char map[20][20];
bool redVisited[20][20];
bool blueVisited[20][20];

pair<int, int> movePoint(int direction, int ty, int tx, int by, int bx) {
    // direction: 0, 1, 2, 3 => 동 서 남 북
    if(direction == 0) {
        while(1) {
            if(map[ty][tx + 1] == 'O') {
                tx++; break;
            }
            if((tx + 1 == bx && by == ty) || map[ty][tx + 1] == '#') break;
            tx++;
        }
    } else if (direction == 1) {
        while(1) {
            if(map[ty][tx - 1] == 'O') {
                tx--; break;
            }
            if((tx - 1 == bx && by == ty )|| map[ty][tx - 1] == '#') break;
            tx--;
        }
    } else if (direction == 2) {
        while(1) {
            if(map[ty + 1][tx] == 'O') {
                ty++; break;
            }
            if((ty + 1 == by && bx == tx) || map[ty + 1][tx] == '#') break;
            ty++;
        }
    } else if (direction == 3) {
        while(1) {
            if(map[ty - 1][tx] == 'O') {
                ty--; break;
            }
            if((ty - 1 == by && bx == tx) || map[ty - 1][tx] == '#') break;
            ty--;
        }
    }

    return make_pair(ty, tx);
}

int bfs() {
    int cnt = 0;
    bool isNotOk = false;
    queue<pair<pair<int, int>, pair<int, int> > > qu;
    qu.push(make_pair(make_pair(fry, frx), make_pair(fby, fbx)));
    redVisited[fry][frx] = true;
    blueVisited[fby][fbx] = true;

    while(int s = qu.size()) {
        // s /= 2;
        bool isNormalOk = false;
        while(s--) {
            bool redOk = false;
            bool blueOk = false;
            int ry = qu.front().first.first;
            int rx = qu.front().first.second;

            int by = qu.front().second.first;
            int bx = qu.front().second.second;
            qu.pop();

            if(map[ry][rx] == 'O') redOk = true;
            if(map[by][bx] == 'O') blueOk = true;
            if(redOk) {
                if(blueOk == false) {
                    isNormalOk = true;
                    break;
                }
                continue;
            }
            if(blueOk) continue;

            for(int i = 0 ; i < 4 ; i++) {
                // 동 서 남 북 이동
                pair<int, int> redPoint;
                pair<int, int> bluePoint;
                if(i == 0) {
                    if(rx > bx) { // red 먼저
                        redPoint = movePoint(i, ry, rx, by, bx);
                        bluePoint = movePoint(i, by, bx, redPoint.first, redPoint.second);
                    } else {
                        // blue 먼저
                        bluePoint = movePoint(i, by, bx, ry, rx);
                        redPoint = movePoint(i, ry, rx, bluePoint.first, bluePoint.second);
                    }
                } else if(i == 1) {
                    if(rx > bx) {
                        // blue 먼저
                        bluePoint = movePoint(i, by, bx, ry, rx);
                        redPoint = movePoint(i, ry, rx, bluePoint.first, bluePoint.second);
                    } else {
                        // red 먼저
                        redPoint = movePoint(i, ry, rx, by, bx);
                        bluePoint = movePoint(i, by, bx, redPoint.first, redPoint.second);
                    }
                } else if (i == 2) {
                    if(ry > by) {
                        // red 먼저
                        redPoint = movePoint(i, ry, rx, by, bx);
                        bluePoint = movePoint(i, by, bx, redPoint.first, redPoint.second);
                        
                    } else {
                        // blue 먼저
                        bluePoint = movePoint(i, by, bx, ry, rx);
                        redPoint = movePoint(i, ry, rx, bluePoint.first, bluePoint.second);
                    }
                } else if (i == 3) { 
                    if(ry > by) {
                        // blue 먼저
                        bluePoint = movePoint(i, by, bx, ry, rx);
                        redPoint = movePoint(i, ry, rx, bluePoint.first, bluePoint.second);
                    } else {
                        // red 먼저
                        redPoint = movePoint(i, ry, rx, by, bx);
                        bluePoint = movePoint(i, by, bx, redPoint.first, redPoint.second);
                    }
                }
                int newRedY = redPoint.first;
                int newRedX = redPoint.second;
                int newBlueY = bluePoint.first;
                int newBlueX = bluePoint.second;

                qu.push(make_pair(make_pair(newRedY, newRedX), make_pair(newBlueY, newBlueX)));
            }
        }
        if(isNormalOk) break;
        if(cnt == 11) break;
        cnt++;
    }

    if(cnt == 11) return -1;
    return cnt;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            scanf("%c", &map[i][j]);
            if(map[i][j] == 'B') fby = i, fbx = j, map[i][j] = '.';
            if(map[i][j] == 'R') fry = i, frx = j, map[i][j] = '.';
        }
    }

    printf("%d", bfs());
}