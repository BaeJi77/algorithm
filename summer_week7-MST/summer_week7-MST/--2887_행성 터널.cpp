//  https://www.acmicpc.net/problem/2887
//  2887_행성 터널.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

ll n,p[100004],cnt,sum;
pair<ll, ll> x[100004],y[100004],z[100004];
vector<pair<ll, pair<ll, ll>>> vt;

ll Find(ll x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

bool Merge(ll u , ll v){
    ll uu = Find(u);
    ll vv = Find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}

int main(){
    scanf("%lld" , &n);
    for (ll i = 0; i < n; i++) {
        ll tx,ty,tz;
        scanf("%lld %lld %lld" , &tx,&ty,&tz);
        x[i] = make_pair(tx, i);
        y[i] = make_pair(ty, i);
        z[i] = make_pair(tz, i);
        p[i] = i;
    }
    
    sort(x,x+n);
    for (ll i = 0; i < n-1; i++) vt.push_back({abs(x[i].first-x[i+1].first),{x[i].second,x[i+1].second}});
//    for(ll i = 0 ; i < n ; i++) prllf("%d " , x[i]); puts("");
    
    sort(y,y+n);
    for (ll i = 0; i < n-1; i++) vt.push_back({abs(y[i].first-y[i+1].first),{y[i].second,y[i+1].second}});
    
    sort(z,z+n);
    for (ll i = 0; i < n-1; i++) vt.push_back({abs(z[i].first-z[i+1].first),{z[i].second,z[i+1].second}});
    
    sort(vt.begin(),vt.end());
    
    for (auto x : vt){
        if(cnt == n-1) break;
        ll w = x.first;
        ll a = x.second.first;
        ll b = x.second.second;
        
        if(Find(a) == Find(b)) continue;
        Merge(a, b);
        sum+=w;
        cnt++;
    }
    
    printf("%lld" , sum);
}
