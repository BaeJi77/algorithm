#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;


int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int N, M;
    vector<int> candidate;
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < M ; i++) {
        int a;
        scanf("%d", &a);
        candidate.push_back(a);
    }

    sort(candidate.begin(), candidate.end(), [](int x, int y) -> bool {
        return x > y;
    });

    int maxIdx = -1;
    int maxx = -1;
    for(int i = 0 ; i < candidate.size() ; i++) {
        if(i + 1 > N) break;
        
        if(maxx < (i + 1) * candidate[i]) {
            maxIdx = i;
            maxx = max(maxx , (i + 1) * candidate[i]);
        }
    }

    printf("%d %d", candidate[maxIdx], (maxIdx + 1) * candidate[maxIdx]);
}
