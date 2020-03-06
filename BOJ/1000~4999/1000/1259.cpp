#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string Q;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    while(cin>>Q) {
        if(Q[0] == '0' && Q.size() == 1) 
            break;
        
        int ans = 1;
        int length = Q.size() % 2 == 0 ? Q.size()/2 : Q.size()/2 + 1;
        for(int i = 0 ; i < length ; i++) {
            char front = Q[Q.size() - i - 1];
            char back = Q[i];
            if(front != back) {
                ans = 0;
                break;
            }
        }
        if(ans) cout<<"yes\n";
        else cout<<"no\n";
    }
}