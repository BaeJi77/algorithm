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

int ans;
string input;
stack<int> st;

int cal() {
    st.pop();

    int ret = 0;
    int sum = 0;
    
    while(1) {
        if(st.top() == -1) {
            st.pop();
            ret = sum * st.top();
            break;
        } else if(st.top() == -2) {
            sum += cal();
        } else {
            sum++;
        }
        st.pop();
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>input;
    for(int i = 0 ; i < input.size() ; ++i) {
        if(input[i] == '(') st.push(-1);
        else if(input[i] == ')') st.push(-2);
        else st.push(input[i] - '0');
    }

    while(st.size() != 0) {
        if(st.top() == -2) {
            ans += cal();
        } else {
            ans++;
        }
        st.pop();
    }

    cout<<ans<<endl;
}