#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N;
vector<pair<int, int> > vt;
int cache[20];

int solve(int idx){
    if(idx > N)
        return -INF;

    if(idx == N){
        return 0;
    }

    int ret = solve(idx+1);
    if(N >= vt[idx].first){
        ret = max (ret, solve(idx + vt[idx].first) + vt[idx].second);
    }
    return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        vt.push_back(make_pair(a,b));
    }
    printf("%d\n", solve(0));
}