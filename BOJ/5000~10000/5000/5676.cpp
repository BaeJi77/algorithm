#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

const ll MAX = 1e5;

ll N,K;
ll seg[MAX * 4 + 10];

ll update(ll pos, ll value, ll node, ll left, ll right) {
    if(pos < left || right < pos)
        return seg[node];
    if(left == right)
        return seg[node] = value;
    
    ll mid = (left + right) / 2;
    return seg[node] = update(pos, value, node*2, left, mid) * update(pos, value, node*2 + 1, mid + 1, right);
}

ll query(ll lo, ll hi, ll node, ll left, ll right) {
    if(right < lo || hi < left)
        return 1;
    if(lo <= left && right <= hi)
        return seg[node];

    ll mid = (left + right) / 2;
    return query(lo, hi, node * 2, left, mid) * query(lo, hi, node*2+1, mid+1, right);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    while(scanf("%d %d", &N, &K) != EOF) {
        fill(seg, seg + MAX*4 + 10, 0);
        for(ll i = 0 ; i < N ; i++ ){
            ll k;
            scanf("%lld", &k);
            if(k != 0) (k > 0) ? k = 1 : k = -1; 
            update(i + 1, k, 1, 1, N);
        }

        for(ll i = 0; i<K ; i++) {
            getchar();
            char q;
            ll a,b;
            scanf("%c %lld %lld", &q,&a,&b);
            if(q == 'C'){
                if(b != 0) (b > 0) ? b = 1 : b = -1; 
                update(a, b, 1, 1, N);
            }else{
                ll result = query(a,b,1,1,N);
                if(result == 0) printf("0");
                else printf("%c", result > 0 ? '+' : '-');
            }
        }
        puts("");
        
    }
}