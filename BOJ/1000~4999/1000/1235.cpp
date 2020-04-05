#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> vt;


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0 ; i < N ; i++) {
        string in;
        cin>>in;
        vt.push_back(in);
    }

    int ans = 0;
    int stringLength = vt[0].size();
    // bool check[101] = {0, };
    for(int i = stringLength - 1 ; i >= 0 ; i--) {
        bool notOk = false;
        for(int j = 0 ; j < N - 1; j++) {
            for(int k = j + 1; k < N ; k++) {
                string temp = vt[j].substr(i, stringLength);
                string temp1 = vt[k].substr(i, stringLength);
                
                if(temp == temp1) {
                    notOk = true;
                    break;
                }
            }
            if(notOk) break;
        }
        if(notOk) continue;
        else {
            ans = stringLength - i;
            break;
        }
    }
    cout<<ans;
}