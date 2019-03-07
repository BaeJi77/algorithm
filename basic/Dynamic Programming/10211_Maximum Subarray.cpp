#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = -987654321;

int arr[1004],N;
int psum[1004], cache[1004];

int solve(int cur){
    // printf("%d %d\n" , cur, cache[cur]);
    if(cur == N){
        return 0;
    }
    
    int& ret = cache[cur];
    if(ret != INF)
        return ret;
    // printf("%d %d\n" , cur, ret);
    ret = max(arr[cur] , solve(cur+1) + arr[cur]);
    
    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d" , &T);
    while(T--){
        int ans = INF;
        scanf("%d" , &N);
        for(int i = 0 ; i < N ; i++){
            scanf("%d", &arr[i]);
            cache[i] = INF;
        }
        solve(0);
        for(int i = 0 ; i < N ; i++){
            ans = max(ans, cache[i]);
        }
        printf("%d\n" , ans);
    }
}