#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M;
int map[60][60];
bool visited[60][60];

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

bool isPoss(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

int dfs(int y, int x, int first, int depth, int fy, int fx) {
    int ret = 0;
    visited[y][x] = true;
    
    for(int i = 0 ; i < 4 ; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!isPoss(yy, xx)) continue;
        if(map[yy][xx] != first) continue;
        if(depth>= 4 && yy == fy && xx == fx) {
            return 1;
        }
        if(visited[yy][xx]) continue;
        ret += dfs(yy, xx, first, depth + 1 , fy, fx);
    }
    
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            char a = getchar();
            map[i][j] = a - 'A';
        }
    }

    int ans = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            memset(visited, 0, sizeof(visited));
            ans += dfs(i, j, map[i][j], 1, i, j);
        }
    }

    if(ans) printf("Yes");
    else printf("No");
}