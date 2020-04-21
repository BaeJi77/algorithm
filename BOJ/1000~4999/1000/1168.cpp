#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<int> map;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    for(int i = 1 ; i <= N ; ++i) {
        map.push_back(i);
    }

    int idx = 0;
    printf("<");
    for(int i = 0 ; i < N ; ++i) {
        idx += (K - 1);
        idx %= map.size();
        if(map.size() != 1) printf("%d, ", map[idx]);
        else printf("%d", map[idx]);
        map.erase(map.begin() + idx);
    }
    printf(">");
}