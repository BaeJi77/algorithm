#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N;
priority_queue <pair<int, int> > pq;
vector<int> boom;
vector<int> ans;

void LeftBoom(int idx, int power) {
    if(idx == -1)
        return;
    if(boom[idx] < power) {
        LeftBoom(idx - 1, boom[idx]);
        boom[idx] = -1;
    }
}

void rightBoom(int idx, int power) {
    if(idx == boom.size())
        return;
    if(boom[idx] < power) {
        rightBoom(idx + 1, boom[idx]);
        boom[idx] = -1;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        boom.push_back(k);
        pq.push(make_pair(k, i));
    }

    while(!pq.empty()) {
        int power = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(boom[idx] == -1) continue;
        ans.push_back(idx + 1);
        LeftBoom(idx-1, power);
        rightBoom(idx+1, power);
    }

    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size() ; i++)
        printf("%d\n", ans[i]);
}