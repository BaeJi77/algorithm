#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
vector<pair<int, int> > vt;
bool visited[1010];

bool comp(pair<int, int> a, pair<int, int> b) {
    return sqrt((10000 - a.first)*(10000 - a.first) + (10000 - a.second) * (10000 - a.second)) > sqrt((10000 - b.first)*(10000 - b.first) + (10000 - b.second) * (10000 - b.second));
}

int calDist(pair<int, int> a, pair<int, int> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int bfs(int mid) {
    queue<pair<int, int> > qu; // cnt, index
    memset(visited, 0, sizeof(visited));
    qu.push(make_pair(0, 0));
    visited[0] = true;
    while(int s = qu.size()) {
        while(s--) {
            int nowCnt = qu.front().first;
            int nowIdx = qu.front().second;
            // if(mid==750) printf("\n%d %d %d %d %d\n", s, nowCnt, nowIdx, vt[nowIdx].first, vt[nowIdx].second);
            qu.pop();

            if(vt[nowIdx].first == 10000 && vt[nowIdx].second == 10000)
                return true;

            if(nowCnt > K)
                continue;
            
            for(int i = 1 ; i < vt.size() ; i++) {
                if(visited[i]) continue;

                int nowDist = calDist(vt[nowIdx], vt[i]);
                int needThings = nowDist / 10;
                if (nowDist % 10 != 0) needThings++;
                // if(mid == 750) printf("%d %d %d %d %d %d\n", vt[nowIdx].first, vt[nowIdx].second, vt[i].first, vt[i].second, nowDist, needThings);
                if(mid >= needThings) {
                    visited[i] = true;
                    qu.push(make_pair(nowCnt + 1, i));
                }
            }
        }
    }

    return false;
}

int f (int mid) { // mid는 내 연료통
    // 방문 횟수
    int visitCnt = 0;
    int nowIndex = 0;
    bool dontGo = false;
    while(1) {
        if(nowIndex == vt.size() - 1)
            break;
        // 못가는 경우에 어떻게 하나요?
        
        bool isPossToGoNext = false;
        for(int i = vt.size() - 1 ; i > nowIndex ; i--) {
            int nowDist = calDist(vt[nowIndex], vt[i]);
            int needThings = nowDist / 10;
            if (nowDist % 10 != 0) needThings++;

            // printf("%d %d %d %d %d %d\n", vt[nowIndex].first, vt[nowIndex].second, vt[i].first, vt[i].second, nowDist, needThings);

            if(mid >= needThings) {
                visitCnt++;
                nowIndex = i;
                isPossToGoNext = true;
                break;
            }
        }
        
        if(!isPossToGoNext) {
            dontGo = true;
            break;
        }
    }

    if(dontGo) return -1; // 왼쪽에 있는 기준선을 오른 쪽으로.
    else return visitCnt - 1;
}

int cal() {
    int left = 1;
    int right = 1500;
    while(left <= right) {
        int mid = (left + right) / 2;
        // int F = f(mid); // F는 방문 횟수 -1는 안된다는 에러의 의미 => 값을 더 늘려야됨
        int F = bfs(mid);
        // printf("%d %d %d %d\n", left, right, mid, F);
        if(F) { // 가능하다.
            right = mid - 1;
        } else { // 불가능
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    vt.push_back(make_pair(0,0));
    vt.push_back(make_pair(10000,10000));
    for(int i = 0 ; i < N ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        vt.push_back(make_pair(a,b));
    }

    sort(vt.begin(), vt.end(), comp);
    printf("%d\n",cal());
    // for(int i = 0 ; i < vt.size() ; i++)
    //     printf("%d %d\n", vt[i].first, vt[i].second);
    
}