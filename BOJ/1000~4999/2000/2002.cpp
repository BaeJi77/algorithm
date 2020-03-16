#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int N;
queue<string> qu;
string before[1010];
string after[1010];

map<string, int> beforeMap;

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 1 ; i <= N ; i++) {
        string temp;
        cin>>temp;
        before[i] = temp;
        beforeMap[temp] = i;
    }

    for(int i = 1 ; i <= N ; i++) {
        string temp;
        cin>>temp;
        after[i] = temp;
    }

    int ans = 0;
    for(int i = 1 ; i <= N ; i++) {
        // 나보다 밑에 순위중에 원래 나보다 높은 순위가 있었으면 이건 문제있는거지~
        string nowCar = after[i];
        int beforeRank = beforeMap.find(nowCar)->second;
        bool isIllegal = false;
        vector<string> vt;
        for(int j = i+1 ; j <= N ; j++) {
            int beforeRankForNowLowRank = beforeMap.find(after[j])->second;
            if(beforeRank > beforeRankForNowLowRank) {
                isIllegal = true;
                break;
            }
        }
        if(isIllegal) ans++;
    }

    cout<<ans;
}