#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, score, P;
vector<int> vt;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d", &N, &score, &P);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        vt.push_back(k);
    }
    vt.push_back(score);

    sort(vt.begin(),vt.end());
    reverse(vt.begin(),vt.end());

    int firstValue = -1;
    int cnt = 0;
    for(int i = 0 ; i < vt.size() ; ++i) {
        if(vt[i] == score) {
            if(firstValue == -1) firstValue = i + 1;
            cnt = i + 1;
        }
    }
    printf("%d\n", cnt > P ? -1 : firstValue);
}