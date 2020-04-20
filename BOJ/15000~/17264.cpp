#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, P;
int W, L, G;
bool isSuccess;
map<string, char> hackings;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N>>P;
    cin>>W>>L>>G;
    for(int i = 0 ; i < P ; ++i) {
        string player;
        char q;
        cin>>player>>q;
        hackings[player] = q;
    }

    int score = 0;
    for(int i = 0 ; i < N ; ++i) {
        string player;
        cin>>player;
        if(hackings.find(player) != hackings.end()) {
            // 기존의 입력이 있는 경우
            if(hackings[player] == 'W') score += W;
            else score -= L;
            if(score >= G) isSuccess = true;
        } else 
            score -= L;
        score = score < 0 ? 0 : score;
    }

    if(isSuccess) cout<<"I AM NOT IRONMAN!!";
    else cout<<"I AM IRONMAN!!";
}