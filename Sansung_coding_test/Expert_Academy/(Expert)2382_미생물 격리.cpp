#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct worm{
    int x;
    int y;
    int n;
    int d;
    worm(int x,int y, int n, int d):x(x), y(y), n(n), d(d){};
};

int N,M,K,ans;
queue<worm> qu; // first.first: y좌표 , first.second: x좌표, second.first: 미생물 수, second.second: 방향
int map[104][104][5];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
//상: 1, 하: 2, 죄: 3, 우: 4
//큐에 넣어서 한 타임이 지날때마다 map에 작성을 하고 

void cal() {
    ans = 0;
    for(int i = 0 ; qu.size() ; i++){
        ans += qu.front().n;
        qu.pop();
    }
}

int changeDir(int dir){
    if(dir <= 2){
        return dir == 1 ? 2 : 1;
    } else {
        return dir == 3 ? 4 : 3;
    }
}

//미생물의 수 반절로 줄이고, 방향 바꿔주기
void makeHalfWorm(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 1 ; j < 5 ; j++){
            if(map[i][0][j] != 0){
                int temp = map[i][0][j] / 2;
                map[i][0][j] = 0;
                map[i][0][changeDir(j)] = temp;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(map[0][i][j] != 0){
                int temp = map[0][i][j] / 2;
                map[0][i][j] = 0;
                map[0][i][changeDir(j)] = temp;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(map[i][N-1][j] != 0){
                int temp = map[i][N-1][j] / 2;
                map[i][N-1][j] = 0;
                map[i][N-1][changeDir(j)] = temp;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(map[N-1][i][j] != 0){
                int temp = map[N-1][i][j] / 2;
                map[N-1][i][j] = 0;
                map[N-1][i][changeDir(j)] = temp;
            }
        }
    }
}

void dfs(int t) {
    if(t == M){
        //현재 남은 미생물 계산
        cal();
        return;
    }

    memset(map,0,sizeof(map));
    //map에 미생물들의 다음 목적지를 보냄. 미생물을 처리되는 경우 반절을 저장 방향을 바꿔줌
    for(int i = 0 ; i < qu.size(); i++){
        int dir = qu.front().d;
        int x = qu.front().x + dx[dir];
        int y = qu.front().y + dy[dir];
        int n = qu.front().n;
        map[y][x][dir] += n;
        qu.pop();
    }

    int tempMap[104][104] = {0,};
    //map을 보고 합쳐진 경우 어느방향으로 갈지 결정. 다시 큐에 넣고 다음 단계로 이동
    makeHalfWorm();
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            bool checkExist = false;;
            int sum = 0;
            int dir = 0;
            int maxDir = 0;
            for(int k = 1 ; k < 5 ; k++){
                sum += map[i][j][k];
                if(maxDir < map[i][j][k]) {
                    dir = k;
                    maxDir = map[i][j][k];
                    checkExist = true;
                }
            }
            tempMap[i][j] = sum;

            if(checkExist){
                qu.push(worm(i,j,sum,dir));
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d ", map[i][j]);
        }
        puts("");
    }
    puts("");

    dfs(t+1);
    return;
}

int main(){
    freopen("input.txt","r",stdin);
    int test;
    scanf("%d" , &test);
    for(int tc = 1 ; tc <= test ; tc++){
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0 ; i < K ; i++){
            int a,b,c,d;
            scanf("%d %d %d %d", &a,&b,&c,&d);
            qu.push(worm(a,b,c,d));
        }
        dfs(0);
        printf("#%d %d\n", tc, ans);
    }
}