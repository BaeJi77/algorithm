#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};

int N, visitCnt, maxVisitCnt;
char map[110][110];
bool visited[110][110];
vector<pair<int, int> > zeros;
vector<pair<int, int> > ones;
vector<pair<int, int> > twos;
vector<pair<int, int> > threes;

bool isPoss(int y, int x) {
    return y>=1 && y <= N && x>= 1 && x <= N;
}

int countShopInMap() {
    int shopCnt = 0;
    for(int i = 2 ; i <= N - 1 ; i++)
        if(map[2][i] == '#') shopCnt++;
    for(int i = 2 ; i <= N - 1 ; i++)
        if(map[N-1][i] == '#') shopCnt++;
    for(int i = 2 ; i <= N - 1 ; i++)
        if(map[i][2] == '#') shopCnt++;
    for(int i = 2 ; i <= N - 1 ; i++)
        if(map[i][N-1] == '#') shopCnt++;
    return shopCnt;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    
    for(int i = 1 ; i <= N ; i++) {
        getchar();
        for(int j = 1 ; j <= N ; j++) {
            scanf("%c", &map[i][j]);
            if(map[i][j] == '0') zeros.push_back(make_pair(i, j));
            if(map[i][j] == '1') ones.push_back(make_pair(i, j));
            if(map[i][j] == '2') twos.push_back(make_pair(i, j));
            if(map[i][j] == '3') threes.push_back(make_pair(i, j));
        }
    }

    if(N <= 2) {
        printf("0");
        return 0;
    }
    if(N == 3) {
        printf("%d", map[1][1] == '0' ? 0 : 1);
        return 0;
    }

    for(int i = 0 ; i < zeros.size() ; i++) {
        int y = zeros[i].first;
        int x = zeros[i].second;
        for(int j = 0 ; j < 8 ; j++) {
            int yy = y + dy[j];
            int xx = x + dx[j];
            if(!isPoss(yy, xx)) continue;
            if('0' <= map[yy][xx] && map[yy][xx] <= '3') continue;
            map[yy][xx] = 'X';
        }
    }

    for(int i = 0 ; i < threes.size() ; i++) {
        int y = threes[i].first;
        int x = threes[i].second;
        for(int j = 0 ; j < 8 ; j++) {
            int yy = y + dy[j];
            int xx = x + dx[j];
            if(!isPoss(yy, xx)) continue;
            if('0' <= map[yy][xx] && map[yy][xx] <= '3') continue;
            map[yy][xx] = '*';
        }
    }

    while(countShopInMap()) {
        for(int i = 0 ; i < ones.size() ; i++) {
            int nearShopCnt = 0;
            int nearStarCnt = 0;
            int y = ones[i].first;
            int x = ones[i].second;
            vector<pair<int ,int> > temp;
            for(int j = 0 ; j < 8 ; j++) {
                int yy = y + dy[j];
                int xx = x + dx[j];
                if(!isPoss(yy, xx)) continue;
                if('0' <= map[yy][xx] && map[yy][xx] <= '3') continue;
                if(map[yy][xx] == '#') {
                    nearShopCnt++;
                    temp.push_back(make_pair(yy, xx));
                }
                if(map[yy][xx] =='*') nearStarCnt++;
            }
            if(nearStarCnt == 1) {
                for(int k = 0 ; k < temp.size() ; k++)
                    map[temp[k].first][temp[k].second] = 'X';
            } else if (nearStarCnt == 0) {
                if(temp.size() > 1) // 후보가 너무 많음
                    continue;
                else if(temp.size() == 1) { // 후보가 하나임
                    for(int k = 0 ; k < temp.size() ; k++)
                        map[temp[k].first][temp[k].second] = '*';
                }
            }
        }
        for(int i = 0 ; i < twos.size() ; i++) {
            int nearShopCnt = 0;
            int nearStarCnt = 0;
            int y = twos[i].first;
            int x = twos[i].second;
            vector<pair<int ,int> > temp;
            for(int j = 0 ; j < 8 ; j++) {
                int yy = y + dy[j];
                int xx = x + dx[j];
                if(!isPoss(yy, xx)) continue;
                if('0' <= map[yy][xx] && map[yy][xx] <= '3') continue;
                if(map[yy][xx] == '#') {
                    nearShopCnt++;
                    temp.push_back(make_pair(yy, xx));
                }
                if(map[yy][xx] =='*') nearStarCnt++;
            }
            if(nearStarCnt == 2) {
                for(int k = 0 ; k < temp.size() ; k++)
                    map[temp[k].first][temp[k].second] = 'X';
            } else if (nearStarCnt == 1 && nearShopCnt == 1) {
                for(int k = 0 ; k < temp.size() ; k++)
                    map[temp[k].first][temp[k].second] = '*';
            } else if (nearStarCnt == 0) {
                if(temp.size() > 2)
                    continue;
                else if(temp.size() == 2) {
                    for(int k = 0 ; k < temp.size() ; k++)
                        map[temp[k].first][temp[k].second] = '*';
                }
            }
        }
    }

    int ans = 0;
    for(int i = 2 ; i <= N-1 ; i++ ) {
        for(int j = 2 ; j <= N-1; j++) {
            if(map[i][j] == '*' || map[i][j] == '#') ans++;
        }
    }
    printf("%d", ans);
}