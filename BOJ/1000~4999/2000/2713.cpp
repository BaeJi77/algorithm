#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M;
string str;
bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int map[30][30];
        memset(map, -1, sizeof(map));
        scanf("%d %d", &N, &M);
        getline(cin, str);
        str.erase(str.begin());
        
        int ny = 0;
        int nx = -1;
        int dir = 0; // 0 왼, 1: 아, 2: 왼, 3: 위
        for(int i = 0 ; i < str.size(); i++) {
            int alphaToNumber = str[i] == ' ' ? 0 : str[i] - 'A' + 1;
            for(int i = 1<<4 ; i >= 1 ; i = i>>1) {
                int y = ny + dy[dir];
                int x = nx + dx[dir];

                if(isPoss(y, x) == false) {
                    dir = (dir + 1) % 4;
                    y = ny + dy[dir];
                    x = nx + dx[dir];
                } else if (isPoss(y, x) && map[y][x] != -1) {
                    dir = (dir + 1) % 4;
                    y = ny + dy[dir];
                    x = nx + dx[dir];
                }
                
                map[y][x] = alphaToNumber & i ? 1 : 0;
                ny = y;
                nx = x;
            }
        }

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                if(map[i][j] != -1) printf("%d", map[i][j]);
                else printf("0");
            }
        }
        puts("");
    }
}