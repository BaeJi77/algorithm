#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N,K,maxLength;
int map[10][10];
int visited[10][10];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isposs(int y,int x){
    return x >= 0 && y >= 0 && x < N && y < N;
}


void func(int n, int y, int x, int can){
    maxLength = max(maxLength, n);
    for(int i = 0 ; i < 4 ; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];

        if(!isposs(yy, xx))
            continue;

        if(map[y][x] > map[yy][xx] && !visited[yy][xx]){
            visited[yy][xx] = 1;
            func(n+1, yy, xx, can);
            visited[yy][xx] = 0;
        } else if (can == 1 && !visited[yy][xx] && map[y][x] <= map[yy][xx] && map[y][x] > map[yy][xx] - K) {
            visited[yy][xx] = 1;
            int temp = map[yy][xx];
            map[yy][xx] = map[y][x] - 1;
            visited[yy][xx] = 1;
            func(n+1, yy, xx, can-1);
            visited[yy][xx] = 0;
            map[yy][xx] = temp;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t ; tc++ ){
        int topmount = -1;
        vector<pair<int,int> > top;
        scanf("%d %d" , &N, &K);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                scanf("%d" , &map[i][j]);
                topmount = max(topmount, map[i][j]);
            }
        }

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(topmount == map[i][j]){
                    top.push_back(make_pair(i,j));
                }
            }
        }

        maxLength = 0;
        memset(visited,0,sizeof(visited));
        for(int i = 0 ; i < top.size(); i++){
            visited[top[i].first][top[i].second] = 1;
            func(1, top[i].first, top[i].second, 1);
            visited[top[i].first][top[i].second] = 0;
        }

        printf("#%d %d\n", tc, maxLength);
    }
}