#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N;
int student[1001];
int cache[1001];

int func(int l, int r, int maxx, int minn){
    if(l == N || r == N){
        return 0;
    }

    int& ret = cache[l];
    if(ret != -1)
        return ret;
    
    maxx = max(maxx, student[r]);
    minn = min(minn, student[r]);

    return ret = max(func(l, r+1, maxx, minn), func(r+1, r+1, -INF, INF) + maxx - minn);
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &student[i]);
    }
    memset(cache, -1, sizeof(cache));
    printf("%d", func(0, 0, -INF, INF));
}