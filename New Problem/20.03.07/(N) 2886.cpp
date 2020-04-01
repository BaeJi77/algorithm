#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[101][101];
int visited[101][101];
vector<pair<int, int> > chairs;
vector<pair<int, int> > people;
bool visited[101][101];

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int makeDist(int sy, int sx, int ny, int nx) {
    return (sy - ny) * (sy - ny) + (sx - nx) * (sx - nx);
}

void bfs(int sy, int sx) {
    memset(visited, 0, sizeof(visited));
    priority_queue<pair<int, pair<int, int> > > pq;
    queue<pair<int, int> > qu;
    qu.push(make_pair(sy, sx));
    while(int s = qu.size()) {
        while(s--) {
            int y = qu.front().first;
            int x = qu.front().second;
            qu.pop();
            if(map[y][x] == 2)
                pq.push(make_pair(-makeDist(sy,sx,y,x), make_pair(y, x)));
            
            for(int i = 0 ; i < 4 ; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(visited[yy][xx]) continue;
                qu.push(make_pair(yy,xx));
            }
        }
    }

    vector<pair<int, int> > sameChairWant;
    int ret = 0;
    
    int pqTopValue = -pq.top().first;
    sameChairWant.push_back(make_pair(pq.top().second.first, pq.top().second.second));
    pq.pop();

    int pqSize = pq.size();
    for(int i = 0 ; i < pqSize ; i++) {
        if(pqTopValue == (pq.top().first * (-1))){
            sameChairWant.push_back(make_pair(pq.top().second.first, pq.top().second.second)); 
        }
        pq.pop();
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    printf("%d %d\n", N, M);
    
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            char a = getchar();
            if(a == '.') map[i][j] = 0;
            if(a == 'L') {
                map[i][j] = 1;
                chairs.push_back(make_pair(i, j));
            }
            if(a == 'X') {
                map[i][j] = 2;
                people.push_back(make_pair(i, j));
            }
        }
    }

    

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            printf("%d ", map[i][j]);
        }
        puts("");
    }

    // 
}

// 나한테 가장 가까운 의자가 있는 경우 => 거기로 간다. => 하지만 나보다 더 가까운 의자가 있는 경우는 안감 => 다른 가까운 의자로 이동함.
// 의자에서 가장 가까운 곳을 먼저 조사하면 다른 의자가 더 가까울 수 있는데 고려할 수 없다.
// 의자 후보군을 다 만든 다음에 모두 비교? 이건 시간초과 날 것 같은데

/*
3 7
..X....
X.LLL.X
....X..
=> 1

4 4
.LX.
....
.X..
.L..
=> 0

4 4
.LX.
.X..
....
.L..
=> 1
*/