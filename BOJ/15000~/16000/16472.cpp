#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAX = 1e9;

int N, ans, bit;
string input;
int lastPos[30];

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N>>input;

    for(int i = 0 ; i < 30 ; ++i)
        lastPos[i] = MAX;
    
    int left = 0;
    int right = 0;
    int includeChar = 0;
    
    // bit가 1로 가능하면 고고. 안되면 가능한 알파벳으로 추가
    while(right < input.size()) {
        int charNumber = input[right] - 'a';
        if(bit & 1<<charNumber) { // 포함하고 있는 상태라면
            lastPos[charNumber] = right;
            right++;
        } else {
            if(includeChar < N) { // 포함 가능
                bit |= 1<<charNumber;
                lastPos[charNumber] = right;
                includeChar++;
                right++;
            } else { // 가장 뒤에 있는 놈을 버리고 뒤에 있는 애 + 1에 left를 가지고 놈
                int minValue = MAX;
                int targetIdx = -1;
                for(int i = 0 ; i < 26 ; ++i) {
                    if(minValue > lastPos[i]) {
                        minValue = lastPos[i];
                        targetIdx = i;
                    }
                }
                lastPos[targetIdx] = MAX;

                // bit에서 이 친구 색을 빼줘야됨.
                bit &= ~(1<<targetIdx);
                left = minValue + 1;
                includeChar--;
            }
        }
        ans = max(ans, right - left);
    }
    printf("%d", ans);
}