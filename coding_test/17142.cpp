#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 987654321;

int N, M;
int map[51][51];
vector<pair<int ,int> > virus;
vector<pair<int, int> > pos;
int tempMap[51][51];
int ans = MAX;
bool visited[51][51];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool isposs(int y, int x) {
    return x>=0&&y>=0&&y<N&&x<N;
}

int bfs() {
    // temp 맵을 가져와서 마킹함.
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            tempMap[i][j] = map[i][j];
        }
    }

    int temp[51][51];
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            temp[i][j] = map[i][j];
        }
    }

    int ret = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > qu;
    for(int i = 0 ; i < pos.size(); i++) {
        qu.push(make_pair(pos[i].first, pos[i].second));
        visited[pos[i].first][pos[i].second] = true;
    }

    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();
            temp[y][x] = ret;

            for(int i = 0 ; i < 4 ;i++) {
                int yy = dy[i] + y;
                int xx = dx[i] + x;
                if(!isposs(yy, xx)) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] == 0) {
                    visited[yy][xx] = true;
                    qu.push(make_pair(yy, xx));
                }
            }
        }
        ret++;
    }

    return ret;
}

bool checkMap() {
    // 모두 0이 있는지 없는지 체크;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            if(visited[i][j] == false && tempMap[i][j] != 1) {
                if(tempMap[i][j] == 2)
                    continue;
                return false;
            }
                
        }
    }
    return true;
}

void dfs(int idx, int cnt, int limit) {
    // printf("%d %d %d\n", idx, cnt, limit);

    if(cnt == limit) {
        // 이젠 bfs 바이러스 번지개 하기
        int bfsTime = bfs();
        bool checkAllVirus = checkMap();
        //cout<<bfsTime<<" "<<checkAllVirus<<endl;
        if(checkAllVirus && bfsTime < ans) {
            ans = bfsTime;
        }
        return;
    } else {
        if(idx == virus.size()){
            return;
        }

        pos.push_back(make_pair(virus[idx].first, virus[idx].second));
        dfs(idx + 1, cnt + 1, limit);
        pos.pop_back();
        dfs(idx + 1, cnt, limit);
    }
    return;
}


int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    dfs(0, 0, M);
    printf("%d", ans == MAX ? -1 : ans - 1);
}