#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

int N, d;
set<int> st;
vector<int> ans;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &d);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        int aPos = a;
        for(auto val : st) {
            if(val <= a) {
                if(val + d >= aPos) aPos = val + d;
                else continue;
            }
            if(val > a) {
                if(aPos > val - d) aPos = val + d;
                else break;
            }
        }
        st.insert(aPos);
        ans.push_back(aPos);
    }

    for(auto val : ans)
        printf("%d ", val);
}