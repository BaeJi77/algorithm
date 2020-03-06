#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int map[54][54];
bool visited[54][54];
int altitude[54][54];
vector<int> alti;
int N, homeCnt;
int nowMin, nowMax;
pair<int, int> sp;
set<int> st;

const int dx[] = { 0,0,-1,1,-1,-1,1,1 };
const int dy[] = { -1,1,0,0,-1,1,-1,1 };

bool isposs(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N;
}

int bfs (int y, int x, int nowMin, int nowMax) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > qu;
    if(nowMin <= altitude[y][x] && altitude[y][x] <= nowMax) {
        visited[y][x] = true;
        qu.push(make_pair(y, x));
    }

    int ret = 0;
    while(int s = qu.size()) {
        while(s--) {
            int yy = qu.front().first;
            int xx = qu.front().second;
            qu.pop();

            for(int i = 0 ; i < 8 ; i++) {
                int dyy = yy + dy[i];
                int dxx = xx + dx[i];
                
                if(isposs(dyy, dxx) == false) continue;
                if(visited[dyy][dxx] == true ) continue;

                int nextAltitude = altitude[dyy][dxx];
                if(nextAltitude < nowMin || nextAltitude > nowMax) continue;
                visited[dyy][dxx] = true;
                if(map[dyy][dxx] == 1) ret++;
                qu.push(make_pair(dyy, dxx));
            }
        }
    }

    return ret;
}

int soll() {
    int ans = 1e9;
    int j = 0;
    for(int i = 0 ; i < alti.size() ; i++) {
        while(1) {
            if(j > i) break;
            memset(visited, 0, sizeof(visited));
            int eachHomeCnt = bfs(sp.first, sp.second, alti[j], alti[i]);
            if(eachHomeCnt != homeCnt)
                break;

            ans = min(ans, alti[i] - alti[j]);
            j++;
        }
    }
    return ans;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < N ; j++) {
            char in = getchar();
            if(in == 'P') {
                map[i][j] = 2;
                sp = make_pair(i, j);
            }
            if(in == 'K') {
                homeCnt++;
                map[i][j] = 1;
            }
                
            if(in == '.')
                map[i][j] = 0;
        }
    }

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &altitude[i][j]);
            alti.push_back(altitude[i][j]);
        }
    }

    sort(alti.begin(), alti.end());
    printf("%d\n", soll());
}