#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const ll NMToCM = 1e7;

ll x, n;
vector<ll> vt;
vector<pair<ll, ll> > ans;

ll findRestPiece(ll first) {
    ll left = 0;
    ll right = n;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll sumTwoNumber = first + vt[mid];
        ll F;
        if(sumTwoNumber == x * NMToCM)
            F = 2;
        else if(sumTwoNumber > x * NMToCM)
            F = 1;
        else F = 0;
        
        if(F == 2) {
            // 맞는 친구를 찾음.
            return mid;
        } else if (F == 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void sol() {
    for(ll i = 0 ; i < n ; i++) {
        // 하나 선택해서 나머지 하나는 log n 으로 찾기
        ll findResult = findRestPiece(vt[i]);
        if(findResult == -1)
            continue;
        else {
            if(i == findResult) // 값은 인덱스 인 경우 제외
                continue;
            ans.push_back(make_pair(i, findResult));
        }
            
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    while(scanf("%lld", &x) != EOF) {
        vt.clear();
        ans.clear();
        scanf("%lld", &n);
        for(ll i = 0 ; i < n ; i++) {
            ll q;
            scanf("%lld", &q);
            vt.push_back(q);
        }
        sort(vt.begin(), vt.end());
        sol();
        // if(n <= 1) { // 넣어줘도 되고 안넣어줘도 되고
        //     printf("danger\n");
        //     continue;
        // }
        if(ans.size() == 0)
            printf("danger\n");
        else {
            ll maxIndex = -1;
            ll maxValue = -1;
            for(ll i = 0 ; i < ans.size() ; i++) {
                if(vt[ans[i].first] > vt[ans[i].second])
                    continue;
                ll nowValue = abs(vt[ans[i].first] - vt[ans[i].second]);
                if(nowValue > maxValue) {
                    maxIndex = i;
                    maxValue = nowValue;
                }
            }
            printf("yes %lld %lld\n", vt[ans[maxIndex].first], vt[ans[maxIndex].second]);
        }
    }
}