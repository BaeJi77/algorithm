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

bool comp(string a, string b) {
    if(a.size() != b.size())
        return a.size() < b.size();
    if(a.size() == b.size()) {
        int aSum = 0;
        int bSum = 0;
        for(int i = 0 ; i < a.size() ; i++) {  
            if('0' <= a[i] && a[i] <= '9')
                aSum += a[i] - '0';
        }
        
        for(int i = 0 ; i < b.size() ; i++) {  
            if('0' <= b[i] && b[i] <= '9')
                bSum += b[i] - '0';
        }
        if(aSum != bSum)
            return aSum < bSum;
        else
            return a < b;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0 ; i < N ; i++) {
        string temp;
        cin>>temp;
        vt.push_back(temp);
    }

    sort(vt.begin(), vt.end(), comp);
    for(auto i : vt)
        cout<<i<<endl;
}