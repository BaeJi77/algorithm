#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];
vector<int> vt;
set<int> st;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

bool isposs(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

int bfs(int nowMin, int nowMax) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > qu;
    if(nowMin <= map[0][0] && map[0][0] <= nowMax) {
        qu.push(make_pair(0, 0));
        visited[0][0] = true;
    }
    bool ans = false;

    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();

            if(y == N-1 && x == N-1) {
                ans = true;
                break;
            }


            for(int i = 0 ; i < 4 ; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(!isposs(yy, xx)) continue;
                if(visited[yy][xx]) continue;
                if(map[yy][xx] < nowMin || map[yy][xx] > nowMax) continue;

                visited[yy][xx] = true;
                qu.push(make_pair(yy, xx));
            }
        }
        if(ans)
            break;
    }
    return ans;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)  {
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &map[i][j]);
            st.insert(map[i][j]);
        }
    }

    for(auto i = st.begin(); i != st.end(); i++) {
        vt.push_back(*i);
    }

    sort(vt.begin(), vt.end());
    int j = 0;
    int ans = 1e9;
    for(int i = 0 ; i < vt.size(); i++) {
        while(1) {
            bool findIt = bfs(vt[j], vt[i]);
            if(!findIt) 
                break;
            
            ans = min(ans, vt[i] - vt[j]);
            j++;
        }
    }
    printf("%d", ans);
}