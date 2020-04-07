#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

int N;
int seats[1000010];
set<int> st;
priority_queue<pair<int, int> > seatPQ;
priority_queue<pair<int, int> > pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int a, b;
        scanf("%d %d",&a, &b);
        pq.push(make_pair(-a, -b));
    }

    int seatIdx = 0;
    for(int i = 0 ; i < N ; i++) {
        if(seatPQ.size() != 0) {
            while(-pq.top().first >= -seatPQ.top().first) {
                int seatNumber = seatPQ.top().second;
                st.insert(seatNumber);
                seatPQ.pop();
                if(seatPQ.size() == 0) break;
            }
        }

        if(st.size() == 0) { // 꽉 참
            // set을 더 늘려줘야 됨 -> 좌석 증가.
            seatPQ.push(make_pair(pq.top().second, seatIdx));
            seats[seatIdx++]++;
        } else {
            auto emptySeatNumber = *st.begin();
            seats[emptySeatNumber]++;
            seatPQ.push(make_pair(pq.top().second, emptySeatNumber));
            st.erase(st.begin());
        }
        pq.pop();
    }

    vector<int> ans;
    for(int i = 0 ; i < N ; i++) {
        if(seats[i] == 0) break;
        ans.push_back(seats[i]);
    }
    
    printf("%d\n", ans.size());
    for(auto cnt : ans) printf("%d " , cnt);
}