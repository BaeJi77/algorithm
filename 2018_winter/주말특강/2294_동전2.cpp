#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;

const int INF = 987654321;

int N,K,coin[104];
int cache[100004]; // 이 가격에서 0으로 가는데 최소 동전의 수

int solve(int cost){
    if(cost == 0)
        return 0;
    else if(cost < 0)    
        return INF;
    
    int& ret = cache[cost];
    if(ret != -1)
        return ret;
    
    ret = INF;
    for(int i = N-1 ; i >= 0 ; i--){
        ret = min(ret , solve(cost - coin[i]) + 1);
    }
    
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" , &N, &K);
    memset(cache,-1,sizeof(cache));
    for(int i = 0 ; i < N ;i++){
        scanf("%d" , &coin[i]);
    }

    int ans = solve(K);
    printf("%d\n" , ans == INF ? -1 : ans);
}