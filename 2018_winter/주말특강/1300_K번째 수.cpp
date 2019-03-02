#include <iostream>
#include <algorithm>

#define MAX 1000000000
typedef long long ll;
using namespace std;


ll N,K;

ll totalLowNumber(ll mid){
    ll sum = 0;
    for(ll i = 1 ; i <= N ; i++ ){
        sum += min(N,mid/i);
    }
    return sum;
}

ll search(){
    ll lo = 1;
    ll hi = MAX+1;
    while(lo < hi){
        ll mid = (lo+hi)/2;
        if(totalLowNumber(mid) < K){
            lo = mid+1;
        }else {
            hi = mid;
        }
    }
    return lo;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>N>>K;
    cout<<search()<<endl;
}