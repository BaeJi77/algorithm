#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N,stair[304];
int cache[304][3];

int solve(int cur, int conti){
    if(cur < 0)
        return -INF;
    if(conti == 3 && cur != 0)
        return -INF;
        
    if(cur == 0)
        return 0;

    int& ret = cache[cur][conti];
    if(ret != -1)
        return ret;

    ret = solve(cur-2, 1) + stair[cur];
    if(conti <= 2)
        ret = max(ret, solve(cur-1, conti+1)+stair[cur]);
    
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d", &stair[i]);
    }

    memset(cache,-1,sizeof(cache));
    printf("%d", solve(N, 1));
}