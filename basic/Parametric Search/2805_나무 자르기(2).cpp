#include <cstdio>

using namespace std;

typedef long long ll;

const ll MAX = 1e6;
ll N,M,wood[MAX+1];

ll find(ll left, ll right){
    while(left < right){
        ll mid = (left+right)/2;
        ll sum = 0;
        for(ll i = 0 ; i < N ; i++){
            if(wood[i] > mid)
                sum+= wood[i] - mid;
        }       

        if(sum < M){
            right = mid;
        }else {
            left = mid+1;
        }
    }
    return left;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%lld %lld", &N, &M);
    for(ll i = 0 ; i < N ; i++){
        scanf("%d", &wood[i]);
    }

    printf("%lld", find(1, 2e9+1)-1);
}