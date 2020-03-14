#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N;
queue<string> qu;
map<string, int> before;
map<string, int> after;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 1 ; i <= N ; i++) {
        string temp;
        cin>>temp;
        before[temp] = i;
        qu.push(temp);
    }

    int ans = 0;
    for(int i = 1 ; i <= N ; i++) {
        string temp;
        cin>>temp;
        after[temp] = i;

        if(qu.front() != temp) {
            ans++;
        } else {
            qu.pop();
        }
    }

    printf("%d", ans);
}