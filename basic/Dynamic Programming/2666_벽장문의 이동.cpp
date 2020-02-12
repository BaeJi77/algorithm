#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N,p,q,order[24],K;
int cache[24][24][24];

int func(int idx, int left, int right){
    if(idx == K){
        return 0;
    }

    int& ret = cache[idx][left][right];
    if(ret != -1)
        return ret;
    
    //왼쪽, 오른쪽, order[idx]와 비교
    ret = min(func(idx+1, order[idx], right) + abs(left - order[idx]), func(idx+1, left, order[idx]) + abs(right - order[idx]));
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d %d", &p, &q);
    scanf("%d", &K);
    for(int i = 0 ; i < K; i++){
        scanf("%d", &order[i]);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d", func(0, p, q));
}