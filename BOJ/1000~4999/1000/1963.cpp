#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int N;
int primes[10010];

void era() {
    primes[0] = 1;
    primes[1] = 1;
    for(int i = 2 ; i < 10000; i++) {
        if(primes[i] == 0) {
            for(int j = i * i ; j < 10000 ; j += i) 
                primes[j] = 1;
        }
    }
}

int bfs(int start, int end) {
    bool visited[10010] = {0,};
    queue<int> qu;
    qu.push(start);
    visited[start] = true;

    int cnt = 0;
    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();
            if(now == end) return cnt;

            string nowToString = to_string(now);
            for(int i = 0 ; i < 4 ; i++) {
                for(int j = 0 ; j < 10 ; j++) {
                    // to_integer
                    if(i == 0 && j == 0) continue;
                    string temp = nowToString;
                    temp[i] = j + '0';
                    int newNumber = atoi(temp.c_str());
                    if(visited[newNumber]) continue;
                    if(primes[newNumber]) continue;

                    visited[newNumber] = true;
                    qu.push(newNumber);
                }
            }
        }
        cnt++;
    }

    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    era();
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        int ret = bfs(a, b);
        if(ret == -1) printf("Impossible");
        else printf("%d", ret);
        puts("");
    }
}