#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1e7;

int ans, t;
bool primes[MAX+10];
bool visited[MAX+10];
string temp;

void era() {
    primes[0] = 1;
    primes[1] = 1;
    for(int i = 2 ; i <= sqrt(MAX) ; i++) {
        if(primes[i] == 0) {
            for(int j = i * i ; j <= MAX ; j += i) {
                primes[j] = 1;
            }
        }
    }
}

void cal(int preNumber, int digit, int bit) {
    preNumber *= 10;
    if(digit == 1){
        for(int i = 0 ; i < temp.size() ; i++) {
            if(bit & (1<<i)) continue;
            int newNumber = preNumber + temp[i] - '0';
            if(primes[newNumber] == 0 && visited[newNumber] == false) {
                ans++;
                visited[newNumber] = true;
            }
        }
    } else {
        for(int i = 0 ; i < temp.size() ; i++ ) {
            if(bit & (1<<i)) continue;
            cal(preNumber + temp[i] - '0', digit - 1, bit | 1 << i);
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    era();
    cin>>t;
    while(t--) {
        ans = 0;
        memset(visited, 0, sizeof(visited));
        cin>>temp;
        for(int i = 0 ; i < temp.size() ; i++) {
            if(primes[temp[i] - '0']) continue;
            if(visited[temp[i] - '0']) continue;

            visited[temp[i] - '0'] = true;
            ans++;
        }

        for(int i = 2 ; i <= temp.size() ; i++) {
            // i는 digit;
            for(int j = 0 ; j < temp.size() ; j++) {
                if(temp[j] == '0') continue;
                cal(temp[j] - '0', i - 1, 1<<j);
            }
        }
        printf("%d\n", ans);
    }
}