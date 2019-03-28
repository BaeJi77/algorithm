#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N,S,M;
int arr[101];
int cache[101][1001];

int func(int idx, int volume){
    if(volume < 0 || volume > M)
        return -INF;
    printf("%d %d\n", idx, volume);
    if(idx == N)
        return volume;
    
    int& ret = cache[idx][volume];
    if(ret != -1)
        return ret;
    
    ret = max(func(idx+1, volume + arr[idx]), func(idx+1, volume - arr[idx]));
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &N, &S, &M);
    memset(cache,-1,sizeof(cache));
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &arr[i]);
    }

    int ans = func(0, S);
    printf("%d", ans == -INF ? -1 : ans);
}