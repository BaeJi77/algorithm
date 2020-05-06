#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

int num[10];
int ans;
string input;
set<string> st;
map<string, int> dp;

void solve(string now, int arr[], string path) {
    if(now.size() == input.size()) {
        if(now == input) st.insert(path);
        return;
    }

    for(int i = 0 ; i < 10 ; ++i) {
        if(arr[i] > 0) {
            arr[i]--;
            solve(to_string(i) + now, arr, path + to_string(i) + now);
            solve(now + to_string(i), arr, path + to_string(i) + now);
            arr[i]++;
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>input;
    for(int i = 0 ; i < input.size() ; ++i) {
        num[input[i] - '0']++;
    }

    for(int i = 0 ; i < 10 ; ++i) {
        if(num[i] > 0) {
            string temp = to_string(i);
            num[i]--;
            solve(temp, num, temp);
            num[i]++;
        }
    }
    cout<<st.size();
}