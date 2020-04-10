#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
char map[3010][3010];
char ans[3010][3010];

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i) {
        getchar();
        for(int j = 0 ; j < M ; ++j) {
            scanf("%c", &map[i][j]);
        }
    }
    
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            if(map[i][j] == '#') ans[i][j] = '#';
            else ans[i][j] = '.';
        }
    }

    int minDownValue = 3001;
    for(int i = 0 ; i < M ; ++i) {
        int xbottonIdx = -1;
        int shopTopIdx = 0;
        for(int j = 0 ; j < N ; ++j) {
            if(map[j][i] == 'X') xbottonIdx = j;
            if(map[j][i] == '#') {
                shopTopIdx = j;
                break;
            }
        }
        if(xbottonIdx == -1) continue;

        minDownValue = min(minDownValue, shopTopIdx - xbottonIdx - 1);
    }
    
    for(int i = 0 ; i < N; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            if(map[i][j] == 'X') ans[i + minDownValue][j] = 'X';
        }
    }

    for(int i = 0 ; i < N; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            printf("%c", ans[i][j]);
        }
        puts("");
    }
}