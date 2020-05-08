#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

int N, C;
int arr[5001];
set<int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &C);
    for(int i = 0 ; i < N ; ++i) {
        scanf("%d", &arr[i]);
        st.insert(arr[i]);
    }

    bool ans = false;
    for(int i = 0 ; i < N ; ++i) {
        if(arr[i] == C) ans = true;
        for(int j = i + 1 ; j < N ; ++j) {
            if(arr[i] + arr[j] == C) ans = true;
            if((C - arr[i] - arr[j] == arr[i]) || (C - arr[i] - arr[j] == arr[j])) continue;
            if(st.find(C - arr[i] - arr[j]) != st.end()) ans = true;
            if(ans) break;
        }
        if(ans) break;
    }

    printf("%d", ans);
}