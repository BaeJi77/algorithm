#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
vector<int> vt;
set <int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N; i++) {
        int k;
        scanf("%d", &k);
        vt.push_back(k);
        st.insert(k);
    }

    int ans = 0;
    for(auto i : st) {
        int nowNumber = vt[0];
        int contiCnt = 1;
        for(int j = 1 ; j < N ; j++) {
            if(i == vt[j]) continue;
            if(nowNumber == vt[j]) {
                contiCnt++;
            } else {
                nowNumber = vt[j];
                contiCnt = 1;
            }
            ans = max(ans, contiCnt);
        }
    }

    printf("%d", ans);
}