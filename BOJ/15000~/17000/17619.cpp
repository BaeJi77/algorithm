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

int N, Q;
int p[100001];
vector<pair<pair<int, int>, int>> map;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);

    if(aa == bb) return;
    p[bb] = aa;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &Q);
    for(int i = 0 ; i < N ; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b ,&c);
        map.push_back({{a, b}, i+1});
    }

    sort(map.begin(), map.end());

    memset(p, -1, sizeof(p));
    for(int i = 0, j = 1 ; i < N && j < N;) {
        if(map[i].first.second >= map[j].first.first) {
            merge(map[i].second, map[j].second);
            j++;
        } else 
            i++;
    }

    for(int i = 0 ; i < Q ;  ++i) {
        int a, b;
        scanf("%d %d\n", &a, &b);
        if(find(a) == find(b)) printf("1");
        else printf("0");
        puts("");
    }
}