#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

const ll INF = 987654321;

ll s,t,a,b;

// ll bfs(ll sa){
//     queue<ll> qu;
//     qu.push(sa);
//     visited[sa] = true;

//     ll cnt = 0;
//     while(ll s = qu.size()){
//         while(s--){
//             ll top = qu.front();
//             qu.pop();
            
//             if(top == t)
//                 return cnt;
            
//             ll product = top * b;
//             ll add = top + a;
            
//             if(!visited[product] && product <= MAXARRAY){
//                 visited[product] = true;
//                 qu.push(product);
//             }else if(!visited[add] && add <= MAXARRAY){
//                 visited[add] = true;
//                 qu.push(add);
//             }
//             printf("%lld %lld %lld\n" , top, add, product);
//         }
//         cnt++;
//     }
//     return -1;
// }

ll solve(ll sa){
    if(sa > t)
        return INF;
    if(sa == t){
        return 0;
    }

    ll ret = INF;
    ret = min(ret, solve(sa + a) + 1);
    ret = min(ret, solve(sa * b) + 1);

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    ll T;
    scanf("%lld", &T);
    for(ll tc = 1 ; tc <= T ; tc++){
        scanf("%lld %lld %lld %lld", &s, &t, &a, &b);
        ll ans = solve(s);
        printf("#%lld %lld\n" , tc, ans == INF ? -1 : ans );
    }
}