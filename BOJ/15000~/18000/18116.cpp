#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
int p[1000001];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if(aa == bb) return;
    if(-p[aa] > -p[bb]) {
        p[aa] += p[bb];
        p[bb] = aa;
    } else {
        p[bb] += p[aa];
        p[aa] = bb;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    memset(p, -1, sizeof(p));
    for(int i = 0 ; i < N ; ++i) {
        char q;
        int a, b;
        cin>>q;
        if(q == 'I') {
            // merge
            cin>>a>>b;
            merge(a, b);
        }
        if(q == 'Q') {
            // 집합 사이즈
            cin>>a;
            cout<<-p[find(a)]<<"\n";
        }
    }
}