#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string input, ans;
stack<char> oper;

int calPriority(char operation) {
    switch(operation) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>input;
    for(int i = 0 ; i < input.size() ; ++i) {
        char now = input[i];
        int nowCharPriority = calPriority(now);
        switch(now) {
            case '+':
            case '-':
            case '*':
            case '/': 
                while(!oper.empty()) {
                    if(calPriority(oper.top()) < nowCharPriority) break;
                    ans += oper.top();
                    oper.pop();
                }
                oper.push(now);
                break;
            
            case '(':
                oper.push(now);
                break;
            
            case ')': 
                while(!oper.empty()) {
                    if(oper.top() == '(') {
                        oper.pop();
                        break;
                    }
                    ans += oper.top();
                    oper.pop();
                }
                break;
            
            default:
                ans += now;
                break;
        }
    }
    while(!oper.empty()) {
        ans += oper.top();
        oper.pop();
    }
    cout<<ans<<"\n";
}