#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

string input;

void printReverse (string normalString) {
    reverse(normalString.begin(), normalString.end());
    for(auto i : normalString)
        cout<<i;
}

void checkNormalString(string str) {
    int idx = 0;
    // str 범위를 넘어가면 공백이지 않나?
    for(int i = 1 ; i < str.size() ; i++) {
        if(str[i] == ' ') {
            printReverse(str.substr(idx, i - idx));
            idx = i + 1;
            cout<<" ";
        }
    }
    printReverse(str.substr(idx, str.size()));
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    getline(cin, input);
    int normalStringStartIdx = input[0] == '<' ? -1 : 0;
    bool bracketFlag = false;
    for(int i = 0 ; i < input.size(); i++) {
        if(input[i] == '<') {
            bracketFlag = true;
            if(normalStringStartIdx != -1) { // > ... < 사이에 있는 애들 리버스 해줘야 함.
                checkNormalString(input.substr(normalStringStartIdx, i - normalStringStartIdx));
            }
            normalStringStartIdx = -1;
        }
        if(bracketFlag) cout<<input[i];

        if(input[i] == '>') {
            normalStringStartIdx = i + 1;
            bracketFlag = false;
        }
    }
    checkNormalString(input.substr(normalStringStartIdx, input.size()));
}