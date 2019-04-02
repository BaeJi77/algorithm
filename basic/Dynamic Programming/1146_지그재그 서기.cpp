#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1e6;

int N,ans;
int cache[101][101][101];
bool visited[101];

//N-1번째 수, N-2번째 수
int func(int idx, int prepre, int pre){
    if(idx == N)
        return 1;

    // int& ret = cache[idx][prepre][pre];
    // if(ret != -1)
    //     return ret;
    
    int ret = 0;
    if(prepre < pre){
        for(int i = pre-1 ; i >= 1 ; i--){  
            if(visited[i])
                continue;
            visited[i] = true;
            ret += func(idx+1, pre, i) % MOD;
            ret %= MOD;
            visited[i] = false;
        }
    }else if(prepre > pre){
        for(int i = pre+1 ; i <= N ; i++){
            if(visited[i])
                continue;
            visited[i] = true;
            ret += func(idx+1, pre, i);
            ret %= MOD;
            visited[i] = false;
        }
    }
    // for(int i = 1 ; i <= N ; i++){
    //     if(visited[i])
    //         continue;
    //     if(prepre < pre && pre > i) { // pre보다 더 작은 사람
    //         visited[i] = true;
    //         ret += func(idx+1, pre, i) % MOD;
    //         ret %= MOD;
    //         visited[i] = false;
    //     }else if(prepre > pre && pre < i){
    //         visited[i] = true;
    //         ret += func(idx+1, pre, i);
    //         ret %= MOD;
    //         visited[i] = false;
    //     }
    // }

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    memset(cache,-1,sizeof(cache));
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(i == j)
                continue;
            visited[i] = true;
            visited[j] = true;
            ans += func(2, i, j) % MOD;
            visited[i] = false;
            visited[j] = false;
            ans %= MOD;
        }
    }
    printf("%d", ans);
}