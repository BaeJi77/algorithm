#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 1000000000
typedef long long ll;
using namespace std;

ll N,M,px,py;
bool visited[100004];
vector<vector<pair<ll,ll> > > vt;

//최대 중량 초과시 이동불가, 돌아가서 도착만 하면 됨
void func(ll mid, ll nowPoint){
    visited[nowPoint] = true;
    for(int i = 0 ; i < vt[nowPoint].size() ; i++){
        ll there = vt[nowPoint][i].first;
        ll cost = vt[nowPoint][i].second;
        if(!visited[there] && mid <= cost){
            func(mid, there);
        }
    }
}

ll search(){
    ll lo = 1;
    ll hi = MAX+1;
    while(lo < hi){
        ll mid = (lo+hi)/2;
        memset(visited, 0, sizeof(visited));
        func(mid, px);
        if(visited[py] == true){
            lo = mid+1;
        }else {
            hi = mid;
        }
    }
    return lo;
}



int main(){
    freopen("input.txt","r",stdin);
    cin>>N>>M;
    vt.resize(N+1);
    for(int i = 0 ; i < M ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        vt[a].push_back(make_pair(b,c));
        vt[b].push_back(make_pair(a,c));
    }
    cin>>px>>py;
    ll ans = search();
    cout<<ans-1;
}