#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N,M,K;
int cache[304][304];
vector<vector<pair<int, int> > > vt;

//visit <= M 이기만 하면됨
int func(int idx, int visit){
    if(idx == N && visit <= M)
        return 0;
    if(visit > M)
        return -INF;
    
    int& ret = cache[idx][visit];
    if(ret != -1)
        return ret;
    
    ret = -INF;
    for(int i = 0 ; i < vt[idx].size() ; i++){
        int nextIdx = vt[idx][i].first;
        int cost = vt[idx][i].second;
        ret = max(ret, func(nextIdx, visit+1) + cost);
    }

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &N, &M, &K);
    vt.resize(N+1);
    memset(cache,-1,sizeof(cache));
    for(int i = 0 ; i < K ; i++){
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        if(a < b)
            vt[a].push_back(make_pair(b,c));
    }
    printf("%d", func(1, 1));
}