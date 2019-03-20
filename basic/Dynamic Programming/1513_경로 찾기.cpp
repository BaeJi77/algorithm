#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000007;

int N,M,K;
vector<pair<int, int> > vt;
int cache[51][51][51][51];
int map[51][51];

//remain는 남은 방문 애들, recent는 최근 방문한 오락실 번호
int func(int x, int y, int remain, int recent){
    if(y > M || x > N)
        return 0;

    int& ret = cache[x][y][remain][recent];
    if(ret != -1)
        return ret;
    
    if(y == M && x == N){
        if(map[x][y] == 0)
            return remain == 0 ? 1 : 0;
        else if(map[x][y] != 0 && remain == 1 && map[x][y] > recent)
            return 1;
        else 
            return 0;
    }

    if(map[x][y] != 0){ // 다음 방문해야할 오락실 발견
        if(remain == 0 || recent > map[x][y]) 
            return ret = 0;
        remain--;
        recent = map[x][y];
    }
    
    ret = func(x + 1, y, remain, recent) % MOD + func(x , y + 1, remain, recent) % MOD;
    ret %= MOD;
    return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0;  i < K ; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        map[a][b] = i+1;
    }
    memset(cache,-1,sizeof(cache));

    for(int i = 0 ; i <= K ; i++){
        printf("%d ", func(1, 1, i, 0) % MOD);
    }
}