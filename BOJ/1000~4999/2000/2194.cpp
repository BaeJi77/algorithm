#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, M, K, A, B;
int sy, sx, ey, ex;
int map[510][510];
bool visited[510][510];

const int dy[] ={0,0,1,-1};
const int dx[] ={1,-1,0,0};

bool isPoss(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

int bfs(int startY, int startX) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(startY, startX));
    visited[startY][startX] = true;

    int cnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();
            
            if(y == ey && x == ex) return cnt;
            
            for(int i = 0 ; i < 4 ; i++) {
                // 0 => 오른, 1 => 왼, 2 => 위, 3 => 아래
                int yy = y + dy[i];
                int xx = x + dx[i];

                bool notOk = false;
                // for(int j = yy ; j < yy + A ; j++) {
                //     for(int k = xx ; k < xx + B ; k++) {
                //         if(isPoss(j, k) == false || map[j][k]) {
                //             notOk = true;
                //             break;
                //         }
                //     }
                //     if(notOk) break;
                // }

                if(visited[yy][xx]) continue;
                if(i == 0) {
                    int rightPoint = xx + B - 1;
                    for(int j = y ; j < y + A ; j++) {
                        if(isPoss(j, rightPoint) == false || map[j][rightPoint]) {
                            notOk = true;
                            break;
                        }
                    }
                } else if(i == 1) {
                    for(int j = y ; j < y + A ; j++) {
                        if(isPoss(j, xx) == false || map[j][xx]) {
                            notOk = true;
                            break;
                        }
                    }
                } else if(i == 2) {
                    int downPoint = yy + A - 1;
                    for(int j = x ; j < x + B ; j++) {
                        if(isPoss(downPoint, j) == false || map[downPoint][j]) {
                            notOk = true;
                            break;
                        }
                    }
                } else if(i == 3) {
                    for(int j = x ; j < x + B ; j++) {
                        if(isPoss(yy, j) == false || map[yy][j]) {
                            notOk = true;
                            break;
                        }
                    }
                }

                if(notOk) continue;
                else {
                    visited[yy][xx] = true;
                    qu.push(make_pair(yy, xx));
                }
            }
        }
        cnt++;
    }

    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d %d %d", &N, &M, &A, &B, &K);
    for(int i = 0 ; i < K ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    scanf("%d %d", &sy, &sx);
    scanf("%d %d", &ey, &ex);

    printf("%d", bfs(sy, sx));
}