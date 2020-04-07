#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int map[20][20];

bool check3x3Map(int sy, int sx) {
    bool visited[10] = {0,};
    for(int i = sy ; i < sy + 3; i++) {
        for(int j = sx ; j < sx + 3; j++) {
            if(visited[map[i][j]]) return false;
            else visited[map[i][j]] = true;
        }
    }
    return true;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t ; tc++) {
        bool isOk = true;
        for(int i = 1; i <= 9 ; i++) {
            for(int j = 1; j <= 9 ; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for(int i = 1 ; i <= 9 ; i++) {
            if(!isOk) break;
            bool visited[10] = {0,};
            for(int j = 1 ; j <= 9 ; j++) {
                if(visited[map[i][j]]) isOk = false;
                else visited[map[i][j]] = true;
            }
        }

        for(int i = 1 ; i <= 9 ; i++) {
            if(!isOk) break;
            bool visited[10] = {0,};
            for(int j = 1 ; j <= 9 ; j++) {
                if(visited[map[j][i]]) isOk = false;
                else visited[map[j][i]] = true;
            }
        }

        for(int i = 1 ; i <= 9 ; i += 3) {
            if(!isOk) break;
            for(int j = 1 ; j <= 9 ; j += 3) {
                isOk = check3x3Map(i, j);
            }
        }

        if(isOk) printf("Case %d: CORRECT\n", tc);
        else printf("Case %d: INCORRECT\n", tc);
    }
}