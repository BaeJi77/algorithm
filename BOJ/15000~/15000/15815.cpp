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

stack<int> st;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    string input;
    cin>>input;
    for(int i = 0 ; i < input.size() ; ++i) {
        if('0' <= input[i] && input[i] <= '9') {
            st.push(input[i] - '0');
        } else {
            // 연산자인 경우
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            int result;
            switch (input[i])
            {
            case '+':
                result = first + second;
                break;

            case '-':
                result = first - second;
                break;

            case '*':
                result = first * second;
                break;

            case '/':
                result = first / second;    
                break;

            default:
                break;
            }
            st.push(result);
        }
    }
    cout<<st.top();
}