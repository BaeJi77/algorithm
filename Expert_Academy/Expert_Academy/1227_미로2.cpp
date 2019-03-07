#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int map[104][104];
bool visited[104][104];
int sy,sx,ey,ex;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int isposs(int y, int x){
    return x >= 0 && y >= 0 && x < 100 && y < 100;
}

bool bfs(int y, int x){
    queue<pair<int, int> > qu;
    memset(visited,0,sizeof(visited));
    visited[y][x] = true;
    qu.push(make_pair(y,x));
    while(int s = qu.size()){
        while(s--){
            int yy = qu.front().first;
            int xx = qu.front().second;
            qu.pop();

            if(ey == yy && ex == xx)
                return true;

            for(int i = 0 ; i < 4 ; i++){
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if(isposs(ny, nx) && !visited[ny][nx] && map[ny][nx] != 1){
                    qu.push(make_pair(ny, nx));
                    visited[ny][nx] = 1;
                }
            }
        }
    }
    return false;
}

int main(){
    int n;
    freopen("input.txt", "r", stdin);
    while(scanf("%d" , &n) != EOF){
        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j < 100 ; j++){
                scanf("%1d", &map[i][j]);
                if(map[i][j] == 2){
                    sy = i;
                    sx = j;
                } else if (map[i][j] == 3){
                    ey = i;
                    ex = j;        
                }
            }
        }

        printf("#%d %d\n" , n, bfs(sy, sx));
    }
}

