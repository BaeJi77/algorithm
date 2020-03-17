#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int ans;
vector<vector<pair<int, int > > > vt;

void cal(int y, int sum, int bit) {
    if(y == 11) {
        ans = max(ans, sum);
        return;
    }

    for(int i = 0 ; i < vt[y].size() ; i++) {
        // first 만큼 밀었는데 &연산해서 같으면 누가 있는거지
        if(bit & (1<<vt[y][i].first)) continue;
        cal(y + 1, vt[y][i].second + sum, bit | (1<<vt[y][i].first));
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        vt.clear();
        vt.resize(15);
        for(int i = 0 ; i < 11 ; i++) {
            for(int j = 0 ; j < 11 ; j++) {
                int k;
                scanf("%d", &k);
                if(k == 0) continue;
                vt[i].push_back(make_pair(j, k));
            }
        }
        cal(0, 0, 0);
        printf("%d\n", ans);
    }
}