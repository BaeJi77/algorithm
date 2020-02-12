#include <cstdio>
#include <cstdlib>

using namespace std;

int N,M;
int sy,sx,dir,cnt;
int map[54][54];
bool visited[54][54];

//0은 북, 1은 동, 2은 남, 3은 서
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

bool isposs(int y, int x){
    return x >= 0 && y >= 0 && x < M && y < N;
}

void dfs(int y, int x, int dir){
    if(map[y][x] == 0){
        cnt++;
        map[y][x] = cnt;
    }
    
    int nextDir = dir;
    for(int i = 0 ; i < 4 ; i++){
        nextDir = nextDir < 1 ? 3 : nextDir - 1;
        int xx = x + dx[nextDir];
        int yy = y + dy[nextDir];
        
        if(isposs(yy,xx) && map[yy][xx] == 0){
            dfs(yy, xx, nextDir);
        }
    }
    
    nextDir = (dir+2)%4;
    int yy = y+dy[nextDir];
    int xx = x+dx[nextDir];
    // printf("%d %d %d %d %d %d\n", y, x, dir, y+dy[nextDir], x+dx[nextDir], nextDir);
    if(map[yy][xx] != 1){
        dfs(yy, xx,  dir);
    } else {
        printf("%d\n", cnt);
        exit(0);
        return;
    }
}

void printMap(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            printf("%2d " , map[i][j]);
        }
        puts("");
    }
    puts("");
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &sy, &sx, &dir);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%d", &map[i][j]);
        }
    }
    dfs(sy, sx, dir);
    printf("%d\n", cnt);
    // printMap();   
}