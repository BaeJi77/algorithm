#include <cstdio>
#include <algorithm>

using namespace std;

int map[101];
int N,M;

int sol(int X, int Y) {
    int ret = 0;
    // 시작 지점 인덱스
    for(int i = 0 ; i < N ; i++) {
        int Z = 0;
        for(int j = 0 ; j < M ; j++) {
            Z *= 10;
            Z += map[(i + j) % N];
        }
        if(X <= Z && Z <= Y)
            ret++;
    }

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &N, &M);
        int X = 0;
        int Y = 0;
        for(int i = 0 ; i < M ; i++) {
            X *= 10;
            int k;
            scanf("%d", &k);
            X += k;
        }

        for(int i = 0 ; i < M ; i++) {
            Y *= 10;
            int k;
            scanf("%d", &k);
            Y += k;
        }

        for(int i = 0 ; i < N ; i++) 
            scanf("%d", &map[i]);

        printf("%d\n", sol(X, Y));
    }
}