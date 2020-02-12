#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int box[1004];
int cache[1004][1004]; // 현재위치가 idx이고 이전 preNumber을 넣었을 때 최대로 상자를 넣는 경우

int func(int idx, int preNumber){
    if(idx == N)
        return 0;
    // printf("%d %d\n", idx, preNumber);
    int& ret = cache[idx][preNumber];
    if(ret != -1)
        return ret;
    
    ret = func(idx+1, preNumber);
    if(preNumber < box[idx])
        ret = max(ret, func(idx+1, box[idx]) + 1);
    
    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &box[i]);
    }
    memset(cache, -1, sizeof(cache));
    printf("%d", func(0, 0));
}
