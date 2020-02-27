#include <cstdio>
#include <algorithm>

using namespace std;

int M,N,K;
char map[11][11];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &M, &N, &K);
    for(int i = 0 ; i < M ; i++)  {
        getchar();
        for(int j = 0 ; j < N ; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    for(int i = 0 ; i < M ; i++) {
        for(int k = 0 ; k < K ; k++) {
            for(int j = 0 ; j < N ; j++) {
                for(int kk = 0 ; kk < K ; kk++) {
                    printf("%c", map[i][j]);
                }
            }
            puts("");
        }
    }
}