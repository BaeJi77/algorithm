#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

const ll MAX = 10000;
const ll INF = 987654321;

ll N;
bool visited[MAX+1];
bool condition[MAX+1];
ll cost[MAX+1];
ll cache[MAX+1][2];
vector<vector<ll> > map;
vector<vector<ll> > tree;

void makeTree(ll here){
    condition[here] = true;
    for(ll i = 0 ; i < map[here].size(); i++){
        ll there = map[here][i];
        if(!condition[there]){
            makeTree(there);
            tree[here].push_back(there);
        }
    }
}

//select -> 1 : 현재 마을이 우수마을로 선정된 경우, 0 : 선정 x
ll func(ll idx, ll select){
    ll& ret = cache[idx][select];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(ll i = 0 ; i < tree[idx].size(); i++){
        ll nextPos = tree[idx][i];
        
        if(select){
            ret += func(nextPos, 0);
        } else {
            ret += max(func(nextPos, 0), func(nextPos, 1) + cost[nextPos]);
        }
    }
    visited[idx] = false;
    
    return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    map.resize(N+1);
    tree.resize(N+1);
    memset(cache,-1,sizeof(cache));
    for(ll i = 1 ; i <= N ; i++){
        scanf("%d", &cost[i]);
    }

    for(ll i = 0 ; i < N ; i++){
        ll a,b;
        scanf("%d %d", &a,&b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    makeTree(1);

    printf("%lld", max(func(1, 0), func(1, 1) + cost[1]));
}