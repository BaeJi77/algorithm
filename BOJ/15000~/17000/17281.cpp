#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, ans;
int map[51][10];
int order[10];

int calScore() {
    int score = 0;
    int nowSwingNumber = 1;
    for(int i = 1; i <= N ; ++i) {
        int outCount = 0;
        int j = nowSwingNumber;
        int base[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        while(1) {
            bool isFinished = false;
            if(outCount == 3) break;
            if(j == 10) j = 1;

            // map[i][order[j]] => 현재 이닝에 타자의 결과
            int nowResult = map[i][order[j]];
            if(nowResult != 0) base[0] = 1;

            switch (nowResult)
            {
            case 0:
                outCount++;
                if(outCount == 3) isFinished = true;
                break;
            
            case 1:
                for(int k = 3 ; k >= 0 ; k--) {
                    if(base[k] == 0) continue;
                    base[k + 1] += 1;
                    base[k] = 0;
                }
                break;
            
            case 2:
                for(int k = 3 ; k >= 0 ; k--) {
                    if(base[k] == 0) continue;
                    base[k + 2] += 1;
                    base[k] = 0;
                }
                break;

            case 3:
                for(int k = 3 ; k >= 0 ; k--) {
                    if(base[k] == 0) continue;
                    base[k + 3] += 1;
                    base[k] = 0;
                }
                break;
            
            case 4:
                for(int k = 3 ; k >= 0 ; k--) {
                    if(base[k] == 0) continue;
                    base[k + 4] += 1;
                    base[k] = 0;
                }
                break;
            
            default:
                break;
            }
            if(isFinished == false) j++;
        }
        for(int i = 4 ; i < 9 ; ++i) {
            score += base[i];
        }
        nowSwingNumber = j + 1;
    }
    return score;
}

void decideOrder(int now, int check) {
    if(now == 10) {
        ans = max(ans, calScore());
        return;
    }

    for(int i = 1 ; i <= 9 ; ++i) {
        if(check & 1<<i) continue;
        order[now] = i;
        if(now == 3) decideOrder(now + 2, check | 1<<i);
        else decideOrder(now + 1, check | 1<<i);
        order[now] = -1;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = 1 ; j <= 9 ; ++j) { 
            int result;
            scanf("%d", &result);
            map[i][j] = result;
        }
    }

    order[4] = 1;
    decideOrder(1, 1<<1);
    printf("%d", ans);
}