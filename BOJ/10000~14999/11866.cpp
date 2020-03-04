#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<int> qu;
vector<int> ans;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    for(int i = 1 ; i <= N ; i++) {
        qu.push(i);
    }

    int cnt = 0;
    while(!qu.empty()) {
        cnt++;
        if(cnt == K) {
            cnt = 0;
            ans.push_back(qu.front());
            qu.pop();
            continue;
        }

        int temp = qu.front();
        qu.pop();
        qu.push(temp);
    }

    for(int i = 0 ; i < ans.size() ; i++) {
        if(i == 0) 
            printf("<");
        if (i == ans.size() - 1)
            printf("%d>", ans[i]);
        else 
            printf("%d, ", ans[i]);
    }
}