#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int N,H,W,ans;
int map[20][20];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isposs(int y, int x){
    return y >= 0 && x >= 0 && y < H && x < W;
}

void breakWall(int y, int x){
    if(map[y][x] == 0)
        return;

    int d = map[y][x];
    map[y][x] = 0;
    for(int i = 1 ; i < d ; i++){
        for(int j = 0 ; j < 4 ; j++){
            int ny = y + i * dy[j];
            int nx = x + i * dx[j];

            if(isposs(ny, nx) && map[ny][nx] != 0)
                breakWall(ny, nx);
        }
    }
}

void copyMap(int cMap[][20], int newMap[][20]){
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            newMap[i][j] = cMap[i][j];
        }
    }
}

void sortMap(){
    for(int i = 0 ; i < W ; i++){
        for(int  j = H - 1 ; j >= 0 ; j--){
            int y = j;
            int x = i;
            if(map[y][x] == 0)
                continue;
            
            while(1){
                if(map[y+1][x] == 0 && isposs(y+1, x)){
                    map[y+1][x] = map[y][x];
                    map[y][x] = 0;
                    y++;
                } else {
                    break;
                }
            }
        }
    }
}

void fall(int k) {
    if(k == N){
        int cnt = 0;
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                if(map[i][j] != 0)
                    cnt++;
            }
        }
        
        ans = min(ans, cnt);
        return;
    }
    
    int temp[20][20];
    copyMap(map, temp);
    
    for(int i = 0 ; i < W ; i++){
        int y = 0;
        int x = i;
        while(isposs(y, x) && map[y][x] == 0)
            y++;

        breakWall(y, x);
        sortMap();
        fall(k+1);
        copyMap(temp, map);        
    }
}


int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    for(int tc = 1 ; tc <= t ; tc++){
        scanf("%d %d %d" , &N, &W, &H);
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                scanf("%d" , &map[i][j]);
            }
        }
        
        ans = INF;
        fall(0);
        printf("#%d %d\n" , tc, ans);
    }
}