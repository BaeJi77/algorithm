#include <cstdio>
#include <map>
#include <iostream>

using namespace std;
typedef long long ll;

ll N;
map<ll, ll> mp;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%lld", &N);
    for(ll i = 0 ; i < N ; i++){
        ll a;
        scanf("%lld", &a);
        mp[a]++;
    }

    ll number = 0;
    ll maxValue = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(maxValue < it->second){
            maxValue = it->second;
            number = it->first;
        }
    }
    printf("%lld", number);
}