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
stack<char> st;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>input;
    for(auto c : input)
        st.push(c);
    
    int idx = input.size();
    int QLength = 0;
    bool include = false;
    while(!st.empty()) {
        idx--;
        if(st.top() == ')') {
            include = true;
        } else if(st.top() == '(') {
            include = false;
            QLength = QLength * (input[idx - 1] - '0');
            idx--;
            st.pop();
        } else {
            QLength++;
        }
        st.pop();
    }
    printf("%d\n", QLength);
}