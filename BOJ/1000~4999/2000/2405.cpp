#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<int> vt;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        vt.push_back(a);
    }
    sort(vt.begin(), vt.end());
    // (평균 - 중위값) * 3
    // (A+B+C) - 3 * B
    // A + C - 2 * B
    // C = vt[N-1];
    // A = vt[j-1];
    for(int i = 1 ; i < N - 1 ; ++i) {
        ans = max(ans, abs(vt[i - 1] + vt[N - 1] - 2 * vt[i]));
        ans = max(ans, abs(vt[0] + vt[i + 1] - 2 * vt[i]));
    }

    printf("%d", ans);
}