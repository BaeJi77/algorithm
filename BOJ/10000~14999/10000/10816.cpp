#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int N,M;
map<int, int> mp;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++ ) {
        int k;
        scanf("%d", &k);
        mp[k]++;
    }

    scanf("%d", &M);
    for(int i = 0 ; i < M ; i++) {
        int k;
        scanf("%d", &k);
        printf("%d ", mp.find(k)->second);
    }
}