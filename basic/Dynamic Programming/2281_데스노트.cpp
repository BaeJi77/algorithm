#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M;
int cache[1001][1001];
int word[1001];

int func(int idx, int x){
    if(idx == N)
        return 0;
    
    int& ret = cache[idx][x];
    if(ret != -1)
        return ret;
    
    ret = func(idx + 1 , word[idx]) + pow(M - x, 2); // 다음 줄에 쓰기
    if(x + 1 + word[idx] <= M) // 현재 줄에 쓰기
        ret = min(ret, func(idx + 1, x + 1 + word[idx]));
    
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &word[i]);
    memset(cache, -1, sizeof(cache));
    printf("%d", func(1, word[0]));
}