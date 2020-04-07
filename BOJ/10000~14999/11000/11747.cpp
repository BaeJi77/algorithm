#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<int> vt;
set<int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        vt.push_back(k);
        st.insert(k);
    }

    for(int i = 0 ; i < N - 1 ; i++) {
        int firstDigit = vt[i] * 10;
        firstDigit += vt[i + 1];
        st.insert(firstDigit);
        if(i != N - 2) {
            firstDigit *= 10;
            firstDigit += vt[i + 2];
            st.insert(firstDigit);
        }
    }

    int ans = 0;
    for(auto i : st) {
        if(i == ans) {
            ans++;
        } else break;
    }
    printf("%d\n", ans);
}