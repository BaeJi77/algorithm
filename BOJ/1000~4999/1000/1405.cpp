#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
double per[4]; //동 서 남 북
bool visitied[100][100];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

double dfs(int y, int x, int cnt) {
    if(cnt == 0) return 1.0;

    visitied[y][x] = true;
    double ret = 0;
    for(int i = 0 ; i <  4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(visitied[yy][xx]) continue;
        ret += dfs(yy, xx, cnt - 1) * per[i];
    }
    visitied[y][x] = false;

    return ret;
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < 4 ; i++) {
        int k;
        scanf("%d", &k);
        per[i] = (double)k/100;
    }   
    printf("%.9lf", dfs(50, 50, N));
}