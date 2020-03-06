#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
char map[51][51];
int ans[20];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M; j++) {
            map[i][j] = getchar();
        }
    }

    int order = 1;
    for(int i = M-1 ; i >= 1 ; i--) {
        bool existRankTeam = false;
        for(int j = 0 ; j < N ; j++) {
            if('1' <= map[j][i] && map[j][i] <= '9' && ans[map[j][i] - '0'] == 0) {
                ans[map[j][i] - '0'] = order;
                existRankTeam = true;
            }
        }
        if(existRankTeam)
            order++;
    }

    for(int i = 1 ; i < 10 ; i++)
        printf("%d\n", ans[i]);
}