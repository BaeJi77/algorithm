#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        st.clear();
        int N, M;
        scanf("%d", &N);
        for(int i = 0 ; i < N ; ++i) {
            int k;
            scanf("%d", &k);
            st.insert(k);
        }

        scanf("%d", &M);
        for(int i = 0 ; i < M ; ++i ) {
            int k;
            scanf("%d", &k);
            if(st.find(k) != st.end()) printf("1\n");
            else printf("0\n");
        }
    }
}