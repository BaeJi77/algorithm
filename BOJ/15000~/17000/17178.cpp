#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int N;
string map[101][5];
stack<string> st;
priority_queue<pair<int, int> > pq;

bool isSame(string now) {
    if(pq.top().first != -now[0]) return false;
    if(pq.top().second != -stoi(now.substr(2, now.size()))) return false;
    return true;
}

bool isSameForTwoString(string in, string now) {
    if(in[0] != now[0]) return false;
    if(stoi(in.substr(2, in.size())) != stoi(now.substr(2, now.size()))) return false;
    return true;
}

int main() {
    freopen("/Users/user/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < 5; ++j) {
            string in;
            cin>>in;
            map[i][j] = in;
            pq.push(make_pair(-in[0], -stoi(in.substr(2,in.size()))));
        }
    }

    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < 5 ; ++j) {
            while(!st.empty() && isSame(st.top())) {
                st.pop();
                pq.pop();
            }

            if(isSame(map[i][j])) {
                pq.pop();
                continue;
            }

            st.push(map[i][j]);
        }
        while(!st.empty() && isSame(st.top())) {
            st.pop();
            pq.pop();
        }
    }

    if(st.empty() && pq.empty()) cout<<"GOOD";
    else cout<<"BAD";
}