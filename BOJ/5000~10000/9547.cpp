#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int C, V;
vector<vector<int> > like;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        like.clear();
        int vote[101] = {0,};
        priority_queue<pair<int, int> > pq;
        scanf("%d %d", &C, &V);
        like.resize(V+1);
        for(int i = 0 ; i < V ; i++) {
            for(int j = 0 ; j < C; j++) {
                int a;
                scanf("%d", &a);
                like[i].push_back(a);
                if(j == 0) vote[a]++;
            }
        }

        for(int i = 1 ; i <= C ; i++) {
            pq.push(make_pair(vote[i], i));
        }
        pair<int, int> first = pq.top();
        pq.pop();
        pair<int, int> second = pq.top();
        if(first.first > V / 2) {
            printf("%d %d\n", first.second, 1);
        } else {
            // 한번 더 투표
            int a1 = first.second;
            int a2 = second.second;
            
            memset(vote, 0, sizeof(vote));
            for(int i = 0 ; i < V ; i++) {
                for(int j = 0 ; j < C ; j++) {
                    if(like[i][j] == a1) {
                        vote[a1]++;
                        break;
                    } else if(like[i][j] == a2) {
                        vote[a2]++;
                        break;
                    }
                }
            }
            printf("%d %d\n", vote[a1] > vote[a2] ? a1 : a2, 2);
        }
    }
}