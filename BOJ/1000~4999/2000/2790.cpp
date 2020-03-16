#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int scores[300010];
vector<int> vt;

bool comp (int a, int b) {
    return a > b;
}

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        vt.push_back(k);
    }
    
    sort(vt.begin(), vt.end(), comp);

    int ans = 0;
    int available1st = 0;
    for(int i = 0 ; i < N ; i++ ) {
        if(vt[i] + N >= available1st) ans++;
        available1st = max(available1st, vt[i] + i + 1);
    }
    printf("%d", ans);
}
