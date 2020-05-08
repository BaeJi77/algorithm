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

int N;
int map[1000001];
int ans[1000001];
stack<int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    memset(map,-1,sizeof(map));
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        map[i] = a;
        // st.push(a);
    }

    for(int i = N - 1; i >= 0 ; --i) {
        if(st.empty()) {
            ans[i] = -1;
            st.push(map[i]);
        } else if(st.top() > map[i]) {
            ans[i] = st.top();
            st.push(map[i]);
        } else if(st.top() <= map[i]) {
            while(st.top() <= map[i]) {
                st.pop();
                if(st.empty()) break;
            }

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(map[i]);
        }
    }

    for(int i = 0 ; i < N ; ++i) 
        printf("%d ", ans[i]);
}