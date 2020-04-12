#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    while(1) {
        string str;
        getline(cin, str);
        if(str == ".")
            break;

        stack<int> st;
        bool isOk = true;
        for(int i = 0 ; i < str.size(); ++i) {
            if(str[i] == '(') st.push(1);
            if(str[i] == '[') st.push(2);
            if(str[i] == ')') {
                if(st.empty()) {
                    isOk = false;
                } else {
                    if(st.top() != 1) {
                        isOk = false;
                    }
                    st.pop();
                }
            }
            if(str[i] == ']') {
                if(st.empty()) 
                    isOk = false;
                else {
                    if(st.top() != 2) {
                        isOk = false;
                    }
                    st.pop();
                }
            }
            if(isOk == false) break;
        }

        if(!st.empty()) isOk = false;

        if(isOk) cout<<"yes\n";
        else cout<<"no\n";
     }
}