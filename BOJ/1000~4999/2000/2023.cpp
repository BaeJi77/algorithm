#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

int N;
int primes[] = {2, 3, 5, 7};
set<int> st;

bool isPrime(int number) {
    if(number == 1) return false;
    for(int i = 2; i * i <= number ; ++i) {
        if(number % i == 0) return false;
    }
    return true;
}

void solve(int pre, int digit) {
    if(digit == N) {
        st.insert(pre);
        return;
    }

    for(int i = 1 ; i < 10 ; ++i) {
        int temp = pre * 10 + i;
        if(isPrime(temp) == false) continue;
        solve(temp, digit + 1);
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < 4 ; ++i)
        solve(primes[i], 1);
    for(auto val : st)
        cout<<val<<"\n";
}