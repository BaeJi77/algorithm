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

string input;
string bomb;
stack<pair<char, int> > st;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>input>>bomb;
    int nowCorrectSize = 0;
    for(int i = 0 ; i < input.size() ; ++i) {
        if(input[i] == bomb[nowCorrectSize]) nowCorrectSize++;
        else if(input[i] == bomb[0]) nowCorrectSize = 1;
        else nowCorrectSize = 0;
        
        st.push(make_pair(input[i], nowCorrectSize));
        if(nowCorrectSize == bomb.size()) {
            for(int i = 0 ; i < bomb.size() ; ++i)
                st.pop();
            if(st.empty()) nowCorrectSize = 0;
            else nowCorrectSize = st.top().second;
        }
    }

    string ans = "";
    while(!st.empty()) {
        ans += st.top().first;
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if(ans.empty()) cout<<"FRULA";
    else cout<<ans;
}