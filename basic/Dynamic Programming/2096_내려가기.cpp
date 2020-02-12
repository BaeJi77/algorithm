#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N, map[100001][3];
int cache[100001][3];

int maxFunc(int y, int x){
    if(y == N)
        return 0;

    int& ret = cache[y][x];
    if(ret != -1)
        return ret;

    ret = maxFunc(y+1, x); // 그냥 내려감
    if(x == 0) {
        ret = max(ret, maxFunc(y+1, 1)) + map[y][x];
    }else if(x == 1){
        ret = max(ret, max(maxFunc(y+1, 1), maxFunc(y+1, 2))) + map[y][x];
    }else if(x == 2) {
        ret = max(ret, maxFunc(y+1, 1))  + map[y][x];
    }

    return ret;
}

int minFunc(int y, int x){
    if(y == N)
        return 0;
    
    int& ret = cache[y][x];
    if(ret != -1)
        return ret;

    ret = INF;
    if(x == 0) {
        ret = min(ret, min(minFunc(y+1, 0), minFunc(y+1, 1)) + map[y][x]);
    }else if(x == 1){
        ret = min(ret, min(minFunc(y+1, 0), minFunc(y+1, 1)) + map[y][x]);
        ret = min(ret, minFunc(y+1, 2) + map[y][x]);
    }else if(x == 2) {
        ret = min(ret, max(minFunc(y+1, 1), minFunc(y+1, 2)) + map[y][x]);
    }
    
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 3 ; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    cache[0][0] = map[0][0];
    cache[0][1] = map[0][1];
    cache[0][2] = map[0][2];
    
    for(int i = 1 ; i <= N ; i++){
        cache[i][0] = max(cache[i-1][0], cache[i-1][1]) + map[i][0];
        cache[i][1] = max(cache[i-1][0], max(cache[i-1][1], cache[i-1][2])) + map[i][1];
        cache[i][2] = max(cache[i-1][1], cache[i-1][2]) + map[i][2];
    }
    int maxx = max(cache[N][0], max(cache[N][1],cache[N][2]));
    

    cache[0][0] = map[0][0];
    cache[0][1] = map[0][1];
    cache[0][2] = map[0][2];
    for(int i = 1 ; i <= N ; i++){
        cache[i][0] = min(cache[i-1][0], cache[i-1][1]) + map[i][0];
        cache[i][1] = min(cache[i-1][0], min(cache[i-1][1], cache[i-1][2])) + map[i][1];
        cache[i][2] = min(cache[i-1][1], cache[i-1][2]) + map[i][2];
    }
    int minn = min(cache[N][0], min(cache[N][1],cache[N][2]));

    printf("%d %d\n", maxx, minn);
}