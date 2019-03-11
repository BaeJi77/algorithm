#include <cstdio>
#include <algorithm>

using namespace std;

int N,ans;
int map[24][24];
int maxMap[24][24];
//0 : 왼쪽, 1: 위쪽, 2: 오른쪽, 3: 아래쪽
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

/*
4개의 방향을 계속 생각하면서 계속 재귀해서 들어감
그 전 map을 복사하고 다시 돌아올때는 다시 이전 맵으로 복귀 시킴

*/

bool isposs(int y, int x){
    return x >= 0 && y >= 0 && x < N && y < N;
}

void copyMap(int preMap[][24], int newMap[][24]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
             newMap[i][j] = preMap[i][j];
        }
    }
}

void leftDir(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] == 0)
                continue;

            int y = i;
            int x = j;
            while(1){
                // if(map[y][x-1] == 0 && map[y][x] == 0)
                //     break;
                if(isposs(y, x-1) && map[y][x-1] == map[y][x]){
                    map[y][x-1] = 2*map[y][x-1];
                    map[y][x] = 0;
                }else if(isposs(y, x-1) && map[y][x-1] == 0){
                    map[y][x-1] = map[y][x];
                    map[y][x] = 0;
                } else
                    break;
                x--;
            }
        }
    }
}

void rightDir(){
    for(int i = 0 ; i < N ; i++){
        for(int j = N-1 ; j >= 0 ; j--){
            if(map[i][j] == 0)
                continue;
            
            int y = i;
            int x = j;
            while(1){
                // if(map[y][x+1] == 0 && map[y][x] == 0)
                //     break;
                if(isposs(y, x+1) && map[y][x+1] == map[y][x]){
                    map[y][x+1] = 2*map[y][x+1];
                    map[y][x] = 0;
                } else if (isposs(y, x+1) && map[y][x+1] == 0){
                    map[y][x+1] = map[y][x];
                    map[y][x] = 0;
                }else
                    break;
                x++;
            }
        }
    }
}

void topDir() {
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[j][i] == 0)
                continue;
            
            int x = i;
            int y = j;
            while(1){
                // if(map[y-1][x] == 0 && map[y][x] == 0)
                //     break;
                if(isposs(y-1, x) && map[y-1][x] == map[y][x]){
                    map[y-1][x] = 2*map[y][x];
                    map[y][x] = 0;
                    
                } else if (isposs(y-1, x) && map[y-1][x] == 0){
                    map[y-1][x] = map[y][x];
                    map[y][x] = 0;
                } else {
                    break;
                }
                y--;
            }
        }
    }
}

void downDir() {
    for(int i = 0 ; i < N ; i++){
        for(int j  = N-1 ; j >= 0 ; j--){
            if(map[j][i] == 0 )
                continue;
            
            int x = i;
            int y = j;
            while(1){
                // if(map[y+1][x] == 0 && map[y][x] == 0)
                //     break;
                if(isposs(y+1, x) && map[y+1][x] == map[y][x]){
                    map[y+1][x] = 2*map[y][x];
                    map[y][x] = 0;
                } else if(isposs(y+1, x) && map[y+1][x] == 0){
                    map[y+1][x] = map[y][x];
                    map[y][x] =0;
                }else 
                    break;
                y++;
            }
        }
    }
}

void go(int k){
    if(k == 5){
        int tempMax = -1;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                tempMax = max(tempMax, map[i][j]);
            }
        }
        ans = max(ans, tempMax);
        return;
    }

    int temp[24][24] = {0,};
    copyMap(map, temp);

    //방향 설정
    for(int i = 0 ; i < 4 ; i++){
        switch(i){
            case 0:
                leftDir();
                break;
            case 1:
                topDir();
                break;
            case 2:
                rightDir();
                break;
            case 3:
                downDir();
                break;    
            default:
                break;
        }
        go(k+1);
        copyMap(temp,map);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d" , &map[i][j]);
        }
    }

    ans = -1;
    go(0);
    printf("%d", ans);
}