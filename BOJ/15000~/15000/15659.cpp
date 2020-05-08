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
int maxx = -1e10;
int minn = 1e10;
int numbers[15];
int oper[4]; // +, -, *, /

int toCalNumber(string val) {
    queue<int> num;
    queue<char> operStack;
    int ret = 0;
    int tempNumber = -1;
    for(int i = 0 ; i < val.size() ; ++i) {
        if('0' <= val[i] && val[i] <= '9') { // number
            if(tempNumber == -1) tempNumber = i;
        } else {
            num.push(stoi(val.substr(tempNumber, i - tempNumber)));
            tempNumber = -1;
            operStack.push(val[i]);
        }
    }
    num.push(stoi(val.substr(tempNumber, val.size() - tempNumber)));

    stack<int> ans;
    ans.push(num.front());
    num.pop();
    
    while(!operStack.empty()) {
        int frontNumber = num.front();
        int ansTopNumber = ans.top();
        char frontOper = operStack.front();
        if(operStack.front() == '+') {
            ans.push(num.front());
            num.pop();
        }
        if(operStack.front() == '-') {
            ans.push(-num.front());
            num.pop();
        }
        if(operStack.front() == '*') {
            int temp = ans.top();
            ans.pop();
            temp *= num.front();
            num.pop();

            ans.push(temp);
        }
        if(operStack.front() == '/') {
            int temp = ans.top();
            ans.pop();
            temp = temp / num.front();
            num.pop();

            ans.push(temp);
        }
        operStack.pop();
    }

    while(!ans.empty()) {
        ret += ans.top();
        ans.pop();
    }

    return ret;
}

void solve(int idx, string val) {
    if(idx == N) {
        int number = toCalNumber(val);
        maxx = max(maxx, number);
        minn = min(minn, number);
        return;
    }

    for(int i = 0 ; i < 4 ; ++i) {
        if(oper[i] == 0) continue;
        oper[i]--;
        switch (i)
        {
        case 0:
            solve(idx + 1, val + '+' + to_string(numbers[idx]));
            break;
        
        case 1:
            solve(idx + 1, val + '-' + to_string(numbers[idx]));
            break;

        case 2:
            solve(idx + 1, val + '*' + to_string(numbers[idx]));
            break;

        case 3:
            solve(idx + 1, val + '/' + to_string(numbers[idx]));
            break;
        
        default:
            break;
        }
        oper[i]++;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        scanf("%d", &numbers[i]);
    }

    for(int i = 0 ; i < 4 ; ++i) 
        scanf("%d", &oper[i]);

    solve(1, to_string(numbers[0]));
    printf("%d\n%d", maxx, minn);
}