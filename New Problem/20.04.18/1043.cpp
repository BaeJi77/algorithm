#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool dontLieGroup[51]; // 1 => 말하면 안되는 그룹
bool dontLieNumber[51]; // 1 => 진실을 말했던 사람들 넘버
vector<vector<int> > group;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    group.resize(M+1);

    int k;
    scanf("%d", &k);
    for(int i = 0 ; i < k ; ++i) {
        int lie;
        scanf("%d", &lie);
        dontLieNumber[lie] = true;
    }

    for(int i = 0 ; i < M ; ++i) {
        int num;
        scanf("%d", &num);
        bool dontSay = false;
        for(int j = 0 ; j < num ; ++j) {
            int people;
            scanf("%d", &people);
            if(dontLieNumber[people]) dontSay = true;
            group[i].push_back(people);
        }
        if(dontSay) {
            dontLieGroup[i] = true;
            for(int j = 0 ; j < num ; ++j) {
                dontLieNumber[group[i][j]] = true;
            }
        }
    }

    while(1) {
        bool isChanged = false;
        for(int i = 0 ; i < M ; ++i) {
            if(dontLieGroup[i] == true) continue;
            bool dontSay = false;
            for(int j = 0 ; j < group[i].size() ; ++j) {
                if(dontLieNumber[group[i][j]]) {
                    dontSay = true;
                    isChanged = true;
                }
            }
            
            if(dontSay) {
                dontLieGroup[i] = true;
                for(int j = 0 ; j < group[i].size() ; ++j) {
                    dontLieNumber[group[i][j]] = true;
                }
            }
        }

        if(isChanged == false) break;
    }

    int ans = 0;
    for(int i = 0 ; i < M ; i++) 
        if(!dontLieGroup[i]) ans++;
    printf("%d", ans);
}