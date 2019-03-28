#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;
const ll MAX = 1e5;

ll N,M;
vector<vector<pair<ll, ll> > > vt;
ll sy,sx;
bool visited[MAX+1];

bool bfs(ll w){
    memset(visited, 0, sizeof(visited));
    queue<ll> qu;
    qu.push(sy);
    while(ll s = qu.size()){
        while(s--){
            ll top = qu.front();
            qu.pop();

            if(top == sx)
                return true;
            
            for(ll i = 0 ; i < vt[top].size() ; i++){
                ll here = vt[top][i].first;
                ll we = vt[top][i].second;

                if(w <= we && !visited[here]){
                    qu.push(here);
                    visited[here] = true;
                }
            }
        }
    }

    return false;
}

ll find(ll left, ll right){
    while(left < right){
        ll mid = (left + right)/2;
        if(bfs(mid)){ // 갈수 있어
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    vt.resize(N+1);
    for(ll i = 0 ; i < M ; i++){
        ll a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        vt[a].push_back(make_pair(b,c));
        vt[b].push_back(make_pair(a,c));
    }
    scanf("%d %d", &sy, &sx);
    printf("%lld", find(1, 1e9+1)-1);
}