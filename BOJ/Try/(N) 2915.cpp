#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N, ans;
string map;

int convertStringToNumber(string str) {
    if(str == "I") return 1;
    if(str == "II") return 2;
    if(str == "III") return 3;
    if(str == "IV") return 4;
    if(str == "V") return 5;
    if(str == "VI") return 6;
    if(str == "VII") return 7;
    if(str == "VIII") return 8;
    if(str == "IX") return 9;
    if(str == "X") return 10;
    if(str == "XX") return 20;
    if(str == "XXX") return 30;
    if(str == "XL") return 40;
    if(str == "L") return 50;
    if(str == "LX") return 60;
    if(str == "LXX") return 70;
    if(str == "LXXX") return 90;
    if(str == "XC") return 90;
    return -1;
}

int calculateStringToNumber(string str) {
    int ret = 0;
    int i = 0;
    int firstValue = 0;
    bool isExistedSecondDigit = false;
    // 십의 자리가 오고 일의 자리가 와야지
    for(int j = 1 ; j <= str.size() ; j++) {
        string temp = str.substr(i, j);
        int convertedValue = convertStringToNumber(temp);
        if(convertedValue != -1) {
            i = j + 1;
            int secondDigit = convertedValue / 10;
            if(secondDigit) isExistedSecondDigit = true;
            if(firstValue == 0) {
                if(secondDigit == 0) firstValue = 1;
                else firstValue = 10;
            }
            ret += convertedValue;
        }
    }
    if(isExistedSecondDigit && firstValue == 1) return 0;
    if(i != str.size() + 1) return 0;
    return ret;
}

void solve(int bit, string nowString) {
    if((1 << N) - 1 == bit) {
        // cout<<bit<<" "<<nowString<<endl;
        int num = calculateStringToNumber(nowString);
        cout<<nowString<<" "<<num<<endl;
        if(num != 0) ans = min(ans, num);
        return;
    }

    for(int i = 0 ; i < N ; i++) {
        if(bit & 1 << i) continue;
        solve(bit | 1 << i, nowString + map[i]);
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>map;
    N = map.size();
    ans = 100;
    solve(0, "");
}