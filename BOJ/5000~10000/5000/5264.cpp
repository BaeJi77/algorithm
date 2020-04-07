#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

int N;
int num[5010];
int check[400020];
unordered_set<int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &num[i]);
    }

    int ans = 0;
    for(int i = 0 ; i < N ; i++) {
        int now = num[i];
        for(int j = 0 ; j < i ; j++) {
            // 값의 존재 여부를 파악
            // now - num[j]가 존재하냐
            if(st.find(now - num[j]) != st.end()) {
                ans++;
                break;
            }
        }
        for(int j = 0 ; j <= i ; j++) 
            st.insert(now + num[j]);
    }
    printf("%d", ans);
}