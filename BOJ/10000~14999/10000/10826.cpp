#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string dp[10010];

string add(string a, string b) {
    string result = "";
    // 뒤에서부터 값을 더함
    // 10이 넘으면 다음 값에 +1 해서 넘겨줌
    // 마지막에 값이 넘어온게 있으면 result 맨 앞에 넘어줌
    bool carry = false;
    for(int i = 0 ; i < max(a.size(), b.size()) ; ++i) {
        bool preCarryValue = carry;
        carry = false;
        int sum = preCarryValue ? 1 : 0;
        // 뒤에 부터 읽어야 함.
        if(a.size() > i) 
            sum += a[a.size() - 1 - i] - '0';
        if(b.size() > i)
            sum += b[b.size() - 1 - i] - '0';
        if(sum >= 10) {
            sum %= 10;
            carry = true;
        }
        result.insert(result.begin(), sum + '0');
    }
    if(carry)
        result.insert(result.begin(), '1');
        
    return result;
}

string solve(int num) {
    if(num == 0) return "0";
    if(num == 1) return "1";

    string& ret = dp[num];
    if(ret != "")
        return ret;
    
    ret = add(solve(num - 1), solve(num - 2));

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0 ; i <= N ; ++i)
        dp[i] = "";
    cout<<solve(N);
}