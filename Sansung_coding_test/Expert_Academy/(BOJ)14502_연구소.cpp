#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N,M,ans;
int map[10][10];
bool visited[10][10];
vector<pair<int, int> > vt;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

bool isposs(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < M;
}

void copyMap(int preMap[][10], int newMap[][10]){
    for(int i = 0 ; i < N ; i++ ){
        for(int j = 0 ; j < M ; j++){
            newMap[i][j] = preMap[i][j];
        }
    }
}

void dfs(int y, int x){
    map[y][x] = 2;
    for(int i = 0 ; i < 4 ; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(isposs(yy,xx) && map[yy][xx] == 0){
            
            dfs(yy,xx);
        }
    }
}

void printMap(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            printf("%d " , map[i][j] );
        }
        puts("");
    }
    puts("");
}

//전체 맵에 바이러스들이 퍼지도록 남은 공간을 계산해서 리턴
int cal(){
    int temp[10][10];
    // printMap();    
    copyMap(map, temp);
    for(int i = 0 ; i < vt.size(); i++){
        dfs(vt[i].first, vt[i].second);
    }  
    
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 0)
                cnt++;
        }
    }

    // printMap();    
    copyMap(temp,map);
    return cnt;
}



//재귀로 맵 카피해서 계속
void solve(int k){
    if(k == 3){
        if(ans < cal()){
            ans = max(ans , cal());
            // printf("%d\n", ans);
        }
        return;
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] != 0)
                continue;
            
            map[i][j] = 1;
            solve(k+1);
            map[i][j] = 0;
        }
    }
}


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2)
                vt.push_back(make_pair(i,j));
        }
    }

    solve(0);
    printf("%d\n", ans);
}