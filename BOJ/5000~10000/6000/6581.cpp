#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> vt;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    string input;
    while(cin>>input) {
        vt.push_back(input);
    }

    int nowLineSize = 0;
    for(int i = 0 ; i < vt.size(); i++) {
        if(vt[i] == "<br>") {
            cout<<"\n";
            nowLineSize = 0;
        }
        else if(vt[i] == "<hr>") {
            if(nowLineSize != 0) cout<<"\n";
            cout<<"--------------------------------------------------------------------------------\n";
            nowLineSize = 0;
        }
        else {
            if(nowLineSize + vt[i].size() > 80) {
                cout<<"\n";
                nowLineSize = 0;
            }
            cout<<vt[i]<<" ";
            nowLineSize += vt[i].size() + 1;
        }
    }
}