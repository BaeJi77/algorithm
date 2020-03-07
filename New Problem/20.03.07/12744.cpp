#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int N, ans = 20;
vector<pair<int, char> > vt;
set<vector<pair<int, char> > > st;

bool isSorted(vector<pair<int, char> > isOkArray) {
    for(int i = 0 ; i < N ; i++) {
        if(isOkArray[i].first != i + 1 || isOkArray[i].second != '+')
            return false;
    }
    return true;
}

vector<pair<int, char> > reverseValueAndDirection(vector<pair<int, char> > panCakes, int first, int end) {
    reverse(panCakes.begin() + first, panCakes.begin() + end);
    
    for(int i = first ; i < end ; i++) {
        char newDirection = panCakes[i].second == '+' ? '-' : '+';
        int newValue = panCakes[i].first;
        panCakes[i] = make_pair(newValue, newDirection);
    }

    return panCakes;
}

int bfs(vector<pair<int, char> > init) {
    int cnt = 0;
    queue<vector<pair<int, char> > > qu;
    st.insert(init);
    qu.push(init);
    while(int s = qu.size()) {
        while(s--) {
            vector<pair<int, char> > nowPanCakes = qu.front();
            qu.pop();

            if(isSorted(nowPanCakes)) {
                return cnt;
            }
            
            for(int i = 0 ; i < N ; i++) {
                vector<pair<int, char> > newPanCakes = nowPanCakes;
                newPanCakes = reverseValueAndDirection(newPanCakes, 0, i + 1);
                if(st.find(newPanCakes) != st.end()) continue; // 존재함.
                st.insert(newPanCakes);
                qu.push(newPanCakes);
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++ ) {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        vt.push_back(make_pair(a, b));
    }
    printf("%d", bfs(vt));
}